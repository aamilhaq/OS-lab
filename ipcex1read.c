#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main(){
key_t key=2018;
int shmid = shmget(key,3*sizeof(int),0666|IPC_CREAT);
int *array=(int*)shmat(shmid,(void*)0,0);

    int comb;
	
    comb=(array[0])/(( array[1])*( array[2]));
    printf("The value of combination is %d\n", comb);
    shmdt(array);
    shmctl(shmid, IPC_RMID, NULL);
 }

