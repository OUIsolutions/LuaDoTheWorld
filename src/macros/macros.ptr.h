//silver_chain_scope_start
//mannaged by silver chain: https://github.com/OUIsolutions/SilverChain
#include "../imports/imports.consts.h"
//silver_chain_scope_end


#if defined(__linux__) || defined(__APPLE__)
#define  ldtw_ptr_cast long long
#endif

#ifdef  _WIN32
#define  ldtw_ptr_cast  long

#endif
