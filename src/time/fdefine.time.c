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