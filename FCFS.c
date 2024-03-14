#include<stdio.h>

struct FCFS{
	char name[2];
	int AT,BT;
	};

void main(){

	struct FCFS pr[10],temp;
	int n,i,j,WT,TT,CT=0,totalWT=0,totalTT=0;
	float avgWT,avgTT;

	printf("Enter the number of processes\n");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		printf("Enter the Name,Burst time and Arrival time of process%d\n",i+1);
		scanf("%s%d%d",pr[i].name,&pr[i].BT,&pr[i].AT);
		}	

	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(pr[j].AT>pr[j+1].AT){

				temp=pr[j];
				pr[j]=pr[j+1];
				pr[j+1]=temp;
				}
			}
		}
	for(i=0;i<n;i++){
		if(pr[i].AT>CT){
			CT=pr[i].AT;
		}
	WT=CT-pr[i].AT;
	totalWT+=WT;
	CT+=pr[i].BT;
	TT=pr[i].BT+WT;
	totalTT+=TT;
}
	avgWT=(float)(totalWT)/(float)(n);
	printf("Average Waiting Time = %f\n",avgWT);
	avgTT=(float)(totalTT)/(float)(n);
	printf("Average TurnAround Time = %f\n",avgTT);
}
