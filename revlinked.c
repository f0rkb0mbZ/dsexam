#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *createnode()
{
    node *head = NULL;
    head = (node *)malloc(sizeof(node));
    return head;
}

void printll(node *head)
{
    node * temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insertnode(node *prev, int data)
{
    if (prev == NULL)
    {
        printf("The given previous node can't be NULL\n");
        return;
    }

    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
}

void deletenode(node **head, int key)
{
    node *temp = *head, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}

static void revlist(node ** head)
{
    node * prev = NULL;
    node * current = *head;
    node * next = NULL;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main()
{
    node *head = createnode();
    node *first = createnode();
    node *second = createnode();

    head->data = 1;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = NULL;

    insertnode(second, 5);

    //deletenode(&head, 2);

    printll(head);

    revlist(&head);

    printll(head);
}