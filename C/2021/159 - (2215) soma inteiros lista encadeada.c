#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

struct node* add(struct node* head, int item)
{
    struct node* newnode = create(item);
    newnode->next = head;

    return newnode;
}

void print(struct node* head)
{
    struct node* ptr = head;

    while(ptr != NULL)
    {
        if(ptr->next == NULL)
            printf("%d\n", ptr->item);
        else
            printf("%d ", ptr->item);
        ptr = ptr->next;
    }
}

void scan(struct node** head, char stop)
{
    char charac;

    while(scanf(" %c", &charac) && charac != stop)
    {
        //barrar todos os 0 à esquerda. eles seriam os primeiros adicionados, então *head == NULL
        if(charac == '0' && *head == NULL)
            getchar();
        //barrar todos os espaços em branco
        else if(!isspace(charac))
            *head = add(*head, charac - '0');
    }
}

void sumelse(struct node** head3, struct node* ptr, struct node* ptr2, int* carry)
{
    if(*carry + (ptr->item + ptr2->item) < 10)
    {
        //carry foi consumido
        *head3 = add(*head3, *carry + (ptr->item + ptr2->item));
        *carry = 0;
    }
    else
        //carry não foi consumido, mas foi somado com os outros. "vai 1"
        *head3 = add(*head3, (*carry + ptr->item + ptr2->item)%10);
}

void sumnull(struct node** head3, struct node* ptr2, int* carry)
{
    if(*carry)
    {
        if(*carry + ptr2->item < 10)
        {
            //carry foi consumido
            *head3 = add(*head3, *carry + ptr2->item);
            *carry = 0;
        }
        else
        {
            //carry não foi consumido, mas foi somado com os outros. "vai 1"
            *head3 = add(*head3, (*carry + ptr2->item)%10);
        }
    }
    else
    {   
        //apenas uma parcela a se somar
        *head3 = add(*head3, ptr2->item);
    }
}

void sum(struct node** head, struct node** head2, struct node** head3)
{
    struct node* ptr = *head;
    struct node* ptr2 = *head2;
    int carry = 0;

    while(ptr != NULL | ptr2 != NULL)
    {
        if(ptr == NULL)
        {
            sumnull(head3, ptr2, &carry);
        }
        else if(ptr2 == NULL)
        {
            sumnull(head3, ptr, &carry);
        }
        else if(ptr->item + ptr2->item >= 10)
        {
            if(carry)
            {
                sumelse(head3, ptr, ptr2, &carry);
            }
            else
            {
                //apenas se soma as parcelas. como essa soma vai dar igual ou maior que 10
                //um carry irá surgir
                *head3 = add(*head3, (ptr->item + ptr2->item) - 10);
                carry = 1;
            }
        }
        else
        {
            if(carry)
            {
                sumelse(head3, ptr, ptr2, &carry);
            }
            else
            {
                //apenas se soma as parcelas
                *head3 = add(*head3, ptr->item + ptr2->item);
            }
        }

        //se os ponteiros não apontarem para NULL
        if(ptr)
            ptr = ptr->next;
        if(ptr2)
            ptr2 = ptr2->next;
    }
    //caso após toda a soma ainda sobre um carry
    if(carry)
        *head3 = add(*head3, carry);
}

int main()
{
    struct node* head = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;
    //head3 é a soma das parcelas head1 e head2
    
    scan(&head, '+');
    scan(&head2, '=');

    if(head == NULL && head2  == NULL)
        printf("Lista vazia!\n");
    else
    {
        sum(&head, &head2, &head3);
        print(head3);
    }
    
    free(head);
    free(head2);
    free(head3);
    return 0;
}