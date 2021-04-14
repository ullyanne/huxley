#include <stdio.h>
#include <stdlib.h>

struct node
{
    int id;
    int freq;
    struct node* next;
};

struct node* create(int id)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->id = id;
    newnode->next = NULL;

    return newnode;
}

struct node* add(struct node* head, int id)
{
    struct node* newnode = create(id);
    newnode->next = head;

    return newnode;
}

void print(struct node* head)
{
    struct node* ptr = head;

    while(ptr != NULL)
    {
        printf("%c %d\n", (char)(ptr->id), ptr->freq);
        ptr = ptr->next;
    }
}

void swapfreq(struct node* x, struct node* y)
{
    int aux;

    aux = x->freq;
    x->freq = y->freq;
    y->freq = aux;
}

void swapid(struct node* x, struct node* y)
{
    int aux;

    aux = x->id;
    x->id = y->id;
    y->id = aux;
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
            if(ptr->id < ptr->next->id)
            {
                swapid(ptr, ptr->next);
                swapfreq(ptr, ptr->next);
                swapped = 1;
            }
            
            ptr = ptr->next;
        }
        
        last = ptr;
    } while (swapped);
}

void search(struct node** head, int id)
{
    struct node* ptr = *head;

    while(ptr != NULL)
    {
        if(ptr->id == id)
        {
            ptr->freq++;
            return;
        }
        
        ptr = ptr->next;
    }

    /*se não estiver na lista, é adicionado a ela*/
    *head = add(*head, id);
    (*head)->freq = 1;
}

int main()
{
    struct node* head = NULL;
    char letter;

    while(scanf("%c", &letter) != EOF)
        search(&head, (int)letter);

    bubblesort(head);
    print(head);
    
    free(head);
    return 0;
}