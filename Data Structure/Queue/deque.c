#include <stdio.h>
#include <stdbool.h>

int MAX_SIZE = 5;

int deque[5];
int front = -1;
int rear = -1;
int count = 0;

bool isEmpty()
{
    return front == -1;
}

bool isFull()
{
    return count == MAX_SIZE;
}

//insertion at the end
void enqueue_rear(int item)
{
    if (isFull())
    {
        printf("Deque is full!\n");
        return;
    }

    // first time inserting an element
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    // rear reached last index of array
    else if (rear == MAX_SIZE - 1)
    {
        rear = 0;
    }
    // normal increment of rear to fill in the deque
    else
    {
        rear = rear + 1;
    }
    count++;
    deque[rear] = item;
}

// insertion at the start
void enqueue_front(int item)
{
    if (isFull())
    {
        printf("The Deque is full!\n");
        return;
    }

    // first time insertion
    if (front == -1)
    {
        rear = 0;
        front = 0;
    }
    // when front is at the 0th index and insert at front is called
    else if (front == 0)
    {
        front = MAX_SIZE - 1;
    }
    // normal decrement of front for insertion into the deque
    else
    {
        front = front - 1;
    }
    count++;
    deque[front] = item;
}

// deletion at the start
int dequeue_front()
{
    if (isEmpty())
    {
        printf("The Deque is empty!\n");
        return -1;
    }

    int value = deque[front];
    count--;

    //checks if only one element is left
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }

    else if (front == MAX_SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front = front + 1;
    }

    return value;
}

//deletion at the end
int dequeue_rear()
{
    if (isEmpty())
    {
        printf("The Deque is empty!\n");
        return -1;
    }

    int value = deque[rear];
    count--;

    //checks if only one element is left
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX_SIZE - 1;
    }
    else
    {
        rear = rear - 1;
    }

    return value;
}

//returns the number of element present in the queue
int len()
{
    return count;
}

//shows which element is at the front of the deque
int get_front()
{
    if (isEmpty())
    {
        printf("The Deque is empty!\n");
        return -1;
    }

    return deque[front];
}

// shows which element is at the rear of the deque
int get_rear()
{
    if (isEmpty() || rear == -1)
    {
        printf("The Deque is empty!\n");
        return -1;
    }

    return deque[rear];
}

int main()
{
    printf("\nInserting '1' in front\n");
    enqueue_front(1);

    printf("Inserting '2' in rear\n");
    enqueue_rear(2);

    printf("Inserting '10' in front\n");
    enqueue_front(10);

    printf("Inserting '3' in rear\n\n");
    enqueue_rear(3);

    // *** Order of the Elements in the Deque: 10 1 2 3 *** //

    printf("Number elements in deque: %d\n\n", len());

    if (get_front() != -1 && get_rear() != -1)
    {
        printf("Element at the front of Deque: %d\n", get_front());
        printf("Element at the rear of Deque: %d\n\n", get_rear());
    }

    if (!isEmpty())
    {
        printf("The value removed from front: %d\n", dequeue_front());
        printf("The value removed from rear: %d\n\n", dequeue_rear());
    }

    if (get_front() != -1 && get_rear() != -1)
    {
        printf("Element at the front of Deque: %d\n", get_front());
        printf("Element at the rear of Deque: %d\n\n", get_rear());
    }

    printf("Number elements in deque: %d\n\n", len());

    printf("Called Dequeue three times! '1' & '2' will be removed and then third time deque underflow will happen.\n");
    dequeue_front();
    dequeue_rear();
    dequeue_front();
}