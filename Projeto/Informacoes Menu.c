/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Informacoes.c
 * Author: Christopher
 *
 * Created on February 8, 2020, 2:54 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "struct.h"

/**
 * Menu de informacoes, vai listar todos os quarto, clientes e reservas guardadas
 * @param Clientes, apontador para a estrutura de clientes
 * @param n_clientes, numero de clientes
 * @param Reservas, apontador para a estrutura de reservas
 * @param n_reservas, numero de reservas
 * @param Quartos, apontador para a estrutura de quarto
 * @param n_quartos, numero de quartos
 */
void menuInformacoes(struct Cliente **Clientes, int *n_clientes,struct Reserva **Reservas, int *n_reservas,struct Quarto **Quartos, int *n_quartos){
     
     int opcao;
     
     do {
        printf("*------------------------* \n");
        printf("       Informacoes         \n");
        printf("*------------------------* \n");
        printf("1 - Consultar Quartos \n");
        printf("2 - Consultar Clientes \n");
        printf("3 - Consultar Reservas \n");
        printf("4 - Consultar Quartos Ocupados \n");
        printf("5 - Consultar Quartos Manutencao \n");
        printf("5 - Consultar Reservas Superiro a 200$ \n");
        printf("0 - Recuar \n");
        do {
            printf("Escolha uma opção >> ");
            scanf("%d", &opcao);
        }      
        while (opcao < 0 || opcao > 3);
        switch (opcao) {
            case 0:
                break;
                
            case 1: listarQuarto(*Quartos, *n_quartos);
                break;
                
            case 2: listarClient(*Clientes, *n_clientes);
                break;
            
            case 3: listarReservas(*Reservas, *n_reservas);
                break;
                
            case 4: listarQuartoOcupados(*Reservas, *n_reservas);
                break;
                
            case 5: listarQuartoMenutencao(*Reservas, *n_reservas);
                break;
                
            case 6: listarReservasMaior200(*Reservas, *n_reservas);
                break;
                
            default: puts("A opcao e invalida! \n");
        }
    }   
    while (opcao != 0);
}
