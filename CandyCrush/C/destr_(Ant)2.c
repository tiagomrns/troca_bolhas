// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

void DESTRUICAO(BASE *b){

  int preDESTR=b->score;

  for (BOLHA **a = &b->top; *a!=NULL;){
    if ((*a)->marca==2) {
      if(b->debug) { printf("\nComprimento da Corrente : "); FLUSH }
      DestroiBolhas(b, *a, a, &a, &b->score);
      //DestroiBolhas(b, &a, &b->score);
    } else
      if(*a) a=&(*a)->prox;
  }

  if (preDESTR<b->score) {
    Campo(b, 0);
    SDL_Delay(200);
  }
}

/*void DestroiBolhas(BASE *b, BOLHA ***a, int *score){//BASE *b, BOLHA *a, BOLHA **b3, int *score){
  int flag=0;
  (**a)->marca=3;
  if(b->debug) { printf(" #"); FLUSH }

  for (BOLHA **step = &b->top; *step!=NULL; flag=0) {
    if ( Match(b, ***a, **step) ) {
      (**a)->marca=4;

      if((*step)->marca<3){
        if((*step)->prox==**a) flag=1;  // *pind=step
        DestroiBolhas(b, &step, score);
        if(flag) *a=step;;
        step = &b->top; //talvez apagar
      }
    }
    if(*step) step=&(*step)->prox;
  }

  if ((**a)->marca==4) {
    if(b->debug) { printf("\nElimina %d|%d \n", LC(**a, 'y', b), LC(**a, 'x', b)); SPACE }
    rmLista(b, *a); //base e o indireto
    (*score)++;
  }
}*/

void DestroiBolhas(BASE *b, BOLHA *a, BOLHA **ind, BOLHA ***pind, int *score){//BASE *b, BOLHA *a, BOLHA **b3, int *score){
  int flag=0;
  a->marca=3;
  if(b->debug) { printf(" #"); FLUSH }

  printf("\nENTRA\n"); FLUSH

  for (BOLHA **step = &b->top; *step!=NULL; flag=0) {
    if ( Match(b, *a, **step) ) {
      a->marca=4;

      if((*step)->marca<3){

        printf("%d|%d\tif(%p == %p)", LC(a, 'y', b), LC(a, 'x', b), (void *)(*step)->prox, (void*)(*ind)); FLUSH

        if((*step)->prox==*ind) flag=1;  // *pind=step

        printf("\t*pind(%p) = %p;\n", (void*)(*pind), (void*)(step)); FLUSH

        DestroiBolhas(b, *step, step, &step, score);

        if(flag) *pind=step;;

        step = &b->top; //talvez apagar
      }
    }
    if(*step) step=&(*step)->prox;
  }

  printf("L  C   c  m p\t\tpp\tind----------------Antes de eliminar\n"); FLUSH
  for (BOLHA **walk = &b->top; *walk!=NULL; walk=&(*walk)->prox) {
    printf("%d  %d   %d  %d %p\t%p\t%p\n", LC(*walk, 'y', b), LC(*walk, 'x', b), (*walk)->cor, (*walk)->marca, (void *)(*walk), (void *)(*walk)->prox, (void*)(walk)); FLUSH
  }

  if (a->marca==4) {
    //if(b->debug) { printf("\nElimina %d|%d  *ind=%p  --=%p\n", LC(a, 'y', b), LC(a, 'x', b) , (void *)(*ind), (void *)((*ind)->prox)) ); SPACE }
    printf("\nElimina %d|%d    *ind=%p\n", LC(a, 'y', b), LC(a, 'x', b), (void *)(*ind)); SPACE

    rmLista(b, *pind); //base e o indireto
    (*score)++;
  }

  printf("L  C   c  m p\t\tpp\tind----------------Depois de eliminar\n"); FLUSH
  for (BOLHA **walk = &b->top; *walk!=NULL; walk=&(*walk)->prox) {
    printf("%d  %d   %d  %d %p\t%p\t%p\n", LC(*walk, 'y', b), LC(*walk, 'x', b), (*walk)->cor, (*walk)->marca, (void *)(*walk), (void *)(*walk)->prox, (void*)(walk)); FLUSH
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
