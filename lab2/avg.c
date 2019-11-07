#include <stdio.h>
#include <stdlib.h>


int main(int argc,char* argv[]){
    int sum=0;
    int i;
    if(argc == 1){						//in case you didn't have args
	    perror("incomplete line !");
	    exit(1);						//free all with error
    }
    for(i = 1;i<argc;i++){
	    sum += atoi(argv[i]);				//takes string to int
    }
    printf("the avg is : %lf.1\n",((double)sum)/(argc-1));	//%lf for double
    return 0;
}
