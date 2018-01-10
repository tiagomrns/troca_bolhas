// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

void JANELA_RENDERER(BASE *b){
  if(SDL_Init(SDL_INIT_EVERYTHING)!=0) {
      SDL_GetError();
      exit(0);
    }

  janela = SDL_CreateWindow("ColorCrush - Jogo Aeroespecial", JanelaCentrada, b->largurajanela, b->alturajanela, 0);
  if (!janela) printf("ERRO SDL: %s\n", SDL_GetError());
  render = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
  if (!render) printf("ERRO SDL: %s\n", SDL_GetError());

  printf("Linhas-%d  Colunas-%d  Raio-%d\tJANELA %dx%d\n", b->linhas, b->colunas, b->raio, b->largurajanela, b->alturajanela);
}

void Fundo(int c1, int c2, int c3){
  SDL_SetRenderDrawColor(render, c1, c2, c3, 255);//cor branca
  SDL_RenderClear(render);//usa a cor definida na funcao anterior para pintar o fundo
}

void Menu(BASE *b){
 SDL_Rect r1, r2, r3;
 char pontos[25];

 r1.x = 0;
 r1.y = 0;
 r1.w = b->largurajanela;
 r1.h = 40;

 r2.x = 30; //Margem de 30 pixeis na esquerda
 r2.y = 5;
 r2.w = 111; //Novo Jogo ocupa 71 pixeis e sobra 10 para cada lado (cada carater é 7 pixeis e entrea carateres ha 1 pixel)
 r2.h = 30;

 r3.x = 161; //Margem de 20 pixeis na esquerda
 r3.y = 5;
 r3.w = 63; //Fim ocupa 7*3+2 = 23 pixeis. Mais 40 pixeis para o texto nao ficar colado ao retangulo
 r3.h = 30;

 SDL_SetRenderDrawColor( render, preto, 255 );
 SDL_RenderFillRect(render, &r1);
 SDL_SetRenderDrawColor( render, cinzaclaro, 255 );
 SDL_RenderFillRect(render, &r2);
 SDL_RenderFillRect(render, &r3);

 sprintf(pontos, "Pontos    %d", b->score);
 stringRGBA(render, 50, 17, "Novo Jogo", preto, 255);
 stringRGBA(render, 181, 17, "Fim", preto, 255);
 stringRGBA(render, b->largurajanela-139, 17, pontos, branco, 255);
}

void DrawB(int x, int y, int c, int r, int RGB[][3]){
  filledCircleRGBA(render, x, y, r, RGB[c][0], RGB[c][1], RGB[c][2], 255);
  circleRGBA(render, x, y, r, RGB[c][0]/4, RGB[c][1]/4, RGB[c][2]/4, 255);
}

void Grelha(BASE *b, int debug){
  if(debug) { printf("\n L  C  COR\tATUAL        PROX\n"); FLUSH }

  for (BOLHA *step=b->top; step!=NULL; step=step->prox){

    DrawB(step->x, step->y, step->cor, b->raio, b->RGB);

    if(debug) {
      char CodigoCor[2];
      DrawB(step->x, step->y, 8, 20, b->RGB);
      sprintf(CodigoCor, "%d", step->cor);
      stringRGBA(render, step->x-3, step->y-3, CodigoCor, preto, 255);
      printf(" %d  %d   %d\t%p    %p\n", LC(step, 'y', b), LC(step, 'x', b), step->cor, (void*)step, (void *)step->prox); FLUSH
    }
  }
  SDL_RenderPresent(render);
}

void DesenhaCruz(int raio, int x, int y) {
  SDL_SetRenderDrawColor(render, cinza, 255);
  for (int i = -1; i < 2; i++) { //Atribuir espessura de 3 pixeis à cruz
    SDL_RenderDrawLine(render, x-raio+4, y+i, x+raio-4, y+i);
    SDL_RenderDrawLine(render, x+i, y-raio+4, x+i, y+raio-4);
  }
  SDL_RenderPresent(render);
}

