#include <sys/stat.h>
#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

void main() {

 struct stat sfile;
 stat("even.txt", &sfile);

 printf("Inode Number = %ld\n", sfile.st_ino);
 printf("Size = %ld\n", (long)sfile.st_size);

}

