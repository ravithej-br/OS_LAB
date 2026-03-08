#include <stdio.h>

int main() {
    printf("Name:Ravithej B R\n" "USN:1BM25CS503\n""PRG:SRTF\n");
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int AT[n], BT[n], RT[n], CT[n], TAT[n], WT[n], start[n];
    int i, time = 0, completed = 0, min, pos;

    float avgTAT=0, avgWT=0;

    for(i=0;i<n;i++){
        printf("Enter AT and BT for P%d: ",i+1);
        scanf("%d %d",&AT[i],&BT[i]);

        RT[i] = BT[i];
        start[i] = -1;
    }

    while(completed < n){
        min = 999;

        for(i=0;i<n;i++){
            if(AT[i] <= time && RT[i] > 0 && RT[i] < min){
                min = RT[i];
                pos = i;
            }
        }

        if(min == 999){
            time++;
        }
        else{
            if(start[pos] == -1)
                start[pos] = time;

            RT[pos]--;
            time++;

            if(RT[pos] == 0){
                completed++;
                CT[pos] = time;
                TAT[pos] = CT[pos] - AT[pos];
                WT[pos] = TAT[pos] - BT[pos];

                avgTAT += TAT[pos];
                avgWT += WT[pos];
            }
        }
    }

    printf("\n%-5s %-12s %-10s %-15s %-15s %-12s %-12s\n",
    "P","ArrivalTime","BurstTime","CompletionTime","TurnAroundTime","WaitingTime","ResponseTime");

    for(i=0;i<n;i++)
        printf("%-5d %-12d %-10d %-15d %-15d %-12d %-12d\n",
        i+1, AT[i], BT[i], CT[i], TAT[i], WT[i], start[i]-AT[i]);

    printf("\nAverage TurnAroundTime = %.2f",avgTAT/n);
    printf("\nAverage WaitingTime = %.2f",avgWT/n);

    return 0;
}

