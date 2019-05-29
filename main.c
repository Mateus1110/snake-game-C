#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include<stdbool.h>
#include"snake.h"
#define LIN 30
#define COL 50


void main(){
	no *f;
	food fd;
	ini_lista(&f);
	ini_food(&fd);
	srand(time(NULL));
	system("color 0A");
	
	char campo[LIN][COL] = {};
    cria_campo(campo);
    colore();
    texto();
	start_snake(campo, &f, &fd);
}
	



