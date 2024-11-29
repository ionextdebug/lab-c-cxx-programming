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

void print_list(node_t *root)
{

    node_t *temp = root;

    while (temp != NULL)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
}

int main()
{
    node_t root, n1, n2, n3;

    root = set_node(0, &n1);
    n1 = set_node(1, &n2);
    n2 = set_node(2, &n3);
    n3 = set_node(3, NULL);

    print_list(&root);

}