#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Cell{
    struct Cell *next;
    int val;
    
}Cell;

typedef struct {
  Cell *head;  
}List;

Cell * create_Cell(int val)
{
    Cell *c =(Cell*)malloc(sizeof(Cell));
    c->val = val;
    c->next = NULL;
return c;
}

List * create_list()
{
   List *l = (List*)malloc(sizeof(List));
return l;
}
int inserir_primeiro(List *l,Cell *c)
{
    l->head = c;
    return 1;
}
int inserir(List *l,Cell *c)
{
    if(l ==NULL)
    {
        l = create_list();
        return 1;
    }
    else
    {
        Cell *aux = l->head;
        while(aux->next != NULL)
        {
            aux= aux->next;
            
        }
        aux->next = c;
        
    }
    return 1;
}
int imprimir(List *l)
{
    Cell * aux =l->head;
    while(aux != NULL)
    {
        printf("%d ",aux->val);
        aux =aux->next;
    }
    return 1;
}
Cell *encontrar_ultima(List *l)
{
    Cell *aux;
    aux =l->head;
    while(aux->next != NULL)
    {
        aux = aux->next;
    }
    return aux;
}
int inverter(List *l )
{
    Cell *aux1,*aux2,*ultima;
    ultima = encontrar_ultima(l);
    while (l->head->next != NULL)//vai para quandol->head aponta para NULL, que dizer que todos os ponteros foram invertidos , , colocar a cabeca na utima celula.
    {
    aux1=aux2= l->head;
    while(aux2->next!=NULL)
    {
        //acontecera que aux 1 ficara sempre uma celula atras de aux2 ;
        aux1 =aux2;
        aux2= aux2->next;
    }
    aux2->next = aux1 ;
    aux1->next = NULL;
    }
   
    l->head = ultima ;
    return 1;
    
}
int main() {

    int input=0,cont =0;
    List *L = create_list();
    while(input!=-1)
    {
        scanf("%d",&input);
        if(input != -1)
        {
            Cell* aux = create_Cell(input);
           if(cont== 0)
           {
               inserir_primeiro(L, aux);
           }
           else
           {
               inserir(L ,aux);
           }
            
            cont++;
        }
     }
    inverter(L);
    imprimir(L);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
