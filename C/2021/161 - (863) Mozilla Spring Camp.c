#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    int item;
    struct node* next;
};

struct stack
{
    struct node* top;
    int size;
};

struct node* createNode(int item)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->item = item;

    return newnode;
}

struct stack* createStack()
{
    struct stack* newstack = (struct stack*) malloc(sizeof(struct stack));
    newstack->top = NULL;
    newstack->size = 0;
    return newstack;
}

bool isEmpty(struct stack* stack)
{
    return stack->size == 0;
}

void push(struct stack** stack, int item)
{
    struct node* newtop = createNode(item);
    newtop->next = (*stack)->top;
    (*stack)->top = newtop;
    (*stack)->size++;
}

struct node* pop(struct stack* stack)
{
    if(isEmpty(stack))
        printf("Stack underflow.\n");
    else
    {
        struct node* currentTop = stack->top;
        stack->top = currentTop->next;
        stack->size--;

        return currentTop;
    }
}

void popTilEmpty(struct stack* stack)
{
    while(!isEmpty(stack))
    {
        pop(stack);
    }
}

struct node* peek(struct stack* stack)
{
    if(isEmpty(stack))
        printf("Stack underflow.\n");
    else
    {
        return stack->top;
    }
}

void print(struct stack* stack)
{
    struct node* ptr = stack->top;
    if(isEmpty(stack))
        printf("Empty stack.");
    
    while(ptr!= NULL)
    {
        printf("%d ", ptr->item);
        ptr = ptr->next;
    }
    printf("\n");
}

void countback(struct stack* back)
{
    struct node* current = back->top;
    int count = 0;
    while(current->next != NULL)
    {
        count++;
        current = current->next;
    }

    printf("BACK: %d\n", count);
}

void countfwd(struct stack* forward)
{
    struct node* current = forward->top;
    int count = 0;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }

    printf("FORWARD: %d\n", count);
}

int main()
{
    struct stack* back = createStack();
    struct stack* forward = createStack();
    char str[8];
    //apenas para preencher o nó e ter uma ideia de qual nó era
    int bckcount = 0;

    while(scanf("%s", str) != EOF)
    {
        if(!strcmp(str, "ENTER"))
        {
            push(&back, bckcount);
            bckcount++;
            //a pilha de forward é esvaziada se não estiver vazia
            popTilEmpty(forward);
        }
        else if(!strcmp(str, "BACK"))
            push(&forward, pop(back)->item);
        else if(!strcmp(str, "FORWARD"))
            push(&back, pop(forward)->item);
    }

    //conta quantos backs e forwards é possível dar
    countback(back);
    countfwd(forward);

    free(back);
    free(forward);
}