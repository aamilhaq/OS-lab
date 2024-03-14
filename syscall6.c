#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void main(){

int fd1 = open("test.txt", O_RDONLY);
if (fd1 < 0) {
printf("Error\n ");
exit(1);
}

printf("opened the fd = %d \n", fd1);
if (close(fd1) < 0) {
printf("Error\n");
exit(1);
}

printf("closed the fd.\n");

}
















