#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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

void preOrder(struct binaryTree* bt)
{
    if(bt != NULL)
    {
        printf("%d ", bt->item);
        preOrder(bt->left);
        preOrder(bt->right);
    }
}

/*QUEUE CUJOS NÓS SÃO NÓS DE ÁRVORE-------------*/
struct nodeQ
{
    struct binaryTree* bt;
    struct nodeQ* next;
};

struct queue
{
    struct nodeQ* head;
    struct nodeQ* tail;
    int size;
};

struct nodeQ* createNodeQ(struct binaryTree* bt)
{
    struct nodeQ* newnode = (struct nodeQ*) malloc(sizeof(struct nodeQ));
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
    struct nodeQ* newtail = createNodeQ(bt);
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

struct nodeQ* dequeue(struct queue** queue)
{
    if(isEmpty(*queue))
        printf("Queue underflow.\n");
    else
    {
        struct nodeQ* dequeued = (*queue)->head;
        
        (*queue)->head = (*queue)->head->next;
        (*queue)->size--;

        if((*queue)->head == NULL)
            (*queue)->tail == NULL;
        
        return dequeued;
    }
}


/*LIST--------------*/
struct node
{
    int item;
    struct node* next;
};

struct node* createNode(int item)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->item = item;
    newnode->next = NULL;

    return newnode;
}

void addEnd(struct node** head, int index, int item)
{
    struct node* newnode = createNode(item);

    if(head[index] == NULL)
    {
        head[index] = newnode;
        return;
    }

    struct node* last = head[index];

    while(last->next != NULL)
        last = last->next;
    
    last->next = newnode;
}

void print(struct node* head)
{
    struct node* ptr = head;

    while(ptr != NULL)
    {
        if(ptr->next == NULL)
            printf("%d", ptr->item);
        else
            printf("%d ", ptr->item);
        ptr = ptr->next;
    }
}

/*-----------------*/
void adjList(struct node** adjacencyList, int* values, int times)
{
    int value, nodeleft, noderight;
    
    for(int i = 0; i < times; i++)
    {
        adjacencyList[i] = NULL;
        scanf("%d%d%d", &value, &nodeleft, &noderight);
        values[i] = value;

        addEnd(adjacencyList, i, nodeleft);
        addEnd(adjacencyList, i, noderight);
    }
}

//criar árvore a partir de lista de adjacência
struct binaryTree* createTree(struct node** adjacencyList, int* values, int node)
{
    if(node != -1)
    {
        struct binaryTree* bt = create(values[node]);
        bt->left = createTree(adjacencyList, values, adjacencyList[node]->item);
        bt->right = createTree(adjacencyList, values, adjacencyList[node]->next->item);
        
        return bt;
    }

    return NULL;
}

void BFS(struct binaryTree* bt, int* currentLevel)
{
    int min, max;
    struct queue* queue = createQueue();

    enqueue(&queue, bt);
    struct nodeQ* ptr;

    while(!isEmpty(queue))
    {
         //checa tudo que está no mesmo nível de profundidade. uma vez por profundidade
        if(queue->head->bt->level > *currentLevel)
        {
            *currentLevel+=1;
            ptr = queue->head;

            min = INT_MAX;
            max = INT_MIN;

            while(ptr != NULL && ptr->bt->level == *currentLevel)
            {
                if(min > ptr->bt->item)
                    min = ptr->bt->item;

                if(max < ptr->bt->item)
                    max = ptr->bt->item;

                ptr = ptr->next;
            }
            printf("Nivel %d: Maior = %d, Menor = %d\n", *currentLevel, max, min);
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
}

int main()
{
    struct binaryTree* root = NULL;
    
    int level = 0;
    int nodes;
    scanf("%d", &nodes);

    struct node* adjacencyList[nodes];
    int values[nodes];

    adjList(adjacencyList, values, nodes);
    root = createTree(adjacencyList, values, 0);
    
    if(root)
        root->level = 1;

    BFS(root, &level);

    free(root);
    return 0;
}