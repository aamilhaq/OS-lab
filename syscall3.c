#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(){

char *args[]={"./syscall2",NULL};
execvp(args[0],args);


printf("this wont execute");

}
