#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
  int numero=1;
  do{
    scanf("%d",&numero);
    if(numero){
      if(numero%2==0)
          fprintf(stdout,"Numero pari %d\n",numero );
      else
        fprintf(stderr,"Numero dispari %d\n",numero );
  }
}while(numero!=0);
  fprintf(stdout, "Termino.\n");
  return 0;
}
