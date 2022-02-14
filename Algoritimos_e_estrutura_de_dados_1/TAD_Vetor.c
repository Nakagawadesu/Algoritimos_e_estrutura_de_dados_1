#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int *v; 
    int q; 
    int n;
}Vetor;

Vetor * iniciar(int n)
{
    Vetor *V = (Vetor*)malloc(sizeof(Vetor));
    V->v =(int*)malloc(n*sizeof(int));
    V->q = 0;
    V->n= n;
    return V;
        
}

int inserir(Vetor *v, int x)
{
    
    v->v[v->q]=x;
    v->q++;
    return 1;
}


Vetor * intercalar(Vetor *v1, Vetor *v2){
  Vetor *V3;
   V3 = iniciar(v1->n+v2->n);
    int i=0,j=0,k=0;
     while(v1->q!=0 &&v2->q!=0)
     {
         if(v1->q!=0 && v2->q!=0 )
         {
             V3->v[i] = v1->v[j];
             v1->q--;
             V3->q++;
             i++;
             j++;
             
             V3->v[i] = v2->v[k];
             v2->q--;
             V3->q++;
             i++;
             k++;
             
         }
         if(v1->q==0 && v2->q!=0 )
         {
             while(v2->q!=0)
         {
             V3->v[i] = v2->v[k];
             k++;
             i++;
             v2->q--;
             V3->q--;
         }       
         }
         
         if(v1->q!=0 && v2->q==0 )
         {
             while(v1->q!=0)
         {
            V3->v[i] = v1->v[j];
             j++;
             i++;
             v1->q--;
             V3->q--; 
         }
         }
     }
    return V3;
    
}


Vetor * concatenar(Vetor *v1, Vetor *v2)
{
    Vetor *V3;
   V3 = iniciar(v1->n+v2->n);
    int j =0;
    for(int i =0;i<v1->n;i++)
    {
        V3->v[j]= v1->v[i];
        j++;
    }
     for(int i =0;i<v2->n;i++)
    {
        V3->v[j]= v2->v[i];
        j++;
    }
    return V3;
    
}


Vetor * subvetor(Vetor *v1, int ini, int fim)
{
    Vetor *Novo = (Vetor*)malloc(sizeof(Vetor));
      Novo->v  = (int*)malloc((fabs(fim -ini)+1)*sizeof(int));
    int j=0;
    for(int i = ini;i<=fim ;i++)
    {
         Novo->v[j]= v1->v[i];
         j++;
    }
    
    return Novo;
}

int main()
{
    int n;
    Vetor *V1,*V2;
    int input;
    scanf("%d",&n);
    V1=iniciar(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&input);
        inserir(V1,input);
    }
     scanf("%d",&n);
    V2=iniciar(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&input);
        inserir(V2,input);
    }
    int ini,fim;
    scanf("%d %d",&ini,&fim);
    /*for(int i=0; i<V2->n ;i++)
    {
        printf("%d",V2->v[i]);
    }
    */
    Vetor *V3;
    V3 = intercalar(V1, V2);
    for(int i=0; i<V3->n ;i++)
    {
        printf("%d ",V3->v[i]);
    }
    free(V3);
    printf("\n");
    V3= concatenar(V1, V2);
    for(int i=0; i<V3->n ;i++)
    {
        printf("%d ",V3->v[i]);
    }
     printf("\n");
    free(V3);
    V3= subvetor(V1,  ini, fim);
    for(int i = 0;i<= fabs(fim -ini);i++)
    {
        printf("%d ",V3->v[i]);
    }
     printf("\n");
    return 0;
}
