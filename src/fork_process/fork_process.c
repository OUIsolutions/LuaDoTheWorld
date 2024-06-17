

LuaCEmbedResponse * create_fork_process(LuaCEmbed *args) {

     int pid =fork();
     if(pid==0) {
          LuaCEmbed_run_args_lambda(args,0,NULL,0);
          lua_close(args->state);
          exit(0);
     }
     

}