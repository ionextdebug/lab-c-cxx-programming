#include <stdio.h>
#include <stdlib.h>

typedef struct treenode
{
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *create_node(int value)
{
    treenode *result = malloc(sizeof(treenode));
    if (result != NULL)
    {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
}

void printtabs(int numtabs)
{
    for (int i = 0; i < numtabs; i++)
    {
        printf("\t");
    }
}

void print_tree_rec(treenode *root, int level)
{
    if (root == NULL)
    {
        printtabs(level);
        printf("---\n");
        return;
    }

    printtabs(level);
    printf("value == %d\n", root->value);

    printtabs(level);
    printf("left\n");

    print_tree_rec(root->left, level + 1);

    printtabs(level);
    printf("right\n");
    print_tree_rec(root->right, level + 1);

    printtabs(level);
    printf("done\n");
}

void print_tree(treenode *root)
{
    print_tree_rec(root, 0);
}

int main()
{
    treenode *n1 = create_node(10);
    treenode *n2 = create_node(20);
    treenode *n3 = create_node(30);
    treenode *n4 = create_node(40);
    treenode *n5 = create_node(50);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;

    print_tree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
}