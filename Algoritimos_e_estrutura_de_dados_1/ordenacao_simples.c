#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Cell{
   struct Cell *next;
    int val;
    
    
}Cell;
typedef struct {
    
    Cell * head;
}List;

Cell * create_cell(int val)
{
    Cell * c = (Cell*)malloc(sizeof(Cell));
        
    c->val = val;
    c->next = NULL;
        
    return c;
}
List * create_List()
{
    List * l= (List*)malloc(sizeof(List));
    l->head= NULL;
    return l;
}

void inserir(Cell* c, List *l)
{
    Cell * aux;
    if(l->head ==NULL)
    {
     l->head = c;   
    }
    else{
        aux= l->head;
        while(aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next= c;
    }
    
    
}
void imprimir_lista(List * l)
{
    Cell* aux;
    aux = l->head;
    while(aux->next != NULL)
        {
            printf("%d ",aux->val);
            aux = aux->next;
        }
       printf("%d ",aux->val);
}


void bubble_sort(List * l)
{
    int cont =0 ;//para contar se ouve trocas de  celulas
    Cell * auxAnt, * auxPost ;
    int aux;
   auxPost = l->head;
   auxAnt = auxPost;
    cont =0;
    while (auxPost->next !=NULL)
    {
    auxAnt = auxPost;
    auxPost = auxPost->next;
      if(auxAnt->val > auxPost->val)
       {
           aux = auxPost->val;
           auxPost->val = auxAnt->val;
           auxAnt->val = aux;
            cont++;
          
       }
     
    }
    if(cont ==0)//nao ocorreu nenhuma troca
    {
        return;
    }
    bubble_sort(l);//ocorreu aluma troca quer dizerque nao esta organizado
    
        
    
    
}
int main() {

    int input;
    List * L = create_List();
    Cell* c;
    while(input!=-1)
    {
     scanf("%d",&input);
        if(input!=-1)
        {
        c= create_cell(input);
        inserir(c, L);
        }
    }
    bubble_sort(L);
    imprimir_lista(L);
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
