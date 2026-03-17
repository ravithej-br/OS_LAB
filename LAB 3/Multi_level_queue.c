#include <stdio.h>

int main() {
    printf("Name:Ravithej B R\nUSN:1BM25CS503\nPRG:MLQ (User RR + System FCFS)\n");

    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], AT[n], BT[n], type[n];
    int CT[n], TAT[n], WT[n], RT[n], remBT[n];
    int completed[n];

    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter AT, BT and Queue No (1-User, 2-System) for P%d: ", i+1);
        scanf("%d %d %d", &AT[i], &BT[i], &type[i]);

        remBT[i] = BT[i];
        completed[i] = 0;
        RT[i] = -1;
    }

    printf("Enter Time Quantum (for User Queue): ");
    scanf("%d", &tq);

    int current_time = 0, done = 0;

    while(done < n) {

        int executed = 0;

        // 🔴 USER QUEUE (RR - Highest Priority)
        for(int i = 0; i < n; i++) {
            if(type[i] == 1 && AT[i] <= current_time && remBT[i] > 0) {

                if(RT[i] == -1)
                    RT[i] = current_time - AT[i];

                if(remBT[i] > tq) {
                    current_time += tq;
                    remBT[i] -= tq;
                } else {
                    current_time += remBT[i];
                    remBT[i] = 0;

                    CT[i] = current_time;
                    TAT[i] = CT[i] - AT[i];
                    WT[i] = TAT[i] - BT[i];

                    completed[i] = 1;
                    done++;
                }

                executed = 1;
            }
        }

        // 🔵 SYSTEM QUEUE (FCFS - Lower Priority)
        if(executed == 0) {
            for(int i = 0; i < n; i++) {
                if(type[i] == 2 && AT[i] <= current_time && remBT[i] > 0) {

                    if(RT[i] == -1)
                        RT[i] = current_time - AT[i];

                    current_time += remBT[i];
                    remBT[i] = 0;

                    CT[i] = current_time;
                    TAT[i] = CT[i] - AT[i];
                    WT[i] = TAT[i] - BT[i];

                    completed[i] = 1;
                    done++;

                    executed = 1;
                    break; // FCFS → one at a time
                }
            }
        }

        // ⏩ If CPU idle → move time forward
        if(executed == 0)
            current_time++;
    }

    float avgTAT = 0, avgWT = 0;

    printf("\n%-5s %-10s %-10s %-10s %-15s %-15s %-12s %-12s\n",
           "P","AT","BT","Queue","CT","TAT","WT","RT");

    for(int i = 0; i < n; i++) {
        printf("P%-4d %-10d %-10d %-10s %-15d %-15d %-12d %-12d\n",
               pid[i], AT[i], BT[i],
               (type[i]==1?"User":"System"),
               CT[i], TAT[i], WT[i], RT[i]);

        avgTAT += TAT[i];
        avgWT += WT[i];
    }

    printf("\nAverage Turnaround Time = %.2f", avgTAT/n);
    printf("\nAverage Waiting Time = %.2f\n", avgWT/n);

    return 0;
}