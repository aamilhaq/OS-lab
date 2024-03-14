#include <stdio.h>

struct Process {
    int AT;
    int BT;
    int CT;
    int WT;
    int TT;
};

void calculateTimes(struct Process p[], int n) {
    int totalWT = 0;
    int totalTT = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].BT > p[j + 1].BT) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    p[0].CT = p[0].BT;
    p[0].TT = p[0].BT;
    p[0].WT = 0;
    totalWT = 0;
    totalTT = p[0].TT;
    for (int i = 1; i < n; i++) {
        p[i].CT = p[i - 1].CT + p[i].BT;
        p[i].TT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TT - p[i].BT;
        totalWT += p[i].WT;
        totalTT += p[i].TT;
    }

    float avgWT = (float)totalWT / n;
    float avgTT = (float)totalTT / n;

    printf("Average Waiting Time: %.2f\n", avgWT);
    printf("Average Turnaround Time: %.2f\n", avgTT);
}

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].AT);
        printf("Burst Time: ");
        scanf("%d", &p[i].BT);
    }

    calculateTimes(p, n);

    
}

