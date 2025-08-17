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
    const char *time_str = LuaCEmbed_get_string_arg(args, 0);
    if(LuaCEmbed_has_errors(args)) {
        char *error_msg = LuaCEmbed_get_error_message(args);
        return LuaCEmbed_send_error("Error getting time string: %s", error_msg);
    }
    
    LuaCEmbedTable *created_table = LuaCembed_new_anonymous_table(NULL);
    // Assuming time_str is in the format 2020-07-10T12:34:56.000Z
    struct tm tm;
    if (strptime(time_str, "%Y-%m-%dT%H:%M:%S.%fZ", &tm) == NULL) {
        return LuaCEmbed_send_error("Invalid time format");
    }
    time_t seconds = mktime(&tm);
    long nanoseconds = 0; // Assuming no fractional seconds in the input
    LuaCEmbedTable_set_long_prop(created_table, "seconds", seconds);
    LuaCEmbedTable_set_long_prop(created_table, "nanoseconds", nanoseconds);
    LuaCEmbedTable_set_long_prop(created_table, "milliseconds", nanoseconds / 1000000);
    return LuaCEmbed_send_table(created_table);
}