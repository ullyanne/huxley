#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*QUEUE--------------*/
struct nodeQ
{
    int item;
    struct nodeQ* next;
};

struct queue
{
    struct nodeQ* head;
    struct nodeQ* tail;
    int size;
};

struct nodeQ* createNode(int item)
{
    struct nodeQ* newnode = (struct nodeQ*) malloc(sizeof(struct nodeQ));
    newnode->item = item;

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

void enqueue(struct queue** queue, int item)
{
    struct nodeQ* newtail = createNode(item);
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

void printQ(struct queue* queue)
{
    struct nodeQ* ptr = queue->head;
    if(isEmpty(queue))
        printf("Empty queue.");
    
    while(ptr!= NULL)
    {
        printf("%d ", ptr->item);
        ptr = ptr->next;
    }
    printf("\n");
}

/*LIST-----------*/

struct node
{
    int item;
    struct node* next;
};

struct node* create(int item)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->item = item;
    newnode->next = NULL;

    return newnode;
}

void addSort(struct node** head, int item)
{
    struct node* newnode = create(item);
    
    if(*head == NULL || item <= (*head)->item)
    {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    struct node* last = *head;

    while(last->next != NULL && item > last->next->item)
        last = last->next;
    
    newnode->next = last->next;
    last->next = newnode;
}

void print(struct node* head)
{
    struct node* ptr = head;

    while(ptr != NULL)
    {
        printf("%d ", ptr->item);
        ptr = ptr->next;
    }

    printf("\n");
}

/*GRAPH--------------*/
struct graph
{
    struct node** adjacencyList;
    bool* visited;
    int* predecessor;
    int* distance;
    int size;
};

struct graph* createGraph(int size)
{
    struct graph* newgraph = (struct graph*) malloc(sizeof(struct graph));
    newgraph->adjacencyList = (struct node**) malloc(size * sizeof(struct node*));
    newgraph->visited = (bool*) malloc(size* sizeof(bool));
    newgraph->predecessor = (int*) malloc(size* sizeof(int));
    newgraph->distance = (int*) malloc(size* sizeof(int));
    newgraph->size = size;

    for(int i = 0; i < size; i++)
    {
        newgraph->adjacencyList[i] = NULL;
        newgraph->visited[i] = false;
        newgraph->predecessor[i] = -1;
        newgraph->distance[i] = -1;
    }

    return newgraph;
}

void clear(struct graph* graph)
{
    for(int i = 0; i < graph->size; i++)
    {
        graph->visited[i] = false;
        graph->predecessor[i] = -1;
        graph->distance[i] = -1;
    }
}

void BFS(struct graph* graph, int from)
{
    struct queue* queue = createQueue();
    enqueue(&queue, from);
    //inicializando os dados do nó de origem
    graph->distance[from] = 0;
    graph->visited[from] = true;
    graph->predecessor[from] = -1;

    struct node* child ;

    while(!isEmpty(queue))
    {
        child = graph->adjacencyList[queue->head->item];
        printf("Iniciando busca em largura a partir de %d\n", queue->head->item);

        while(child != NULL)
        {
            //se o nó não foi visitado
            if(!graph->visited[child->item])
            {
                enqueue(&queue, child->item);
                graph->visited[child->item] = true;
                graph->distance[child->item] = graph->distance[queue->head->item]+1;
                graph->predecessor[child->item] = queue->head->item;
            }
            child = child->next;
        }

        dequeue(&queue);
    }
}

//a partir de um array de predecessores, traça o caminho partindo do destino até a origem
void path(struct graph* graph, int to, int from, int* flag, int originalto)
{
    if(to == -1)
        return;

    if(to == from)
    {
        printf("\nCaminho entre %d e %d: ", from, originalto);
        printf("%d", to);
        *flag = 1;
        return;
    }

    path(graph, graph->predecessor[to], from, flag, originalto);
    
    if(*flag)
        printf(" => %d", to);
}

int main()
{
    int nodes, connections, to, from, cases, flag;
    scanf("%d", &nodes);

    struct graph* graph = createGraph(nodes);
    
    scanf("%d%d", &connections, &cases);

    //criando a lista de adjacência
    for(int i = 0; i < connections; i++)
    {
        scanf("%d%d", &from, &to);
        addSort(&graph->adjacencyList[from], to);
    }

    printf("--------\n");
    for(int i = 0; i < cases; i++)
    {
        flag = 0;
        printf("\n");
        scanf("%d%d", &from, &to);
        printf("Caso de Teste #%d - BFS(%d)\n\n", i+1, from);

        //BFS para criar o array de distância, predecessor e de visitados
        BFS(graph, from);

        printf("\n");

        for(int i = 0; i < nodes; i++)
        {
            printf("%d |", i);

            if(graph->distance[i] == -1)
                printf(" - |");
            else
                printf(" %d |", graph->distance[i]);
            
            if(graph->predecessor[i] == -1)
                printf(" -\n");
            else
                printf(" %d\n", graph->predecessor[i]);
        }

        //traçar o caminho da origem até o destino caso haja
        path(graph, to, from, &flag, to);
        
        if(!flag)
            printf("\nSem caminho entre %d e %d", from, to);
        printf("\n\n--------\n");
        
        //limpar array de visitados, predecessor e distância para uma nova busca
        clear(graph);
    }


}

