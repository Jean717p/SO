#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(){
	int i;
	for (i=2; i>=1; i--) {
		sleep(1);
		if (!fork ())
	    printf ("%d\n", -i);
	  else
	    printf ("%d\n", i);
		sleep(1);
	}
	return 0;
}
