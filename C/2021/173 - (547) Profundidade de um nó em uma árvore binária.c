#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/*TREE-----------------------*/
struct binaryTree
{
    int item;
    int level;
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

        root = create(atoi(digits));
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

/*QUEUE----------------------*/
struct node
{
    struct binaryTree* bt;
    struct node* next;
};

struct queue
{
    struct node* head;
    struct node* tail;
    int size;
};

struct node* createNode(struct binaryTree* bt)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->bt = bt;
    newnode->next = NULL;

    return newnode;
}

struct queue* createQueue()
{
    struct queue* newqueue = (struct queue*) malloc(sizeof(struct queue));
    newqueue->head = NULL;
    newqueue->tail = NULL;
    newqueue->size = 0;
    return newqueue;
}

bool isEmpty(struct queue* queue)
{
    return queue->size == 0;
}

void enqueue(struct queue** queue, struct binaryTree* bt)
{
    struct node* newtail = createNode(bt);
    (*queue)->size++;

    if((*queue)->head == NULL)
    {
        (*queue)->head = newtail;
        (*queue)->tail = newtail;
        return;
    }
    
    (*queue)->tail->next = newtail;
    (*queue)->tail = newtail;
}

struct node* dequeue(struct queue** queue)
{
    if(isEmpty(*queue))
        printf("Queue underflow.\n");
    else
    {
        struct node* dequeued = (*queue)->head;
        
        (*queue)->head = (*queue)->head->next;
        (*queue)->size--;

        if((*queue)->head == NULL)
            (*queue)->tail == NULL;
        
        return dequeued;
    }
}

void print(struct queue* queue)
{
    struct node* ptr = queue->head;
    if(isEmpty(queue))
        printf("Empty queue.");
    
    while(ptr!= NULL)
    {
        printf("%d ", ptr->bt->item);
        ptr = ptr->next;
    }
    printf("\n");
}

void BFS(struct binaryTree* bt, int* currentLevel, int value, struct queue* queue)
{
    enqueue(&queue, bt);
    struct node* ptr;

    while(!isEmpty(queue))
    {
        if(queue->head->bt->level > *currentLevel)
        {
            *currentLevel+=1;
            ptr = queue->head;

            while(ptr != NULL && ptr->bt->level == *currentLevel)
            {
                if(ptr->bt->item == value)
                {
                    printf("ESTA NA ARVORE\n%d\n", ptr->bt->level);
                    return;
                }

                ptr = ptr->next;
            }
        }

        if(queue->head->bt->left != NULL)
        {
            queue->head->bt->left->level = queue->head->bt->level+1;
            enqueue(&queue, queue->head->bt->left);
        }
        if(queue->head->bt->right != NULL)
        {
            queue->head->bt->right->level = queue->head->bt->level+1;
            enqueue(&queue, queue->head->bt->right);
        }
        
        dequeue(&queue);
    }

    printf("NAO ESTA NA ARVORE\n-1\n");
}

int main()
{
    struct binaryTree* root = NULL;
    struct queue* queue = createQueue();
    char arvore[100000];
    char carac;
    int i = 0, value;

    //filtrando os espaços
    while(scanf("%c", &carac) && carac != '\n')
        if(!isspace(carac))
        {
            arvore[i] = carac;
            i++;
        }

    arvore[i] = '\0';
    
    /*criando árvore a partir de uma string*/
    int index = 0;
    root = addFromString(arvore, &index);

    /*BFS*/
    scanf("%d", &value);
    int level = -1;

    if(root != NULL)
        root->level = 0;

    BFS(root, &level, value, queue);
    
    free(root);
    free(queue);
    return 0;
}