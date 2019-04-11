#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void binary(int *, int);

int main (int argc,char *argv[]){
  int n;
  int *vet;
  n = atoi (argv[1]);
  vet = (int *)malloc(n * sizeof(int));
  if (vet == NULL) {
    printf("Allocatin Error.\n");
    exit(1);
  }
  printf("Binary Numbers:\n");
  binary(vet, n);
  free(vet);
  return 0;
}

void binary(int *vet,int n){
  int i,j;
  for(i=0;i<=n;i++){
    if(i==n){
      for(j=0;j<n;j++){
        printf("%d\n",vet[j]);
      }
      printf("\n" );
      exit(0);
    }
    else{
      if(fork()){ //padre
        if(fork()){ //padre
          wait((int*)0);
          wait((int*)0);
          exit(1);
        }
        else{ //child 2
          vet[i]=1;
        }
      }
      else{//child 1
        vet[i]=0;
      }
    }
  }
  return;
}
