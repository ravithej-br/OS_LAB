#include <stdio.h>

int main() {

    int n, m, i, j, k;
    printf("\n---Deadlock Detection algorithm--- \n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int allocation[n][m];
    int request[n][m];
    int available[m];

    // Allocation Matrix
    printf("\nEnter the allocation matrix:\n");

    for(i = 0; i < n; i++) {

        printf("Process %d: ", i);

        for(j = 0; j < m; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Request Matrix
    printf("\nEnter the request matrix:\n");

    for(i = 0; i < n; i++) {

        printf("Process %d: ", i);

        for(j = 0; j < m; j++) {
            scanf("%d", &request[i][j]);
        }
    }

    // Available Resources
    printf("\nEnter the available resources: ");

    for(i = 0; i < m; i++) {
        scanf("%d", &available[i]);
    }

    int work[m];
    int finish[n];
    int safeSeq[n];

    // Initialize
    for(i = 0; i < m; i++)
        work[i] = available[i];

    for(i = 0; i < n; i++) {

        int zero = 1;

        for(j = 0; j < m; j++) {

            if(allocation[i][j] != 0) {
                zero = 0;
                break;
            }
        }

        if(zero)
            finish[i] = 1;
        else
            finish[i] = 0;
    }

    int count = 0;

    while(count < n) {

        int found = 0;

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                int possible = 1;

                for(j = 0; j < m; j++) {

                    if(request[i][j] > work[j]) {
                        possible = 0;
                        break;
                    }
                }

                if(possible) {

                    for(k = 0; k < m; k++)
                        work[k] += allocation[i][k];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    int deadlock = 0;

    for(i = 0; i < n; i++) {

        if(finish[i] == 0) {
            deadlock = 1;
            break;
        }
    }

    if(deadlock == 0) {

        printf("\nSystem is in safe state.\n");
        printf("Safe Sequence is: ");

        for(i = 0; i < count; i++) {

            printf("P%d ", safeSeq[i]);
        }

        printf("\n");
    }
    else {

        printf("\nSystem is in deadlock state.\n");
        printf("Deadlocked processes are: ");

        for(i = 0; i < n; i++) {

            if(finish[i] == 0)
                printf("P%d ", i);
        }

        printf("\n");
    }

    return 0;
}