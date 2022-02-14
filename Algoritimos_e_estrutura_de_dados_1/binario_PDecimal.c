#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct Cell{
    int val;
   struct Cell *next;
}Cell;

typedef struct{
  Cell *topo;
}Pilha;

int vazia(Pilha *P)
{
    if (P == NULL|| P->topo == NULL)
    {
        return 1;
    }
    return 0;
}
Cell * iniciarCell(int valor)
{
   Cell *C = (Cell*)malloc(sizeof(Cell));
    C->val = valor;
    C->next= NULL;
    return C;
}
Pilha * iniciarPilha()
{
Pilha * P= (Pilha*)malloc(sizeof(Pilha));
P->topo = NULL;
return P;
}

Pilha* Empilhar(Pilha *P,int valor){

Cell *C ;
if (vazia(P))
{
   P= iniciarPilha(P);
}
C = iniciarCell(valor);



C->next = P->topo;
P->topo = C;
return P;
}

void imprimirPilha(Pilha *P)
{
    Cell *aux;
    aux = P->topo;
    while (aux->next !=NULL)
    {
        printf("%d",aux->val);
        aux = aux->next;
    }
    
}
int Desempilhar(Pilha *p)
{
  Cell *aux ;
    int valor ;
  aux = p->topo;
    valor = aux->val;
  p->topo = aux->next;
    free (aux);
  return valor;  
  

}
int main()
{
   Pilha *P;

  P = iniciarPilha();
  int input=0;
while(input != -1)
{
    scanf("%d",&input);
    if(input != -1)
    {
    P = Empilhar(P,input);
    }
    
}
//imprimirPilha(P);
 int decimal = 0;
  int  mult=1;
while (P->topo != NULL)
{    
    
    int i =Desempilhar(P);
    //printf("%d",i);
    decimal = decimal +(i*mult);
    mult = mult*2;
}
 
printf("%d",decimal);
    return 0;
}
