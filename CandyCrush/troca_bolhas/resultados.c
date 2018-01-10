// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

void faz_tudo_resultados(RESULTADO **ptop, int score){
	RESULTADO *ultimo = (RESULTADO*)calloc(1, sizeof(RESULTADO));
	if(!ultimo){
	printf("Erro na alocacao de memoria"); FLUSH
		exit(-1);
	}

	printf("Nome:");
	scanf("%10s", ultimo->nome);
	ultimo->pontos = score;

	ultimo->prox=*ptop;
	*ptop=ultimo;

	ordenar_pontuacoes(ptop);

	faz_resultados_txt(*ptop);
}

void guarda_fich(RESULTADO **ptop){
	RESULTADO *aux, **ultimo = ptop;
	FILE *pr=fopen("resultados.txt", "r");
	char linha[25];

	if(!pr) return;

	while ( fgets(linha, 25, pr) ) {
		aux=(RESULTADO*)calloc(1, sizeof(RESULTADO));

		if(!aux){
			printf("Erro na alocacao de memoria"); FLUSH
			exit(-1);
		}
		sscanf(linha, "%10s\t\t%d", aux->nome, &aux->pontos);

		*ultimo=aux;
		ultimo=&(aux->prox);
	}
	fclose(pr);

}

void troca_blocos(RESULTADO **b1, RESULTADO **b2) {
	RESULTADO *aux=(*b2)->prox;
	(*b2)->prox=*b1;
	*b1=*b2;
	*b2=aux;
}

void ordenar_pontuacoes(RESULTADO **ptop) {
  for (int troca=1; troca;){
    troca=0;
    for(RESULTADO **step = ptop; (*step)->prox!=NULL; step = &(*step)->prox){
			if( (*step)->pontos < (*step)->prox->pontos) {
				troca_blocos(step, &((*step)->prox));
				troca=1;

			}
		}
  }
}

void faz_resultados_txt(RESULTADO *top){
	FILE *fp; int i=0;
	fp=fopen("resultados.txt", "w");

  printf("\n             NOME   PONTOS\n\n");
	for(; top; top = top->prox){

		fprintf(fp, "%10s\t\t%d\n", top->nome, top->pontos); //guarda todos os resultados por ordem em resultados.txt

		if (i<10) {//imprime os melhores resutados
			printf(" %2dº   %10s  %7d\n", i+1, top->nome, top->pontos);
			i++;
		}
	} // i>1 para nao ficar 1 melhores resultados, um erro gramatical
	if (i>1) printf("\n (%d melhores resultados)\n", i); //no maximo serao 10

	fclose(fp);
}
