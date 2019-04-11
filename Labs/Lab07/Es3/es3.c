#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <pthread.h>

#define MAXPATH 200

struct _threadargs {
 char filein[MAXPATH];
 char fileout[MAXPATH];
 int tot;
};
typedef struct _threadargs ThreadArgs;

void *tf(void*);
int *read_file (char *filename,int *size);
void sort (int *vett,int size);
void write_file (int *vett,int size,char *filename);


int main (int argc,char* argv[]){
  pthread_t threadID,*th;
  ThreadArgs *ta,**tt;
  void *exitstatus;
  char *fout={"FileOut.txt"};
  int i,j,*vett,*vett2,nt,nul;
  nt=atoi(argv[1]);
  if(nt<1)
    exit(-1);
  th=malloc(nt*sizeof(pthread_t));
  tt=malloc(nt*sizeof(ThreadArgs*));
  for(i=j=0;i<nt;i++) {
    ta = malloc(sizeof(ThreadArgs));
    ta->tot=0;
    sprintf(ta->filein,"%s%d.txt",(char *)argv[2],i+1);
    printf("%s\n",ta->filein );
    sprintf(ta->fileout,"%s%d.txt",(char *)argv[3],i+1);
    pthread_create(&threadID,NULL,tf,(void*)(ta));
    tt[i]=ta; th[i]=threadID;
  }
  i=0;
  threadID=th[i];
  pthread_join (threadID, &exitstatus);
  j=tt[i]->tot;
  printf("tot_%d=%d\n",i,j);
  vett2=read_file(tt[i]->fileout,&nul);
  vett=malloc(j*sizeof(int));
  for(j=0;j<(tt[i]->tot);j++)
    vett[j]=vett2[j];
  write_file(vett,tt[i]->tot,fout);
  for(i=1;i<nt;i++){
    threadID=th[i];
    pthread_join (threadID, &exitstatus);
    vett2=read_file(tt[i]->fileout,&nul);
    printf("tot_%d=%d\n",i,tt[i]->tot);
    for(nul=j;j<(nul+tt[i]->tot);j++)
      vett[j]=vett2[j-nul];
    sort(vett,j);
    if(!fork()){
      execlp("rm","rm",tt[i-1]->fileout,NULL);
    }
  //free(ta);
  }
  if(!fork()){
    execlp("rm","rm",tt[nt-1]->fileout,NULL);
  }
  write_file(vett,j,fout);
  //free(vett); free(vett2); free(tt); free(th);
  return 0;
}
void *tf (void *arg){
  ThreadArgs *thargs;
  thargs=(ThreadArgs *)arg;
  char *filename;
  filename=thargs->filein;
  int *vett=NULL, size;
  vett=read_file(filename,&size);
  thargs->tot=size;
  assert(vett!=NULL);
  sort(vett,size);
  write_file(vett,size,thargs->fileout);
  free(vett);
  return 0;
}

int *read_file (char *filename,int *size){
  int *vett,s,i=0;
  FILE *fp=NULL;
  fp=fopen(filename,"r");
  assert(fp!=NULL);
  fscanf(fp,"%d",&s);
  vett=(int *)malloc(s*sizeof(int));
  while(fscanf(fp,"%d",&vett[i++])!=EOF);
  *size=s;
  fclose(fp);
  return vett;
}

void sort (int *vett,int size){
  int i,j,temp;
  for(i=0;i<size;i++) {
    for(j=0;j<i;j++) {
      if(vett[i]<vett[j]) {
        temp=vett[i]; //swap
        vett[i]=vett[j];
        vett[j]=temp;
      }
    }
  }
  return;
}

void write_file (int *vett,int size,char *filename){
  int i;
  FILE *fp=NULL;
  printf("write %s\n",filename);
  fp=fopen(filename,"w");
  fprintf(fp,"%d\n",size);
  for(i=0;i<size;i++) {
    fprintf(fp,"%d\n",vett[i]);
  }
  fclose(fp);
}