void CruzFlutuante(BASE *b, int xr, int yr){
  int x = b->xrato;
  int y = b->yrato;

  if (Trigonometrias(&x, &y, xr, yr, b->raio)){
    ArredondarCoordenadas(b->raio, &x, &y);

    BOLHA *bolha = BOLHAfromXY(b, x, y);
    if (bolha){
      DesenhaCruz(b->raio, x, y);
      DrawB(x, y, bolha->cor, b->raio, b->RGB);
    }
  }
}

void DesenhaX(BASE *b, int x, int y, int cor){
  filledCircleRGBA(render, x, y, b->raio, cinza, 255);
  SDL_SetRenderDrawColor(render, b->RGB[cor][0], b->RGB[cor][1], b->RGB[cor][2], 255);
  for (int i = -1; i < 2; i++) { //Atribuir espessura de 3 pixeis à cruz
    SDL_RenderDrawLine(render, x-b->raio+2+i, y-b->raio+2, x+b->raio-2+i, y+b->raio-2);
    SDL_RenderDrawLine(render, x+b->raio-2+i, y-b->raio+2, x-b->raio+2+i, y+b->raio-2);
  }
  SDL_RenderPresent(render);
}

void mostratroca(BASE *b, BOLHA bolha1, BOLHA bolha2){
  int x1, y1, c1=bolha1.cor;
  int x2, y2, c2=bolha2.cor;

  for (int i = 1; i < 7; i++) {
    x1 = bolha2.x*i/7 + bolha1.x*(7-i)/7;
    x2 = bolha1.x*i/7 + bolha2.x*(7-i)/7;
    y1 = bolha2.y*i/7 + bolha1.y*(7-i)/7;
    y2 = bolha1.y*i/7 + bolha2.y*(7-i)/7;

    //desenhar as bolhas com alguma transparencia para ajudar a dar ilusao de movimento
    filledCircleRGBA(render, x2, y2, b->raio, b->RGB[c2][0], b->RGB[c2][1], b->RGB[c2][2], 100);
    filledCircleRGBA(render, x1, y1, b->raio, b->RGB[c1][0], b->RGB[c1][1], b->RGB[c1][2], 100);
    SDL_RenderPresent(render);
    filledCircleRGBA(render, bolha1.x, bolha1.y, b->raio, b->RGB[c2][0], b->RGB[c2][1], b->RGB[c2][2], 255);
    filledCircleRGBA(render, bolha1.x, bolha1.y, b->raio, b->RGB[c1][0], b->RGB[c1][1], b->RGB[c1][2], 255);
    SDL_Delay(10);
  }
}

void mostraqueda(BASE *b, BOLHA bolha, int y){
  while (y < bolha.y) {
    y+=b->raio/10;
    DrawB(bolha.x, y, bolha.cor, b->raio, b->RGB);
    SDL_Delay(0.1);
    SDL_RenderPresent(render);
    filledCircleRGBA(render, bolha.x, y-5, b->raio, cinza, 255);
  }
}

void Vitoria(int l, int a){
  printf("\n\nVitória!\n");
  SPACE
  SDL_SetRenderDrawColor(render, 0, 150, 0, 255); //verde
  SDL_RenderClear(render); //fundo verde
  stringRGBA(render, l/2-28, a/2-17, "VITORIA", 255, 255, 255, 255); //imprimir "VITORIA" no centro do ecra
  SDL_RenderPresent(render);
}

void GameOver(int l, int a){
  printf("Game Over - Não Existem Jogadas Possíveis para Ganhar\n");
  SPACE
  SDL_SetRenderDrawColor(render, 255, 0, 0, 255); //vermelho
  SDL_RenderClear(render); //fundo vermelho
  stringRGBA(render, l/2-36, a/2-17, "GAME OVER", 0, 0, 0, 255); //imprimir "GAME OVER" no centro do ecra
  SDL_RenderPresent(render);
}

void Campo(BASE *b, int debug){
  Fundo(cinza);
  Menu(b);
  Grelha(b, debug);
}
