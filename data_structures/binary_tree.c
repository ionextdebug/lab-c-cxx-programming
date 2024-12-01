#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool insert_number(treenode **rootptr, int value)
{
    treenode *root = *rootptr;

    if (root == NULL)
    {
        (*rootptr) = create_node(value);
        return true;
    }

    if (value == root->value)
    {
        return false;
    }

    if (value < root->value)
    {
        return insert_number(&(root->left), value);
    }
    else
    {
        return insert_number(&(root->right), value);
    }
}

bool find_number(treenode *root, int value)
{
    if (root == NULL)
        return false;
    if (root->value == value)
        return true;
    if (value < root->value)
        return find_number(root->left, value);

    return find_number(root->right, value);
}

int main()
{
    treenode *root = NULL;

    insert_number(&root, 15);
    insert_number(&root, 16);
    insert_number(&root, 17);
    insert_number(&root, 18);
    insert_number(&root, 19);
    insert_number(&root, 20);

    print_tree(root);
}