#include <stdio.h>
#include <time.h>
#include <stdarg.h>

int fsum(int count, ...)
{
    va_list args;
    va_start(args, count);
    int sum = 0;

    for (int i = 0; i < count; i++)
    {
        sum += va_arg(args, int);
    }

    va_end(args);
    return sum;
}

int main(void)
{
    int sum = fsum(3, 1, 2, 3);

    printf("The sum is: %d.\n", sum);
}