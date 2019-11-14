#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h> 

void printErr(char str[]){
    perror(str);
    exit(1);
}

//return 0 if great , return -1 in failed 
int writeWord(int from , int to){
    int nRead,nWrite;
    char buff, space = ' ';
    while((nRead = read(from,&buff,1)) != 0){
        // not mendatory just for show
        if(buff == ' ' || buff == '\n'){
            if((nWrite = write(to,&space,1)) == -1) printErr("invalid write");
            printf("%c",space);
            break;
        }
        if((nWrite = write(to,&buff,1)) == -1) printErr("invalid write");
        printf("%c",buff);
    }
    if(nRead == 0){
        if((nWrite = write(to,&space,1)) == -1) printErr("invalid write");
        printf("%c",space);
        return -1;
    }
    return 0;
}


int main(int argc,char* argv[]){
    int flag1 =0, flag2 =0;
    char buff1,buff2;
    int nRead,nWrite;
    char space = ' ';
    //check arguments 
    if(argc != 4){
        printf("amount of args = %d\n",argc);
        perror("invalid arguments");
        exit(1);
        }

    // get handles to files 
    int fd[4];
    for(int i=1;i<argc;i++)
        if((fd[i] = open(argv[i],O_RDWR)) == -1)
            printErr("bad files! ");

    while((flag1 = writeWord(fd[1],fd[3])) != -1 &&  (flag2 = writeWord(fd[2],fd[3])) != -1);
    if(flag1 == -1)
        while((flag2 = writeWord(fd[2],fd[3])) != -1);
    if(flag2 == -1)
        while((flag1 = writeWord(fd[1],fd[3])) != -1);

    printf("\n");

    // close the files
    for(int i=1;i<argc;i++) 
        close(fd[i]);
    return 0;
}