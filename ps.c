#include<stdio.h>

struct process {
    char name[5];
    int BT, AT, priority, WT, TOT;
}p[20], temp;

int main() {
    int n, i;
    float totalTOT = 0, totalWait = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter the process name: ");
        scanf("%s", &p[i].name);
        printf("Burst Time: ");
        scanf("%d", &p[i].BT);
        printf("Arival Time: ");
        scanf("%d", &p[i].AT);
        printf("Enter priority(lower value means higher priority): ");
        scanf("%d", &p[i].priority);

        p[i].WT = 0;
        p[i].TOT = 0;
    }

    for(i = 0; i < n-1; i++) {
        for (int j = i; j < n; j++) {
            if(p[j].AT < p[i].AT || (p[j]).AT == p[i].AT && p[j].priority < p[i].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    } 

    int time = 0;
    printf("\n---- GANTT CHART ----\n");
    printf("0 | ");

    // Priority scheduling Logic
    for(i = 0; i < n; i++) {
        if(time < p[i].AT) {
            time = p[i].AT;
        }

        p[i].WT = time - p[i].AT;
        p[i].TOT = p[i].WT + p[i].BT;
        totalWait += p[i].WT;
        totalTOT += p[i].TOT;

        time += p[i].BT;
        printf("%d %s | ", time, p[i].name);
    }

    float avwait = totalWait /n;
    float avtot = totalTOT / n;

    printf("\nPname\tAT\tBT\tPriority\tWT\tTOT\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i].name, p[i].AT, p[i].BT, p[i].priority, p[i].WT, p[i].TOT);
    }   

    printf("Average Waiting Time: %.2f\n", avwait);
    printf("Average turnarount time: %.2f\n", avtot);
    
    return 0;
}