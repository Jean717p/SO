#include <stdio.h>

int main(int argc,char **argv){
    FILE *fp,*fd; char car;
    fp=fopen(argv[1],"r");
    fd=fopen(argv[2],"w");
    while(fscanf(fp,"%c",&car)!=EOF){
	fprintf(fd,"%c",car);
	}
    fclose(fp);
    fclose(fd);
    return 0;
}
	
