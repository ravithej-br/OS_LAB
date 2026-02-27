#include <stdio.h>

void linearSearch(int arr[], int n, int key) {
    int i, found = 0;
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Found %d at index %d\n", key, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Element %d not found\n", key);
    }
}

int main() {
    int arr[10], i, key;

    printf("Enter 10 elements:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    linearSearch(arr, 10, key);

    return 0;
}
