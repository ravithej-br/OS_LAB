#include <stdio.h>

void smallest(int arr[], int n) {
    int small = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < small) {
            small = arr[i];
        }
    }
    printf("Smallest value = %d\n", small);
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    smallest(arr, n);

    return 0;
}
