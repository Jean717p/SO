#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef int * Semaforo;

Semaforo semA,semC,semE,semF,semG,semH,semI;

Semaforo make_sem(){
  int *sem;
  sem = calloc(2,sizeof(int));
  pipe(sem);
  return sem;
}
void WAIT(Semaforo s) {
  int junk;
  read(s[0], &junk, 1);
  return;
}
void SIGNAL(Semaforo s) {
  write(s[1], "x", 1); return;
}
void pA(){
  printf("A %d\n",getpid());
  SIGNAL(semA);
  SIGNAL(semA);
}
void pB(){
  printf("B %d\n",getpid());
  return;
}
void pI(){
  WAIT(semG);
  WAIT(semH);
  printf("I %d\n",getpid());
  SIGNAL(semI);
  return;
}
void pD(){
  WAIT(semA);
  printf("D %d\n",getpid());
  return;
}
void pH(){
  printf("H %d\n",getpid());
  SIGNAL(semH);
  return;
}
void pC(){
  WAIT(semA);
  printf("C %d\n",getpid());
  SIGNAL(semC);
  return;
}
void pE(){
  printf("E %d\n",getpid());
  return;
}
void pF(){
  WAIT(semC);
  printf("F %d\n",getpid());
  SIGNAL(semF);
  return;
}
void pG(){
  WAIT(semF);
  printf("G %d\n",getpid());
  SIGNAL(semG);
  return;
}
int main(){
  int cicli=0;
  semA=make_sem();
  semC=make_sem();
  semF=make_sem();
  semG=make_sem();
  semH=make_sem();
  semI=make_sem();
  do{
    printf("Ciclo: %d\n",cicli+1 );
    if(!fork()){ //Il figlio nasce come A e morirà come I
      if(fork()){ //A->C
        if(fork()){ //A->D
          pA(); //A->B->I
          pB();
          pI();
          exit(0);
        }
        else{ //D -> H
          pD();
          pH();
          exit(0);
        }
      }
      else if(fork()){//C->E C->F
        pC();//C->E->G
        pE();
        pG();
        exit(0);
      }
      else{ //F
        pF();
        exit(0);
      }
    }
    WAIT(semI);
    cicli++;
  }while(cicli<4);
  return 0;
}
