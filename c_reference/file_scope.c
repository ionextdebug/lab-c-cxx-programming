#include <stdio.h>

int i;
static int g(int a) { return a; }

int main(void)
{
    i = g(2);
    printf("%d\n", i);
}