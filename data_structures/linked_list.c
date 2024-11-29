#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node node_t;

node_t set_node(int value, node_t *next)
{

    node_t node;
    node.value = value;
    node.next = next;

    return node;
}

node_t *create_new_node(int value)
{
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
    return node;
}

void print_list(node_t *root)
{

    node_t *temp = root;

    while (temp != NULL)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

node_t *find_the_node(node_t *head, int value)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value == value)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

void insert_after_node(node_t *node_to_insert_after, node_t *new_node)
{
    new_node->next = node_to_insert_after->next;
    node_to_insert_after->next = new_node;
}

int main()
{
    node_t *head = NULL;
    node_t *tmp;

    for (int i = 0; i < 25; i++)
    {
        tmp = create_new_node(i);
        head = insert_at_head(&head, tmp);
    }

    tmp = find_the_node(head, 13);
    printf("Found the node with value: %d\n.", tmp->value);

    insert_after_node(tmp, create_new_node(100));

    print_list(head);

    return 0;
}