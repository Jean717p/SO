#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>

int ricorri(char*,struct stat);
int main(int argc,char **argv){
  struct stat buf;
  if(argc!=2){
    printf("Chiamata fallita.\n");
    exit(-1);
  }
  if(ricorri(argv[1],buf)!=0)
    printf("Errore.\n");
  return 0;
}
int ricorri(char *path,struct stat buf){
  char* temp; DIR *dp=NULL;
  struct dirent *dirp=NULL;
  if((dp=opendir(path))==NULL){
  printf("Errore apertura cartella %s\n",path);
  exit(-2);
}
if(lstat(path,&buf)<0){
  printf("Error 2\n");
  exit(-3);
 }
 else if(S_ISDIR(buf.st_mode)==0){
   printf("Error 3.\n");
   exit(-4);
 }
 while((dirp=readdir(dp))!=NULL){
  temp=malloc((strlen(path)+strlen(dirp->d_name)+2)*sizeof(char*));
  sprintf(temp,"%s/%s",path,dirp->d_name);
  if(lstat(temp,&buf)<0){
    printf("Error 4.\n");
    exit(-5);
  }
  else if(S_ISDIR(buf.st_mode)==0){
    printf("%s ",dirp->d_name);}
  else{
    printf("%s ",dirp->d_name);
    if(dirp->d_name[0]!='.')
      printf("./%s: ",dirp->d_name);
  }
  printf("\n\n");
  if(dirp->d_name[0]!='.')
    ricorri(temp,buf);
 }
if(closedir(dp)<0){
  printf("Error 5.\n");
  exit(-6);
 }
 else
   printf("\n\n");

  return 0;
}
