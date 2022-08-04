/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Faturas.c
 * Author: Christopher
 *
 * Created on February 8, 2020, 2:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/**
 * Menu das faturas para escolher se queremos a fatura mensal ou trimestral
 * @param Clientes, apontador para a estrutura de cliente
 * @param n_clientes, numero de clientes
 * @param Reservas, apontador para a estrutura de reserva
 * @param n_reservas, numero de reservas
 * @param Quartos, apontador para a estrutura de quarto
 * @param n_quartos, numero de quartos
 */
void menuFaturas(struct Cliente **Clientes, int *n_clientes,struct Reserva **Reservas, int *n_reservas){
     
     int opcao;
     
     do {
        printf("*------------------------* \n");
        printf("          Faturas          \n");
        printf("*------------------------* \n");
        printf("1 - Mensal \n");
        printf("0 - Recuar \n");
        do {
            printf("Escolha uma opcao >> ");
            scanf("%d", &opcao);
        }      
        while (opcao < 0 || opcao > 2);
        switch (opcao) {
            case 0:
                break;
                
            case 1: fmensal(*Reservas, *n_reservas, *Clientes, *n_clientes);
                break;

            default: puts("A opcao e invalida! \n");
        }
    }   
    while (opcao != 0);
}

/**
 * Imprimir a fatura mensal
 * @param Reservas, apontador para a estrutura de reserva
 * @param n_reservas, numero de reservas
 * @param Clientes, apontador para a estrutura de cliente
 * @param n_clientes, numero de clientes
 */
void fmensal(struct Reserva *Reservas, int n_reservas, struct Cliente *Clientes, int n_clientes){

    int i, e_nif, existe, numReserva, existeR;
    int x;

        printf("NIF do Cliente: ");
        scanf("%d",&e_nif);
        existe = verificarClient(*Clientes,n_clientes,e_nif);

    if (existe != 1){
        for (i=0; i < n_clientes ; i++){
            printf("*-----FATURA---*\n");
            printf("Nome: %s \n", Clientes[i].nome);
            printf("NIF: %d \n", Clientes[i].nif);

            printf("Numero da Reserva: ");
            scanf("%d",&numReserva);
            existeR = verificarReserva(*Reservas,n_reservas,numReserva);
               
            if(existeR != -1){
            for (x=0; x < n_reservas; x++){
                printf("Numero do quarto:%d \n", Reservas[x].numQuarto);
                printf("Numero de adultos:%d \n", Reservas[x].numAdultos);
                printf("Numero de crianças:%d \n", Reservas[x].numCriancas);
                printf("Numero de noites:   %d              \n", Reservas[x].numNoites);
                if ((strcmp(Reservas[x].pensao, "b")==0) || (strcmp(Reservas[x].pensao, "B")==0)){
                    printf("Pensao: Base \n");
                } else if ((strcmp(Reservas[x].pensao, "m")==0) || (strcmp(Reservas[x].pensao, "M")==0)){
                    printf("Pensao: Meia \n");
                } else if ((strcmp(Reservas[x].pensao, "c")==0) || (strcmp(Reservas[x].pensao, "C")==0)){
                    printf("Pensao: Completa \n");
                }
            }

            printf("Preco Total: %.2f \n",Reservas[x].precoTotal);
            printf("*------------*\n");
            }
        }

    } else {
        printf("NIF ou Reserva invalido! \n");
    }
}