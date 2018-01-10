// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

float Distancia(int x1, int x2, int y1, int y2);
int ZonaDeJogo(BASE *b);
void ArredondarCoordenadas(int r, int *x, int *y);
void CoordRato(BASE *b, SDL_Event e);
BOLHA *BOLHAfromXY(BASE *b, int x, int y);
int Trigonometrias(int *x1, int *y1, int x2, int y2, int raio);
void DOWN(BASE *b, SDL_Event event);
void UP(BASE *b, SDL_Event event);
void MarcaTroca(BASE *b);
void queda(BOLHA *top, BOLHA *step1, int solo, int raio);
void SDL_SPACE(void);
char *cor(int c);
