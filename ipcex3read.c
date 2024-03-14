#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

void main(){
	key_t key = 1000;
	int shmid = shmget(key, 1024, 0666|IPC_CREAT);
	int *num = (int*) shmat(shmid,(void*)0,0);
	printf("Data read from the shared memory: %d\t",*num);
	int rev=0,n,rem;
	int i=*num;
	for(n=i;n>0;n=n/10){
		rem=n%10;
		rev=rev*10+rem;
		}
	printf("The reverse of the number is: %d\t\n",rev);
	if(rev==i){
		printf("The number is palindrome\n");
	}
	else{
		printf("The number is not palindrome\n");
	}
	shmctl(shmid, IPC_RMID, NULL);
}

