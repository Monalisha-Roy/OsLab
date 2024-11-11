#include<stdio.h>

struct process {
    int id, ser, wait, tot;
}p[20], temp;

void main() {
    int n, i, j, t_wait = 0, t_tot = 0;
    float avwait, avturn;

    printf("Enter the no. of process: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter PID: ");
        scanf("%d", &p[i].id);
        printf("Enter Service time");
        scanf("%d", &p[i].ser);
    }

    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(p[i].ser > p[j].ser) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    p[0].wait = 0;
    p[0].tot = p[0].ser;

    for(i = 1; i < n; i++) {
        p[i].wait = p[i-1].wait + p[i-1].ser;
        t_wait += p[i].wait;
        p[i].tot = p[i].wait + p[i].ser;
        t_tot += p[i].tot;
    }

    t_tot += p[0].tot;

    printf("PID\tSER\tWAIT\tTOT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].ser, p[i].wait, p[i].tot);
    }

    avturn = (float)t_tot/n;
    avwait = (float)t_wait/n;

    printf("Gantt Chart\n");
    printf("|");
    for(i = 0; i < n; i++) {
        printf("P%d|", p[i].id);
    }
    printf("\n");

    printf("0    ");
    for(i = 0; i < n; i++) {
        printf("%d    ", p[i].tot);
    }

    printf("\nTotal wait time: %d\n", t_wait);
    printf("Total turnout time: %d\n", t_tot);
    printf("Average wait time: %d2.f\n", avwait);
    printf("Average tot: %d2.f", avturn);
}