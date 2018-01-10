// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

void DESTRUICAO(BASE *b){
  //BOLHA *ant=NULL;
  int preDESTR=b->score;

  for (BOLHA **a = &b->top; *a!=NULL;){
    if ((*a)->marca==2) {
      printf("\nEntra 0 %d|%d", LC(*a, 'y', b), LC(*a, 'x', b)); FLUSH

      if(b->debug) { printf("\nComprimento da Corrente : "); FLUSH }
      //DestroiBolhas(b, a, NULL, &ant, &(b->score));
      DestroiBolhas(b, *a, a, &a, &b->score);//&ant, &(b->score));
      //if (ant) a=ant;
      //else a=b->top;

    } //else {
      //ant=a;
    //}
    //if(!a) break;
    if(*a) a=&(*a)->prox;
  }

 #if VISUAL
  if (preDESTR<b->score) {
    SDL_RenderPresent(render);
    SDL_Delay(500); //tempo para observar a chacina
  }
 #endif
}

void DestroiBolhas(BASE *b, BOLHA *a, BOLHA **ind, BOLHA ***pind, int *score){//BASE *b, BOLHA *a, BOLHA **b3, int *score){
  a->marca=3;
  if(b->debug) { printf(" #"); FLUSH }
  printf("\nantes do for\n"); FLUSH

  for (BOLHA **step = &b->top; *step!=NULL;) {
    if ( Match(b, *a, **step) ) {
      printf("depois do match\n");FLUSH

      a->marca=4;

      if((*step)->marca<3){
        if((*step)->prox==**pind) *pind=step;
        DestroiBolhas(b, *step, step, &step, score);
      }
    }
    if(*step) step=&(*step)->prox;
  }

  if (a->marca==4) {
    if(b->debug) { printf("\nElimina %p %d|%d,  %p", (void *)a, LC(a, 'y', b), LC(a, 'x', b), (void *)a->prox); SPACE }

    rmLista(b, *pind); //base e o indireto
    printf("   eliminou\n"); FLUSH

    BOLHA *provisoria=BOLHAfromXY(b, 150, 90);
    if (provisoria) { printf("BOLHA 1|2->prox end=%p\n", (void*)provisoria->prox); FLUSH}

    (*score)++;
  }
}
 /*
  if(b->debug) { printf("\nElimina %d|%d", LC(a, 'y', b), LC(a, 'x', b)); FLUSH }

    //usando a funcao que remove da lista dentro da destruicao recursiva poupa-se um ciclo
    rmLista(b, *b3); //remove a bolha atual depois de eliminar todas da mesma cor à volta
    (*score)++;
  }
}*/

/*void DestroiBolhas(BASE *b, BOLHA *a, BOLHA* outra, BOLHA **b3, int *score){
  BOLHA *ant=NULL;//        atual    iteracao ant   b3->prox=a
  a->marca=3;

  if(b->debug) { printf(" #"); FLUSH }

  for (BOLHA *step=b->top; step!=NULL; step=step->prox){
    if (Match(b, *a, *step)) {

      if(step!=outra && step->marca<3){

        if (step->prox==a) (*b3)=ant;
        DestroiBolhas(b, step, a, &ant, score);
        if (ant) step=ant;
        else step=b->top;

      }//basta haver um match que pelos menos duas bolhas sao destruidas
      a->marca=4;
    } else {
      ant=step;
    }
  }

  if(a->marca==4) { //elimina a bolha usando o ap da anterior
    if(b->debug) { printf("\nElimina %d|%d", LC(a, 'y', b), LC(a, 'x', b)); FLUSH }

    //usando a funcao que remove da lista dentro da destruicao recursiva poupa-se um ciclo
    rmLista(b, *b3); //remove a bolha atual depois de eliminar todas da mesma cor à volta
    (*score)++;
  }
}*/

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
