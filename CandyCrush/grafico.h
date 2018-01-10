// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

void JANELA_RENDERER(BASE *b);
void Fundo(int c1, int c2, int c3);
void Menu(BASE *b);
void DrawB(int c, int x, int y, int r, int RGB[][3]);
void Grelha(BASE *b, int debug);
void DesenhaCruz(int raio, int x, int y);
void CruzFlutuante(BASE *b, int xr, int yr);
void DesenhaX(BASE *b, int x, int y, int cor);
void mostratroca(BASE *b, BOLHA bolha1, BOLHA bolha2);
void mostraqueda(BASE *b, BOLHA bolha, int y);
void Vitoria(int l, int a);
void GameOver(int l, int a);
void Campo(BASE *b, int debug);
