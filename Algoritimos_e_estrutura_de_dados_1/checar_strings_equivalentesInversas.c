#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct Cell{
    struct Cell *next;
    char c;
   
}Cell;

typedef struct{
  Cell *topo;
}Pilha;

Cell * create_Cell(char c)
{
    Cell *C = (Cell*)malloc(sizeof(Cell));
    C->c = c;
    C->next= NULL;
    return C;
}
Pilha * create_Pilha()
{
Pilha * P= (Pilha*)malloc(sizeof(Pilha));
P->topo = NULL;
return P;
}

Pilha *Empilhar(Pilha *P,Cell *C)
{
    C->next = P->topo;
    P->topo = C;
  return P;
}
Cell *Desempilhar(Pilha *p)
{
  Cell *aux ;
    
  aux = p->topo;
 
  p->topo = aux->next;
   
  return aux;  
  

}
void imprimirPilha(Pilha *P)
{
    Cell *aux;
    aux = P->topo;
    while (aux->next !=NULL)
    {
        printf("%c ",aux->c);
        aux = aux->next;
    }
  printf("%c ",aux->c);
}

int checar_str(char c1[10],char c2[10])
{
    Pilha *P1,*P2,*P3;
    P1 = create_Pilha();
    P2 = create_Pilha();
    P3 = create_Pilha();
    
    
    
    Cell *aux;
    
    char c =0;
    int i=0;
    
    while(c1[i] != NULL){
        c=c1[i];
        aux =create_Cell(c);
        Empilhar(P1, aux);
        i++;
    }
    
    c=0;
    i=0;
    while(c2[i] != NULL){
        c=c2[i];
        
        aux =create_Cell(c);
        Empilhar(P2, aux);
        i++;
    }
    //imprimirPilha(P2);
    while(P2->topo !=NULL)
    {
    P3 = Empilhar(P3, Desempilhar(P2));//inverterum dos dois;
    }
    //imprimirPilha(P3);
    Cell * c3, *c4;
 
    while(P3->topo!= NULL || P1->topo!=NULL)
    {
      c3= Desempilhar(P3);
      c4= Desempilhar(P1);
        //printf("%c %c",c3->c,c4->c);
        if(c3->c != c4->c)
        {
            printf("nao");//se encontrar algum termo diferente quebra e escreve nao
            break;
        }
    }
    if(c3->c == c4->c)//depois de quebrar vai chegar aqui , por isso necessaro conferir denovo a igualdade
    {
        printf("sim");
     }
    return 1;
}
int main() {
    
    
    char c1[10],c2[10];
    
    scanf("%s",c1);
    scanf("%s",c2);
    
    checar_str(c1, c2);
    
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
