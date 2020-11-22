#include <stdio.h>

int queue[10];
int front = -1;
int rear = -1;

//enqueing at the rear
void push_rear(int item)
{
    if (rear == 9)
    {
        printf("Scheduler is full..try again after some time");
        return;
    }
    if (rear == -1)
    {
        front = 0;
    }
    rear = rear + 1;
    queue[rear] = item;
}

//dequeing at the front
void pop_front()
{
    if (front == -1 || front > rear)
    {
        front = -1;
        rear = -1;
        printf("queue is empty");
        return;
    }
    int value = queue[front];
    front = front + 1;
}

//printing the state of printer
void details()
{
    if (front == -1)
    {
        printf("No one is printing");
        return;
    }
    printf("%d's document is printing\n", queue[front]);

    if (front < rear)
    {
        printf("Scheduled next: ");
        for (int i = front + 1; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    while (1)
    {

        printf("Enter your id:\n");
        int id;
        scanf("%d", &id);

        push_rear(id);

        printf("\nPrinting Details:\n");
        details();

        printf("\nEnter 0 to Exit or 1 to Print Next:\n");
        int c;
        scanf("%d", &c);
        printf("\n");

        if (id % 5 == 0 || id % 3 == 0)
        {
            pop_front();
        }

        if (c == 0)
        {
            break;
        }
    }
}