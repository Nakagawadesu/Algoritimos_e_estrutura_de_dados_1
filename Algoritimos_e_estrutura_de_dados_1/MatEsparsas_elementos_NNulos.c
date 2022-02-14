#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Cell{
       struct Cell *next;
       int valor;
       int col;
   }Cell; 
typedef struct {
        Cell *head;
}Lista;


typedef struct {
       int n_lines;
       int n_cols;
       Lista **line;//ponteiro para o penteiro Lista , no caso as linhas da matriz esparsa
}MatSpa; 

MatSpa * criarMat(int lin,int col )
{
    MatSpa* mat =(MatSpa*) malloc(sizeof(MatSpa));
    mat->n_lines =lin ;
    mat->n_cols = col;
    mat->line = (Lista**) malloc(sizeof(Lista*) * lin);
    for (int i = 0; i < lin; i++){
            mat->line[i] = (Lista*) malloc(sizeof(Lista));
            mat->line[i]->head = NULL;
        }

        return mat;
    
}
Cell* criar_celula(int item, int col){
    Cell *nova = (Cell*) malloc(sizeof(Cell));
    nova->valor = item;
    nova->col = col;
    nova->next = NULL;

    return nova;
}
Lista * criar_Lista(){
    Lista * l = (Lista*)malloc(sizeof(Lista));
    return l;
}

int Contar_nao_nulos(MatSpa * M)
{
    int contador= 0;
    for (int i =0 ;i<M->n_lines;i++)
    {
        Cell * aux;
        aux =M->line[i]->head;
        if(aux != NULL)
        {
              while(aux->next != NULL)
         {
            if (aux->valor != 0)
            {
                contador ++;
                //printf("%d  %d  ",i,aux->col);
            }
            aux = aux->next;
           
               
          }
             if (aux->valor != 0)
                {
                contador ++;
                   
                }
        }
      
        
    }
    return contador;
}

int converter_esparsa(int *m ,MatSpa * mat,int lin ,int cols){
    Cell *aux ;     
    int offset;
    for (int i=0 ;i<lin;i++){
        
        for(int j =0;j<cols;j++){
            offset = i * cols + j;
           if(m[offset]!=0)
           {
               if(mat->line[i]->head == NULL)
               {
                   aux = criar_celula(m[offset],j);
                   mat->line[i]->head = aux;
                   
               }
               else{
                   aux =mat->line[i]->head;
                       
                   while(aux->next != NULL)
                   {
                       aux = aux-> next;
                       
                   }
                   
                   aux->next  = criar_celula(m[offset] , j);
                   
               }
               
           }
        
        }
    }
    return 1;
}


int main() {
    int lin ,cols,input;
    scanf("%d %d",&lin,&cols);
    int offset;
    
    int *m = (int *)malloc(lin * cols * sizeof(int));
    
    
    for (int i=0 ;i<lin;i++){
        
        for(int j =0;j<cols;j++){
            offset = i * cols + j;
            scanf("%d",&input);
            m[offset] =input;
        }
    }
    /*
    //imprimir maqtrizz normal
    for (int i=0 ;i<lin;i++){
        
        for(int j =0;j<cols;j++){
            offset = i * cols + j;
            printf("%d",mat[offset]);
            
        }
    }
    */
    MatSpa * mat =criarMat(lin, cols);
    converter_esparsa(m, mat, lin, cols);
    
    printf("%d",Contar_nao_nulos(mat));

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
