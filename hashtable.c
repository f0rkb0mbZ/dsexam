#include <stdio.h>
#include <stdlib.h>

struct hash_data
{
    int key;
    int value;
};

typedef struct hash_data hash_data;

struct hash_item
{
    int flag;
    hash_data *data;
};

typedef struct hash_item hash_item;

void init_array(int size)
{
    hash_item *array;
    array = (hash_item *)malloc(sizeof(hash_item) * size);
    for (int i = 0; i < size; i++)
    {
        array[i].flag = 0;
        array[i].data = NULL;
    }
}

int hashfunc(int key, int func)
{
    return key % func;
}

int main()
{
    return 0;
}