// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

void faz_tudo_resultados(BASE *b, int score){
	RESULTADOS *ultimo = (RESULTADOS*)calloc(1, sizeof(RESULTADOS));
	if(!ultimo){
	printf("Erro na alocacao de memoria"); FLUSH
		exit(-1);
	}

	printf("Nome:");
	scanf("%10s", &(ultimo->nome));
	ultimo->pontos = score;

	ultimo->prox=b->topRESULT;
	b->topRESULT=ultimo;

	top = guarda_fich();

	ultimo->prox = top;
	top = ultimo;

	top = ordena_lista(top);

	faz_resultados_txt(top);
}

RESULTADOS *guarda_fich(BASE *b){
	RESULTADOS *aux, *ant, *top;
	FILE *pr=fopen("resultados.txt", "r");
	int linhas_fich=0, i;
	char *apc;
	char dados_ficheiro[100][20];
	char linha[18];

	while (fgets(linha, 18, pr)) {

		aux=(RESULTADOS*)calloc(1, sizeof(RESULTADOS));
		if(!aux){
			printf("Erro na alocacao de memoria"); FLUSH
			exit(-1);
		}

		ultimo->prox=aux;
	}

	do {
			apc = fgets(dados_ficheiro[linhas_fich], 20, pr);
			if (apc != NULL)
		  		linhas_fich++;

		} while(apc != NULL);
	fclose(pr);

	for(i=0; i<linhas_fich; i++){
		aux=(RESULTADOS*)calloc(1, sizeof(RESULTADOS));
		if(aux==NULL){
			printf("Erro na alocacao de memoria"); FLUSH
			exit(-1);
		}
		if( i == 0){
			top=aux;
			ant=top;
		}
		if(sscanf(dados_ficheiro[i], "%s\t%d", aux->nome, &(aux->pontos)) != 2){
				return NULL;	//ficheiro vazio
		}
		if(i != 0){
			ant->prox = aux;
			ant=aux;
		}
	}
	return top;
}

RESULTADOS *ordena_lista(RESULTADOS *top){
	RESULTADOS *top2= NULL, *aux, *aux2, *maior, *ant;

	while(top != NULL){
 		ant = top;
 		maior = top;
 		for(aux=top->prox; aux != NULL; aux = aux->prox){
 			if(maior->pontos < aux->pontos){
 				maior = aux;
 				while(ant->prox != maior)
 					ant = ant->prox;
 			}
 		}
 		if(maior != top)
 			ant->prox = maior->prox;
 		else
 			top = top->prox;
 		if(top2 == NULL)
 			top2 = maior;
 		else{
 			for(aux2 = top2; aux2->prox != NULL; aux2 = aux2->prox){}
 			aux2->prox = maior;
 			maior->prox=NULL;
 		}
 	}
 return top2;
}

void faz_resultados_txt(RESULTADOS *top){
	FILE *fp;
	fp=fopen("resultados.txt", "w");

  printf("NOME\tPONTOS\n");
	for(;top != NULL; top = top->prox){
		fprintf(fp, "%s\t%d\n", top->nome, top->pontos);
		printf(" %s\t%d\n", top->nome, top->pontos);
	}

	fclose(fp);
}
