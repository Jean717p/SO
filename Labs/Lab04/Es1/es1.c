#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main () {
  char str[100];
  int i;

  setbuf(stdout,0);
  fork();
  for (i=0; i<2; i++){
    if (fork()) {
      printf("(%d)\n",i);
      sprintf (str, "echo system with i=%d", i);
      system (str);
      sleep(1);
    } else {
      sleep(5);
      sprintf (str, "exec with i=%d", i);
      execlp ("echo", "myPgrm", str, NULL);
    }
  }
  sleep(5);
  return (0);
}
