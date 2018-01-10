#include <stdlib.h>
#include <string.h>

typedef struct inspecao {
  char matricula[9];
  int estado;
} INSPECAO;

INSPECAO *apinspecao = NULL;

//           forçar tipo
apinspecao = (INSPECAO*) calloc(1, sizeof(INSPECAO));

if (!api) printf("n deu para alocar memoria\n");

strncpy((*apinspecao).matricula, "01-02-JJ",8);
(*apinspecao).estdo = 1;

free(api);
api = NULL;

time_t systime;
systime = time(NULL);
puts(ctime(systime));

// (*apinspecao).matricula é a mesma coisa que apinspecao-> matricula
