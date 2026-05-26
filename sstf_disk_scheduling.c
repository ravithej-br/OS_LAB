#include <stdio.h>
#include <stdlib.h>

int main()
{
    int req[100], visited[100] = {0};
    int n, head, i, j, seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d ", head);

    for(i = 0; i < n; i++)
    {
        int min = 9999, pos = -1;

        for(j = 0; j < n; j++)
        {
            if(!visited[j] && abs(req[j] - head) < min)
            {
                min = abs(req[j] - head);
                pos = j;
            }
        }

        visited[pos] = 1;
        seek += abs(req[pos] - head);
        head = req[pos];

        printf("-> %d ", head);
    }

    printf("\nTotal Seek Time = %d\n", seek);

    return 0;
}