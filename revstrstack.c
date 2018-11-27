#include <stdio.h>
#include <stdlib.h>

struct stack
{
    char *arr;
    unsigned int capacity;
    int top;
};

typedef struct stack stack;

stack *createstack(unsigned int capacity)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    s->capacity = capacity;
    s->arr = (char *)malloc(sizeof(char) * capacity);
    return s;
}

int isfull(stack *s)
{
    return s->top == s->capacity - 1;
}

int isempty(stack *s)
{
    return s->top == -1;
}

void push(stack *s, char c)
{
    if (isfull(s))
        return;
    s->arr[++s->top] = c;
    //printf("%c pushed to stack\t", c);
}

char pop(stack *s)
{
    if (isempty(s))
    {
        exit(0);
    }
    return s->arr[s->top--];
}

int main()
{
    char *str;
    int len;
    printf("Enter the string length: ");
    scanf("%d", &len);
    stack *s = createstack(len);
    str = (char *)malloc(sizeof(char) * (len));
    printf("Enter the string: ");
    scanf("%s", str);
    puts(str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        push(s, str[i]);
    }
    printf("\nThe reversed string is: ");
    for (int i = 0; i < len; i++)
    {
        printf("%c", pop(s));
    }

    return 0;
}