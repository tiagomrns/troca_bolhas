// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

void Inicializar(BASE **b, int argc, char const *argv[]){
  (*b)=(BASE *)calloc(1, sizeof(BASE));
  //inicializacao que funciona com a sintaxe da norma c99
  (**b) = (BASE)
        {30, 50, 10, //linhas, colunas, raio,
        12*25, 8*25+40, //largurajanela, alturajanela,
        8*12, //vagas
        {{vermelho},{preto},{azul},{verde},{ciano},{amarelo},{castanho},{roxo},{branco},{cinza}}, //RGB,
        0, 0, 0, //xrato, yrato, mousebuttonup,
        0, NULL, //score, topRESULT,
        0, 0, 0, 0, //vitoria, gameover, novojogo, end
        0, //debug
        NULL}; //top

  ARG_GET(argc, argv, *b);

  (*b)->largurajanela=2*(*b)->colunas*(*b)->raio;
  (*b)->alturajanela=2*(*b)->linhas*(*b)->raio+40;
  limites_tamanho_janela(*b);
  JANELA_RENDERER(*b);

  (*b)->vagas=(*b)->colunas*(*b)->linhas;

  guarda_fich(&(*b)->topRESULT);
}

void Troca(BASE *b){
  BOLHA *step1, *step2;
  int aux;

  for(step1=b->top; step1->prox && step1->marca!=1; step1=step1->prox);

  step2=step1->prox;

  if (step2){
    for(; step2->prox && step2->marca!=1; step2=step2->prox);

    if (step1->marca==1 && step2->marca==1) {

 #if VISUAL
      mostratroca(b, *step1, *step2);
 #endif

      aux=step2->cor;
      step2->cor=step1->cor;
      step1->cor=aux;
      step1->marca=2; step2->marca=2;

      if(b->debug) printf("\nTroca %d|%d com %d|%d", LC(step1, 'y', b),
      LC(step1, 'x', b), LC(step2, 'y', b), LC(step2, 'x', b));
      return;
    }
  }

  if (step1->marca==1) {
    step1->x=b->xrato; //assim é possível levar as bolhas para espaços vazios
    step1->y=b->yrato;
    queda(b->top, step1, b->alturajanela, b->raio);
  }
}

void Gravidade(BASE *b){
  int y;
  for(BOLHA *step=b->top; step!=NULL; step=step->prox) {
    step->marca=0;
    y = step->y; //mostraqueda
    queda(b->top, step, b->alturajanela, b->raio);
    if (y!=step->y) {
      step->marca=2;

 #if VISUAL
      mostraqueda(b, *step, y);
 #endif

    }
  }
  Campo(b, 0);
}

void NovaJogada(BASE *b){
  Campo(b, b->debug);
  b->xrato=0;
  b->yrato=0;
  b->mousebuttonup=0;
}

void UI(BASE *b){
  SDL_Event event;
  do {
    SDL_PollEvent(&event);
    switch (event.type) {

 #if VISUAL
      case SDL_MOUSEMOTION:
        CruzFlutuante(b, event.button.x, event.button.y);
      break;
 #endif

      case SDL_MOUSEBUTTONDOWN:
        DOWN(b, event);
      break;

      case SDL_MOUSEBUTTONUP:
        UP(b, event);
      break;
    }
  } while(!b->mousebuttonup);
}

void Destroi_e_Cai(BASE *b){
  SDL_Event event;
  int aux;

  do {
    aux=b->score;
    DESTRUICAO(b);
    Gravidade(b);

    SDL_PollEvent(&event);
  } while (aux!=b->score);
}

void endGameCONDITION(BASE *b){
  int NrdeCores=9, i;
  BOLHA *step;
  if (b->debug) NrdeCores=4;

  int vectCORES[NrdeCores];
  for (i = 0; i < NrdeCores; i++)
    vectCORES[i]=0;

  for (step=b->top; step!=NULL; step=step->prox)
    vectCORES[step->cor]++;

  for (i-- ; i >= 0; i--){
    if (vectCORES[i]==1){
      printf("\nSó existe uma bolha de cor %s\n", cor(i)); FLUSH
      b->gameover=1;

      if(!b->debug) {
        b->novojogo=1;
      }

      return;
    }
    if (vectCORES[i]==0) NrdeCores--;
  }
  if(!NrdeCores) {
    printf("\nParabens, apagou todas as bolhas do jogo!\n"); FLUSH
    b->vitoria=1;
    if(!b->debug) {
      b->novojogo=1;
    }
  }
}

void NovoJogo(BASE *b){
  IniciaLista(b);
  b->vitoria=0;
  b->gameover=0;
  b->novojogo=0;
  b->score=0;
}

void JOGAR(BASE *b){
  do {
    NovaJogada(b);
    UI(b);
    Troca(b);
    Destroi_e_Cai(b);
    endGameCONDITION(b);
  } while(!b->novojogo && !b->end);
}

void LimpaJogo(BASE *b){
  if(b->vitoria) Vitoria(b->largurajanela, b->alturajanela);
  if(b->gameover) GameOver(b->largurajanela, b->alturajanela);
  b->score=b->score/(b->linhas * b->colunas);
  if (b->vitoria || b->gameover)
    faz_tudo_resultados(&b->topRESULT, b->score);

  for (BOLHA **step=&b->top; *step!=NULL;) {
    rmLista(b, step);
  } // funcao limpar
}
