#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <string.h>
#include <ctype.h>
#include <sys/shm.h>

#define SHM_SIZE 100

void main(){
    key_t key = 2818;
    int shmid = shmget(key, SHM_SIZE*sizeof(char), 0666|IPC_CREAT);
    char *str = (char*)shmat(shmid, (void*)0, 0);
    
    int vcount = 0;
    int count = 0;
    int ncount = 0;
    
    for(int i = 0; str[i] != '\0'; i++){
 if(isdigit(str[i])){
            ncount++;
        }
       
         else if(((str[i]) >= 'a' && (str[i]) <= 'z')||((str[i]) >= 'A' && (str[i]) <= 'Z')){
                if((str[i]) == 'a' || (str[i]) == 'e' || (str[i]) == 'i' || (str[i]) == 'o' || (str[i]) == 'u' ||(str[i]) == 'A' ||(str[i]) == 'E' || (str[i]) == 'I' || (str[i]) == 'O' || (str[i]) == 'U'){
                    vcount++;
                }
        }

        else{
            count++;
        }
    
}
    
    printf("Number of vowels: %d\n", vcount);
    printf("Number of symbols: %d\n", count);
    printf("Number of numbers: %d\n", ncount);
    
    shmdt(str);
}


