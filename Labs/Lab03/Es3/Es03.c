#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
void stampa(char,int i,int pid);
int main(){
  pid_t pid;
  char cas={'P'};
  stampa(cas,1,getpid());
  pid=fork();
  if(pid){
    stampa(cas,2,getpid());
    sleep(01);
    pid=fork();
    if(pid==0){
      sleep(1);
      stampa(cas,5,getpid());
      sleep(1);
      return 0;
    }
    else{
      stampa(cas,4,getpid());
      wait((int*) 0);
    }
    stampa(cas,7,getpid());
  }
  else{
    sleep(01);
    stampa(cas,3,getpid());
    sleep(02);
    stampa(cas,6,getpid());
    sleep(1);
    stampa(cas,8,getpid());
    return 0;
  }
  wait((int*) 0);
  stampa(cas,9,getpid());
  return 0;
}
void stampa(char cas,int i,int pid){
  printf("%c%d %d\n",cas,i,pid);
  return;
}
