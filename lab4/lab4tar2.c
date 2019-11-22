#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <wait.h>

int main(){

    int tmp;
    char buffer[100];
    char bin[] = "/bin/";
    char comm[200] = "";
    printf("$");
    scanf("%s",&buffer); 
    while(strcmp(buffer,"exit")){
        
        int pid =(int)fork();
        if(pid == 0){
            strcpy(comm,bin);
            strcat(comm,buffer);
            execl(comm,buffer,NULL);
            printf("ERROR ERROR ERROR\n");    
        }
        wait(&tmp);
        printf("$");
        scanf("%s",&buffer);
    }

    
    return 0;
}