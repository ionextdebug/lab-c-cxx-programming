#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

int my_stack[STACK_LENGTH];
int top = EMPTY;

bool push(int value)
{
    if (top >= STACK_LENGTH - 1)
        return false;
    top++;

    my_stack[top] = value;
}

int pop()
{
    if (top == EMPTY)
        return STACK_EMPTY;

    int result = my_stack[top];
    top--;
    return result;
}

int main(void)
{
    int tmp;
    
    push(10);
    push(20);

    tmp = pop();
}