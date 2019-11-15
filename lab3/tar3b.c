#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

//function to handle error prints
void printErr(char str[]){
    perror(str);
    exit(-1);
}


void nextChildRec(int i, int N){
    if(i == N)
        exit(0);
    int pid  = (int)fork();
    if(pid == 0){
        printf("I am a child!! : child number %d | my pid = %d | my parents pid = %d \n",i,getpid(),getppid());
        nextChildRec(++i,N);
    }
    int a = 0; 
    //the wait is there so the parent will not die and the child will not be adopted by OS
    wait(&a);
    exit(0);
}

void nextChild(int N){
    nextChildRec(0,N);
}

int main(int argc,char* argv[]){
    
     //input check 
    if(argc < 2)
        printErr("invalid input");
    int N = atoi(argv[1]);
    printf("I am parent! pid = %d\n",(int)getpid());
    nextChild(N);
    return 0;
}