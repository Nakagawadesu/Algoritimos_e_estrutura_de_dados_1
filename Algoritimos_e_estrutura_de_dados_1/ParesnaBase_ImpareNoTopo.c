#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
 int valor;
}Item;

typedef struct {
    Item Items[10];
    int topo;
}Pilha;

Pilha* Alloc()
{
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    //topo recebe -1 pois quando adicionado 1, o valor funciona como um inddice 0 , e assim por diante;
    p->topo = -1;
    
    return p;
}
int pilha_cheia(Pilha *p){
 if (p == NULL)
        return -1;
    else if (p->topo == (10 - 1))
        return 1;
    else
        return 0;
}
int pilha_vazia(Pilha*p)
{
    if (p == NULL)
        return -1;
    else if (p->topo == -1)
        return 1;
    else
        return 0;
}

int empilhar (Pilha *p,int valor){

    Item Item;
      if (p == NULL){
        p = Alloc();
      }

    if(pilha_cheia(p)==0){
        Item.valor = valor;
        //como topo era -1 agora ele vai inserir no valor p->Items[0]
        p->topo++;
        p->Items[p->topo]=Item;
        return 1;
    }

    return 0;

}

Item* desempilhar (Pilha *p)
{
Item *Item1 = NULL;
    if(!pilha_vazia(p))
    {
      Item1 = (Item*) malloc(sizeof(Item));

        *Item1 = p->Items[p->topo];

        p->topo--;

    }
    return Item1;
}

void imprimir_pilha(Pilha *p){
   
    Pilha aux = *p;
    Item *item1;

    while (!pilha_vazia(&aux)){
        item1 = desempilhar(&aux);

        printf("%d ", item1->valor);

        if (item1 != NULL)
        free(item1);
    }
}

int main(){
    Pilha *P1,*P2;
  P1= Alloc();
  P2= Alloc();

  int input =0;
  while(input != -1)
  {
      scanf("%d",&input);
      if(input != -1)
      {
        empilhar(P1,input);
      }
      
  }
  input=0;
  while(input != -1)
  {
      scanf("%d",&input);
      if(input != -1)
      {
         empilhar(P2,input);
      }
  }

 /*  imprimir_pilha(P1);
  imprimir_pilha(P2); */
// criar uma pilha para os pares e uma para os impares
  Pilha *PPAR,*PIMPAR,*PF;
        

  PPAR= Alloc();
  PIMPAR= Alloc();
  PF= Alloc();
 Item *Item1;

        Item1 = (Item*) malloc(sizeof(Item));

 while(pilha_vazia(P1) != 1 )
{ 
  Item1 = desempilhar(P1);
  if(Item1->valor %2 != 0)
   {
   empilhar(PIMPAR,Item1->valor);
   }
   if(Item1->valor %2 == 0)
   {
   empilhar(PPAR,Item1->valor);
   }
}
while(pilha_vazia(P2) != 1 )
{
   Item1 = desempilhar(P2);
   if(Item1->valor %2 != 0)
   {
   empilhar(PIMPAR,Item1->valor);
   } 
   if(Item1->valor %2 == 0)
   {
   empilhar(PPAR,Item1->valor);
   }
 } 

/* imprimir_pilha(PPAR);
imprimir_pilha(PIMPAR); */
while(pilha_vazia(PIMPAR) != 1 )
{

    Item1 = desempilhar(PIMPAR);
    empilhar(PF,Item1->valor);
}
while(pilha_vazia(PPAR) != 1 )
{

    Item1 = desempilhar(PPAR);
    empilhar(PF,Item1->valor);
}



imprimir_pilha(PF);
}
