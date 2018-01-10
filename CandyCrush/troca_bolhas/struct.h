// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

typedef struct bolha{
  int x, y, cor, marca;
  struct bolha *prox;
} BOLHA;

typedef struct result{
  int pontos;
  char nome[11];
  struct result *prox;
} RESULTADO;

typedef struct base{
  int linhas;
  int colunas;
  int raio;

  int largurajanela;
  int alturajanela;

  int vagas;

  int RGB[10][3];

  int xrato;
  int yrato;
  int mousebuttonup;

  int score;
  RESULTADO *topRESULT;

  int vitoria;
  int gameover;
  int novojogo;
  int end;

  int debug;

  BOLHA *top; //Lista Dinâmica
} BASE;
