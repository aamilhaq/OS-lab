
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

void main(){
    key_t key = 2818;
    int shmid = shmget(key, 100*sizeof(char), 0666|IPC_CREAT); 
    char *str = (char*)shmat(shmid, (void*)0, 0);
    printf("Enter the string:\n");
    fgets(str, 100, stdin); 
    printf("The string is: %s\n", str);
    
    shmdt(str);
}



