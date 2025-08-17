//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end

#if defined(__linux__) || defined(__APPLE__)
#include <time.h>
#endif
#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#include <sys/timeb.h>
#endif


LuaCEmbedResponse  * dtw_get_absolute_time(LuaCEmbed *args){
    LuaCEmbedTable *created_table = LuaCembed_new_anonymous_table(args);
    #if defined(__linux__) || defined(__APPLE__)
        struct timespec ts;
        clock_gettime(CLOCK_REALTIME, &ts);
        LuaCEmbedTable_set_long_prop(created_table, "seconds", ts.tv_sec);
        LuaCEmbedTable_set_long_prop(created_table, "nanoseconds", ts.tv_nsec);
        LuaCEmbedTable_set_long_prop(created_table, "milliseconds", ts.tv_nsec / 1000000);
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        struct _timeb timebuffer;
        _ftime(&timebuffer);
        LuaCEmbedTable_set_long_prop(created_table, "seconds", timebuffer.time);
        LuaCEmbedTable_set_long_prop(created_table, "nanoseconds", timebuffer.millitm * 1000000);
        LuaCEmbedTable_set_long_prop(created_table, "milliseconds", timebuffer.millit);
    
    #endif

    return LuaCEmbed_send_table(created_table);
}

LuaCEmbedResponse *dtw_get_absolute_time_from_str(LuaCEmbed *args) {
    const char *time_str = LuaCEmbed_get_str_arg(args, 0);
    if(LuaCEmbed_has_errors(args)) {
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error("Error getting time string: %s", error_msg);
    }
    
    LuaCEmbedTable *created_table = LuaCembed_new_anonymous_table(args);
    // Assuming time_str is in the format 2020-07-10T12:34:56.000Z
    struct tm tm = {0};
    long miliseconds = 0;
 
    if (sscanf(time_str, "%d-%d-%dT%d:%d:%d.%ldZ", 
               &tm.tm_year, &tm.tm_mon, &tm.tm_mday,
               &tm.tm_hour, &tm.tm_min, &tm.tm_sec, &miliseconds) != 7) {
        return LuaCEmbed_send_error("Invalid time format");
    }
    tm.tm_year -= 1900;
    tm.tm_mon -= 1;
    time_t seconds = mktime(&tm);
    long nanoseconds = miliseconds * 1000000; // Convert milliseconds to nanoseconds
    LuaCEmbedTable_set_long_prop(created_table, "seconds", seconds);
    LuaCEmbedTable_set_long_prop(created_table, "nanoseconds", nanoseconds);
    LuaCEmbedTable_set_long_prop(created_table, "milliseconds", miliseconds);
    return LuaCEmbed_send_table(created_table);
}  

LuaCEmbedResponse *dtw_convert_absolute_time_to_str(LuaCEmbed *args) {
    LuaCEmbedTable *absolute_time = LuaCEmbed_get_arg_table(args, 0);
    if(LuaCEmbed_has_errors(args)) {
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error("Error getting absolute time table: %s", error_msg);
    }
    lua_Integer seconds = LuaCembedTable_get_long_prop(absolute_time, "seconds");
    lua_Integer nanoseconds = LuaCembedTable_get_long_prop(absolute_time, "nanoseconds");
    lua_Integer milliseconds = LuaCembedTable_get_long_prop(absolute_time, "milliseconds");

    if(LuaCEmbed_has_errors(args)) {
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error("Error getting properties from absolute time table: %s", error_msg);
    }
    struct tm *tm_info;
    time_t rawtime = seconds;
    tm_info = localtime(&rawtime);
    char buffer[60] ={0};
    strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%S", tm_info);
    sprintf(buffer + strlen(buffer), ".%03lldZ", milliseconds);
    return LuaCEmbed_send_str(buffer);
}