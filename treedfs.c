#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct root *left;
    struct root *right;
};

//typedef struct node node;

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}

struct node *createnode(int data)
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
}

int main()
{
    struct node *root = createnode(6); //level 0

    root->left = createnode(4); //level 1
    root->right = createnode(10);

    root->left->left = createnode(2);//level 2
    // root->left->right = createnode(5);
    // root->right->left = createnode(7);
    // root->right->right = createnode(11);

    // root->left->left->left = createnode(1);//level 3
    // root->left->left->right = createnode(3);
    // root->right->left->left = createnode(8);
    // root->right->left->right = createnode(9);

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

}