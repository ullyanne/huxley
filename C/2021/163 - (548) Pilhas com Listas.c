#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//nós de listas
struct node
{
    int item;
    struct node* next;
};

//nós contidos na pilha, node stack
struct nodest
{
    struct node** head;
    struct nodest* next;
};

struct stack
{
    struct nodest* top;
    int size;
};

struct nodest* createNodest(struct node** head)
{
    struct nodest* newnode = (struct nodest*) malloc(sizeof(struct nodest));
    newnode->head = head;

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

void push(struct stack** stack, struct node** head)
{
    struct nodest* newtop = createNodest(head);
    newtop->next = (*stack)->top;
    (*stack)->top = newtop;
    (*stack)->size++;
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
    printf("\n");
}

struct nodest* pop(struct stack* stack)
{
    if(isEmpty(stack))
        printf("EMPTY STACK\n");
    else
    {
        struct nodest* currentTop = stack->top;
        stack->top = currentTop->next;
        stack->size--;
        print(*(currentTop->head));
        return currentTop;
    }
}

struct node* create(int item)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->item = item;
    newnode->next = NULL;

    return newnode;
}

void addEnd(struct node** head, int item)
{
    struct node* newnode = create(item);

    if(*head == NULL)
    {
        *head = newnode;
        return;
    }

    struct node* last = *head;

    while(last->next != NULL)
        last = last->next;
    
    last->next = newnode;
}

int main()
{
    struct stack* stack = createStack();
    //array de cabeças de lista/array de listas
    struct node** head = (struct node**) malloc(10 * sizeof(struct node*));
    char str[10];
    //tamanho e índice do array
    int size = 10;
    int i = -1;

    while(scanf("%s", str) != EOF)
    {
        if(!strcmp(str, "PUSH"))
        {
            i++;
            //adicionada à pilha a cabeça de uma lista
            push(&stack, head+i);
        }
        else if(!strcmp(str, "POP"))
        {
            //retira da pilha a cabeça de uma lista e printa todos os elementos contidos nessa lista
            pop(stack);
        }
        else
        {
            //adiciona itens à lista
            addEnd(head+i, atoi(str));
        }

        if(i == size-1)
        {
            //se estiver perto de atingir a capacidade máxima
            head = (struct node**) realloc (head, 10 * sizeof(struct node*));
            size *= 2;
        }
        
        //anotações
        // printf("%d\n", head[0]->item);
        // if(head[0]->next == NULL)
        // {
        //     printf("cocada\n");
        // }
        // addEnd(head+1, 6);
        // printf("%d\n", head[1]->item);
        // addEnd(head+1, 12);
        // printf("%d e %d ----\n", head[1]->item, head[1]->next->item);
    }
    
    free(stack);
    free(head);
}