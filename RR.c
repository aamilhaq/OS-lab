#include <stdio.h>
#include <stdbool.h>

struct Process {
    int id;
    int AT;
    int BT;
    int RBT;
    int CT;
    int TT;
    int WT;
};

void calculateTimes(struct Process p[], int n, int QT) {
    int CurT = 0;
    int totalWT = 0;
    int totalTT = 0;
    bool done;

    for (int i = 0; i < n; i++) {
        p[i].RBT = p[i].BT;
    }

    do {
        done = true;
        for (int i = 0; i < n; i++) {
            if (p[i].RBT > 0) {
                done = false; 
                if (p[i].RBT <= QT) {
                    CurT += p[i].RBT;
                    p[i].RBT = 0;
                } else {
		    CurT += QT;
                    p[i].RBT -= QT;
                }

                p[i].WT = CurT - p[i].AT - p[i].BT + p[i].RBT;

                if (p[i].RBT == 0) {
                  
                    p[i].CT = CurT;
                    p[i].TT = p[i].CT - p[i].AT;
                    totalWT += p[i].WT;
                    totalTT += p[i].TT;
                }
            }
        }
    } while (!done);

    float avg_WT = (float)totalWT / n;
    float avg_TT = (float)totalTT / n;

    printf("Average Waiting Time: %.2f\n", avg_WT);
    printf("Average Turnaround Time: %.2f\n", avg_TT);
}

int main() {
    int n, QT;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &QT);

    struct Process p[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d:\n", i + 1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].AT);
        printf("Burst Time: ");
        scanf("%d", &p[i].BT);
        p[i].id = i + 1;
    }

    calculateTimes(p, n, QT);

}
