#include <stdio.h>

int main(void)
{
    goto here;
    puts("Not here.");
here:;
    puts("Here.");
}