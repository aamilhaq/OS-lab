#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void main(){
key_t key=2018;
int shmid = shmget(key,3*sizeof(int),0666|IPC_CREAT);
int *array=(int*)shmat(shmid,(void*)0,0);


int n,r;
printf("Enter the value of n and r:\n");
scanf("%d%d",&n,&r);
int y=n-r;
int i,fact=1;
for(i=1;i<=n;i++){
	fact=fact*i;
}
array[0]=fact;

int j,fact2=1;
for(j=1;j<=r;j++){
	fact2=fact2*j;
}
array[1]=fact2;


int k,fact3=1;


for(k=1;k<=y;k++){
	fact3=fact3*k;
}
array[2]=fact3;

 	printf("Factorial of n: %d\n", fact);
        printf("Factorial of r: %d\n", fact2);
        printf("Factorial of n-r: %d\n", fact3);

printf("Factorial of n: %d\n", array[0]);
        printf("Factorial of r: %d\n",array[1] );
        printf("Factorial of n-r: %d\n",array[2] );


shmdt(array);
}




