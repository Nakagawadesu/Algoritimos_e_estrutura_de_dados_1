#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int mdc(int n1,int n2)
{
    if (n1==0)
    {
        return n2;
    }
    if(n2==0)
    {
        return n1;
    }
    if(n1 ==n2)
    {
        return n1;
    }
    else if(n1>n2)
    {
        return mdc(n2,n1%n2);
    }
    else if(n2>n1)
    {
        return mdc(n1,n2%n1);
    }
    return 0;
}

int main() {
    int n1,n2;
    scanf("%d %d", &n1,&n2);
    printf("%d",mdc(n1,n2));
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
