#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include <limits.h>
#include <errno.h>
#include <stdarg.h>

int main(){
	int i;
	for (i=1; i<=2; i++) {
	  if (!fork ())
	    printf ("%d\n", i);
		sleep(1);
	}
	sleep(3);
	printf ("%d\n", i);

	return 0;
}
