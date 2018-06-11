//
//  main.c
//  tarea_2_PMD
//
//  Created by Mac User on 10/06/18.
//  Copyright © 2018 Mac User. All rights reserved.
//

#include <stdio.h>
#include <time.h>
/* //secuencial
int main(){
    
    clock_t start = clock();
    long long n=50000000000;
    long double x = 0.0;
    long long i;
    for(i=1;i<=n;i++){
        if((i&1)==1)
            x+=(long double)(1)/(long double)((2*i)-1);
        else
            x+=(long double)(-1)/(long double)((2*i)-1);
    }
    clock_t stop = clock();
    int ms = 1000 * (stop - start)/CLOCKS_PER_SEC;
    printf("Pi:     %.10Lf\n", 4*x);
    printf("Tiempo: %d ms\n", ms);
    return 0;
}
*/
//parametrizada
#include <stdlib.h>
#include <pthread.h>

typedef struct{
    long long inicio;
    long long fin;
    long double sumaParcial;
}Rango;

long double serieGregory(Rango);
void * suma(void *param);

int main(int argc, const char * argv[]) {
    
    clock_t start = clock();
    
    int nHilos,i,j=0;
    scanf("%d",&nHilos);
    long long incremento=50000000000/nHilos;
    Rango *rango =(Rango *)malloc(sizeof(Rango )*nHilos);
    rango->inicio=1;
    rango->fin=incremento;
    rango->sumaParcial=0.0;
    for(i=1;i<nHilos;i++){
        (rango+i)->inicio=(rango+j)->inicio+(rango+j)->fin;
        (rango+i)->fin=(rango+j)->fin+incremento;
        (rango+i)->sumaParcial=0.0;
        j+=1;
    }
    
    pthread_t *r =(pthread_t *)malloc(sizeof(pthread_t )*nHilos);
    for(i=0;i<nHilos;i++){
        *(r+i)=NULL;
        pthread_create(&r[i], NULL, suma, (void *) &rango[i]);
        pthread_join(r[i] , NULL);
    }
    long double resultado;
    for(i=0;i<nHilos;i++){
        resultado+=4*((rango+i)->sumaParcial);
    }
    
    clock_t stop = clock();
    
    int ms = 1000 * (stop - start)/CLOCKS_PER_SEC;
    printf("Hilos:  %d\n", nHilos);
    printf("Pi:     %.10Lf\n", resultado);
    printf("Tiempo: %d ms\n", ms);
    
    return 0;
}

void * suma(void *param){
    Rango *r=(Rango*)param;
    long long i;
    for(i=r->inicio;i<=r->fin;i++){
        if((i&1)==1)
            r->sumaParcial+=(long double)(1)/(long double)((2*i)-1);
        else
            r->sumaParcial+=(long double)(-1)/(long double)((2*i)-1);
    }
    return NULL;
}
