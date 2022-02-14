#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
 
int * prog_arit(int n, int r)
{     
    
int *P =(int*) malloc(n*sizeof(int));
P[0]=0;
    for(int i=1;i<= n -1;i++ )
    {
        P[i] = P[i-1]+r;
    }
    return P;
}

int main() {

    int n,r;
    
    scanf("%d %d",&n,&r);

   
    int *p = prog_arit(n,r);
    for(int i =0 ;i<n;i++)
    {
     printf("%d ",p[i]);
    }
   
    
    return 0;
}
