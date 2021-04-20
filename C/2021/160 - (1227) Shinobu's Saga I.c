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

void printPop(struct stack* stack)
{
    if(isEmpty(stack))
        printf("Empty stack.\n");
    while(!isEmpty(stack))
    {
        printf("%d\n", pop(stack)->item);
    }
}

void sum(struct stack** stack)
{
    int total = pop(*stack)->item + pop(*stack)->item;
    push(stack, total);
}

void subtract(struct stack** stack)
{
    int difference = pop(*stack)->item;
    difference = pop(*stack)->item - difference;
    push(stack, difference);
}

void multiply(struct stack** stack)
{
    int product = pop(*stack)->item * pop(*stack)->item;
    push(stack, product);
}

void divide(struct stack** stack)
{
    int quotient = pop(*stack)->item;
    quotient = pop(*stack)->item/quotient;
    push(stack, quotient);
}

int main()
{
    struct stack* stack = createStack();
    int num;
    char charac[10];

    for(int i = 1; i < 3; i++)
    {
        //como o número pode ser maior ou igual a 10, lê-se em string
        scanf("%d", &num);

        for(int j = 0; j < num; j++)
        {
            scanf("%s", charac);
            
            if(!strcmp(charac, "+"))
                sum(&stack);
            else if(!strcmp(charac, "-"))
                subtract(&stack);
            else if(!strcmp(charac, "*"))
                multiply(&stack);
            else if(!strcmp(charac, "/"))
                divide(&stack);
            else
            //convertendo a string para número com a função atoi
                push(&stack, atoi(charac));
        }
        printf("Coordenada %d: ", i);
        printPop(stack);
    }
    
    free(stack);
}
