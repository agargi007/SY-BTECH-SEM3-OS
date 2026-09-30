#include <stdio.h>

int main() {
    int n, choice, time = 0;
    int at[20], bt[20], ct[20], tat[20], wt[20];
    float total_tat = 0, total_wt = 0;

    printf("1. Run FCFS\n2. Exit\nEnter choice: ");
    scanf("%d", &choice);
    
    if (choice != 1) return 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        if (time < at[i]) time = at[i];
        
        ct[i] = time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        time = ct[i];

        total_tat += tat[i];
        total_wt += wt[i];

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAvg TAT: %.2f ms", total_tat / n);
    printf("\nAvg WT:  %.2f ms\n", total_wt / n);

    printf("\nGantt Chart:\n0");
    for (int i = 0; i < n; i++) {
        printf(" -> [P%d] -> %d", i + 1, ct[i]);
    }
    printf("\n");

    return 0;
}

/*

gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit OS_exp4a_FCFS.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc OS_exp4a_FCFS.c -o osexp4
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./osexp4
1. Run FCFS
2. Exit
Enter choice: 1
Enter number of processes: 4
Enter Arrival Time and Burst Time for P1: 1
5
Enter Arrival Time and Burst Time for P2: 3
2
Enter Arrival Time and Burst Time for P3: 3
5
Enter Arrival Time and Burst Time for P4: 5
16

PID     AT      BT      CT      TAT     WT
P1      1       5       6       5       0
P2      3       2       8       5       3
P3      3       5       13      10      5
P4      5       16      29      24      8

Avg TAT: 11.00 ms
Avg WT:  4.00 ms

Gantt Chart:
0 -> [P1] -> 6 -> [P2] -> 8 -> [P3] -> 13 -> [P4] -> 29
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$

*/
