#define LIN 30
#define COL 50

typedef struct node{
	int x;
	int y;
	int info;
	struct node *next;
	struct node *prev;
}no;

typedef struct{
	int x;
	int y;
	int valor;
}food;

void colore();
void texto();
void ini_food(food *fd);
void coloca_comida(food *fd, no **f);
void cria_campo(char campo[LIN][COL]);
void controles();
bool bateu();
bool detecta_colisao(no **f);
void velocidade();
void desenha_cobra(no **f);
void atualiza_cobra(no **f);
void mov(food *fd, no **f);
void start_snake(char campo[LIN][COL], no **f, food *fd);
void printa_tela(char campo[LIN][COL]);
void end_game(no **f);

void ini_lista(no **f);
void insere_last(no **f, int x, int y, int valor);
//void remove_node(no **L, int x);
void print(no **f);
void limpa_lista(no **f); 
