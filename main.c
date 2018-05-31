//
//  main.c
//  PMD_tarea1_limpio
//
//  Created by Mac User on 31/05/18.
//  Copyright © 2018 Mac User. All rights reserved.
//

#include <stdio.h>
#include <string.h>
typedef struct{
    char nombre[15];
    float calificacion;
} Profesor;

void readArray(Profesor *P,int n);
void printArray(Profesor *P,int n);
void mergeArrays(Profesor P1[20],int n1,Profesor *P2,int n2,Profesor P3[40],int n3);   //aqui el P1 esta como arreglo y P2 como apuntador eso fue porque intente la condicional del merge por los dos caminos, dejando todo como arrays y todo como apuntadores 


int main(int argc, const char * argv[]) {
    Profesor arr1[20];
    Profesor arr2[20];
    Profesor arrF[40];
    Profesor *d1=arr1,*d2=arr2,*d3=arrF;
    int n1,n2;
    scanf("%d", &n1);
    readArray(d1,n1);
    scanf("%d", &n2);
    readArray(d2,n2);
    mergeArrays(arr1,n1,d2,n2,arrF,n1+n2);
    printArray(d3,n1+n2);
    
    
    return 0;
}
void readArray(Profesor *P,int n){
    int i;
    char temp;
    float t;
    for(i=0;i<n;i++){
        scanf("%c",&temp);
        scanf("%[^\n]",(P+i*5)->nombre);
        scanf("%f",&t);
        (P+i*5)->calificacion=t;
    }
}
void printArray(Profesor *P,int n){
    int i;
    for(i=0;i<n;i++)
        printf("%s  %f\n",(P+i*5)->nombre,(P+i*5)->calificacion);
}
void mergeArrays(Profesor P1[20],int n1,Profesor *P2,int n2,Profesor P3[40],int n3){
    int i,j,cont,k;
    for(i=0;i<n1;i++){
        cont=i+1;
        for(j=cont;j<n1;j++)
            //c1=&P1.nombre;
            //c1=(P1+i*5)->nombre;
            //c2=(P1+j*5)->nombre;
            if(strcmp(P1[i].nombre,P1[j].nombre)==0){
                //(P3+i*5)->nombre=c1;
                printf("equal\n");
                strcpy(P1[i].nombre,P3[i].nombre);
                break;
            }
            else{
                printf("diferent\n");
                strcpy(P1[i].nombre,P3[i].nombre);
            }
        for(k=0;k<n2;k++){
            if(strcmp(P1[i].nombre,P2[k].nombre)==1){
                strcpy(P1[i].nombre,P3[i].nombre);
                break;
            }
            else{
                printf("diferent\n");
                strcpy(P1[i].nombre,P3[i].nombre);
            }
        }
    }
}
