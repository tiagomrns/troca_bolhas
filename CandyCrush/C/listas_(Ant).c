// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

void IniciaLista(BASE *b){
  BOLHA *ant=NULL;

  for (int i = b->vagas-1; i >= 0; i--) {
    BOLHA *nova = AddFinalLista(b, &ant);

    if (!b->debug) nova->cor = rand()%9; //cor da Bolha entre as 9 (de 0 a 8)
    else nova->cor = rand()%4;

    nova->y = b->raio*(1+2*(i%b->linhas)) +40; //existe um espaco de 40 pixeis acima das bolhas para o Menu
    nova->x = b->raio*(1+2*(i/b->linhas));
    nova->marca=0;
    nova->prox=NULL;
  }
}

BOLHA *AddFinalLista(BASE *b, BOLHA **ant){
  BOLHA *nova = (BOLHA*)calloc(1, sizeof(BOLHA));
  if (!nova) {
    printf("ERRO AO ALOCAR MEMÓRIA!\n");
    exit(0);
  }
  if(!*ant) b->top=nova;
  if(*ant) (*ant)->prox=nova;
  *ant=nova;
  return nova;
}

void rmLista(BASE *b, BOLHA **ind){//BOLHA *ant){
  BOLHA *aux=*ind;
  /*if(ant) {
    aux=ant->prox;
    ant->prox=aux->prox;

  } else {
    aux=b->top;
    b->top=aux->prox;

    if (!aux->prox) {
      b->vitoria=1;
      b->novojogo=1;
    }
  }*/

  *ind=(*ind)->prox;

  DesenhaX(b, aux->x, aux->y, aux->cor);

  free(aux);
}

BOLHA *Sherlock(BASE *b, BOLHA *a){
  for (BOLHA *step=b->top; ; step=step->prox)
    if (step->prox==a)
      return step;
  return NULL;
}

void TrocarBLOCOS(BASE *b, BOLHA *j, BOLHA *k){
  BOLHA *aux;
  BOLHA *antj=Sherlock(b,j);
  BOLHA *antk=Sherlock(b,k);
  aux=k->prox;
  k->prox=j->prox;
  if(!antj) b->top=k;
  if(antj) antj->prox=k;
  j->prox=aux;
  if(!antk) b->top=j;
  if(antk) antk->prox=j;
}
