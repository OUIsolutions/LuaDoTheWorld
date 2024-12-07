
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.consts.h"
//silver_chain_scope_end

#ifdef __linux__
#define  ldtw_ptr_cast long long
#endif

#ifdef  _WIN32
#define  ldtw_ptr_cast  long

#endif
