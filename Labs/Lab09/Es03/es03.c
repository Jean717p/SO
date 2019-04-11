#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <sys/types.h>
#include <pthread.h>
#include <semaphore.h>
#include <ctype.h>
//soluzione a 7 semafori anziché 9
typedef struct Threadargs{
  pthread_t threadid;
  int id,nome;
}th;

sem_t semA,semB,semC,semD,semE,semF,semG,semH,semI;
void *pA();void *pC();void *pD(); void *pF();
void *pB();void *pE();void *pG();void *pH(); void *pI();

int main(){
  int i,nT=9,cicli=0; void *retval;
  th *td;
  td=(th*)malloc(nT*sizeof(th));
  sem_init(&semA,0,1);
  sem_init(&semB,0,0);
  sem_init(&semC,0,0);
  sem_init(&semD,0,0);
  sem_init(&semE,0,0);
  sem_init(&semF,0,0);
  sem_init(&semG,0,0);
  sem_init(&semH,0,0);
  sem_init(&semI,0,0);
  printf("Ciclo: %d\n",cicli+1 );
  for(i=0;i<nT;i++){
    td[i].id=i;
    td[i].nome=i+'A';
    printf("Thread %c creato.\n",td[i].nome);
    switch(td[i].nome){
      case 'A': pthread_create(&(td[i].threadid),NULL,pA,(void*) &td[i]);break;
      case 'B': pthread_create(&(td[i].threadid),NULL,pB,(void*) &td[i]);break;
      case 'C': pthread_create(&(td[i].threadid),NULL,pC,(void*) &td[i]);break;
      case 'D': pthread_create(&(td[i].threadid),NULL,pD,(void*) &td[i]);break;
      case 'E': pthread_create(&(td[i].threadid),NULL,pE,(void*) &td[i]);break;
      case 'F': pthread_create(&(td[i].threadid),NULL,pF,(void*) &td[i]);break;
      case 'G': pthread_create(&(td[i].threadid),NULL,pG,(void*) &td[i]);break;
      case 'H': pthread_create(&(td[i].threadid),NULL,pH,(void*) &td[i]);break;
      case 'I': pthread_create(&(td[i].threadid),NULL,pI,(void*) &td[i]);break;
                }
    }
  for(i=0;i<nT;i++){
    pthread_join(td[i].threadid,&retval);
  }
  sem_destroy(&semA);
  sem_destroy(&semB);
  sem_destroy(&semC);
  sem_destroy(&semD);
  sem_destroy(&semE);
  sem_destroy(&semF);
  sem_destroy(&semG);
  sem_destroy(&semH);
  sem_destroy(&semI);
  free(td);
  return 0;
}

void *pA(void *arg){
  th *td; int n=1;
  td=(th*) arg;
  while(1){
    sem_wait(&semA);
    printf("Ciclo %d\n", n++);
    printf("%c %d\n",td->nome,(int)td->threadid);
    sem_post(&semB);
    sem_post(&semC);
    sem_post(&semD);
    sleep(1);
  }
  pthread_exit((void*)1);
}
void *pB(void *arg){
  th *td;
  td=(th*) arg;
  while(1){
    sem_wait(&semB);
    printf("%c %d\n",td->nome,(int)td->threadid);
    sem_post(&semI);
    sleep(1);
  }
  pthread_exit((void*)1);
}
void *pD(void *arg){
  th *td=(th*)arg;
  while(1){
    sem_wait(&semD);
    printf("%c %d\n",td->nome,(int)td->threadid);
    sem_post(&semH);
    sleep(1);
  }
  pthread_exit((void*)1);
}
void *pH(void *arg){
  th *td=(th*)arg;
  while(1){
    sem_wait(&semH);
    printf("%c %d\n",td->nome,(int)td->threadid);
    sem_post(&semI);
    sleep(1);
  }
  pthread_exit((void*)1);
}
void *pC(void *arg){
  th *td=(th*)arg;
  while(1){
    sem_wait(&semC);
    printf("%c %d\n",td->nome,(int)td->threadid);
    sem_post(&semE);
    sem_post(&semF);
    sleep(1);
  }
  pthread_exit((void*)1);
}
void *pE(void *arg){
  th *td=(th*)arg;
  while(1){
    sem_wait(&semE);
    printf("%c %d\n",td->nome,(int)td->threadid);
    sem_post(&semG);
    sleep(1);
  }
  pthread_exit((void*)1);
}
void *pF(void *arg){
  th *td=(th*)arg;
  while(1){
    sem_wait(&semF);
    printf("%c %d\n",td->nome,(int)td->threadid);
    sem_post(&semG);
    sleep(1);
  }
  pthread_exit((void*)1);
}
void *pG(void *arg){
  th *td=(th*)arg;
  while(1){
    sem_wait(&semG);
    sem_wait(&semG);
    printf("%c %d\n",td->nome,(int)td->threadid);
    sem_post(&semI);
    sleep(1);
  }
  pthread_exit((void*)1);
}
void *pI(void *arg){
  th *td;
  td=(th*) arg;
  while(1){
    sem_wait(&semI);
    sem_wait(&semI);
    sem_wait(&semI);
    printf("%c %d\n",td->nome,(int)td->threadid);
    sem_post(&semA);
    sleep(1);
  }
  pthread_exit((void*)1);
}
