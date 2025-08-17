//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.fdeclare.h"
//silver_chain_scope_end

LuaCEmbedResponse  * dtw_get_pid(LuaCEmbed *args){
    #if defined(__linux__) || defined(__APPLE__)
        return LuaCEmbed_send_long(getpid()); 
    #elif defined(_WIN32) || defined(_WIN64)
        return LuaCEmbed_send_long(GetCurrentProcessId());
    #endif  
    return LuaCEmbed_send_error("Error: Unsupported platform for getting PID");
}

LuaCEmbedResponse *dtw_is_pid_alive(LuaCEmbed *args){
    lua_Integer pid = LuaCEmbed_get_long_arg(args, 0);
    if(LuaCEmbed_has_errors(args)){
        return LuaCEmbed_send_error("Error: Invalid PID argument");
    }
    
    #if defined(__linux__) || defined(__APPLE__)
        int status = kill(pid, 0);
        if (status == 0) {
            return LuaCEmbed_send_bool(true); // Process is alive
        } else if (errno == ESRCH) {
            return LuaCEmbed_send_bool(false); // Process does not exist
        } else {
            return LuaCEmbed_send_error("Error: Unable to check process status");
        }
    #elif defined(_WIN32) || defined(_WIN64)
        HANDLE hProcess = OpenProcess(SYNCHRONIZE, FALSE, (DWORD)pid);
        if (hProcess != NULL) {
            CloseHandle(hProcess);
            return LuaCEmbed_send_bool(true); // Process is alive
        } else {
            return LuaCEmbed_send_bool(false); // Process does not exist
        }
    #endif  
}