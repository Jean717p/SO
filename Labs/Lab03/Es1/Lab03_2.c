#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
	int i;
	for(i=3; i>1; i--) {
	  if (fork ())
	    printf ("%d\n", i);
		sleep(1);
	}
	sleep(3);
	printf ("%d\n", i);
	return 0;
}
