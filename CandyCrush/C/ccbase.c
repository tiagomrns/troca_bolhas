////////////    ccbase.c    /////    C C C C C C C C C C C
#ifndef
include "ccbase.h"

#define JanelaCentrada SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED
#define COR_c RGB[c][0], RGB[c][1], RGB[c][2]

void DadosConfig(ALL z){
  z.linhas=
  z.colunas=
  z.raio=
}

void JANELA_RENDERER(ALL z){
  if(SDL_Init(SDL_INIT_EVERYTHING)!=0) {
      ERRO_SDL();
      exit(1);
    }
    janela = SDL_CreateWindow("Bolhas - O Jogo", JanelaCentrada, z.largurajanela, z.alturajanela, 0);
    if (!janela) printf("ERRO SDL: %s\n", SDL_GetError());
    render = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
    if (!render) printf("ERRO SDL: %s\n", SDL_GetError());
}

void MatrizE(ALL z) {
  for (int i = 0; i < z.linhas; i++)
    for (int j = 0; j < z.colunas; j++)
      int bolhas[linhas][colunas]=rand()%9;
}

void InitCor(BASE *b){
  b->RGB[][]={{255,0,0},{130,0,130},{0,0,200},{0,200,255},{0,150,0},{255,200,0},{150,100,50},{25,25,25},{255,255,255}};
  //          vermelho     roxo       azul      ciano       verde     amarelo     castanho      preto      branco
}

void DrawB(int c, int x, int y, int r){
  SDL_SetRenderDrawColor(render, COR_c, 255 );
  filledCircleRGBA(render, x*r, y*r, r*0.9, COR_c, 255);
  circleRGBA(render, x*r, y*r, r*0.9, 0, 0, 0, 255);
}

void Grelha(ALL z){
  for (int i = 0; i < z.linhas; i++)
    for (int j = 0; j < z.colunas; j++)
      if (z.bolhas[i][j]>-1) DrawB(z.bolhas[i][j], i, j, z.raio);
}

void Menu(BASE b){
 SDL_Rect r1, r2, r3, r4;
 char pontos[20];

 r1.x = 0;
 r1.y = 0;
 r1.w = b.largurajanela;
 r1.h = 40;

 r2.x = 30; //Margem de 30 pixeis na esquerda
 r2.y = 5;
 r2.w = 111; //Novo Jogo ocupa 71 pixeis e sobra 10 para cada lado (cada carater é 7 pixeis e entrea carateres ha 1 pixel)
 r2.h = 30;

 r3.x = 161; //Margem de 20 pixeis na esquerda
 r3.y = 5;
 r3.w = 63; //Fim ocupa 7*3+2 = 23 pixeis. Mais 40 pixeis para o texto nao ficar colado ao retangulo
 r3.h = 30;

 r4.x = 274; //Margem de 50 pixeis na esquerda
 r4.y = 5;
 r4.w = b.largurajanela-304; //Margem de 30 pixeis na direita
 r4.h = 30;

 SDL_SetRenderDrawColor( render, 255, 255, 255, 255 );
 SDL_RenderFillRect(render, &r1);
 SDL_SetRenderDrawColor( render, 200, 200, 200, 255 );
 SDL_RenderDrawRect(render, &r1);
 SDL_RenderFillRect(render, &r2);
 SDL_RenderFillRect(render, &r3);
 SDL_SetRenderDrawColor(render, 100, 100, 100, 255 );
 SDL_RenderFillRect(render, &r4);
 sprintf(pontos, "Pontos     %d", Score);
 stringRGBA(render, 50, 17, "Novo Jogo", 20, 20, 20, 255);
 stringRGBA(render, 181, 17, "Fim", 20, 20, 20, 255);
 stringRGBA(render, 294, 17, pontos, 230, 230, 230, 255);
}
