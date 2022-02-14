
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
 char c;
}Item;

typedef struct {
    Item Items[1000];
    int topo;
}Pilha;

Pilha* Criar()
{
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    
    p->topo = -1;
    //-1 pois quando adicionar 1 item : indice = topo =0,e assim por diante
    return p;
}
int pilha_cheia(Pilha *p){
 if (p == NULL)
        return -1;
    else if (p->topo == (1000 - 1))
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

int empilhar (Pilha *p,char C){

    Item Item;//struct auxiliar
      if (p == NULL){
        p = Criar();
      }

    if(pilha_cheia(p)==0)//pilha nao esta cheia
    {
        Item.c = C;
       
        p->topo++;
        p->Items[p->topo]=Item;
        return 1;
    }

    return 0;

}

Item* desempilhar (Pilha *p)
{
Item *Item1 = NULL;//ponteiro de item para guardar o item do topo
    if(!pilha_vazia(p))
    {
      Item1 = (Item*) malloc(sizeof(Item));

        *Item1 = p->Items[p->topo];//item do topo guardado

        p->topo--;//retira o item removido do topo

    }
    return Item1;
}

void imprimir_pilha(Pilha *p){
   
    Pilha aux = *p;//cira se um ponteiro de pilhas pois se tentar desempilhar a pilha originla, reduziremos o topo dela , nao queremos isso, ela deve ser mantida intacta
    Item *item1;

    while (!pilha_vazia(&aux)){
        item1 = desempilhar(&aux);

        printf("%c ", item1->c);

        if (item1 != NULL)
        free(item1);
    }
}
int main() {
    char  S[1000];
    
    Item *C,*C_anterior;
    char Parenteses;//char para armazenar o ultimo parenteses lido no laco while;
    C= (Item*)malloc(sizeof(Item));
    C_anterior= (Item*)malloc(sizeof(Item));
    int N;
    int j=0,contP1=0,contP2=0,contP=0;//parenteses
    Pilha *P;
    P=Criar();
scanf ("%d",&N);
    
    for(int i =0;i<N;i++)
    {
        scanf("%s",&S);
        //printf("%s\n",S);
       for (int i = 0; i < strlen(S); i++)
        {
            
            C->c = S[j];
          empilhar(P,C->c);
              j++;
           
        }
       // printf("%c",C->c);
       
        
        while(P->topo!=-1)
        {
            
            C=desempilhar(P);
           // printf("%c",C->c);
            if(C->c==40)
            {
                C_anterior->c= Parenteses;//guardandoo parenteses anterior
                contP1++;
                Parenteses= C->c;
            }
            if(C->c==41)
            {
                C_anterior->c= Parenteses;//guardandoo parenteeses anterior
                contP2++;
                Parenteses= C->c;
            }
            if(contP2==0 && contP1==1)//encontrou o primeiro ( sem estar ffechado na esquerda da string; 
            {
                
                break;
            }
            if(C->c==41&&C_anterior->c==40)//quer dizer que encontramos )( ou seja , temos quer pares deles no meio se existirem valores impares quer dizer que na estao fechados, se estver no canto sera identificado em outros ifs;
            {
                contP++;
               // printf("aa");
                //printf("%d %d",C->c,C_anterior->c);
            }
        }
       // printf("%d %d ",contP1,contP2);
        if(Parenteses ==41)//o ultimo parenteses encontrado foi );
        {
            printf("incorrect\n");
        }
         else if(contP1!=contP2){
            printf("incorrect\n");
        }
        else if(contP1%2!=0 && contP2%2!=0 &&contP%2!=0){
            printf("incorrect\n");
        }
        else if(contP1%2==0 && contP2%2==0 &&contP%2==0){
            printf("incorrect\n");
        }
        else if(contP1==contP2 &&contP%2==0)//se encontrado )( em pares o numero de pares de parenteses tem que ser igual 
        {
            printf("correct\n");
        }
        else if(contP1==contP2 && contP1%2==0&&contP2%2==0 &&contP%2!=0) //se enconrado um numero de pares de parenteses impar e )( em pares impares
        {
            printf("correct\n");
        }
       
       // printf("%d %d \n",contP1,contP2);
        contP1=0;contP2=0;
        j=0;
       
        
    }
    
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
