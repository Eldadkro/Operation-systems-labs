#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <wait.h>
#include <string.h>

void printEr(char str[]){
    perror(str);
    exit(-1);
}

int main(int argc,char* argv[]){
    
    int tmp = 0;
    if (argc == 1){printEr("invalid input");}
    for(int i=1;i<argc;i++){
        int pid = (int)fork();
        
        if(pid == 0){
        execl(argv[i],argv[i],NULL);

        }
        wait(&tmp);
    }
    printf("END\n");
    return 0;
}