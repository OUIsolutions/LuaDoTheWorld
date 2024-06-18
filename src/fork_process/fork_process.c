
int lua_do_the_world_sleep_mili_seconds(long miliseconds){
     struct timespec rem;
     struct timespec req= {
          (int)(miliseconds / 1000),     /* secs (Must be Non-Negative) */
          (miliseconds % 1000) * 1000000 /* nano (Must be in range of 0 to 999999999) */
      };

     return nanosleep(&req , &rem);
}

LuaCEmbedResponse * fork_wait(LuaCEmbedTable *self,LuaCEmbed *args) {

     int timeout = LuaCEmbed_get_long_arg(args,0);
     if(LuaCEmbed_has_errors(args)) {
          char *error_msg = LuaCEmbed_get_error_message(args);
          return LuaCEmbed_send_error(error_msg);
     }
     int wait_time = LuaCembedTable_get_long_prop(self,FORK_SLEEP_PROP);
     int waited= 0;

     while (true) {

     }

}


LuaCEmbedResponse * is_fork_alive(LuaCEmbedTable *self,LuaCEmbed *args) {
     int pid = LuaCembedTable_get_long_prop(self,PID_PROP);
     int status;
     pid_t new_pid = waitpid(pid, &status, WNOHANG);
     LuaCEmbedTable_set_long_prop(self,FORK_STATUS,status);

     if(new_pid == 0) {
          return LuaCEmbed_send_bool(true);
     }
     return LuaCEmbed_send_bool(false);
}



LuaCEmbedResponse * kill_process(LuaCEmbedTable *self,LuaCEmbed *args) {
     int pid = LuaCembedTable_get_long_prop(self,PID_PROP);
     kill(pid, SIGKILL);
     return  NULL;
}

LuaCEmbedResponse * fork_delete(LuaCEmbedTable *self,LuaCEmbed *args) {
     int pid = LuaCembedTable_get_long_prop(self,PID_PROP);
     kill(pid, SIGKILL);
     return  NULL;
}

LuaCEmbedResponse * create_fork_process(LuaCEmbed *args) {

     int pid =fork();
     if(pid==0) {

          LuaCEmbed_run_args_lambda(args,0,NULL,0);
          if(LuaCEmbed_has_errors(args)) {
               printf("error %s\n",LuaCEmbed_get_error_message(args));
               LuaCEmbed_clear_errors(args);
          }

          exit(0);
     }
     if(pid == -1) {
          return LuaCEmbed_send_error(IMPOSSIBLE_TO_FORK);
     }

     LuaCEmbedTable *self =LuaCembed_new_anonymous_table(args);
     LuaCEmbedTable_set_long_prop(self,PID_PROP,pid);
     LuaCEmbedTable_set_long_prop(self,FORK_SLEEP_PROP,FORK_SLEEP_DEFAULT_TIME);
     LuaCEmbedTable_set_method(self,DELETE_METHOD,fork_delete);
     LuaCEmbedTable_set_method(self,KILL_FORK_METHOD,kill_process);
     LuaCEmbedTable_set_method(self,IS_FORK_ALIVE,is_fork_alive);
     return LuaCEmbed_send_table(self);


}