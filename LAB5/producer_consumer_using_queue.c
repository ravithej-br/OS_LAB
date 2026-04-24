#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int front = -1, rear = -1;

// Semaphores
sem_t empty, full, mutex;

void producer() {
    int item;

    // Check full
    if ((rear + 1) % BUFFER_SIZE == front) {
        printf("Buffer is FULL! Cannot produce.\n");
        return;
    }

    printf("Enter item to produce: ");
    scanf("%d", &item);

    sem_wait(&empty);
    sem_wait(&mutex);

    if (front == -1) front = 0;
    rear = (rear + 1) % BUFFER_SIZE;
    buffer[rear] = item;

    printf("Produced %d at position %d\n", item, rear);

    sem_post(&mutex);
    sem_post(&full);
}

void consumer() {
    int item;

    // Check empty
    if (front == -1) {
        printf("Buffer is EMPTY! Cannot consume.\n");
        return;
    }

    sem_wait(&full);
    sem_wait(&mutex);

    item = buffer[front];
    printf("Consumed %d from position %d\n", item, front);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % BUFFER_SIZE;
    }

    sem_post(&mutex);
    sem_post(&empty);
}

int main() {
    int choice;

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    printf("Enter ");
    printf("1. Producer ");
    printf("2. Consumer ");
    printf("3. Exit\n");

    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                producer();
                break;
            case 2:
                consumer();
                break;
            case 3:
                printf("Exiting...\n");
                sem_destroy(&empty);
                sem_destroy(&full);
                sem_destroy(&mutex);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
