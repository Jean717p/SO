#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

#define MAXPATH 200

struct _threadargs {
 char filein[MAXPATH];
 char fileout[MAXPATH];
};
typedef struct _threadargs ThreadArgs;

void *tf(void*);
int *read_file (char *filename,int *size);
void sort (int *vett,int size);
void write_file (int *vett,int size,char *filename);


int main (int argc,char* argv[]){
  pthread_t threadID ;
  ThreadArgs *ta;
  void *exitstatus;
  int i,nt;
  nt=atoi(argv[1]);
  for(i=0;i<nt;i++) {
    ta = malloc(sizeof(ThreadArgs));
    sprintf(ta->filein,"%s%d.txt",(char *)argv[2],i+1);
    printf("%s\n",ta->filein );
    sprintf(ta->fileout,"%s%d.txt",(char *)argv[3],i+1);
    pthread_create(&threadID,NULL,tf,(void*)(ta));
    pthread_join (threadID , &exitstatus );
  }
  return 0;
}
void *tf (void *arg){
  ThreadArgs *thargs;
  thargs=(ThreadArgs *)arg;
  char *filename;
  filename=thargs->filein;
  int *vett=NULL, size;
  vett=read_file(filename,&size);
  assert(vett!=NULL);
  sort(vett,size);
  write_file(vett,size,thargs->fileout);
  free(vett);
  free(thargs);
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
  for(i=0;i<size;i++) {
    fprintf(fp,"%d\n",vett[i]);
  }
  fclose(fp);
}
