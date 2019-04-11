#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (int argc, char const * argv[]){
  char a;
  // FILE *fin, *fout;
  int fin, fout;
  fin=open(argv[1], O_RDONLY);
  fout=open(argv[2], O_WRONLY);
  if(fin==-1 || fout==-1){
    printf("Errore apertura di un file\n");
    return -1;
  }
  while(read(fin, &a, 1)==1) write(fout, &a, 1);
  return 0;
}
