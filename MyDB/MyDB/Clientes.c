//
//  Clientes.c
//  MyDB
//
//  Created by Mac User on 19/06/18.
//  Copyright © 2018 Mac User. All rights reserved.
//

#include "Clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct strCliente{
    int id_cliente;
    char nombre[10];
    char apellidoP[10];
    char apellidoM[10];
    Fecha f;
};

Cliente newCliente(char ruta[400]){
    Cliente clientetemp;
    FILE *clientes = fopen(ruta,"ab+");
    int i;
    while(!feof(clientes)){
        fread(&clientetemp,sizeof(struct strCliente),1,clientes);
        i++;
    }
    int temp;
    char temp2;
    Cliente new=(Cliente)malloc(sizeof(struct strCliente));
    //scanf("%d",&temp);
    new->id_cliente=i;
    scanf("%[^\n]",new->nombre);
    scanf("%c",&temp2);
    scanf("%[^\n]",new->apellidoP);
    scanf("%c",&temp2);
    scanf("%[^\n]",new->apellidoM);
    scanf("%c",&temp2);
    scanf("%d",&temp);
    new->f.dia=temp;
    scanf("%d",&temp);
    new->f.mes=temp;
    scanf("%d",&temp);
    new->f.ano=temp;
    fwrite(new,sizeof(struct strCliente),1,clientes);
    fclose(clientes);
    return new;
    
}

void printCliente(Cliente who){
    printf("%d\n",who->id_cliente);
    printf("%s\n",who->nombre);
    printf("%s\n",who->apellidoP);
    printf("%s\n",who->apellidoM);
    printf("%hd,",who->f.dia);
    printf("%hd,",who->f.mes);
    printf("%hd\n",who->f.ano);
    
}
