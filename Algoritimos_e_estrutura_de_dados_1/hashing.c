#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell{
       struct Cell *next;
       int valor;
       
   }Cell; 
typedef struct {
        Cell *head;
}Lista;


typedef struct {
       int B;//tamanho do bucket
       Lista **Bucket;//ponteiro para o penteiro Lista , no caso as linhas da matriz esparsa
}T_Hash; 

T_Hash * criarTHash(int T)
{
    T_Hash* H =(T_Hash*) malloc(sizeof(T_Hash));
    H->B = T ;
    H->Bucket = (Lista**) malloc(sizeof(Lista*) * T);
    for (int i = 0; i < T; i++){
            H->Bucket[i] = (Lista*) malloc(sizeof(Lista));
            H->Bucket[i]->head = NULL;
        }

        return H;
    
}
Cell* criar_celula(int item){
    Cell *nova = (Cell*) malloc(sizeof(Cell));
    nova->valor = item;
    nova->next = NULL;

    return nova;
}
int hashing(int k,int B)
{
    int h = k%B;
    return h;
}
int inserir_chave(int val ,T_Hash *H)
{
    int k = hashing(val,H->B);
    

    if(H->Bucket[k]->head== NULL)//caso simples se o bucket nao conter nada 
    {
        H->Bucket[k]->head = criar_celula(val);
        printf("%d\n",k);
    }
    else//caso que devera utilizar  ordenacao//
        //para inserir em ua ordem certa , a Celula proxima deve ser maior e anterior menor
    {
        Cell * aux1,*aux2;
        aux1=aux2= H->Bucket[k]->head;
        if(val < aux2->valor)//o novo valor tem que ser colocado antes
        {
          H->Bucket[k]->head =criar_celula(val); ;
            H->Bucket[k]->head->next = aux2;//next da nova cabbeca aponta para a antuga cabeca
        }
        else{//caso a acabeca nao seja menor basta checa se o novo valor se encaixa entre alguma celula
        while(aux1->next != NULL )
        {
            
            aux2 = aux1;
             aux1= aux1->next;
            if(aux1->valor > val && aux2->valor <val )//se antes de chegar na ultima celula encontrar um valor maior
            {
                Cell *c = criar_celula(val);
                aux2->next = c;//colocar celula entre as duas  celulas
                c->next= aux1;
            }
        }
        //checar para  a ultima e penultima celula tambem
        if(aux1->valor > val && aux2->valor <val )//se antes de chegar na ultima celula encontrar um valor maior
            {
                Cell *c = criar_celula(val);
                aux2->next = c;//colocar celula entre as duas  celulas
                c->next= aux1;
            }
        aux1->next = criar_celula(val);
        printf("%d\n",k);
        }
    }
   
   return 1; 
}


int imprimir_T(T_Hash * H)
{
   
    for (int i =0 ;i<H->B;i++)
    {
        Cell * aux;
        aux =H->Bucket[i]->head;
        if(aux ==NULL)
        {
          printf("%d: ->",i);
        }
        else{
            printf("%d: ",i);
        while(aux->next != NULL)
         {
           printf("-> %d ",aux->valor);
                //printf("%d  %d  ",i,aux->col);
            
        
            aux = aux->next;
           
               
         }
         printf("-> %d ",aux->valor);
        }
        printf("\n");
    }
    
   return 1 ;
}
int main() {
    int B,k,n;//b eh o tamanho da tabela, k o item a ser inserido e n o numero de chaves
    scanf("%d %d",&B,&n);
    T_Hash * h = criarTHash(B);
    for (int i =0;i<n;i++)
    {
     scanf("%d",&k);
        inserir_chave(k, h);
    }
    printf("\n");
    //ordenarT_Hash(h);
    imprimir_T(h);
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
