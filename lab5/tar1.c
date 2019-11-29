#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>

char strG[1000] = "";

void* func1(){

    for(int i=0;i<4;i++){
        printf("%s\n",strG);
        sleep(5);
    }
}


void* func2(void *tmp){

    for(int i=0;i<30;i++){
        strcat(strG,((char*)tmp));
        sleep(1);
    }
}

void* func3(){

    for(int i=0;i<10;i++){
        strcpy(strG,"X");
        sleep(7);
    }
}

int main(){

    pthread_t tid[3];

    strcpy(strG,"ab");
    int a1,a2,a3;
    a1 = pthread_create(&tid[0],NULL,func1,NULL);
    a2 = pthread_create(&tid[1],NULL,func2,"cd");
    a3 = pthread_create(&tid[2],NULL,func3,NULL);
    if(a1 != 0 || a2 != 0 || a3 != 0){
        printf("couldn't create threads %d %d %d\n",a1,a2,a3);
        exit(0);
    }
    pthread_join(tid[0],NULL);
    pthread_join(tid[1],NULL);
    pthread_join(tid[2],NULL);
    return 0;
}
