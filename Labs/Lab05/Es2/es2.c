#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 12

void child(int,int);
  int i,j,v,fd,c;
int main(int argc,char* argv[]){
  int vet[N]={0,10,5,20,15,30,25,40,35,50,45,60};
  if(argc!=2){
    fprintf(stderr,"Use ./%s file_name\n",argv[0]);
    exit(-1);
  }
  fd=creat(argv[1],0666);
  if(fd==-1){
    fprintf(stderr, "Impossibile creare %s\n",argv[1]);
    exit(-1);
  }
  for(i=0;i<N;i++){
    write(fd,&vet[i],sizeof(int));
  }
  close(fd);
  fd=open(argv[1],O_RDWR);
  if(fd==-1){
    fprintf(stderr, "Errore apertura file %s\n",argv[1] );
    exit(-1);
  }
  fprintf(stdout, "File preordinamento:\n" );
  for(i=0;i<N;i++){
    lseek(fd,i*sizeof(int),SEEK_SET);
    c=read(fd,&v,sizeof(int));
    if(c<=0){
      fprintf(stderr, "Error reading the file.\n" );
      exit(-1);
    }
    fprintf(stdout, "%2d\n",v );
  }
  fprintf(stdout, "\n" );
  close(fd);
  fd=open(argv[1],O_RDWR);
  if(fd==-1){
    fprintf(stderr, "Errore apertura file %s\n",argv[1] );
    exit(-1);
  }
  fprintf(stdout, "Sto ordinando....\n" );
  for(i=0;i<N-1;i++){
    for(j=0;j<N-1-i;j++){
      if(fork()){
        wait((int*)0);
        break;
      }
      else{
        child(fd,j);
        if(j)
          exit(0);
      }
    }
  }
  close(fd);
  fd=open(argv[1],O_RDONLY);
  if(fd==-1){
    fprintf(stderr, "Errore apertura file %s\n",argv[1] );
    exit(-1);
  }
  fprintf(stdout, "File postordinamento:\n" );
  for(i=0;i<N;i++){
    lseek(fd,i*sizeof(int),SEEK_SET);
    c=read(fd,&v,sizeof(int));
    if(c<=0){
      fprintf(stderr, "Error reading file %s\n",argv[1]);
      exit(-1);
    }
    fprintf(stdout, "%2d\n",v );
  }
  fprintf(stdout, "\n" );
  close(fd);

  return 0;
}
void child(int fd,int j){
  int v1,v2,c1,c2;
  lseek(fd,j*sizeof(int),SEEK_SET);
  c1=read(fd,&v1,sizeof(int));
  c2=read(fd,&v2,sizeof(int));
  if(c1<=0||c2<=0){
    fprintf(stderr, "Errore lettura file.\n" );
    exit(-1);
  }
  if(v1>v2){
    lseek(fd,j*sizeof(int),SEEK_SET);
    c1=write(fd,&v2,sizeof(int));
    c2=write(fd,&v1,sizeof(int));
  }
}
