#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
//#include <math.h>

int main(int argc,char** argv){
	int i,N,n,t;
	if(argc!=3)
		exit(-1);
	n=atoi(argv[1]);
	t=atoi(argv[2]);
	//N=pow(2,n);
	for(N=1,i=0;i<n;i++)
		N*=2;
	for(i=1;i<=N;i*=2){
		if(!fork()){
			if(!fork()){
					exit(i);
			}
		}
	}
	sleep(t);
	printf("Io termino\n");
	return 0;
}
