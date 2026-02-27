#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], ct[n], tat[n], wt[n], completed[n];
    float totalWT = 0, totalTAT = 0;
    int time = 0, count = 0;

    for(int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        completed[i] = 0;
    }

    while(count < n) {
        int min = INT_MAX, index = -1;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && !completed[i] && bt[i] < min) {
                min = bt[i];
                index = i;
            }
        }

        if(index != -1) {
            time += bt[index];
            ct[index] = time;
            tat[index] = ct[index] - at[index];
            wt[index] = tat[index] - bt[index];
            completed[index] = 1;
            count++;

            totalWT += wt[index];
            totalTAT += tat[index];
        } else {
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time = %.2f", totalWT/n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT/n);

    return 0;
}
