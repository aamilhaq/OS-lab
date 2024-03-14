#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>

void main()

{ DIR *dirp;

struct dirent *dp;
if((dirp=opendir("/home/s4csb/aamil"))==NULL) 
{printf("\n cannot open");
exit(1); }

for(dp=readdir(dirp); dp!=NULL; dp=readdir(dirp))
{
if(dp->d_type==DT_REG) 
printf("%s\n",dp->d_name);
}

closedir(dirp);

}
