#include <unistd.h>



int main(){

    execl("ls","ls",NULL);
    
    return 0;
}