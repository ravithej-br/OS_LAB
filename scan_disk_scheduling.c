#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int req[100], n, head, disk_size;
    int i, seek = 0, direction;

    printf("SCAN Disk Scheduling\n");

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter direction (0 for LEFT, 1 for RIGHT): ");
    scanf("%d", &direction);

    sort(req, n);

    printf("\nSeek Sequence: %d ", head);

    int index;

    for(i = 0; i < n; i++)
    {
        if(req[i] >= head)
        {
            index = i;
            break;
        }
    }

    if(direction == 1)
    {
        // RIGHT

        for(i = index; i < n; i++)
        {
            seek += abs(req[i] - head);
            head = req[i];

            printf("-> %d ", head);
        }

        seek += abs((disk_size - 1) - head);
        head = disk_size - 1;

        printf("-> %d ", head);

        for(i = index - 1; i >= 0; i--)
        {
            seek += abs(req[i] - head);
            head = req[i];

            printf("-> %d ", head);
        }
    }
    else
    {
        // LEFT

        for(i = index - 1; i >= 0; i--)
        {
            seek += abs(req[i] - head);
            head = req[i];

            printf("-> %d ", head);
        }

        seek += abs(head - 0);
        head = 0;

        printf("-> %d ", head);

        for(i = index; i < n; i++)
        {
            seek += abs(req[i] - head);
            head = req[i];

            printf("-> %d ", head);
        }
    }

    printf("\nTotal Seek Time = %d\n", seek);

    return 0;
}