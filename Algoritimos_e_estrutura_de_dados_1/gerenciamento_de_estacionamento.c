#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct Cell{
    struct Cell *next;
    int val;
    
}Cell;


typedef struct Fila{
    
   Cell *Primeiro;
   Cell *Ultimo;
}Fila;
Fila *CreateFila()
{
    Fila *F = (Fila*)malloc(sizeof(Fila));
    F->Primeiro =NULL;
    F->Ultimo =NULL;
return F;
}
Cell *Create_Cell(int val)
{
    Cell *C  = (Cell*)malloc(sizeof(Cell));
    C->val = val;
    C->next =NULL;
return C;

}
Fila* Enfileirar(int val,Fila *f){
    
    Cell *aux = Create_Cell(val);
   if(f->Primeiro==NULL)
   {
       f->Primeiro =aux;
       f->Ultimo= aux;
   }
   else{
       f->Ultimo->next = aux;
       f->Ultimo = aux;
   }
    return f;
}
int Desenfileirar(Fila *f){
 Cell *aux ;
  int val =0;
  
aux = f->Primeiro;
val = aux->val;
f->Primeiro = aux->next;
free(aux);
  return val;
 
}
void Encontrar_Carro(Fila *f,int valor)
{
    int contCarros=0;
    Cell *aux;
    Fila *Faux; // fila que armazena s caros movidos parae devolve para a oura fila depois
    
    aux = f->Primeiro;
    Faux = CreateFila();
    
    //tem que contar os carros para poder desenfileirar a fila de carros movidos posteriormente;
    //percorre do comeco da fila ate encontrar o carro
    while(aux->val != valor )
    {
        
        if(aux->next != NULL)
        {
        aux = aux->next;
            
            //printf("%d",aux->val);
   
            contCarros ++;
        }
        if(aux->next == NULL&& aux->val !=valor)
        {
        contCarros++;
        imprimir(f);
        printf("\n%d\n",contCarros);//carro nao existe
     printf("falha");
        exit(0);
        }
        
    }
  //Desenfileirar  carros 
    //e enfileirar nos carros tirados
    int i =0;
    while(i<contCarros)
    {
        Faux =Enfileirar(Desenfileirar(f),Faux);
        i++;
    }
    
    
    //remover o carro 
   
    Desenfileirar(f);
     
    //enfileira os carros da fila de carro removidos
    i=0;
    while (i<= contCarros-1)
    {
        f =Enfileirar(Desenfileirar(Faux),f);
        i++;
    }
    
   
    
    imprimir(f);
   printf("\n%d\n",contCarros);
   printf("sucesso");
   
}
void imprimir(Fila*f)
{
     Cell *aux;
    aux = f->Primeiro;

        while(aux != NULL) 
         {
         printf("%d ",aux->val);
         aux = aux->next;
         }
   
}
int main() {
    int input =0,car;
    Fila *f =CreateFila();
    while(input!= -1)
    {
        scanf("%d",&input);
        if(input!= -1)
        {
        Enfileirar(input,f);
    
        }
    }
    scanf("%d",&car);
    Encontrar_Carro(f,car);
     
    return 0;
}
