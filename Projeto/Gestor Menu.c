/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Gestor.c
 * Author: Christopher
 *
 * Created on February 7, 2020, 11:13 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

/**
 * Menu para o gestor escolher caso queria entrar no menu dos quartos, faturas ou informacoes
 * @param Clientes, apontador para a estrutura de cliente
 * @param n_clientes, numero de clientes
 * @param Reservas, apontador para a estrutura de reserva
 * @param n_reservas, numero de reservas
 * @param Quartos, apontador para a estrutura de quarto
 * @param n_quartos, numero de quartos
 * @param n_max, numero maximo
 * @param n_maxQ, numero maximo
 * @param n_maxR, numero maximo
 */
void menuGestor(struct Cliente **Clientes, int *n_clientes, struct Reserva **Reservas, int *n_reservas, struct Quarto **Quartos, int *n_quartos,int *n_max, int *n_maxQ, int *n_maxR){
     
     int opcao;
     
     do {
        printf("*------------------------* \n");
        printf("          Gestor           \n");
        printf("*------------------------* \n");
        printf("1 - Quartos \n");
        printf("2 - Faturas \n");
        printf("3 - Informacoes \n");
        printf("0 - Recuar \n");
        do {
            printf("Escolha uma opcao >> ");
            scanf("%d", &opcao);
        }      
        while (opcao < 0 || opcao > 3);
        switch (opcao) {
            case 0:
                break;
                
            case 1: menuQuartos(Quartos, n_quartos, n_maxQ);
                break;
                
            case 2: menuFaturas(Clientes, n_clientes, Reservas, n_reservas, Quartos, n_quartos);
                break;
            
            case 3: menuInformacoes(Clientes, n_clientes, Reservas, n_reservas, Quartos, n_quartos);
                break;
                
            default: puts("A opcao e invalida! \n");
        }
    }   
    while (opcao != 0);
}