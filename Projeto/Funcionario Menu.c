/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Funcionario.c
 * Author: Christopher
 *
 * Created on February 7, 2020, 10:58 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

/**
 * Menu do Funcionario para criar reserva, novo cliente, guardar essas informacoes e editar clientes
 * @param Clientes, apontador para a estrutura de cliente 
 * @param n_clientes, numero de clientes
 * @param Reservas, apontador para a estrutura de reserva
 * @param n_reservas, numero de reserva
 * @param Quartos, apontador para a estrutura de quarto
 * @param n_quartos, numero de quartos
 * @param n_max, numero maximo
 * @param n_maxR, numero maximo
 */
void menuFuncionario(struct Cliente **Clientes, int *n_clientes, struct Reserva **Reservas,  int *n_reservas, struct Quarto **Quartos, int *n_quartos, int *n_max, int *n_maxR){
    
    int opcao;

    do {
        printf("*------------------------* \n");
        printf("       Funcionario         \n");
        printf("*------------------------* \n");
        printf("1 - Nova Reserva \n");
        printf("2 - Addicionar \n");
        printf("3 - Guardar \n");
        printf("4 - Editar \n");
        printf("0 - Recuar \n");
        do {
            printf("Escolha uma opcao >> ");
            scanf("%d", &opcao);
        }     
        while (opcao < 0 || opcao > 4);
        switch (opcao) {
            case 0:
                break;
                
            case 1: addReserva(Reservas, n_reservas, Quartos, n_quartos, n_maxR);
                break;

            case 2: addClient(Clientes, n_clientes, n_max);
                break;
                
            case 3: gravarfc(*Clientes, *n_clientes);
                    gravarfr(*Reservas, *n_reservas);
                break;
                
            case 4: editarClient(*Clientes, *n_clientes);
                break;
                
            default: puts("A opcao e invalida! \n");
        }
    }  
    while (opcao != 0);
}