/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.c
 * Author: Christopher
 *
 * Created on February 7, 2020, 10:39 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

/**
 * Funcao para adicionar cliente
 * @param Clientes, apontador para a estrutura de cliente
 * @param n_clientes, numero de clientes
 * @param n_max, numero maximo
 */
void addClient(struct Cliente **Clientes, int *n_clientes, int *n_max){
    struct Cliente * temp;
    int e_nif, existe;
    char empresa[3];
    
    if(*n_clientes == *n_max){
        temp=(struct Cliente*) realloc (*Clientes, sizeof(struct Cliente)*((*n_clientes) + MAX));
        
        if (temp == NULL){
            printf("Erro na realocacao! \n");
        }
        else{
            *Clientes = temp;
            *n_max = (*n_clientes) + MAX;
            printf("NIF do Cliente: ");
            scanf("%d",&e_nif);
            existe = verificarClient(*Clientes,*n_clientes,e_nif);
            if(existe == -1){
                (*Clientes)[*n_clientes].nif = e_nif;
                printf("Empresa: ");
                scanf("%s", empresa);
                if ((strcmp(empresa, "Sim") == 0) || (strcmp(empresa, "sim") == 0)){
                    strcpy((*Clientes)[*n_clientes].empresa, empresa);
                    printf("Nome da Empresa: ");
                    scanf("%s",&(*Clientes)[*n_clientes].nome);
                }
                else{
                    strcpy((*Clientes)[*n_clientes].empresa, empresa);
                    printf("Nome do Cliente: ");
                    scanf("%s",&(*Clientes)[*n_clientes].nome);
                    printf("Numero CC do Cliente: ");
                    scanf("%d",&(*Clientes)[*n_clientes].ncc);   
                }
                (*n_clientes)++;
            }
            else{
                printf("Esse NIF ja existe! \n");
            }
        }
    }
    else{
            printf("NIF do Cliente: ");
            scanf("%d",&e_nif);
            existe = verificarClient(*Clientes,*n_clientes,e_nif);
            if(existe == -1){
                (*Clientes)[*n_clientes].nif = e_nif;
                printf("Empresa: ");
                scanf("%s", empresa);
                if ((strcmp(empresa, "Sim") == 0) || (strcmp(empresa, "sim") == 0)){
                    strcpy((*Clientes)[*n_clientes].empresa, empresa);
                    printf("Nome da Empresa: ");
                    scanf("%s",&(*Clientes)[*n_clientes].nome);
                }
                else{
                    strcpy((*Clientes)[*n_clientes].empresa, empresa);
                    printf("Nome do Cliente: ");
                    scanf("%s",&(*Clientes)[*n_clientes].nome);
                    printf("Numero CC do Cliente: ");
                    scanf("%d",&(*Clientes)[*n_clientes].ncc);   
                }
                (*n_clientes)++;
            }
            else{
                printf("Esse NIF ja existe! \n");
            }
    }
}

/**
 * Funcao para verificar se o nif do cliente ja existe
 * @param Clientes, apontador para a estrutura de cliente
 * @param n_clientes, numero de clientes
 * @param e_nif, variavel que ira ser usada para verificar o nif dos clientes
 * @return 
 */
int verificarClient(struct Cliente *Clientes, int n_clientes, int e_nif){
    int i, e;
    
    e= -1;
    
     for (i=0; i < n_clientes; i++){
        if (Clientes[i].nif == e_nif){
            e = i;
        }
        if (e == -1){
        }
     }
return e;
}

/**
 * Funcao para editar as informacoes dos clientes
 * @param Clientes, apontador para a estrutura de cliente
 * @param n_clientes, numero de clientes
 */
