#include <stdio.h>

int main() {
    int n, time = 0, done = 0, p, wait, turn;
    float sum_w = 0, sum_t = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    int at[n], bt[n], rt[n];
    
    for(int i = 0; i < n; i++) {
        printf("Enter AT and BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    
    printf("\nProcess\tWait\tTurnaround\n");
    
    while(done < n) {
        p = -1;
        
        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && (p == -1 || rt[i] < rt[p])) {
                p = i;
            }
        }
        
        time++;
        
        if(p != -1) {
            rt[p]--;
            
            if(rt[p] == 0) {
                done++;
                turn = time - at[p];
                wait = turn - bt[p];
                sum_w += wait;
                sum_t += turn;
                printf("P%d\t%d\t%d\n", p + 1, wait, turn);
            }
        }
    }
    
    printf("\nAvg Wait: %.2f\nAvg Turn: %.2f\n", sum_w / n, sum_t / n);
    
    return 0;
}

/*
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gedit SRTF.c
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ gcc SRTF.c -o srtf
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$ ./srtf
Enter number of processes: 4
Enter AT and BT for P1: 12 3
Enter AT and BT for P2: 0 4
Enter AT and BT for P3: 6 8
Enter AT and BT for P4: 7 12

Process Wait    Turnaround
P2      0       4
P3      0       8
P1      2       5
P4      10      22

Avg Wait: 3.00
Avg Turn: 9.75
gargi_007@LAPTOP-113399:/mnt/e/SY-BTECH-SEM3/Programming$
*/
