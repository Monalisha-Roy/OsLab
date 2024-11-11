#include<stdio.h>
#include<string.h>

struct process {
    char pname[5];
    int arrivalT, burstT, remainingT, turnarountT, waitingT;
}p[20];

void main() {
    int n, i, tq, time = 0, completedProcesses = 0;
    float t_wait = 0, t_tot = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter process name: ");
        scanf("%s", &p[i].pname);
        printf("Arrival time: ");
        scanf("%d", &p[i].arrivalT);
        printf("Burst Time: ");
        scanf("%d", &p[i].burstT);

        p[i].remainingT = p[i].burstT;
        p[i].waitingT = 0;
        p[i].turnarountT = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &tq);

    printf("\n---- GANTT CHART ----\n");
    printf("0 | ");

    while (completedProcesses < n) {
        int allProcessesChecked = 1;

        for (i = 0; i < n; i++) {
            if (p[i].remainingT > 0 && p[i].arrivalT <= time) {
                allProcessesChecked = 0;

                if(p[i].remainingT > tq) {
                    time += tq;
                    p[i].remainingT -= tq;
                } else {
                    time += p[i].remainingT;
                    p[i].remainingT = 0;
                    p[i].turnarountT = time - p[i].arrivalT;
                    p[i].waitingT = p[i].turnarountT - p[i].burstT;
                    t_tot += p[i].turnarountT;
                    t_wait += p[i].waitingT;
                    completedProcesses++;
                }
                printf("%d %s | ", time, p[i].pname);
            }
        }
        if (allProcessesChecked) {
            time++;
        }
    }

    printf("\n");

    float avwait = t_wait / n;
    float avtot = t_tot / n;

    printf("\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", p[i].pname, p[i].arrivalT, p[i].burstT, p[i].waitingT, p[i].turnarountT);
    }

    printf("Average waiting time: %.2f\n", avwait);
    printf("Average turnaround time: %.2f\n", avtot);
}