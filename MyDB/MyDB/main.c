//
//  main.c
//  MyDB
//
//  Created by Mac User on 19/06/18.
//  Copyright © 2018 Mac User. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int dia;
    int mes;
    int ano;
}Fecha;
typedef struct{
    int id_cliente;
    char nombre[10];
    char apellidoP[10];
    char apellidoM[10];
    Fecha f;
}Cliente;
typedef struct{
    int id_cuenta;
    char id_usuario;
    int saldo;
    Fecha f_apertura;
}Cuenta;
typedef struct{
    int id_transaccion;
    char tipo[20];
    int cuenta_origen;
    int cuenta_destino;
    Fecha f_transaccion;
    int monto;
}Transaccion;

int main(void) {
    
    char ruta1[400],ruta2[400],ruta3[400],ruta4[400],rutF[400],temp[400];
    printf("ruta de carpeta: \n");
    scanf("%[^\n]",&rutF);
    scanf("%c",&temp);
    
    strcpy(ruta1,rutF);
    strcpy(ruta2,rutF);
    strcpy(ruta3,rutF);
    strcpy(ruta4,rutF);
    
    strcat(ruta1,"/clientes.dat");
    strcat(ruta2,"/cuentas.dat");
    strcat(ruta3,"/transacciones.dat");
    strcat(ruta4,"/mydb.sys");
    
    FILE *clientes =fopen(ruta1,"ab+");
    if(clientes==NULL)
        return -1;
    
    FILE *cuentas =fopen(ruta2,"ab+");
    if(cuentas==NULL)
        return -1;
    
    FILE *transacciones =fopen(ruta3,"ab+");
    if(transacciones==NULL)
        return -1;
    
    FILE *mydb =fopen(ruta4,"wb+");
    if(mydb==NULL)
        return -1;
    fwrite(rutF,sizeof(char),400,mydb);
    
    fclose(clientes);
    fclose(cuentas);
    fclose(transacciones);
    fclose(mydb);

    //    /Users/macuser/Desktop/Codes/PE_chess/PMD2018/MyDB/
   
    int flag=1,flag2=1,option,option2;
    while(flag){
        printf("<< Sistema MyDB >>\n");
        printf("1. Clientes\n");
        printf("2. Cuentas\n");
        printf("3. Transacciones\n");
        printf("4. Salir\n");
        scanf("%d",&option);
        fflush(stdout);
        switch(option){
            case 1:
                while(flag2){
                    printf("1. Nuevo cliente\n");
                    printf("2. Buscar cliente\n");
                    printf("3. Eliminar cliente\n");
                    printf("4. Imprimir clientes\n");
                    printf("5. Salir\n");
                    scanf("%d",&option2);
                    fflush(stdout);
                    switch(option2){
                        case 1:{
                            int temp3;
                            FILE *clientes = fopen(ruta1,"ab+");
                            if(clientes==NULL)
                                return -1;
                            fseek(clientes,-1*sizeof(Cliente),SEEK_END);
                            Cliente c1;
                            fread(&c1,sizeof(Cliente),1,clientes);
                            c1.id_cliente++;
                            printf("nombre: \n");
                            scanf("%c",&temp);
                            scanf("%[^\n]",c1.nombre);
                            printf("apellido paterno: \n");
                            scanf("%c",&temp);
                            scanf("%[^\n]",c1.apellidoP);
                            printf("apellido materno: \n");
                            scanf("%c",&temp);
                            scanf("%[^\n]",c1.apellidoM);
                            scanf("%c",&temp);
                            printf("dia: \n");
                            scanf("%d",&temp3);
                            c1.f.dia=temp3;
                            printf("mes: \n");
                            scanf("%d",&temp3);
                            c1.f.mes=temp3;
                            printf("año: \n");
                            scanf("%d",&temp3);
                            c1.f.ano=temp3;
                            fwrite(&c1,sizeof(Cliente),1,clientes);
                            fclose(clientes);
                            break;
                        }
                        case 2:{
                            int which_id;
                            printf("cual quieres buscar: \n");
                            scanf("%d",&which_id);
                            FILE *clientes = fopen(ruta1,"rb");
                            if(clientes==NULL)
                                return -1;
                            Cliente c2;
                            fseek(clientes,-1*sizeof(Cliente),SEEK_CUR);
                            fread(&c2,sizeof(Cliente),1,clientes);
                            while(!feof(clientes)){
                                if(c2.id_cliente==which_id){
                                    printf("%d  ",c2.id_cliente);
                                    printf("%s  ",c2.nombre);
                                    printf("%s  ",c2.apellidoP);
                                    printf("%s  ",c2.apellidoM);
                                    printf("%d,",c2.f.dia);
                                    printf("%d,",c2.f.mes);
                                    printf("%d\n",c2.f.ano);
                                    break;
                                }
                                fread(&c2,sizeof(Cliente),1,clientes);
                            }
                            fclose(clientes);
                            break;
                        }
                        case 3:{
                            int which_id;
                            int i=0,j=0;
                            printf("cual deseas eliminar: \n");
                            scanf("%d",&which_id);
                            FILE *clientes = fopen(ruta1,"rb");
                            if(clientes==NULL)
                                return -1;
                            Cliente c2,arrcli[1000];
                            fread(&c2,sizeof(Cliente),1,clientes);
                            while(!feof(clientes)){
                                if(c2.id_cliente!=which_id){
                                    arrcli[i]=c2;
                                    i++;
                                }
                                fread(&c2,sizeof(Cliente),1,clientes);
                            }
                            fclose(clientes);
                            FILE *clientes1 = fopen(ruta1,"wb");
                            for(j=0;j<i;j++)
                                fwrite(&arrcli[j],sizeof(Cliente),1,clientes1);
                            fclose(clientes1);
                            break;
                        }
                        case 4:{
                            FILE *clientes = fopen(ruta1,"rb");
                            if(clientes==NULL)
                                return -1;
                            Cliente c2;
                            fread(&c2,sizeof(Cliente),1,clientes);
                            while(!feof(clientes)){
                                printf("%d  ",c2.id_cliente);
                                printf("%s  ",c2.nombre);
                                printf("%s  ",c2.apellidoP);
                                printf("%s  ",c2.apellidoM);
                                printf("%d,",c2.f.dia);
                                printf("%d,",c2.f.mes);
                                printf("%d\n",c2.f.ano);
                                fread(&c2,sizeof(Cliente),1,clientes);
                            }
                            fclose(clientes);
                            break;
                        }
                        case 5:
                            flag2=0;
                            break;
                    }
                }
                flag2=1;
                break;
            case 2:
                while(flag2){
                    printf("1. Nueva cuenta\n");
                    printf("2. Buscar cuenta\n");
                    printf("3. Eliminar cuenta\n");
                    printf("4. Imprimir cuentas\n");
                    printf("5. Salir\n");
                    scanf("%d",&option2);
                    switch(option2){
                        case 1:{
                            int temp;
                            FILE *cuentas = fopen(ruta2,"ab+");
                            if(cuentas==NULL)
                                return -1;
                            fseek(cuentas,-1*sizeof(Cuenta),SEEK_END);
                            Cuenta cu1;
                            fread(&cu1,sizeof(Cuenta),1,cuentas);
                            cu1.id_cuenta++;
                            printf("a que id de cliente pertenece la cuenta: \n");
                            scanf("%d",&temp);
                            cu1.id_usuario=temp;
                            printf("saldo: \n");
                            scanf("%d",&temp);
                            cu1.saldo=temp;
                            printf("dia apertura: \n");
                            scanf("%d",&temp);
                            cu1.f_apertura.dia=temp;
                            printf("mes apertura: \n");
                            scanf("%d",&temp);
                            cu1.f_apertura.mes=temp;
                            printf("año apertura: \n");
                            scanf("%d",&temp);
                            cu1.f_apertura.ano=temp;
                            FILE *clientes = fopen(ruta1,"rb");
                            if(clientes==NULL)
                                return -1;
                            Cliente c2;
                            fseek(clientes,-1*sizeof(Cliente),SEEK_CUR);
                            fread(&c2,sizeof(Cliente),1,clientes);
                            while(!feof(clientes)){
                                if(c2.id_cliente==cu1.id_usuario){
                                    fwrite(&cu1,sizeof(Cuenta),1,cuentas);
                                    fclose(cuentas);
                                    break;
                                }
                                fread(&c2,sizeof(Cliente),1,clientes);
                            }
                            fclose(clientes);
                            break;
                        }
                            
                            
                        case 2:{
                            int which_id;
                            printf("que cuanta quieres buscar: \n");
                            scanf("%d",&which_id);
                            FILE *cuentas = fopen(ruta2,"rb");
                            if(cuentas==NULL)
                                return -1;
                            Cuenta cu2;
                            fseek(cuentas,-1*sizeof(Cliente),SEEK_CUR);
                            fread(&cu2,sizeof(Cuenta),1,cuentas);
                            while(!feof(cuentas)){
                                if(cu2.id_cuenta==which_id){
                                    printf("%d  ",cu2.id_cuenta);
                                    printf("%d  ",cu2.id_usuario);
                                    printf("%d  ",cu2.saldo);
                                    printf("%d,",cu2.f_apertura.dia);
                                    printf("%d,",cu2.f_apertura.mes);
                                    printf("%d\n",cu2.f_apertura.ano);
                                    break;
                                }
                                fread(&cu2,sizeof(Cuenta),1,cuentas);
                            }
                            fclose(cuentas);
                            break;
                        }
                        case 3:{
                            int which_id;
                            int i=0,j=0;
                            printf("que cuenta quieres eliminar: \n");
                            scanf("%d",&which_id);
                            FILE *cuentas = fopen(ruta2,"rb");
                            if(cuentas==NULL)
                                return -1;
                            Cuenta cu2,arrcue[1000];
                            fread(&cu2,sizeof(Cuenta),1,cuentas);
                            while(!feof(cuentas)){
                                if(cu2.id_cuenta!=which_id){
                                    arrcue[i]=cu2;
                                    i++;
                                }
                                fread(&cu2,sizeof(Cuenta),1,cuentas);
                            }
                            fclose(cuentas);
                            FILE *cuentas1 = fopen(ruta2,"wb");
                            for(j=0;j<i;j++)
                                fwrite(&arrcue[j],sizeof(Cuenta),1,cuentas1);
                            fclose(cuentas1);
                            break;
                        }
                        case 4:{
                            FILE *cuentas = fopen(ruta2,"rb");
                            if(cuentas==NULL)
                                return -1;
                            Cuenta cu2;
                            fread(&cu2,sizeof(Cuenta),1,cuentas);
                            while(!feof(cuentas)){
                                printf("%d  ",cu2.id_cuenta);
                                printf("%d  ",cu2.id_usuario);
                                printf("%d  ",cu2.saldo);
                                printf("%d,",cu2.f_apertura.dia);
                                printf("%d,",cu2.f_apertura.mes);
                                printf("%d\n",cu2.f_apertura.ano);
                                fread(&cu2,sizeof(Cuenta),1,cuentas);
                            }
                            fclose(cuentas);
                            break;
                        }
                        case 5:
                            flag2=0;
                            break;
                    }
                }
                flag2=1;
                
                break;
            case 3:
                while(flag2){
                    printf("1. Déposito\n");
                    printf("2. Retiro\n");
                    printf("3. Transferencia\n");
                    printf("4. Salir\n");
                    scanf("%d",&option2);
                    switch(option2){
                        case 1:{
                            
                            int temp3;
                            FILE *transacciones = fopen(ruta3,"ab+");
                            if(transacciones==NULL)
                                return -1;
                            fseek(transacciones,-1*sizeof(Transaccion),SEEK_END);
                            Transaccion t1;
                            fread(&t1,sizeof(Transaccion),1,transacciones);
                            t1.id_transaccion++;
                            strcpy(t1.tipo,"deposito");
                            t1.cuenta_origen=NULL;
                            printf("cuenta destino: \n");
                            scanf("%d",&t1.cuenta_destino);
                            printf("dia transaccion: \n");
                            scanf("%d",&temp3);
                            t1.f_transaccion.dia=temp3;
                            printf("mes transaccion: \n");
                            scanf("%d",&temp3);
                            t1.f_transaccion.mes=temp3;
                            printf("año transaccion: \n");
                            scanf("%d",&temp3);
                            t1.f_transaccion.ano=temp3;
                            printf("monto: \n");
                            scanf("%d",&t1.monto);
                            
                            
                            Cuenta cu2,arrcue[1000];
                            int i=0,j;
                            FILE *cuentas = fopen(ruta2,"rb");
                            if(cuentas==NULL)
                                return -1;
                            fseek(cuentas,-1*sizeof(Cuenta),SEEK_CUR);
                            fread(&cu2,sizeof(Cuenta),1,cuentas);
                            while(!feof(cuentas)){
                                if(cu2.id_cuenta==t1.cuenta_destino){
                                    cu2.saldo+=t1.monto;
                                    arrcue[i]=cu2;
                                    fwrite(&t1,sizeof(Transaccion),1,transacciones);
                                    fclose(transacciones);
                                }
                                arrcue[i]=cu2;
                                i++;
                                fread(&cu2,sizeof(Cuenta),1,cuentas);
                            }
                            fclose(cuentas);
                            FILE *cuentas1 = fopen(ruta2,"wb");
                            for(j=0;j<i;j++)
                                fwrite(&arrcue[j],sizeof(Cuenta),1,cuentas1);
                            fclose(cuentas1);
                            break;
                        }
                        case 2:{
                            int temp3;
                            FILE *transacciones = fopen(ruta3,"ab+");
                            if(transacciones==NULL)
                                return -1;
                            fseek(transacciones,-1*sizeof(Transaccion),SEEK_END);
                            Transaccion t1;
                            fread(&t1,sizeof(Transaccion),1,transacciones);
                            t1.id_transaccion++;
                            strcpy(t1.tipo,"retiro");
                            t1.cuenta_destino=NULL;
                            printf("cuenta origen: \n");
                            scanf("%d",&t1.cuenta_origen);
                            printf("dia transferencia: \n");
                            scanf("%d",&temp3);
                            t1.f_transaccion.dia=temp3;
                            printf("mes transferencia: \n");
                            scanf("%d",&temp3);
                            t1.f_transaccion.mes=temp3;
                            printf("año transferencia: \n");
                            scanf("%d",&temp3);
                            t1.f_transaccion.ano=temp3;
                            printf("monto: \n");
                            scanf("%d",&t1.monto);
                            
                            
                            Cuenta cu2,arrcue[1000];
                            int i=0,j;
                            FILE *cuentas = fopen(ruta2,"rb");
                            if(cuentas==NULL)
                                return -1;
                            fseek(cuentas,-1*sizeof(Cuenta),SEEK_CUR);
                            fread(&cu2,sizeof(Cuenta),1,cuentas);
                            while(!feof(cuentas)){
                                if(cu2.id_cuenta==t1.cuenta_origen){
                                    if(cu2.saldo>=t1.monto){
                                        cu2.saldo-=t1.monto;
                                        arrcue[i]=cu2;
                                        fwrite(&t1,sizeof(Transaccion),1,transacciones);
                                        fclose(transacciones);
                                    }
                                    else
                                        printf("saldo insuficiente");
                                }
                                arrcue[i]=cu2;
                                i++;
                                fread(&cu2,sizeof(Cuenta),1,cuentas);
                            }
                            fclose(cuentas);
                            FILE *cuentas1 = fopen(ruta2,"wb");
                            for(j=0;j<i;j++)
                                fwrite(&arrcue[j],sizeof(Cuenta),1,cuentas1);
                            fclose(cuentas1);
                            break;
                        }
                        case 3:{
                            int temp3;
                            FILE *transacciones = fopen(ruta3,"ab+");
                            if(transacciones==NULL)
                                return -1;
                            fseek(transacciones,-1*sizeof(Transaccion),SEEK_END);
                            Transaccion t1;
                            fread(&t1,sizeof(Transaccion),1,transacciones);
                            t1.id_transaccion++;
                            strcpy(t1.tipo,"transferencia");
                            printf("cuenta origen: \n");
                            scanf("%d",&t1.cuenta_origen);
                            printf("cuenta destino: \n");
                            scanf("%d",&t1.cuenta_destino);
                            printf("dia transferencia: \n");
                            scanf("%d",&temp3);
                            t1.f_transaccion.dia=temp3;
                            printf("mes transferencia: \n");
                            scanf("%d",&temp3);
                            t1.f_transaccion.mes=temp3;
                            printf("año transferencia: \n");
                            scanf("%d",&temp3);
                            t1.f_transaccion.ano=temp3;
                            printf("monto: \n");
                            scanf("%d",&t1.monto);
                            
                            
                            Cuenta cu2,cu3,arrcue[1000];
                            int i=0,j,k=0;
                            FILE *cuentas = fopen(ruta2,"rb");
                            if(cuentas==NULL)
                                return -1;
                            fseek(cuentas,-1*sizeof(Cuenta),SEEK_CUR);
                            fread(&cu2,sizeof(Cuenta),1,cuentas);
                            while(!feof(cuentas)){
                                
                                if(cu2.id_cuenta==t1.cuenta_origen){
                                    rewind(cuentas);
                                    fread(&cu3,sizeof(Cuenta),1,cuentas);
                                    while(!feof(cuentas)){
                                        if(cu3.id_cuenta==t1.cuenta_destino){
                                            if(cu2.saldo>=t1.monto){
                                                cu2.saldo-=t1.monto;
                                                cu3.saldo+=t1.monto;
                                                arrcue[k]=cu2;
                                                arrcue[i]=cu3;
                                                fwrite(&t1,sizeof(Transaccion),1,transacciones);
                                                fclose(transacciones);
                                            }
                                            else
                                                printf("saldo insuficiente");
                                        }
                                        arrcue[i]=cu3;
                                        i++;
                                        fread(&cu3,sizeof(Cuenta),1,cuentas);
                                    }
                                    break;
                                }
                                k++;
                                fread(&cu2,sizeof(Cuenta),1,cuentas);
                            }
                            fclose(cuentas);
                            FILE *cuentas1 = fopen(ruta2,"wb");
                            for(j=0;j<i;j++)
                                fwrite(&arrcue[j],sizeof(Cuenta),1,cuentas1);
                            fclose(cuentas1);
                            break;
                        }
                        case 4:
                            flag2=0;
                            break;
                    }
                }
                flag2=1;
                break;
            case 4:
                flag=0;
                break;
        }
    }
    return 0;
}



