#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

//function to handle error prints
void printErr(char str[]){
    perror(str);
    exit(-1);
}

int main(int argc,char* argv[]){

    //input check 
    if(argc < 2)
        printErr("invalid input");
    int N = atoi(argv[1]);

    printf("I am parent! pid = %d\n",(int)getpid());
    for(int i=0;i<N;i++){
        int pid = (int)fork();
        if(pid == 0){
            printf("I am a child!! : child number %d | my pid = %d | my parents pid = %d \n",i,getpid(),getppid());
            exit(0);
        }
        int a;
        wait(&a);
    }


    
    return 0;
}