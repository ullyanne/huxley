#include <stdio.h>
#include <stdlib.h>

struct binaryTree
{
    int item;
    struct binaryTree* left;
    struct binaryTree* right;
};

struct binaryTree* create(int item)
{
    struct binaryTree* newBT = (struct binaryTree*) malloc(sizeof(struct binaryTree));
    newBT->item = item;

    newBT->left = NULL;
    newBT->right = NULL;

    return newBT;
}

struct binaryTree* add(struct binaryTree* bt, int item)
{
    if(bt == NULL)
        bt = create(item);
    else if(bt->item > item)
        bt->left = add(bt->left, item);
    else if(bt->item <= item)
        bt->right = add(bt->right, item);
    
    return bt;
}

void preOrder(struct binaryTree* bt)
{
    if(bt != NULL)
    {
        printf("  ( ");
        printf("%d", bt->item);
        preOrder(bt->left);

        preOrder(bt->right);
        printf(" )");
    }
    else
    {
        printf("  ()");
    }
}

int main()
{
    struct binaryTree* root = NULL;
    int item;

    while(scanf("%d", &item) != EOF)
    {
        root = add(root, item);
        printf("----\nAdicionando %d\n", item);
        printf(" ");
        preOrder(root);
        printf(" \n");
    }

    printf("----");

    return 0;
}