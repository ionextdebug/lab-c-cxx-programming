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

void init_hash_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }
}

void print_table()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hash_table[i] == NULL)
        {
            printf("\t%i\t---\n", i);
        }
        else
        {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
}

bool hash_table_insert(person *p)
{

    if (p == NULL)
        return false;

    int index = hash(p->name);

    if (hash_table[index] != NULL)
        return false;

    hash_table[index] = p;

    return true;
}

person *hash_table_lookup(char *name)
{
    int index = hash(name);
    if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
    {
        return hash_table[index];
    }
    else
    {
        return NULL;
    }
}

person *hash_table_delete(char *name)
{
    int index = hash(name);
    if (hash_table[index] != NULL && strncmp(hash_table[index]->name, name, TABLE_SIZE) == 0)
    {
        person *tmp = hash_table[index];
        hash_table[index] = NULL;
        return tmp;
    }
    else
    {
        return NULL;
    }
}

int main(void)
{
    person *lookup_result;
    person jacob = {.name = "jacob", .age = 20};
    person kate = {.name = "kate", .age = 30};
    person phill = {.name = "phill", .age = 40};

    init_hash_table();

    hash_table_insert(&jacob);
    hash_table_insert(&kate);
    hash_table_insert(&phill);

    print_table();

    lookup_result = hash_table_delete("jacob");

    if (lookup_result != NULL)
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not found!\n");
    }

    print_table();

    return 0;
}