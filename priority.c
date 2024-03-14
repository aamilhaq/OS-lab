#include <stdio.h>

struct Process {
    int AT;
    int BT;
    int pri;
    int CT;
    int WT;
    int TT;
    int processed;
};

void calculateTimes(struct Process p[], int n) {
    int totalWT = 0;
    int totalTT = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].pri > p[j + 1].pri) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int CurT = 0;
    for (int i = 0; i < n; i++) {
        CurT += p[i].BT;
        p[i].CT = CurT;
        p[i].TT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TT - p[i].BT;
        totalWT += p[i].WT;
        totalTT += p[i].TT;
    }

    float avg_WT = (float)totalWT / n;
    float avg_TT = (float)totalTT / n;

    printf("Average Waiting Time: %.2f\n", avg_WT);
    printf("Average Turnaround Time: %.2f\n", avg_TT);
}

void main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    printf("Enter arrival time, burst time, and pri for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].AT);
        printf("Burst Time: ");
        scanf("%d", &p[i].BT);
        printf("priority: ");
        scanf("%d", &p[i].pri);
    }

    calculateTimes(p, n);
}


