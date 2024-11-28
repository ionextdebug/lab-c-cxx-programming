#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    printf("rand: %d.\n", rand());
}