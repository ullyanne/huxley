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

struct node* reverse(struct node* prev, struct node* current)
{
    struct node* next;

    if(current == NULL)
        return prev;
    
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;

    return reverse(prev, current);
}

int main()
{
    struct node* head = NULL;
    int item;

    while(scanf("%d", &item) != EOF)
        addEnd(&head, item);

    head = reverse(NULL, head);
    print(head);

    free(head);
    return 0;
}