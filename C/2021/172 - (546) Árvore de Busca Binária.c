#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

struct binaryTree
{
    int item;
    struct binaryTree* left;
    struct binaryTree* right;
};

struct binaryTree* createNode(int item)
{
    struct binaryTree* newBT = (struct binaryTree*) malloc(sizeof(struct binaryTree));
    newBT->item = item;

    newBT->left = NULL;
    newBT->right = NULL;

    return newBT;
}

struct binaryTree* addFromString(char* arvore, int* index) 
{
    struct binaryTree* root = NULL;
    
    if (arvore[*index] == '(') 
    {
        *index += 1;
        
        if (arvore[*index] == ')') 
        {
            *index += 1;
            return NULL;
        }

        char digits[20];
        int i;
        
        for(i = 0; arvore[*index] != '('; i++, *index+=1)
            digits[i] = arvore[*index]; //adicionando no final da string

        digits[i] = '\0';

        root = createNode(atoi(digits));
        root->left = addFromString(arvore, index);
        root->right = addFromString(arvore, index);
    }

    *index += 1;

    return root;
}

void preOrder(struct binaryTree* bt)
{
    if(bt != NULL)
    {
        printf("%d ", bt->item);
        preOrder(bt->left);
        preOrder(bt->right);
    }
}

bool isBinary(struct binaryTree* root, struct binaryTree** lastVisited)
{
    if(root != NULL)
    {
        if(!isBinary(root->left, lastVisited))
            return 0;

        if(*lastVisited != NULL)
            if((*lastVisited)->item > root->item)
                return 0;

        *lastVisited = root;

        if(!isBinary(root->right, lastVisited))
            return 0;
    }

    return 1;
}

int main()
{
    struct binaryTree* root = NULL;
    char arvore[100000];
    char carac;
    int i = 0;

    while(scanf("%c", &carac) != EOF)
        if(!isspace(carac))
        {
            arvore[i] = carac;
            i++;
        }

    arvore[i] = '\0';
    
    int index = 0;
    struct binaryTree* lastVisited = NULL;

    root = addFromString(arvore, &index);

    if(isBinary(root, &lastVisited))
        printf("VERDADEIRO\n");
    else
        printf("FALSO\n");
    
    return 0;
}