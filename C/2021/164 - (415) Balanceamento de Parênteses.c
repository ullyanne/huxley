#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct node
{
    char charac;
    struct node* next;
};

struct stack
{
    struct node* top;
    int size;
};

struct node* createNode(char charac)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->charac = charac;

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

void push(struct stack** stack, char charac)
{
    struct node* newtop = createNode(charac);
    newtop->next = (*stack)->top;
    (*stack)->top = newtop;
    (*stack)->size++;
}

char pop(struct stack* stack)
{
    if(isEmpty(stack))
        return '1';
    else
    {
        struct node* currentTop = stack->top;
        stack->top = currentTop->next;
        stack->size--;

        return currentTop->charac;
    }
}

void popTilEmpty(struct stack* stack)
{
    while(!isEmpty(stack))
    {
        pop(stack);
    }
}

int main()
{
    struct stack* parenthesis = createStack();
    struct stack* brackets = createStack();

    int flag = 0;
    int cases;
    char str[256];

    scanf("%d", &cases);
    getchar();

    for(int i = 0; i < cases; i++)
    {   
        fgets(str, 256, stdin);

        for(int j = 0; j < strlen(str); j++)
        {
            if(str[j] == '(')  
                push(&parenthesis, str[j]);
            else if(str[j] == '[')
                push(&brackets, str[j]);
            else if(str[j] == ')')
            {
                //se tentar dar um pop em uma pilha vazia, é atribuído 1 a flag, o que significa
                //que houve um desbalanceamento de parêntesis
                if(pop(parenthesis) == '1')
                    flag = 1;
            }
            else if(str[j] == ']')
            {
                if(pop(brackets) == '1')
                    flag = 1;
            }
        }

        if(flag)
        {
            printf("No\n");
            flag = 0;
        }
        else if(isEmpty(brackets) && isEmpty(parenthesis))
            printf("Yes\n");
        else
            printf("No\n");

        popTilEmpty(parenthesis);
        popTilEmpty(brackets);
    }
    
    free(parenthesis);
    free(brackets);
    return 0;
}