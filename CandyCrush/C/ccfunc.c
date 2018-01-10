////////////    ccfunc.c    /////    C C C C C C C C C C C
#ifndef
include "ccbase.h"

typedef struct bolha{
  int x, y, cor;
  struct bolha *prox;
} BOLHA;

typedef struct result{
  int pontos;
  char nome[];
  struct result *prox;
} RESULTADOS;

typedef struct base{
  int linhas;
  int colunas;
  int raio;
  int largurajanela;   //int winDIM[2]
  int alturajanela;
  int RGB[9][3];
  int xrato;           //int ratoXY[2]
  int yrato;
  RESULTADOS result;
  int inplay;
  int vitoria;
  int novojogo;
  int fim;
  BOLHA *prox;
} BASE;

void inicio(ALL z){
  DadosConfig(z);
  JANELA_RENDERER(z);
  InitCor(z);
  ConfigCorrect(z);
}

void visual(ALL z){
  SDL_SetRenderDrawColor(render, 150, 150, 150, 255);//cinzento
  SDL_RenderClear(render);//usa a cor definida na funcao anterior para pintar o fundo
  Grelha(z);
  Menu(z);
}

void gamestate(ALL z){


  UserInput(z);
  TrocaBolhas(z);
  Destroi(z);

  Vitoria(z);

  z.inplay=0;
}
