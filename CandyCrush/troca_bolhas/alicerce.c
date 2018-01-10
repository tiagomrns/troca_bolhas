// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

float Distancia(int x1, int x2, int y1, int y2){
  return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}

int ZonaDeJogo(BASE *b) {
  if (b->yrato<40) { //o utilizador clicou algures na barra de menu no topo da janela
    if (b->xrato>29 && b->xrato<142 && b->yrato>4 && b->yrato<36) b->novojogo=1; //clique no botao de novo jogo
    if (b->xrato>160 && b->xrato<225 && b->yrato>4 && b->yrato<36) b->end=1;
    b->xrato=0; b->yrato=0;
    return 0;
  }
  return 1;
}

void ArredondarCoordenadas(int r, int *x, int *y){
  int ax = *x / (2*r);
  int ay = (*y-40) / (2*r);
  *x = (2*ax + 1)*r;
  *y = (2*ay + 1)*r+40;
}

void CoordRato(BASE *b, SDL_Event e){
  b->xrato=e.button.x;
  b->yrato=e.button.y;
  ArredondarCoordenadas(b->raio, &(b->xrato), &(b->yrato));
}

BOLHA *BOLHAfromXY(BASE *b, int x, int y){
  for(BOLHA *step=b->top; step!=NULL; step=step->prox)
    if ((x==step->x)&& (y==step->y))
      return step;

  return NULL;
}

int Trigonometrias(int *x1, int *y1, int x2, int y2, int raio) {
  int norma = Distancia(*x1, x2, *y1, y2);

  if( (*x1||*y1) && (norma > raio) ){

    if ((*x1-x2)*(*x1-x2) > (*y1-y2)*(*y1-y2)) //se a componente x do vetor for superior
      *x1 += (2*raio) * (( x2-*x1) /norma); //projeta o vetor no eixo xx e normaliza-o

    else //o equivalente referentemente a y
      *y1 += (2*raio) * (( y2-*y1) /norma);

    return 1;
  }
  return 0;
}

void DOWN(BASE *b, SDL_Event event){
  if (BUT_NovoJogo){
    b->novojogo=1; //clique no botao de novo jogo
    return;
  }

  if (BUT_Fim){
    b->end=1; //clique no botao de fim
    return;
  }

  if (event.button.y>40) {
    CoordRato(b, event);
    MarcaTroca(b);
  }
}

void UP(BASE *b, SDL_Event event){
  b->mousebuttonup=1;
  if (Trigonometrias(&(b->xrato), &(b->yrato), event.button.x, event.button.y, b->raio)) {
    ArredondarCoordenadas(b->raio, &(b->xrato), &(b->yrato));
    MarcaTroca(b);
  }
}

void MarcaTroca(BASE *b){
  BOLHA *bolha=BOLHAfromXY(b, b->xrato, b->yrato);
  if (bolha) {
    bolha->marca=1;
    DesenhaCruz(b->raio, b->xrato, b->yrato);
  }
}

void queda(BOLHA *top, BOLHA *step1, int solo, int raio){
  step1->y = solo-raio;

  for(BOLHA *step2=top; step2!=NULL; step2=step2->prox)
    if ( (step1->x==step2->x) && (step1->y==step2->y) && (step1!=step2) ) { // só se concretiza com as bolhas
      step1->y = step2->y - 2*raio;                                         // que se encontram abaixo
    }//faz com que (caso exista bolha abaixo) a bolha atual suba
}

void SDL_SPACE(void){
  FLUSH
  printf("\nPRESSIONE ESPAÇO PARA CONTINUAR (NA JANELA SDL)\n"); FLUSH
  SDL_Event event;
  for (int i = 0; i < 2; i++) { //para o Keydown e o Keyup
    do {
      SDL_PollEvent(&event);
    } while(event.key.keysym.sym!=SDLK_SPACE);
  }
}

char *cor(int c){
  switch (c) {
    case 0:
      return "vermelha";
    case 1:
      return "preta";
    case 2:
      return "azul";
    case 3:
      return "verde";
    case 4:
      return "turquesa";
    case 5:
      return "amarela";
    case 6:
      return "castanha";
    case 7:
      return "roxa";
    case 8:
      return "branca";
  }
  return NULL;
}
