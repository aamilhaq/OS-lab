#include<stdio.h>
#include <unistd.h>

void main(){
int pid;
pid = fork();
if (pid == 0){
printf( "\n Process id : %d " , getpid() );
printf("\n Process id : %d " , getppid());
	}
}
