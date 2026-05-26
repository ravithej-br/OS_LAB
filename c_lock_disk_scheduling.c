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
    int req[100], n, head;
    int i, seek = 0, direction, index;

    printf("C-LOOK Disk Scheduling\n");

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter direction (0 for LEFT, 1 for RIGHT): ");
    scanf("%d", &direction);

    sort(req, n);

    for(i = 0; i < n; i++)
    {
        if(req[i] >= head)
        {
            index = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d ", head);

    if(direction == 1)
    {
        // RIGHT

        for(i = index; i < n; i++)
        {
            seek += abs(req[i] - head);
            head = req[i];

            printf("-> %d ", head);
        }

        seek += abs(head - req[0]);
        head = req[0];

        printf("-> %d ", head);

        for(i = 1; i < index; i++)
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

        seek += abs(head - req[n - 1]);
        head = req[n - 1];

        printf("-> %d ", head);

        for(i = n - 2; i >= index; i--)
        {
            seek += abs(req[i] - head);
            head = req[i];

            printf("-> %d ", head);
        }
    }

    printf("\nTotal Seek Time = %d\n", seek);

    return 0;
}