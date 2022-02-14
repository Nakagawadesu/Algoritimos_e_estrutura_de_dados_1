#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
typedef struct {
    int valor;
}Item;

typedef struct {
     Item itens[100];
        int ini;
    int fim;
    int tam;
}Fila;

Fila  * criar_fila()
{
    Fila *f = (Fila*)malloc(sizeof(Fila));
    
    f->ini = -1;
    f->fim=-1;
    f->tam = 0;
    
    return f;
}
int fila_cheia(Fila *f){

    if (f == NULL)
        return -1; 
    else if (f->tam < 100)
        return 0; 
    else
        return 1; 
}


int fila_vazia(Fila *f){
    if (f == NULL)
        return -1; 
    else if (f->tam > 0)
        return 0; 
    else
        return 1; 
}
int enfileirar(Fila *f, int val){
    Item item;

    if (f == NULL)
        f = criar_fila();

    
    if (!fila_cheia(f)){
        item.valor = val;
        
        
        if (f->ini < 0)
            f->ini = 0;

        
        if (f->fim < 100 - 1)
            f->fim++;
        else
            f->fim = 0;

        
        f->itens[f->fim] = item;

     
        f->tam++;

        return 1; 
    }

    return 0;
}
Item* desenfileirar(Fila *f){
    Item *item = NULL;

    
    if (!fila_vazia(f)){
        item = (Item*) malloc(sizeof(Item));

        *item = f->itens[f->ini];

  
        if (f->ini < 100 - 1)
            f->ini++;
        else
            f->ini = 0;

        f->tam--;

        if (f->tam == 0){
            f->ini = -1;
            f->fim = -1;
        }
    }

    return item;
}
void imprimir_fila(Fila *f){
    
    Fila aux = *f;
    Item *item;

    
    while (!fila_vazia(&aux)){
        item = desenfileirar(&aux);

        printf("%d ", item->valor);

        
        free(item);
    }
}

void ler(Fila *F1,Fila *F2)
{ 
    int input =0;
     while (input !=-1)
    {
        scanf("%d",&input);
        if(input!=-1)
        {
            enfileirar(F1, input);
        }
    }
    input =0;
    while (input !=-1)
    {
        scanf("%d",&input);
        if(input!=-1)
        {
            enfileirar(F2, input);
        }
    }
    //imprimir_fila(F1);
   // imprimir_fila(F2);
    
    
    
    
}
Fila * intercalar(Fila *F1,Fila *F2,Fila *F3 )
{
    F3=criar_fila();
    
    Item *aux1,*aux2;
    
    while(F1->tam != 0 && F2 ->tam !=0)
    {
       
             aux1 = desenfileirar(F1);
        
        
             aux2 = desenfileirar(F2);
        
       if (aux2->valor==aux1->valor)
     {
       //  printf("%d    %d    ",F1->tam,F2->tam);
     enfileirar(F3,aux2->valor);
     enfileirar(F3,aux1->valor); 
       }
     
     else if(aux1->valor>aux2->valor)
     {
      enfileirar(F3,aux1->valor);
      enfileirar(F3,aux2->valor);
      }
      else if(aux2->valor>aux1->valor)
      {
     enfileirar(F3,aux2->valor);
     enfileirar(F3,aux1->valor);
      }
    
    }
     if(F2->tam !=0)
     {

     do{
          aux2 = desenfileirar(F2);
        enfileirar(F3, aux2->valor);
          
         // printf("aaa1");
      }while(F2->tam !=0);
     }
    if(F1->tam !=0)
     {
       do{
         aux1 = desenfileirar(F1);
        enfileirar(F3, aux1->valor);
         // printf("aaa2");
      }while(F1->tam !=0);
    }
    return F3;
}
int main() {

    Fila *F1,*F2,*F3;
    F1 =criar_fila();
    F2=criar_fila();
    
    ler(F1,F2);
    F3 =intercalar(F1, F2, F3);
    imprimir_fila(F3);
   // printf("%d %d" ,F1->tam ,F2->tam);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