void editarClient(struct Cliente *Clientes, int n_clientes){
    int i, e_nif;
    
    printf("Introduza o NIF do Cliente: ");
    scanf("%d",&e_nif);
    
    i = verificarClient(Clientes, n_clientes, e_nif);
    
    if (i != -1){
        printf("-------------\n");
        if ((strcmp(Clientes[i].empresa, "Sim") == 0) || (strcmp(Clientes[i].empresa, "sim") == 0)){
            printf("Nome da Empresa: ");
            scanf("%s",&Clientes[i].nome);
            printf("NIF: ");
            scanf("%d",&Clientes[i].nif);
        }
        else{
            printf("Nome: ");
            scanf("%s",&Clientes[i].nome);
            printf("NIF: ");
            scanf("%d",&Clientes[i].nif);
            printf("CC: ");
            scanf("%d",&Clientes[i].ncc);
        }
        printf("-------------\n");   
    }
}

/**
 * Funcao para gravar as informacoes para um ficheiro
 * @param Clientes, apontador para a estrutura de cliente
 * @param n_clientes, numero de clientes
 */
void gravarfc(struct Cliente *Clientes, int n_clientes){
    FILE * f;
    
    int i;
    
    f = fopen ("informacoes.txt","w");
    
    if (f == NULL){
        printf("Nao foi possivel abrir o ficheiro! \n");
    }
    else{
        fwrite(&n_clientes,sizeof(int),1,f);
        i=fwrite(Clientes, sizeof(struct Cliente),n_clientes,f);
        printf("Escreveu no ficheiro %d cliente(s). \n", i);
        fclose(f); 
    }
}

/**
 * Funcao para carregar as informacoes para um ficheiro
 * @param Clientes, apontador para a estrutura de cliente
 * @param n_clientes, numero de clientes
 * @param n_max, numero maximo
 */
void carregarfc(struct Cliente **Clientes, int *n_clientes, int *n_max){
    FILE * f;
    int i, nclientes;
    struct Cliente * clientTemp;
    
    f = fopen ("informacoes.txt", "r");
    
    if (f == NULL){
        printf("Nao foi possivel carregar o ficheiro! \n");
    }
    else{
        nclientes= fread (n_clientes,sizeof(int),1,f);
        if (nclientes == 0){
            printf("Erro na leitura do ficheiro! \n");
    }
        else{
            clientTemp = (struct Cliente*) realloc (*Clientes,sizeof(struct Cliente) * (*n_clientes + MAX));
    
                if (clientTemp==NULL){
                    printf("Erro ao carregar o ficheiro! \n");
                }
                else{ 
                    *Clientes = clientTemp;
                    *n_max = *n_clientes + MAX;
                    i = fread(*Clientes, sizeof(struct Cliente),*n_clientes,f);
                    printf(" %d Clientes carregados com sucesso. \n", i);
                    *n_clientes = i; 
                    fclose(f); 
                }
            }
    }
}

/**
 * Funcao para listar os clientes
 * @param Clientes, apontador para a estrutura de cliente
 * @param n_clientes, numero de clientes
 */
void listarClient(struct Cliente *Clientes, int n_clientes){
    int i;

    for (i = 0; i<n_clientes;i++){
        printf("-------------\n");
        if ((strcmp(Clientes[i].empresa, "Sim") == 0) || (strcmp(Clientes[i].empresa, "sim") == 0)){
            printf("Empresa: %s \n",Clientes[i].nome);
            printf("NIF: %d \n",Clientes[i].nif);
        }
        else{
            printf("Nome: %s \n",Clientes[i].nome);
            printf("NIF: %d \n",Clientes[i].nif);
            printf("CC: %d \n",Clientes[i].ncc);   
        }

    }
    printf("-------------\n");
}

/**
 * Listar os clientes de empresa
 * @param Clientes, apontador para a estrutura de cliente
 * @param n_clientes, numero de clientes
 */
void listarClientEmpresa(struct Cliente *Clientes, int n_clientes){
    int i;

    for (i = 0; i<n_clientes;i++){
        printf("-------------\n");
        if ((strcmp(Clientes[i].empresa, "Sim") == 0) || (strcmp(Clientes[i].empresa, "sim") == 0)){
            printf("Empresa: %s \n",Clientes[i].nome);
            printf("NIF: %d \n",Clientes[i].nif);
        }
    }
    printf("-------------\n");
}