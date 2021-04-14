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

int search(struct node* head, struct node* head2)
{
    struct node* ptr = head;
    struct node* ptr2 = head2;
    int signal = 0;

    //percorrendo principalmente a lista 1, que é a lista do conjunto
    while(ptr != NULL && ptr2 != NULL)
    {
        /*como estará ordenado, se o primeiro elemento da lista 1 for maior que o da lista 2, já
        sabe-se que ao menos um elemento não está contido, logo não é subconjunto*/
        if(ptr->item > ptr2->item)
            return 0;
        
        /*sinaliza que foi encontrado ao menos um item da lista 2, anda +1 slot da lista 2
        e volta pro início da lista 1*/
        if(ptr->item == ptr2->item)
        {
            signal = 1;
            ptr2 = ptr2->next;
            ptr = head;
        }
        else
            //anda um slot da lista 1
            ptr = ptr->next;

        //caso não tenha encontrado ao menos um item até chegar no final da lista 1
        if(ptr == NULL && signal == 0)
            return 0;
    }
    //foram encontrados todos os itens da lista 2 na lista 1
    return 1;
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

void scan(struct node** head, int* len)
{
    int num;
    scanf("%d", &(*len));

    for(int i = 0; i < *len; i++)
    {
        scanf("%d", &num);
        *head = add(*head, num);
    }
}

int main()
{
    struct node* head = NULL;
    struct node* head2 = NULL;

    int len, len2, num;

    scan(&head, &len);
    scan(&head2, &len2);

    //subconjunto não pode ser maior que o conjunto
    if(len2 > len)
    {
        printf("0\n");
        return 0;
    }

    bubblesort(head);
    bubblesort(head2);

    printf("%d\n", search(head, head2));

    free(head);
    free(head2);
    return 0;
}