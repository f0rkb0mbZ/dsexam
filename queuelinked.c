#include <stdio.h>
#include <stdlib.h>

struct qnode
{
    int data;
    struct qnode *next;
};

typedef struct qnode qnode;

struct queue
{
    qnode *front, *rear;
};

typedef struct queue queue;

qnode *newnode(int key)
{
    qnode *temp = (qnode *)malloc(sizeof(qnode));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

queue *createqueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(queue *q, int key)
{
    qnode *temp_node = newnode(key);
    if (q->rear == NULL)
    {
        q->front = q->rear = temp_node;
        return;
    }
}

int main()
{

    return 0;
}