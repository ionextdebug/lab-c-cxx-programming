#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct
{
    char name[MAX_NAME];
    int age;
} person;

person *hash_table[TABLE_SIZE];

unsigned int hash(char *name)
{
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;

    for (int i = 0; i < length; i++)
    {
        hash_value = ((hash_value + name[i]) * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}

bool init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

int main(void)
{

    printf("NameA => %u\n", hash("NameA"));
    printf("NameB => %u\n", hash("NameB"));
    printf("NameC => %u\n", hash("NameC"));
    printf("NameD => %u\n", hash("NameD"));
    printf("NameE => %u\n", hash("NameE"));

    return 0;
}