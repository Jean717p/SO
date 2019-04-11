#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void signalHandler();

int main(){
  pid_t pid;
  if(signal(SIGUSR1,signalHandler)==SIG_ERR){
    fprintf(stderr, "Signal Handler Error \n" );
    return(1);
  }
  pid=fork();
  if(pid){
    fprintf(stdout, "Pid padre: %d, pid figlio: %d\n",getpid(),pid);
    while(1){
      sleep(2);
      kill(pid,SIGUSR1);
      pause();
      fprintf(stdout, "Padre si sveglia\n" );
    }
  }
  else{
    pid=getppid();
    fprintf(stdout, "Figlio: pid=%d , pidpadre=%d\n",getpid(),pid;
    while(1){
      pause();
      fprintf(stdout, "Figlio si sveglia\n" );
      sleep(2);
      kill(pid,SIGUSR1);
    }
  }
  return 0;
}
static void signalHandler(void){
  return;
}
