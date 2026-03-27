#include <stdio.h>
#include <math.h>

// GCD
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    printf("Name:Ravithej B R\n" "USN:1BM25CS503\n" "PRG:Rate monotonic scheduling (RMS) Algorithm\n");
    int n, i;

    printf("Enter the number of processes:");
    scanf("%d", &n);

    int bt[n], p[n];

    printf("Enter the CPU burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }

    printf("Enter the time periods:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // LCM
    int hyper = p[0];
    for (i = 1; i < n; i++) {
        hyper = lcm(hyper, p[i]);
    }

    printf("LCM=%d\n\n", hyper);

    // Table
    printf("Rate Monotone Scheduling:\n");
    printf("PID\tBurst\tPeriod\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, bt[i], p[i]);
    }

    // Utilization
    float U = 0;
    for (i = 0; i < n; i++) {
        U += (float)bt[i] / p[i];
    }

    float bound = n * (pow(2, (float)1/n) - 1);

    printf("\n%f <= %f => %s\n",
           U, bound, (U <= bound) ? "true" : "false");

    printf("Scheduling occurs for %d ms\n", hyper);

    // Remaining time
    int rem[n];
    for (i = 0; i < n; i++)
        rem[i] = 0;

    printf("\n");

    // Scheduling (PRINT ONLY WHEN CHANGE HAPPENS)
    int prev = -2;

    for (int time = 0; time < hyper; time++) {

        // Release
        for (i = 0; i < n; i++) {
            if (time % p[i] == 0) {
                rem[i] = bt[i];
            }
        }

        int selected = -1;

        // Choose highest priority (smallest period)
        for (i = 0; i < n; i++) {
            if (rem[i] > 0) {
                if (selected == -1 || p[i] < p[selected]) {
                    selected = i;
                }
            }
        }

        // Print only when process changes
        if (selected != prev) {
            if (selected == -1)
                printf("%dms onwards: CPU is idle\n", time);
            else
                printf("%dms onwards: Process %d running\n", time, selected + 1);
        }

        if (selected != -1) {
            rem[selected]--;
        }

        prev = selected;
    }

    return 0;
}
