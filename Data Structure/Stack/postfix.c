#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

int operators[4] = {'+', '-', '*', '/'};
int stack[10];
int top = -1;

void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow!\n");
        return;
    }

    top = top + 1;
    stack[top] = value;
}

int pop()
{
    int value = stack[top];
    top = top - 1;
    return value;
}

bool is_operator(char c)
{
    for (int i = 0; i < 4; i++)
    {
        if (c == operators[i])
            return true;
    }

    return false;
}

void calculate(char c)
{
    if (is_operator(c))
    {
        int val2 = pop();
        int val1 = pop();
        int result = 0;
        if (c == operators[0])
        {
            result = val1 + val2;
        }
        else if (c == operators[1])
        {
            result = val1 - val2;
        }
        else if (c == operators[2])
        {
            result = val1 * val2;
        }
        else if (c == operators[3])
        {
            result = val1 / val2;
        }

        push(result);
    }
    else
    {
        printf("Enter the value for %c: ", c);
        int v;
        scanf("%d", &v);
        push(v);
    }
}

int main()
{
    char *exp = (char *)malloc(sizeof(char));

    int i = 0;
    printf("Enter the expression (end with $): ");
    while (true)
    {
        char ch;
        scanf("%c", &ch);
        if (ch == '$')
            break;
        exp[i] = ch;
        i++;
    }

    for (int i = 0; i < strlen(exp); i++)
    {
        calculate(exp[i]);
    }

    printf("\nResult: %d", pop());
}