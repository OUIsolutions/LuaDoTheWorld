
LuaCEmbedResponse * is_fork_alive(LuaCEmbedTable *self,LuaCEmbed *args) {
     int pid = LuaCembedTable_get_long_prop(self,PID_PROP);
     int status;
     pid_t new_pid = waitpid(pid, &status, WNOHANG);
     LuaCEmbedTable_set_long_prop(self,PID_PROP,new_pid);
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
     LuaCEmbedTable_set_method(self,DELETE_METHOD,fork_delete);
     LuaCEmbedTable_set_method(self,KILL_FORK_METHOD,kill_process);
     LuaCEmbedTable_set_method(self,IS_FORK_ALIVE,is_fork_alive);
     return LuaCEmbed_send_table(self);


}