#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Queue
{
    int *arr;
    int front, rear, size;
    unsigned int capacity;
};

typedef struct Queue queue;

queue *createqueue(unsigned int capacity)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = q->capacity - 1;
    q->arr = (int *)malloc(sizeof(int) * q->capacity);
}

bool isfull(queue *q)
{
    return q->size == q->capacity;
}

bool isempty(queue *q)
{
    return q->size == 0;
}

void enqueue(queue *q, int data)
{
    if (isfull(q))
        return;
    q->rear = (q->rear + 1) % (q->capacity);
    q->arr[q->rear] = data;
    q->size++;
    printf("%d enqueued to queue!\n", data);
}

int dequeue(queue *q)
{
    if (isempty(q))
        return INT_MIN;
    int data = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return data;
}

int front(queue *q)
{
    if (isempty(q))
    {
        printf("Queue is empty\n");
        exit(0);
    }
    return q->arr[q->front];
}

int rear(queue *q)
{
    if (isempty(q))
    {
        printf("Queue is empty\n");
        exit(0);
    }
    return q->arr[q->rear];
}


int main()
{
    queue *q = createqueue(6);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    enqueue(q, 6);
    printqueue(q);
    dequeue(q);
    printqueue(q);
    return 0;
}