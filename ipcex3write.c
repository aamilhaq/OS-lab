#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
void main()
{
 key_t key = 1000;
 int shmid = shmget(key, 1024, 0666|IPC_CREAT);
 int *num = (int*) shmat(shmid,(void*)0,0);
 printf("Enter the number:");
 scanf("%d",num);
 printf("Data written in shared memory: %d\n",*num);
 shmdt(num);
 
}

