#include <string.h>  
#include <stdlib.h>  
#include <stdio.h>   
#include "uthash.h"
#include "med.h"
#include "ler.h"
#include "gravar.h"
#include <time.h>
#include "inserir.h"
#include "procura.h"
#include "actualizar.h"
#include "remover.h"
#include "sort.h"
#include "libertar.h"
#include <sys/time.h>
#include <sys/resource.h>
#include "fsmipc.c"

int ins,pro,actu,apagar,ordenar,grav;

int main(int argc, char *argv[]) {
    printf("Carregar a HashTable...\n\n");
    ler();
    char in[15];
    int running=1;
    int stock,max,quantidade;
    char nome[15];
    int modo;  
    while (running) {
	printf("\n");
        printf(" 1. Inserir\n");
        printf(" 2. Procurar\n");
        printf(" 3. Actualizar\n");
        printf(" 4. Apagar\n");
        printf(" 5. Ordenar\n");
        printf(" 6. Sair e Gravar\n");
	printf(" 7. Sair sem Gravar\n");
        gets(in);
        switch(atoi(in)) {
            case 1:    
		printf("Insira o Nome\n");
		gets(in); strcpy(nome,in);
		printf("Indique o Stock\n");
                gets(in); stock = atoi(in);
		ins = cria_semaforo(1234,1);
		P(ins);
                inserir(nome,stock);
		V(ins);
                break;
            case 2:
                printf("Nome que Deseja Procurar\n");	
		gets(in); strcpy(nome,in);
		pro = cria_semaforo(2345,1);
		P(pro);
                procurar(nome);
		V(pro);
                break;
            case 3:
		
		printf("Deseja Realizar uma Encomenda(1) ou uma Venda(2)");
		gets(in); modo= atoi(in);                
		printf("Insira o Nome\n");
		gets(in); strcpy(nome,in);
		printf("Indique a Quantidade\n");
                gets(in); quantidade= atoi(in);
                actu = cria_semaforo(3456,1);
		P(actu);
		 actualizar(nome,quantidade,modo);
		V(actu);
		break;
            case 4:
                printf("Nome que Deseja Remover\n");
		gets(in); strcpy(nome,in);
                apagar = cria_semaforo(4567,1);
		P(apagar);
		remover(nome);
		V(apagar);
                break;
            case 5:
                printf("Indique o Máximo do Top\n");
                gets(in); max = atoi(in);
                ordenar = cria_semaforo(5678,1);
		P(ordenar);
		sort(max);
		V(ordenar);
                break;
            case 6:
		grav = cria_semaforo(6789,1);
		P(grav);
		printf("A guardar ... ");
		gravar();
		V(grav);
                running=0;
                break;
	    case 7:
		printf("Deseja sair sem guardar ? [s/n]");
		gets(in); strcpy(nome,in);
		if(strcmp("s",nome) == 0){
			running=0;
		}else{
			running=1;
		}			
		break;
        }	
    }

    libertar();
    return 0;
}



