#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(){
  pid_t mypid;
  int ufile[2],zfile[2],j,i=0;
  if(pipe(ufile)){
    fprintf(stderr, "Errore pipe u.\n" );
    exit(-1);
  }
  if(pipe(zfile)){
    fprintf(stderr, "Errore pipe z.\n" );
    exit(-1);
  }
  mypid=fork();
  if(mypid){
    mypid=getpid();
    do{
      j=read(zfile[0],&j,sizeof(int));
      fprintf(stdout,"I'm your father! (Pid=%d)\n",mypid);
      j=write(ufile[1],&i,sizeof(int));
    }while(5>i++);
  }
  else{
    mypid=getpid();
    while(1){
      j=write(zfile[1],&j,sizeof(int));
      j=read(ufile[0],&i,sizeof(int));
      fprintf(stdout, "I'm your son! (Pid=%d)\n",mypid);
      if(i==5)
        break;
    }
  }
  return 0;
}
