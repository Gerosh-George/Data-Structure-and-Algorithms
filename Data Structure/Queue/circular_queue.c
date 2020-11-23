#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Queue
{
    int front;
    int rear;
    int *arr;
    int size;
    int count;
};

struct Queue *createCircularQueue(int size)
{

    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));

    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
    queue->count = 0;

    queue->arr = (int *)malloc(size * sizeof(int));

    return queue;
}

bool isEmpty(struct Queue *queue)
{
    return queue->front == -1;
}

bool isFull(struct Queue *queue)
{
    return queue->count == queue->size;
}

void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
    {
        printf("The Circular queue is full!\n");
        return;
    }

    if (queue->front == -1)
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % queue->size; //this will ensure circular nature of queue
    }

    queue->arr[queue->rear] = item;
    queue->count++;
}

int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("The Circular queue is empty!\n");
        return -1;
    }

    int value = queue->arr[queue->front];
    queue->count--;

    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % queue->size; //this will ensure circular nature of queue
    }

    return value;
}

int len(struct Queue *queue)
{
    return queue->count;
}

int peek(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("The circular queue is empty!\n");
        return -1;
    }

    return queue->arr[queue->front];
}

int main()
{

    struct Queue *queue = createCircularQueue(5);

    //dequeue(queue);

    for (int i = 0; i < 5; i++)
    {
        enqueue(queue, i + 1);
    }

    printf("The queue is of size %d and is filled with numbers from 1 to 5\n", queue->size);
    printf("The number of elements in queue: %d\n", len(queue));

    printf("The element at the front (peek): %d\n", peek(queue));
    printf("The value which is deleted: %d\n", dequeue(queue));

    printf("\nNow at the front of the queue there is space for one element to be inserted\n\n");

    printf("Inserting '6' to the queue which should get inserted even though the rear is pointing to last index of the queue array\n");
    enqueue(queue, 6);

    printf("The number of elements in queue: %d\n", len(queue));

    printf("The element at the front (peek): %d\n", peek(queue));
    
    // *** Queue will look like: 2 3 4 5 6***//
    // *** front=1 and rear=0 ***//

    printf("\nProperty of queue is still followed '2' was number entered after 1 so it is still at the front of the queue!!\n");
}
