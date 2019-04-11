#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
	int i;
	for (i=0; i<2; i++) {
	  if (fork ())
	    fork ();
		sleep(1);
	}
	sleep(3);
	printf ("%d\n", i);
 	return 0;
}
