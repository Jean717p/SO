#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc,char* argv[]){
  if(argc!=3){
    printf("Error!\n Please use:\tprg_name file_name -mode \t(mode: -1 system or -2 exec)\n\n");
    exit(-1);
  }
  FILE *fp=fopen(argv[1],"r");
  int i=0;
  char cmd[90],*tmp,**mat;
  if(fp==NULL){
    printf("Error file_name\n" );
    exit(-2);
  }
  if(argv[2][1]=='2'){
    mat=malloc(45*sizeof(char*));
      for(i=0;i<45;i++){
        mat[i]=malloc(15*sizeof(char));
      }
  }
  tmp=malloc(15*sizeof(char));
  while(fscanf(fp,"%s",tmp)!=EOF){
    if(strcmp(tmp,"end")==0){
      printf("(Command: %s)\n",cmd);
      if(argv[2][1]=='1'){
          system(cmd);
        }
      else{
        tmp=mat[i];
        mat[i]=NULL;
        if(!fork())
          execvp(mat[0],mat);
        mat[i]=tmp;
        sleep(3);
        i=0;
      }
    }
    else{
      strcat(cmd,tmp);
      strcpy(mat[i++],tmp);
      strcat(cmd," ");
    }
  }
  fclose(fp);
  return 0;
}
