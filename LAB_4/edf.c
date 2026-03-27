#include <stdio.h>

int main() {
    printf("Name:Ravithej B R\n" "USN:1BM25CS503\n" "PRG:Earliest Deadline first (EDF) Algorithm\n");
    int n, i;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    int bt[n], dl[n], p[n];
    int rem[n], abs_dl[n];

    printf("Enter Burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem[i] = 0;
    }

    printf("Enter Deadlines:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &dl[i]);
    }

    printf("Enter Periods:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // Initialize absolute deadlines
    for (i = 0; i < n; i++) {
        abs_dl[i] = dl[i];
    }

    // Total time
    int total_time = p[0];
    for (i = 1; i < n; i++) {
        if (p[i] > total_time)
            total_time = p[i];
    }

    printf("\nScheduling occurs for %d ms\n\n", total_time);

    int prev_idle = 0;

    for (int time = 0; time < total_time; time++) {

        // ✅ Periodic release + update absolute deadline
        for (i = 0; i < n; i++) {
            if (time % p[i] == 0) {
                rem[i] = bt[i];
                abs_dl[i] = time + dl[i];   // 🔥 KEY FIX
            }
        }

        int selected = -1;
        int min_deadline = 9999;

        // Select earliest absolute deadline
        for (i = 0; i < n; i++) {
            if (rem[i] > 0) {
                if (abs_dl[i] < min_deadline) {
                    min_deadline = abs_dl[i];
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            if (!prev_idle) {
                printf("%dms onwards : CPU is idle.\n", time);
                prev_idle = 1;
            }
        } else {
            printf("%dms : Task %d is running.\n", time, selected + 1);
            rem[selected]--;
            prev_idle = 0;
        }
    }

    return 0;
}
