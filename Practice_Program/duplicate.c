#include <stdio.h>

int main() {
    int n, i, j, flag = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                printf("Duplicate found: %d\n", arr[i]);
                flag = 1;
            }
        }
    }

    if (!flag) {
        printf("No duplicates found\n");
    }

    return 0;
}
