#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct cell{
     
    char nome[15];
    int i;
    struct cell *next;
}cell;

typedef struct{
     
    struct cell * head;
}lista;

lista * criar_lista()
{
    lista * l =(lista*)malloc(sizeof(lista));
    l->head=NULL;
    return l;
    
}
cell * criarCell(int I , char Nome[15] )
{
    cell * c = (cell*)malloc(sizeof(cell));
    c->i =I;
    for (int i= 0;i<15;i++)
    {
          c->nome[i] = Nome[i];
    }
    c->next = NULL;
    return c;
}
int inserir_Cell(lista *l, cell * c)
{
    cell* aux = l->head;
    while(aux->next!=NULL)
    {
        aux = aux->next;
    }
    aux->next = c;
    return 1;
}

void trocar_nome(cell *c1,cell *c2)
{
    char aux[15];
    for (int i= 0;i<15;i++)
    {
          aux[i] = c1->nome[i];
    }
     for (int i= 0;i<15;i++)
    {
          c1->nome[i] = c2->nome[i];
    }
     for (int i= 0;i<15;i++)
    {
          c2->nome[i] = aux[i];
    }
}
int selection_sort(lista *l,int n)
{
    int k =0;
    cell *aux;
    cell* aux2 ,*aux3;
    
    aux= l->head;
    //laco while responsavel pelo indice onde sera colocado o menor numero do vetor 
    //na primeira vez o menor eh colocado no primeiro indice, depois no segundo ate chegar no ultimo indice
    while (k != n-1) //enquanto nao chegar no ultimo indice nao parar;
    {
        aux = l->head;
        while(aux->i !=k)
        {
            aux = aux->next;
           // printf("%d",aux->i);
        }
        aux3 = aux2 = aux;
         while (aux2->next !=NULL)//laco  que vai selecionar o nome de menor valor, para entao colocar no indice no inicio
        {
         
         if( strcmp(aux2->next->nome,aux3->nome) <0 )
         {
            aux3 = aux2->next ;
         }
        aux2 =aux2->next;  
            
        
        }
        trocar_nome(aux,aux3);
        k++;
    }
    return 1;
    
}
int main() {
int  n;
char nome[15];
    cell *aux;
    lista * l = criar_lista();
    scanf("%d",&n);
    gets(nome);
    for (int i=0;i<n;i++)
    {
        gets(nome);
        aux = criarCell(i, nome);  
       // printf ("%s %d",nome ,i);
        if(i ==0)
        {
            l->head = aux;
            
        }else{
            inserir_Cell(l,aux);
        }
        
    }
   selection_sort(l, n);
    
    aux = l->head;
    for(int i=0;i<n;i++)
    {
    printf("%s \n",aux->nome);
        aux = aux->next;
    }
    
    
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
