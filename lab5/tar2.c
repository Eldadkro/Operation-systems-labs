#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int *numbers;
pthread_t *threads;

void printError(char str[]);
void* randNumber(void* input);

int main(int argc, char* argv[]){

    int i;

    if(argc  != 2)
        printError("invalid input");
    int n = atoi(argv[1]);
    if((numbers = (int*)malloc(sizeof(int)*n)) == NULL)
        printError("couldn't allocate memory");
    if((threads = (pthread_t*)malloc(sizeof(pthread_t)*n)) == NULL)
        printError("couldn't allocate memory");
    srand(time(NULL));

    for(i=0;i<n;i++)
        if(pthread_create(&(threads[i]),NULL,randNumber,(void*)&i) != 0)
            printError("couldn't create thread");
    for(i=0;i<n;i++)
        pthread_join(threads[i],NULL);
    int sum=0;
    for(i=0;i<n;i++)
        sum += numbers[i];
    printf("the numbers are: ");
    for(i=0;i<n;i++)
        printf("%d ",numbers[i]);
    printf("\n");
    printf("the avg is: %.3lf\n",((double)sum)/n);
    return 0;
}

void printError(char str[]){

    perror(str);
    exit(-1);
}

void* randNumber(void* input){

    int i = *((int*)input);
    numbers[i] = rand()%11;
    
}
