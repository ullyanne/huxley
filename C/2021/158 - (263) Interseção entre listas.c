#include <stdio.h>
#include <stdlib.h>

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
        printf("%d\n", ptr->item);
        ptr = ptr->next;
    }
}

void swap(struct node* x, struct node* y)
{
    int item;

    item = x->item;
    x->item = y->item;
    y->item = item;
}

void bubblesort(struct node* first)
{
    struct node* ptr;
    struct node* last = NULL;
    int swapped = 0;

    if(first == NULL)
        return;

    do
    {
        ptr = first;
        swapped = 0;

        while(ptr->next != last)
        {
            if(ptr->item > ptr->next->item)
            {
                swap(ptr, ptr->next);
                swapped = 1;
            }
            
            ptr = ptr->next;
        }
        
        last = ptr;
    } while (swapped);
}

void shouldiadd(struct node** head3, int item)
{
    struct node* ptr = *head3;

    while(ptr != NULL)
    {
        if(ptr->item == item)
        {
            return;
        }
        ptr = ptr->next;
    }
    /*se não estiver na lista, é adicionado a ela*/
    *head3 = add(*head3, item);
}

void search(struct node** head, struct node** head2, struct node** head3, int* vazia)
{
    struct node* ptr = *head;
    struct node* ptr2 = *head2;

    //percorrendo principalmente a lista 1, que é a lista do conjunto
    while(ptr != NULL && ptr2 != NULL)
    {
        /*como estará ordenado, se o primeiro elemento da lista 1 for maior que o da lista 2, já
        sabe-se que ele não estará no restante da lista, logo anda +1 slot da lista 2*/
        if(ptr->item > ptr2->item)
        {
            ptr2 = ptr2->next;
            ptr = *head;
        }
        /*sinaliza que a lista de intersecção não está vizia, anda +1 slot da lista 2
        e volta pro início da lista 1*/
        else if(ptr->item == ptr2->item)
        {
            *vazia = 0;
            //se já existir um nó idêntico, ele não é adicionado
            shouldiadd(head3, ptr->item);
            ptr2 = ptr2->next;
            //voltar ao começo da lista 1
            ptr = *head;
        }
        else
            //anda um slot da lista 1
            ptr = ptr->next;

        //caso não tenha encontrado ao menos um item até chegar no final da lista 1
        if(ptr == NULL)
        {
            ptr2 = ptr2->next;
            ptr = *head;
        }
    }
}

void scan(struct node** head)
{
    int num;

    for(int i = 0; i < 20; i++)
    {
        scanf("%d", &num);
        *head = add(*head, num);
    }
}

int main()
{
    struct node* head = NULL;
    struct node* head2 = NULL;
    struct node* head3 = NULL;
    int vazia = 1;
    
    scan(&head);
    scan(&head2);

    bubblesort(head);
    bubblesort(head2);

    search(&head, &head2, &head3, &vazia);
    bubblesort(head3);

    if(vazia)
        printf("VAZIO\n");
    else
        print(head3);

    free(head);
    return 0;
}