#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include<stdbool.h>
#include"snake.h"
#define LIN 30
#define COL 50


int cabecaX = LIN/2, cabecaY = COL/2;
int caudaX, caudaY;
int direcao = -1;
int valor = 0, tamanho = 0, cont, vet[2] = {0,0};
no *aux_mov;
no *comida;
no *cls;
no *ant;
no *update;

enum Direcao_snake{CIMA, BAIXO, ESQUERDA, DIREITA};

void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void HideCursor()
{
  CONSOLE_CURSOR_INFO cursor = {1, FALSE};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}

void cria_campo(char campo[LIN][COL]){
	for(int i = 0; i < LIN; i++){
		for(int j = 0; j < COL; j++){
			if(i == 0 || i == LIN - 1)
				campo[i][j] = '#';
			else{
				if(j == 0 || j == COL - 1)
					campo[i][j] = '#';
			}
		}
	}
}

void printa_tela(char campo[LIN][COL]){
	for(int i = 0; i < LIN; i++){
		for(int j = 0; j < COL; j++){
			printf("%c", campo[i][j]);
		}
		printf("\n");
	}
}

void colore(){
	system("cls");
	char editar;
	int fundo, cor_principal;
	printf("deseja editar as cores do jogo? 's' ou 'n'\n");
	fflush(stdin);
   scanf("%c", &editar);
    	if(editar == 's' || editar == 'S'){
    		printf("escolha cores:\n");
    		printf("escolha cores para o fundo:\n'0' para preto\n'1' para branco\n'2' para cinza\n");
    		scanf("%d", &fundo);
    		printf("escolha a cor principal:\n'0' para verde\n'1' para vermelho\n'2' para amarelo\n");
    		scanf("%d", &cor_principal);
    		switch(fundo){
    			case 0:
    				switch(cor_principal){
    					case 0:
    						system("color 0A");
    						break;
    					case 1:
    						system("color 04");
    						break;
    					case 2:
    						system("color 06");
    						break;
    					default:
    						printf("entrada invalida\n");
    						colore();
    				}
    				break;
    			case 1:
    				switch(cor_principal){
    					case 0:
    						system("color 7A");
    						break;
    					case 1:
    						system("color 74");
    						break;
    					case 2:
    						system("color 76");
    						break;
    					default:
    						printf("entrada invalida\n");
    						colore();
    				}
    				break;
    			case 2:
    				switch(cor_principal){
    					case 0:
    						system("color 8A");
    						break;
    					case 1:
    						system("color 84");
    						break;
    					case 2:
    						system("color 86");
    						break;
    					default:
    						printf("entrada invalida\n");
    						colore();
    				}
    				break;
    			default:
    				printf("entrada invalida\n");
    				colore();
    		}	
    	}
    	else{
    		if(editar == 'n' || editar == 'N')
    			return;
    		else{
    			printf("entrada invalida\n");
    			colore();
    		}
    	}
}	
void ini_food(food *fd){
	int x = 0;
	int y = 0;
	int valor = 0;
}	

void coloca_comida(food *fd, no **f){
	comida = *f;
	fd->x = 1 + rand() % 28;
	fd->y = 1 + rand() % 48;
	while(comida != NULL){
		if(fd->x == comida->x && fd->y == comida->y)
			coloca_comida(fd, &(*f));
		comida = comida->next;
	}
	fd->valor = 1 + rand() % 9;
	gotoxy(fd->y, fd->x);
	printf("%d", fd->valor);
	valor = fd->valor;
}

void controles(){
		switch(getch()){
			case 'w':
				direcao = CIMA;
				break;
			case 's':
				direcao = BAIXO;
				break;
			case 'a':
				direcao = ESQUERDA;
				break;
			case 'd':
				direcao = DIREITA;
				break;
			case 'W':
				direcao = CIMA;
				break;
			case 'S':
				direcao = BAIXO;
				break;
			case 'A':
				direcao = ESQUERDA;
				break;
			case 'D':
				direcao = DIREITA;
				break;
		}
}

bool bateu(){
	if(cabecaY == 0 || cabecaY == COL-1 || cabecaX == 0 || cabecaX == LIN -1){
		return true;
		
	}
	else
		return false;
}

bool detecta_colisao(no **f){
	if((*f)->next == NULL)
		return false;
	else{
		cls = (*f)->next;
		while(cls != NULL){
			if(cls->x == cabecaX && cls->y == cabecaY)
				return true;
			cls = cls->next;
		}
		return false;
	}
}

void desenha_cobra(no **f){
	insere_last(&(*f), cabecaX, cabecaY, 0);
	caudaX = cabecaX;
	caudaY = cabecaY;
	gotoxy(cabecaY, cabecaX);
	printf("o");
	tamanho++;
}

void velocidade(){
	cont = 0;
	for(int i = 5; i < 30; i = (i + 5)){
		if(tamanho < i)
			switch(cont){
				case 0: 
					Sleep(300);
					return;
				case 1: 
					Sleep(250);
					return;
				case 2:
					Sleep(200);
					return;
				case 3:
					Sleep(150);
					return;
				case 4:
					Sleep(100);
					return;
				case 5:
					Sleep(50);
					return;
			}
		else
			cont++;
	}
}	

void atualiza_cobra(no **f){
	update = *f;
	insere_last(&(*f), caudaX, caudaY, valor);
	while(update->next != NULL)
		update = update->next;
	caudaX = update->x;
	caudaY = update->y;
	tamanho++;
}


void mov(food *fd, no **f){
	aux_mov = *f;
	do{

		gotoxy(caudaY, caudaX);
		printf(" ");

		switch(direcao){
			case CIMA:
				cabecaX--;
				break;
			case BAIXO:
				cabecaX++;
				break;
			case ESQUERDA:
				cabecaY--;
				break;
			case DIREITA:
				cabecaY++;
				break;
		}	
		aux_mov->x = cabecaX;
		aux_mov->y = cabecaY;

		if(detecta_colisao(&(*f)) == true)
			end_game(&(*f));

		do{
			gotoxy(aux_mov->y, aux_mov->x);
			printf("o");
			if(aux_mov->next != NULL){
				aux_mov = aux_mov->next;
			}
			else
				goto continua;
		}while(aux_mov != NULL);

		continua:
		caudaX = aux_mov->x;
		caudaY = aux_mov->y;

		if(aux_mov->prev != NULL){
			ant = aux_mov->prev;
		}
		else
			goto pula;

		do{
			vet[0] = ant->x;
			vet[1] = ant->y;
			aux_mov->x = vet[0];
			aux_mov->y = vet[1];
			aux_mov = aux_mov->prev;
			if(ant->prev != NULL)
				ant = ant->prev;
		}while(aux_mov != (*f));

		pula:
		velocidade();

		if(cabecaX == fd->x && cabecaY == fd->y){
			atualiza_cobra(&(*f));
			coloca_comida(fd, &(*f));
			
		}
	}while(!kbhit() && bateu() == false);
}

void start_snake(char campo[LIN][COL], no **f, food *fd){
	system("cls");
	HideCursor();
	printa_tela(campo);
	coloca_comida(fd, &(*f));
	desenha_cobra(&(*f));
	do{
		controles();	
		mov(fd, &(*f));
	}while(bateu() == false);
	end_game(&(*f));
}				


void end_game(no **f){
	gotoxy(0, LIN+1);
	print(&(*f));
	printf("\nSeu placar eh: %d pontos\n", tamanho);
	system("color 07");
	limpa_lista(&(*f));
	free(aux_mov);
	free(update);
	free(ant);
	free(comida);
	free(cls);
	exit(1);
}