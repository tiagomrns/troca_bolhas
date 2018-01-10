//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

int main(int argc, char const *argv[]) {
  srand(time(NULL));

  BASE *base;
  Inicializar(&base, argc, argv);
  if (base->debug) srand(711718);

  do {

    NovoJogo(base);

    JOGAR(base);

    LimpaJogo(base);

  } while(!base->end );

  printf("\nFIM\n");
  return 0;
}
