#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodeP
{
    int priority;
    struct nodeP* next;
};

struct queueP
{
    struct nodeP* head;
    int size;
};

struct nodeP* createnodeP(int priority)
{
    struct nodeP* newnode = (struct nodeP*) malloc(sizeof(struct nodeP));
    newnode->priority = priority;

    return newnode;
}

struct queueP* createqueueP()
{
    struct queueP* newqueue = (struct queueP*) malloc(sizeof(struct queueP));
    newqueue->head = NULL;
    newqueue->size = 0;
    return newqueue;
}

bool isEmptyP(struct queueP* queue)
{
    return queue->size == 0;
}

void printP(struct queueP* queue)
{
    struct nodeP* ptr = queue->head;
    if(isEmptyP(queue))
        printf("Empty queue.");
    
    while(ptr!= NULL)
    {
        printf("%d ", ptr->priority);
        ptr = ptr->next;
    }
    printf("\n");
}

void enqueue(struct queueP** queue, int priority)
{
    struct nodeP* newnode = createnodeP(priority);
    (*queue)->size++;

    if((*queue)->head == NULL)
    {
        newnode->next = (*queue)->head;
        (*queue)->head = newnode;
        return;
    }

    struct nodeP* ptr = (*queue)->head;

    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}

void enqueueP(struct queueP** queue, int priority)
{
    struct nodeP* newnode = createnodeP(priority);
    (*queue)->size++;

    if((*queue)->head == NULL)
    {
        newnode->next = (*queue)->head;
        (*queue)->head = newnode;
        return;
    }
    else if(priority > (*queue)->head->priority)
    {
        newnode->next = (*queue)->head;
        (*queue)->head = newnode;
        return;
    }
    
    struct nodeP* current = (*queue)->head;
    while(current->next != NULL && priority < current->next->priority)
        current = current->next;

    newnode->next = current->next;
    current->next = newnode;
}

int main()
{
    int cases, students, degree;

    scanf("%d", &cases);

    for(int i = 0; i < cases; i++)
    {
        struct queueP* queueP = createqueueP();
        struct queueP* queue = createqueueP();

        scanf("%d", &students);

        for(int j = 0; j < students; j++)
        {
            scanf("%d", &degree);
            enqueueP(&queueP, degree);
            enqueue(&queue, degree);
        }
        
        int immobile = students;
        struct nodeP* ptrp = queueP->head;
        struct nodeP* ptr = queue->head;

        //comparando a fila desordenada com a de prioridade
        for(int j = 0; j < students; j++)
        {
            if(ptrp->priority != ptr->priority)
                immobile--;
            
            ptrp = ptrp->next;
            ptr = ptr->next;
        }
        
        printf("%d\n", immobile);
        free(queueP);
        free(queue);
    }

    return 0;
}