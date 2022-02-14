
#include <stdio.h>
2
#include <string.h>
3
#include <math.h>
4
#include <stdlib.h>
5
​
6
typedef struct Cell{
7
       struct Cell *next;
8
       int valor;
9
       int col;
10
   }Cell; 
11
typedef struct {
12
        Cell *head;
13
}Lista;
14
​
15
​
16
typedef struct {
17
       int n_lines;
18
       int n_cols;
19
       Lista **line;//ponteiro para o penteiro Lista , no caso as linhas da matriz esparsa
20
}MatSpa; 
21
​
22
MatSpa * criarMat(int lin,int col )
23
{
24
    MatSpa* mat =(MatSpa*) malloc(sizeof(MatSpa));
25
    mat->n_lines =lin ;
26
    mat->n_cols = col;
27
    mat->line = (Lista**) malloc(sizeof(Lista*) * lin);
28
    for (int i = 0; i < lin; i++){
29
            mat->line[i] = (Lista*) malloc(sizeof(Lista));
30
            mat->line[i]->head = NULL;
31
        }
32
​
33
        return mat;
34
    
35
}
36
Cell* criar_celula(int item, int col){
37
    Cell *nova = (Cell*) malloc(sizeof(Cell));
38
    nova->valor = item;
39
    nova->col = col;
40
    nova->next = NULL;
41
​
42
    return nova;
43
}
44
Lista * criar_Lista(){
45
    Lista * l = (Lista*)malloc(sizeof(Lista));
46
    return l;
47
}
48
​
49
int verificar_diagonal(MatSpa * M)
50
{
51
    int contador= 0;
52
    Cell * aux;
53
    if(M->n_lines!= M->n_cols)
54
    {
55
        printf("nao diagonal");
56
        return 0;
57
    }
58
    for (int i =0 ;i< M->n_lines;  i++)
59
    {
60
        aux = M->line[i]->head;
61
        if (aux!= NULL)
62
        {
63
        if(aux->next !=NULL)//existe uma celula nao nula depois da cabeca
64
        {
65
           printf("nao diagonal");
66
        return 0;
67
        }
68
        if (aux->col ==i && aux->next == NULL)//a celula head esta na diagonal e nao existere outra celula a direita
69
        {//pelo que  entendi nao precisa ter toda a diagonal diferente de zero basta que os itens que nao esta na diagonal sejam nulos
70
            
71
            contador++;
72
            
73
        }
74
        }
75
        
76
    }
77
    if (contador >=0 && contador <= M->n_lines)//se existe apenas numeros na diagonal e pelom menos um ou seja tudo nulo menos a diagonal
78
    {
79
       printf("diagonal");
80
    }
81
    else {printf("nao diagonal");}
82
    return contador;
83
}
84
​
85
int converter_esparsa(int *m ,MatSpa * mat,int lin ,int cols){
86
    Cell *aux ;     
87
    int offset;
88
    for (int i=0 ;i<lin;i++){
89
        
90
        for(int j =0;j<cols;j++){
91
            offset = i * cols + j;
92
           if(m[offset]!=0)
93
           {
94
               if(mat->line[i]->head == NULL)
95
               {
96
                   aux = criar_celula(m[offset],j);
97
                   mat->line[i]->head = aux;
98
                   
99
               }
100
               else{
101
                   aux =mat->line[i]->head;
102
                       
103
                   while(aux->next != NULL)
104
                   {
105
                       aux = aux-> next;
106
                       
107
                   }
108
                   
109
                   aux->next  = criar_celula(m[offset] , j);
110
                   
111
               }
112
               
113
           }
114
        
115
        }
116
    }
117
    return 1;
118
}
119
​
120
​
121
int main(){
122
    int lin ,cols,input;
123
    scanf("%d ",&lin);
124
    cols =lin;
125
    int offset;
126
    
127
    int *m = (int *)malloc(lin * cols * sizeof(int));
128
    
129
    
130
    for (int i=0 ;i<lin;i++){
131
        
132
        for(int j =0;j<cols;j++){
133
            offset = i * cols + j;
134
            scanf("%d",&input);
135
            m[offset] =input;
136
        }
137
    }
138
    /*
139
    //imprimir maqtrizz normal
140
    for (int i=0 ;i<lin;i++){
141
        
142
        for(int j =0;j<cols;j++){
143
            offset = i * cols + j;
144
            printf("%d",mat[offset]);
145
            
146
        }
147
    }
148
    */
149
    MatSpa * mat =criarMat(lin, cols);
150
    converter_esparsa(m, mat, lin, cols);
151
    
152
  verificar_diagonal(mat);
153
​
154
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
155
    return 0;
156
}
157
​
