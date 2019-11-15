#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>


void printErr(char str[]){
    perror(str);
    exit(1);
}


int main(int argc,char* argv[]){

    int f;
    //check input 
    if(argc < 3)
        printErr("invalid input ");
    if(mkdir(argv[2],S_IRWXU) == -1) printErr("unable to make dir");
    if(chdir(argv[2]) == -1) printErr("unable to move dir");
    if((f=open(argv[1],O_CREAT,664)) == -1) printErr("UNABLE TO MAKE FILE ");

    
    close(f);
    return 0;

}