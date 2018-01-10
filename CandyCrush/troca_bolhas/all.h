// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#ifndef LIBS
#define LIBS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#include "struct.h"
#include "argv.h"
#include "listas.h"
#include "grafico.h"
#include "alicerce.h"
#include "ccfunc.h"
#include "recursiveDESTRUCTION.h"
#include "resultados.h"

#define VISUAL 1

SDL_Window* janela; //variavel global tipo SDL_Window*
SDL_Renderer* render; //variavel global tipo SDL_Renderer*
#define JanelaCentrada SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED

#define CLEANKEYBOARD while (getchar()!='\n');
#define FLUSH fflush(stdout);
#define BUT_NovoJogo event.button.x>29 && event.button.x<142 && event.button.y>4 && event.button.y<36
#define BUT_Fim event.button.x>160 && event.button.x<225 && event.button.y>4 && event.button.y<36
#define SPACE SDL_SPACE();

#define vermelho 255,0,0
#define preto 25,25,25
#define azul 0,0,210
#define verde 0,150,0
#define ciano 0,200,255
#define amarelo 255,200,0
#define castanho 130,80,30
#define roxo 150,0,130
#define branco 230,230,230
#define cinza 130,130,130
#define cinzaclaro 200,200,200

#endif
