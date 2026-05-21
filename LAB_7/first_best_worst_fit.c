#include <stdio.h>

#define MAX 100

void firstFit(int blockSize[], int originalBlock[], int blocks,
              int processSize[], int processes) {

    int allocation[MAX];

    for(int i = 0; i < processes; i++) {
        allocation[i] = -1;
    }

    for(int i = 0; i < processes; i++) {

        for(int j = 0; j < blocks; j++) {

            if(blockSize[j] >= processSize[i]) {

                allocation[i] = j;

                // Remaining memory reused
                blockSize[j] -= processSize[i];

                break;
            }
        }
    }

    printf("\n     ---------- FIRST FIT ----------\n");

    printf("Process No\tProcess Size\tBlock No\tBlock Size\n");

    for(int i = 0; i < processes; i++) {

        printf("%d\t\t%d\t\t",
               i + 1, processSize[i]);

        if(allocation[i] != -1) {

            printf("%d\t\t%d\n",
                   allocation[i] + 1,
                   originalBlock[allocation[i]]);
        }
        else {

            printf("Not Allocated\n");
        }
    }
}

void bestFit(int blockSize[], int originalBlock[], int blocks,
             int processSize[], int processes) {

    int allocation[MAX];

    for(int i = 0; i < processes; i++) {
        allocation[i] = -1;
    }

    for(int i = 0; i < processes; i++) {

        int bestIdx = -1;

        for(int j = 0; j < blocks; j++) {

            if(blockSize[j] >= processSize[i]) {

                if(bestIdx == -1 ||
                   blockSize[j] < blockSize[bestIdx]) {

                    bestIdx = j;
                }
            }
        }

        if(bestIdx != -1) {

            allocation[i] = bestIdx;

            // Remaining memory reused
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\n     ---------- BEST FIT ----------\n");

    printf("Process No\tProcess Size\tBlock No\tBlock Size\n");

    for(int i = 0; i < processes; i++) {

        printf("%d\t\t%d\t\t",
               i + 1, processSize[i]);

        if(allocation[i] != -1) {

            printf("%d\t\t%d\n",
                   allocation[i] + 1,
                   originalBlock[allocation[i]]);
        }
        else {

            printf("Not Allocated\n");
        }
    }
}

void worstFit(int blockSize[], int originalBlock[], int blocks,
              int processSize[], int processes) {

    int allocation[MAX];

    for(int i = 0; i < processes; i++) {
        allocation[i] = -1;
    }

    for(int i = 0; i < processes; i++) {

        int worstIdx = -1;

        for(int j = 0; j < blocks; j++) {

            if(blockSize[j] >= processSize[i]) {

                if(worstIdx == -1 ||
                   blockSize[j] > blockSize[worstIdx]) {

                    worstIdx = j;
                }
            }
        }

        if(worstIdx != -1) {

            allocation[i] = worstIdx;

            // Remaining memory reused
            blockSize[worstIdx] -= processSize[i];
        }
    }

    printf("\n     ---------- WORST FIT ----------  \n");

    printf("Process No\tProcess Size\tBlock No\tBlock Size\n");

    for(int i = 0; i < processes; i++) {

        printf("%d\t\t%d\t\t",
               i + 1, processSize[i]);

        if(allocation[i] != -1) {

            printf("%d\t\t%d\n",
                   allocation[i] + 1,
                   originalBlock[allocation[i]]);
        }
        else {

            printf("Not Allocated\n");
        }
    }
}

int main() {

    int blocks, processes;

    int blockSize1[MAX], blockSize2[MAX], blockSize3[MAX];
    int originalBlock[MAX];
    int processSize[MAX];

    printf("Enter number of memory blocks: ");
    scanf("%d", &blocks);

    if(blocks <= 0 || blocks > MAX) {
        printf("Invalid number of blocks!\n");
        return 0;
    }

    printf("Enter sizes of memory blocks:\n");

    for(int i = 0; i < blocks; i++) {

        scanf("%d", &blockSize1[i]);

        if(blockSize1[i] <= 0) {
            printf("Invalid block size!\n");
            return 0;
        }

        originalBlock[i] = blockSize1[i];

        blockSize2[i] = blockSize1[i];
        blockSize3[i] = blockSize1[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &processes);

    if(processes <= 0 || processes > MAX) {
        printf("Invalid number of processes!\n");
        return 0;
    }

    printf("Enter sizes of processes:\n");

    for(int i = 0; i < processes; i++) {

        scanf("%d", &processSize[i]);

        if(processSize[i] <= 0) {
            printf("Invalid process size!\n");
            return 0;
        }
    }

    firstFit(blockSize1, originalBlock, blocks,
             processSize, processes);

    bestFit(blockSize2, originalBlock, blocks,
            processSize, processes);

    worstFit(blockSize3, originalBlock, blocks,
             processSize, processes);

    return 0;
}