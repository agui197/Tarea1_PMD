//
//  Clientes.h
//  MyDB
//
//  Created by Mac User on 19/06/18.
//  Copyright © 2018 Mac User. All rights reserved.
//

#ifndef Clientes_h
#define Clientes_h

typedef struct{
    short dia;
    short mes;
    short ano;
}Fecha;

typedef enum {false,true} bool;

typedef struct strCliente *Cliente;

Cliente newCliente(char ruta[400]);

Cliente findCliente(int);

bool deleteCliente(int);

void printCliente(Cliente);



#endif /* Clientes_h */
