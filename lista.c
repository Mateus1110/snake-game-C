#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include<stdbool.h>
#include"snake.h"
#define LIN 30
#define COL 50


void texto(){
	system("cls");
	printf("como jogar:\naperte as teclas  w  s  a  d  para se mover para cima, baixo, esquerda e direita respectivamente, sua snake vai crescer conforme voce comer as comidas que sao os numeros que aparecem no campo durante o jogo. A velocidade da snake vai aumentar a cada 5 comidas ingeridas por ela. O jogo acaba se a snake colidir contra a parede ou ela mesma, no final sera mostrado qual tamanho sua snake atingiu e os valores das comidas que ela comeu, BOM JOGO!!!\n Aperte qualquer tecla para iniciar");
	getch();
}


void ini_lista(no **f){
	*f = NULL;
}

void insere_last(no **f, int x, int y, int valor){
	no *P;
	no *new_no = (no*)malloc(sizeof(no));
	new_no->x = x;
	new_no->y = y;
	new_no->info = valor;
	new_no->next = NULL;
	if(*f == NULL){
		new_no->prev = NULL;
	    *f = new_no;
	}
	else{
	   P = *f;
	   while(P->next != NULL)
	       P = P->next;
	   new_no->prev = P;
	   P->next = new_no;
	}
}


/*
void remove_node(no **L, int x){
	if(*L == NULL){
	   printf("lista vazia\n");
	   return;
	}
	else{
	    no *aux;
	    aux = *L;
	    no *pre;
	    pre  = *L;
	    while(aux->info != x){
	         pre = aux;
	         aux = aux->next;
	         if(aux == NULL){
		     printf("\nvalor nao encontrado\n");
		     return;
	         }
	    }
	    if(aux == *L && aux->info == x){ // 1ºvalor
		  *L = aux->next;
 		  free(aux);
	    }
	    else{
		// valor intermediario ou final
		  pre->next = aux->next;
	          free(aux);
				
	    }
	}
	    
}
*/
void print(no **L){
	no *aux = *L;
	printf("lista: ");
	while(aux != NULL){
	    printf("%d ", aux->info);
	    aux = aux->next;
	}
	printf("\n");
}

void limpa_lista(no **f){
	no *aux = *f;
	while((*f)->next != NULL){
		*f = (*f)->next;
		free(aux);
		aux = *f;
	}
	free(aux);
	free(*f);
}