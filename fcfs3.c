#include <stdio.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[100], bt[100], ct[100], tat[100], wt[100];
    float sum_tat = 0, sum_wt = 0;
    int time = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);

        if (time < at[i]) {
            time = at[i];
        }

        ct[i] = time + bt[i];
        time = ct[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        sum_tat += tat[i];
        sum_wt += wt[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) {
        printf(" P%d |", i + 1);
    }
    
    printf("\n%d", at[0]);
    for (int i = 0; i < n; i++) {
        printf("    %d", ct[i]);
    }
    printf("\n");

    printf("\nAvg TAT = %.2f", sum_tat / n);
    printf("\nAvg WT = %.2f\n", sum_wt / n);

    return 0;
}
