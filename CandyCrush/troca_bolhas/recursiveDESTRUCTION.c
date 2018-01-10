// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

void DESTRUICAO(BASE *b){

  int preDESTR=b->score;

  for (BOLHA *a = b->top; a!=NULL; a=a->prox)
    if (a->marca==2) {
      if(b->debug) { printf("\nComprimento da Corrente : "); FLUSH }
      marca_para_destruicao(b, a);
    }

  for (BOLHA **a = &b->top; *a!=NULL;){
    if ((*a)->marca==4) {
      if(b->debug) { printf("\nElimina %d|%d \n", LC(*a, 'y', b), LC(*a, 'x', b)); SPACE }
      rmLista(b, a); //base e o apontador indireto
      b->score++;
    } else
      if(*a) a=&(*a)->prox;
  }

  if (preDESTR<b->score) {
    b->score = preDESTR + (b->score-preDESTR-1)*(b->score-preDESTR-1); //bonus (quadrado da nova pontuacao ganha)
    Campo(b, 0);
    SDL_Delay(200);
  }
}

void marca_para_destruicao(BASE *b, BOLHA *a){
  a->marca=3;
  if(b->debug) { printf(" #"); FLUSH }

  for (BOLHA *step = b->top; step!=NULL; step=step->prox)
    if ( Match(b, *a, *step) ) {
      a->marca=4;

      if( step->marca<3 )
        marca_para_destruicao(b, step);
    }
}

int Match(BASE *b, BOLHA b1, BOLHA b2){
  if (Distancia(b1.x, b2.x, b1.y, b2.y) == 2*b->raio && b1.cor==b2.cor)
    return 1;

  return 0;
}

int LC(BOLHA *a, char c, BASE *b){ //transforma a coordenada y/x de uma bolha na linha/coluna correspondente
  if (c=='y') return (a->y +b->raio-40)/(2*b->raio);
  if (c=='x') return (a->x + b->raio)/(2*b->raio);
  return -1;
}
