#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
//soluzione a 7 semafori anziché 9
typedef struct Threadargs{
  pthread_t threadid;
  int id,nome;
}th;

sem_t semA,semC,semD,semF,semG,semH,semI;
void *pA();void *pC();void *pD(); void *pF();
void pB();void pE();void pG();void pH(); void pI();

int main(){
  int i,nT=4,cicli=0; void *retval;
  th *td;
  td=(th*)malloc(nT*sizeof(th));
  sem_init(&semA,0,0);
  sem_init(&semC,0,0);
  sem_init(&semD,0,0);
  sem_init(&semF,0,0);
  sem_init(&semG,0,0);
  sem_init(&semH,0,0);
  sem_init(&semI,0,1);
  int vet[4]={'A','C','D','F'};
  do{
    printf("Ciclo: %d\n",cicli+1 );
    for(i=0;i<nT;i++){
      td[i].id=i;
      td[i].nome=vet[i];
      printf("%c\n",td[i].nome);
      switch(td[i].nome){
        case 'A': pthread_create(&(td[i].threadid),NULL,pA,(void*) &td[i]);break;
        //case 'B': pthread_creat(td[i].threadid,NULL,pB,(void*)&td[i]);
        case 'C': pthread_create(&(td[i].threadid),NULL,pC,(void*) &td[i]);break;
        case 'D': pthread_create(&(td[i].threadid),NULL,pD,(void*) &td[i]);break;
        //case 'E': pthread_creat(td[i].threadid,NULL,pE,(void*)&td[i]);
        case 'F': pthread_create(&(td[i].threadid),NULL,pF,(void*) &td[i]);break;
        //case 'G': pthread_creat(td[i].threadid,NULL,pG,(void*)&td[i]);
        //case 'H': pthread_creat(td[i].threadid,NULL,pH,(void*)&td[i]);
        //case 'I': pthread_creat(td[i].threadid,NULL,pI,(void*)&td[i]);
      }
    }
    for(i=0;i<nT;i++){
      pthread_join(td[i].threadid,&retval);
    }
    cicli++;
  }while(cicli<3);
  return 0;
}

void *pA(void *arg){
  th *td;
  td=(th*) arg;
  sem_wait(&semI);
  printf("%c %d\n",td->nome,(int)td->threadid);
  sem_post(&semA);
  sem_post(&semA);
  td->nome='B';
  pB(td);
  td->nome='I';
  pI(td);
  pthread_exit((void*)1);
}
void pB(th* td){
  printf("%c %d\n",td->nome,(int)td->threadid);
  return;
}
void pI(th* td){
  sem_wait(&semG);
  sem_wait(&semH);
  printf("%c %d\n",td->nome,(int)td->threadid);
  sem_post(&semI);
  return;
}
void *pD(void *arg){
  th *td=(th*)arg;
  sem_wait(&semA);
  printf("%c %d\n",td->nome,(int)td->threadid);
  td->nome='H'; //D -> H
  pH(td);
  pthread_exit((void*)1);
}
void pH(th* td){
  printf("%c %d\n",td->nome,(int)td->threadid);
  sem_post(&semH);
  return;
}
void *pC(void *arg){
  th *td=(th*)arg;
  sem_wait(&semA);
  printf("%c %d\n",td->nome,(int)td->threadid);
  sem_post(&semC);
  td->nome='E'; //C->E
  pE(td);
  td->nome='G'; //E->G
  pG(td);
  pthread_exit((void*)1);
}
void pE(th *td){
  printf("%c %d\n",td->nome,(int)td->threadid);
  return;
}
void *pF(void *arg){
  th *td=(th*)arg;
  sem_wait(&semC);
  printf("%c %d\n",td->nome,(int)td->threadid);
  sem_post(&semF);
  pthread_exit((void*)1);
}
void pG(th *td){
  sem_wait(&semF);
  printf("%c %d\n",td->nome,(int)td->threadid);
  sem_post(&semG);
  return;
}
