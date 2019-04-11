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
  int i,j; char f[]={"File.txt"},tmp[N];
  int file=creat(f,0666);
  close(file);
  file=open(f,O_RDWR);
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
      sleep(1);
      mypid=getpid();
      fprintf(stdout, "Yo sono Bro-2 : %d\n",mypid);
      lseek(file,0,SEEK_SET);
      i=read(file,&bropid,sizeof(pid_t));
      fprintf(stdout, "Bro-1 il tuo pid è %d\n",bropid);
      lseek(file,0,SEEK_SET);
      i=write(file,&mypid,sizeof(pid_t));
      kill(bropid,SIGUSR1);
      pause();
      fprintf(stdout,"Mi risveglio@Bro-2\n");
      kill(bropid,SIGUSR1);
      pause();
      do{
        fflush(stdout);
        lseek(file,0,SEEK_SET);
        i=read(file,tmp,N*sizeof(char));
        if(strcmp(tmp,"end")==0)
          break;
        fprintf(stdout,"\nBro-2 /*-.-*/\t");
        for(j=strlen(tmp),i=0;i<j;i++){
          fprintf(stdout,"%c",toupper(tmp[i]));
        }
        fprintf(stdout,"\n");
        kill(bropid,SIGUSR1);
        pause();
      }while(1);
      fprintf(stdout,"Bro-2 termina.\n");
      kill(bropid,SIGUSR1);
    }
  }
  else{
    /*FIGLIO 1*/
    mypid=getpid();
    fprintf(stdout, "Yo sono Bro-1 : %d\n",mypid);
    i=write(file,&mypid,sizeof(pid_t));
    pause();
    fprintf(stdout,"Mi risveglio@Bro-1\n");
    lseek(file,0,SEEK_SET);
    i=read(file,&bropid,sizeof(pid_t));
    fprintf(stdout, "Bro-2 il tuo pid è %d\nMo dormo.. Se non mi sveglio c'è un errore..\n",bropid);
    kill(bropid,SIGUSR1);
    sleep(100);
    fprintf(stdout,"Ok continuo allora bro\n____________\n");
    lseek(file,0,SEEK_SET);
    fprintf(stdout, "Inizio del programma....\n");
    fprintf(stdout,"Inserire stringhe, end per terminare.\n");
    do{
      lseek(file,0,SEEK_SET);
      fprintf(stdout,"Tu scemo scemo dare me stringa stringa!\n");
      scanf("%s",tmp);
      i=write(file,tmp,N*sizeof(char));
      kill(bropid,SIGUSR1);
      pause();
    }while(strcmp(tmp,"end")!=0);
    fprintf(stdout,"Bro-1 termina.\n");
  }
  return 0;
}
static void signalHandler(void){
  return;
}
