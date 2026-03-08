#include <stdio.h>

int main() {
    printf("Name:Ravithej B R\n" "USN:1BM25CS503\n" "PRG:FCFS\n");
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int AT[n], BT[n], CT[n], TAT[n], WT[n], RT[n];
    int current_time = 0;

    float avgTAT = 0, avgWT = 0;

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i+1);
        scanf("%d %d", &AT[i], &BT[i]);
    }

    for(i = 0; i < n; i++) {
        if(current_time < AT[i])
            current_time = AT[i];

        RT[i] = current_time - AT[i];

        CT[i] = current_time + BT[i];
        TAT[i] = CT[i] - AT[i];
        WT[i] = TAT[i] - BT[i];

        current_time = CT[i];

        avgTAT += TAT[i];
        avgWT += WT[i];
    }

   printf("\n%-5s %-12s %-10s %-15s %-15s %-12s %-12s\n",
    "P","ArrivalTime","BurstTime","CompletionTime","TurnAroundTime","WaitingTime","ResponseTime");

    for(i=0;i<n;i++)
        printf("%-5d %-12d %-10d %-15d %-15d %-12d %-12d\n",
        i+1, AT[i], BT[i], CT[i], TAT[i], WT[i], RT[i]);

 
    printf("\nAverage TurnAroundTime = %.2f",avgTAT/n);
    printf("\nAverage WaitingTime = %.2f",avgWT/n);
 

    return 0;
}

