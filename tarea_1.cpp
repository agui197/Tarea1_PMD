//
//  main.cpp
//  PMD_tarea_1
//
//  Created by Mac User on 31/05/18.
//  Copyright © 2018 Mac User. All rights reserved.
//

#include <iostream>
typedef struct{
    char nombre[15];
    float calificacion;
} Profesor;

float averageArray(Profesor P,int n);
void readArray(Profesor P,int n);
void mergeArrays(Profesor,int,Profesor,int,Profesor,int);
void sortArray(Profesor,int);
void printArray(Profesor,int);


int main(){
    Profesor arr1[20];  //Primer arreglo
    Profesor arr2[20];  //Segundo arreglo
    Profesor arrF[40];  //Arreglo final, con elementos fusionados y ordenados
    Profesor *d=&arr1;
    int n1, n2; //Longitud de los arreglos
    scanf("%d", &n1);
    readArray(arr1[0],n1); //leer el primer arreglo
    //scanf("%d", &n2);
    //readArray(arr2[0],n2); //leer el segundo arreglo
    //mergeArrays(arr1[0],n1,arr2[0],n2,arrF[0],n1+n2);  //Fusionar los dos arreglos en un tercer arreglo
    /*
    sortArray(_____________);  //Ordenar los elementos del tercer arreglo, recuerde que pueden
    //existir profesores repetidos
    */
    printArray(arr1[0],n1);   //Imprimir el resultado final
    
    return 0;
}
void readArray(Profesor P,int n){
    int i;
    Profesor *d=&P;
    char temp;
    float t;
    for(i=0;i<n;i++){
        scanf("%c",&temp);
        scanf("%[^\n]",(d+i*5)->nombre);
        printf("%p",(d+i*5));
        scanf("%f",&t);
        (d+i*5)->calificacion=t;
    }
}
void printArray(Profesor P,int n){
    int i;
    Profesor *d=&P;
    for(i=0;i<n;i++){
        printf("%s  %f\n",(d+i*5)->nombre,(d+i*5)->calificacion);
    }
}
/*
float averageArray(Profesor P,int n){
    Profesor *d=&P;
    return ((d+n)+
}
 */
/*
void mergeArrays(Profesor P1,int n1,Profesor P2,int n2,Profesor P3,int n3){
    Profesor *d1=&P1,*d2=&P2,*d3=&P3;
    int i,j,cont=0;
    for(i=0;i<n1;i++){
        if((d1+cont*5)->nombre==(d1+i*5)->nombre){
            
        }
        for(j=0;j<n2;i++){
            
        }
    }
}
 */

