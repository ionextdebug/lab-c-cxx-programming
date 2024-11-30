#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define QUEUE_EMPTY INT_MIN

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef struct
{
    node *head;
    node *tail;
} queue;

void init_queue(queue *q)
{
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue *q, int value)
{
    node *new_node = malloc(sizeof(node));

    if (new_node == NULL)
        return false;

    new_node->value = value;
    new_node->next = NULL;
    if (q->tail != NULL)
    {
        q->tail->next = new_node;
    }
    q->tail = new_node;

    if (q->head == NULL)
    {
        q->head = new_node;
    }

    return true;
}

int dequeue(queue *q)
{
    if (q->head == NULL)
        return QUEUE_EMPTY;
    node *tmp = q->head;
    int result = tmp->value;
    q->head = q->head->next;
    if (q->head == NULL)
    {
        q->tail = NULL;
    }
    free(tmp);
    return result;
}

int main()
{
    int t;
    queue q1, q2, q3;

    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);

    enqueue(&q1, 10);
    enqueue(&q2, 20);
    enqueue(&q3, 30);

    while ((t = dequeue(&q2)) != QUEUE_EMPTY)
    {
        printf("t = %d.\n", t);
    }
}