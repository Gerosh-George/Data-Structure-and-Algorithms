#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

int stack[10];
int top=-1;

void push(int value)
{
    if (top == MAX - 1)
    {   // size of stack is equal to size of array defined
        printf("Stack Overflow!\n");
        return;
    }

    top = top + 1;
    stack[top] = value;
}

int pop()
{
    if(top==-1){
        // the stack is empty and the user is trying to pop the value
        printf("Stack Underflow!\n");
        exit(0);
    }
    int value = stack[top];
    top = top - 1;
    return value;
}

void peek()
{
    printf("%d", stack[top]);
}

void print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    printf("Inserting 1 2 3 4 into the stack\n");
    push(1);
    push(2);
    push(3);
    push(4);

    printf("The popped value: %d\n", pop());
    printf("The element in top of the stack at present: ");
    peek();

    printf("\nElements in the stack: ");
    print();
}
