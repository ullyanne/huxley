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
        if(ptr->next == NULL)
            printf("%d", ptr->item);
        else
            printf("%d ", ptr->item);
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

int main()
{
    struct node* head = NULL;
    int item;
    
    while(scanf("%d", &item) != EOF)
        head = add(head, item);

    bubblesort(head);
    print(head);
    free(head);
    return 0;
}