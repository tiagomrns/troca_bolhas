#include <stdio.h>

typedef struct{
  int num, den;
} RACIO;

typedef struct elem_rac{
  RACIO x;
  struct elem_rac* prox;
} BLOCO;

int main(int argc, char const *argv[]) {
  BLOCO *top, *step, *aux;
  RACIO num;
  num.num=1;
  num.den=3;
  RACIO *apnum;
  apnum=&num;
  (*apnum).num=2;
  apnum->den=5;
//////////////////////////

step=top;
step=step->prox;
(*step).x->num; //o segundo bloco guarda o dado útil 2/5
step=step->prox;
step->x=step->prox->x;//o campo x do bloco atual fica igual ao do bloco seguinte
aux=step->prox;
step->prox=aux->prox;//o terceiro fica a apontar para o quinto
free(aux);//eliminar 4º bloco e o 5º bloco passa a 4º com o 3º ainda a apontar para ele

for(i=0, step=top;    step!=NULL;    step=step->prox, i++){
  printf("Bloco %d. Rac=%d/%d\n", i, step->x.num, step->x.den);
}

BLOCO *top=NULL, *aux;
top=ordenalista(top);

}

BLOCO* procura_ponto_de_insecao(BLOCO* top, BLOCO* novo){
  BLOCO *blocoanterior=NULL, *atual=NULL;
  if(top==NULL) return top; // se a lista estiver vazia
  for (atual=top; atual!=NULL; atual=atual->prox){
    if (compara(atual->x, novo->x)) return blocoanterior;
    blocoanterior=atual;
  }
  return blocoanterior;
}

BLOCO* inserir_ordenadamente(BLOCO* top, BLOCO* novo){
  BLOCO *blocoanterior;
  blocoanterior=procura_ponto_de_insecao(top, novo);
  if (anterior==NULL) {// se o anterior n existir significa que o novo vai ser o primeiro elemento
    novo->prox=top;
    return novo; //o novo é o topo da lista
  }
  novo->prox=anterior->prox;
  anterior->prox=novo;
  return top;
}

//SORT de LISTA - insercao numa lista nova, ie, trocar as ligacoess
BLOCO* ordenalista(BLOCO *top){
  topaux=NULL;;

  while (top!=NULL) {
    aux=top;
    top=top->prox;
//  BLOCO*                       BLOCO* BLOCO*
    topaux=inserir_ordenadamente(topaux, aux);  //cria lista auxiliar com topaux
  }
return topaux;
}
