#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define N 25
static void signalHandler();

int main(){
  pid_t bropid,mypid;
  int i,j; char tmp[N];
  int file[2];
  if(pipe(file)){
    fprintf(stderr, "Errore pipe.\n" );
    exit(-1);
  }
  if(signal(SIGUSR1,signalHandler)==SIG_ERR){
    fprintf(stderr, "Signal Handler Error \n" );
    return(1);
  }
  if(fork()){
    if(fork()){
      wait((int*) 0);
      wait((int*) 0);
      fprintf(stdout,"Bigbro termina con successo.\n___________\n\nFuck yeah\n___________\n");
    }
    else{
      /*FIGLIO 2*/
      close(file[1]);
      mypid=getpid();
      fprintf(stdout, "Yo sono Bro-2 : %d\n",mypid);
      i=read(file[0],&bropid,sizeof(pid_t));
      fprintf(stdout, "Bro-1 il tuo pid è %d\n",bropid);
      kill(bropid,SIGUSR1);
      do{
        fflush(stdout);
        i=read(file[0],&j,sizeof(int));
        i=read(file[0],tmp,(j+1)*sizeof(char));
        if(strcmp(tmp,"end")==0)
          break;
        fprintf(stdout,"\nBro-2 /*-.-*/\t");
        for(j=strlen(tmp),i=0;i<j;i++){
          fprintf(stdout,"%c",toupper(tmp[i]));
        }
        fprintf(stdout,"\n");
        kill(bropid,SIGUSR1);
      }while(1);
      fprintf(stdout,"Bro-2 termina.\n");
      kill(bropid,SIGUSR1);
      close(file[0]);
    }
  }
  else{
    /*FIGLIO 1*/
    mypid=getpid();
    fprintf(stdout, "Yo sono Bro-1 : %d\n",mypid);
    close(file[0]);
    i=write(file[1],&mypid,sizeof(pid_t));
    pause();
    fprintf(stdout, "Inizio del programma....\n");
    fprintf(stdout,"Inserire stringhe, end per terminare.\n");
    do{
      fprintf(stdout,"Tu scemo scemo dare me stringa stringa!\n");
      scanf("%s",tmp);
      j=strlen(tmp);
      i=write(file[1],&j,sizeof(int));
      i=write(file[1],tmp,(j+1)*sizeof(char));
      pause();
    }while(strcmp(tmp,"end")!=0);
    fprintf(stdout,"Bro-1 termina.\n");
    close(file[1]);
  }
  return 0;
}
static void signalHandler(void){
  return;
}
