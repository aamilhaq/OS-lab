#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

void main(){

key_t key = ftok("file",69);

int shmid = shmget(key, 1024, 0666|IPC_CREAT);

char *str = (char*) shmat(shmid,(void*)0,0);


printf("Enter data:\n");
gets(str);
printf("Data written in shared memory: %s\n",str);


shmdt(str);
}
