#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct sequence
{
    int start;
    int end;
    int accumulator;
};

struct node
{
    int item;
    int index;
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

int main()
{
    struct node* head;
    struct sequence seq;
    char charac;
    int count, index, start, end;

    while(1)
    {
        head = NULL;
        count = 0, index = 0, start = 0, end = 0, seq.start = 0, seq.end = 0, seq.accumulator = 0;
        
        //até chegar no end of file ou encontrar um espaço branco
        while(scanf("%c", &charac) != EOF && isspace(charac) == 0) 
        {
            //cast
            int digito = charac - '0';
            head = add(head, digito);
            //adicionando o index de cada nó, isto é, sua posição
            head->index = index;
            
            //se o conteúdo do nó for 0
            if(head->item == 0)
            {   
                //definir o start a partir do contador = 0
                if(count == 0)
                {
                    start = head->index;
                    count++;
                }
                //contando os zeros consecutivos
                else
                    count++;
                
                //end sempre atualizado quando encontrar um novo 0 sem interrupções
                end = head->index;

                //se essa for a maior sequência, guarde-a
                //compare com a struct que guarda o início e o fim da maior sequência de zeros
                if(count > seq.accumulator)
                {
                    seq.accumulator = count;
                    seq.start = start;
                    seq.end = end;
                }
            }
            else
            //caso o conteúdo seja 1, a contagem é reiniciada
                count = 0;
            
            //posição do próximo nó
            index++;
        }
        
        //se o próximo nó é um nó que contém apenas um único 0, pare o programa
        if(head->item == 0 && head->next == NULL && head->index == 0)
        {
            free(head);
            break;
        }

        //printar o início e o fim da maior sequência de zeros
        printf("%d %d\n", seq.start, seq.end);
        free(head);
    }

    return 0;
}