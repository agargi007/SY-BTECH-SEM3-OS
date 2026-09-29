#include <stdio.h>

int main() {
    int n;
    float total_wt = 0, total_tat = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int bt[n], wt[n], tat[n];
    
    for(int i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    
    wt[0] = 0;
    for(int i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }
    
    printf("\nProcess\tBurst\tWait\tTurnaround\n");
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    }
    
    printf("\nAvg Wait: %.2f", total_wt / n);
    printf("\nAvg Turnaround: %.2f\n", total_tat / n);
    
    return 0;
}

/*

gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit FCFS.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc FCFS.c -o fcfs
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./fcfs
Enter number of processes: 5
Enter burst time for P1: 12
Enter burst time for P2: 6
Enter burst time for P3: 2
Enter burst time for P4: 5
Enter burst time for P5: 4

Process Burst   Wait    Turnaround
P1      12      0       12
P2      6       12      18
P3      2       18      20
P4      5       20      25
P5      4       25      29

Avg Wait: 15.00
Avg Turnaround: 20.80
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$

*/
