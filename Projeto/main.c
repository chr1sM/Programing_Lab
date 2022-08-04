/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Christopher
 *
 * Created on February 7, 2020, 10:22 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

/**
 * Menu principal
 * @param argc
 * @param argv
 * @return 
 */

int main(int argc, char** argv) { 
    struct Cliente *Clientes;
    struct Reserva *Reservas;
    struct Quarto *Quartos;
    
    char utilizador[1];
    int n_clientes = 0, n_reservas = 0, n_quartos = 0;
    int opcao, n_max = 0, n_maxR = 0, n_maxQ = 0;
    Clientes = (struct Cliente *) malloc (sizeof (struct Cliente) * MAX);
    Reservas = (struct Reserva *) malloc (sizeof (struct Reserva) * MAX);
    Quartos = (struct Quarto *) malloc (sizeof (struct Quarto) * MAX);

    n_max = MAX;
    n_maxR = MAX;
    n_maxQ = MAX;
    
    if ((Clientes == NULL) || (Quartos == NULL) || (Reservas == NULL)){
        printf("Erro \n");
        exit(0);
    }

    do {
        printf("*------------------------* \n");
        printf("          Menu             \n");
        printf("*------------------------* \n");
        printf("1 - Login \n");
        printf("0 - Sair \n");
        do {
            printf("Escolha uma opcao >> ");
            scanf("%d", &opcao);
        }       
        while (opcao < 0 || opcao > 1);
        switch (opcao) {
            case 0: printf("A sair... \n");
                break;
                
            case 1: printf("Utilizador: ");
                    scanf("%s", &utilizador);
                    if((strcmp(utilizador, "F") == 0) || (strcmp(utilizador, "f") == 0)) {
                         carregarfc(&Clientes, &n_clientes, &n_max);
                         menuFuncionario(&Clientes, &n_clientes, &Reservas, &n_reservas, &Quartos, &n_quartos, &n_max , &n_maxQ, &n_maxR);
                    }
                    else if((strcmp(utilizador, "G") == 0) || (strcmp(utilizador, "g") == 0)){
                        carregarfc(&Clientes, &n_clientes, &n_max); 
                        carregarfq(&Quartos, &n_quartos, &n_maxQ);
                        carregarfr(&Reservas, &n_reservas, &n_maxR);
                        menuGestor(&Clientes, &n_clientes, &Reservas, &n_reservas,&Quartos, &n_quartos, &n_max , &n_maxQ, &n_maxR);
                    }
                    else {
                        printf("Utilizador errado! \n");
                    }
                   break;
                
            default: puts("A opcao e invalida! \n");
        }
    }   
    while (opcao != 0);
    free(Clientes);
    free(Reservas);
    free(Quartos);
    return (EXIT_SUCCESS);
}