#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


typedef struct esfera{
    float raio,area,volume,diametro;
}Esfera;

void atualizar_esfera(Esfera *e, float r ){

    e->raio = r;
    e->diametro = 2*r;
    e->volume = (3*3.14*r*r*r)/4;
    e->area = 4*3.14*r*r;
   
}
int main(){
 Esfera E;

 float r;

scanf("%f" ,&r);
atualizar_esfera(&E,r);
printf("raio: %.1f\narea: %.1f\nvolume: %.1f\ndiametro: %.1f",E.raio,E.area,E.volume,E.diametro);
    return 0 ;
}
