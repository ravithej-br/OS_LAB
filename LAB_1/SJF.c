#include <stdio.h>

int main() {
    printf("Name:Ravithej B R\n" "USN:1BM25CS503\n" "PRG:SJF\n");
    int n, i, pos;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int AT[n], BT[n], CT[n], TAT[n], WT[n], RT[n], done[n];
    int current_time = 0, completed = 0;

    float avgTAT=0, avgWT=0;

    for(i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d %d",&AT[i],&BT[i]);
        done[i]=0;
    }

    while(completed < n){
        int minBT = 999;

        for(i=0;i<n;i++){
            if(AT[i] <= current_time && done[i]==0 && BT[i] < minBT){
                minBT = BT[i];
                pos = i;
            }
        }

        if(minBT == 999){
            current_time++;
        }
        else{
            RT[pos] = current_time - AT[pos];

            CT[pos] = current_time + BT[pos];
            TAT[pos] = CT[pos] - AT[pos];
            WT[pos] = TAT[pos] - BT[pos];

            current_time = CT[pos];
            done[pos] = 1;
            completed++;

            avgTAT += TAT[pos];
            avgWT += WT[pos];
        }
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

