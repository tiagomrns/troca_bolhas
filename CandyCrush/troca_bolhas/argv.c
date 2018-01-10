// Trabalho Final de Programacao           Docente: Bertinho D'Andrade Costa
//   Roberta Vieira 89711      Tiago Martins 89718

#include "all.h"

void ARG_GET(int argc, char const *argv[], BASE *b){
  for (int i = 1; i < argc; i++) {
    if(!strcmp("--h", argv[i])) HelpPROMT();
    if (!strcmp("-d", argv[i])) b->debug=1;
    ARG_SET("-l", argv, i-1, &(b->linhas));
    ARG_SET("-c", argv, i-1, &(b->colunas));
    ARG_SET("-r", argv, i-1, &(b->raio));
  }
  if(b->debug) {
    b->linhas=6;
    b->colunas=6;
    b->raio=50;
  }
  if(argc<2) printf("   --h  for help promt\n");
}

void ARG_SET(char const *str, char const *argv[], int i, int *z){
  if (!strcmp(str, argv[i]))
    *z=atoi(argv[i+1]);
}

void HelpPROMT(){
  printf("\n\tColorCrush - Jogo de Puzzle\n\n");
  printf("//////////////////////      MANUAL DE INSTRUÇÕES\n\n\n COMANDOS TERMINAL\n\n");
  printf("\tArgumentos:\n\t-r [int]\tRAIO\t--modificar o tamanho do raio das bolas\n");
  printf("\t-l [int]\tLINHAS\t--determinar o número de linhas do tabuleiro inicial\n");
  printf("\t-c [int]\tCOLUNAS\t--escolher a número de colunas do tabuleiro inicial\n");
  printf("\t-d\t\tMODO DEBUG\n");
  printf("\tEXEMPLO: ./ColorCrush -r 32 -c 12 -l 6\n\n");
  printf("\n MODO DEBUG\n\n\t./ColorCrush -d\n\tÉ possível acompanhar a execução do código passo a passo.\n\tO tabuleiro gerado é constante.\n\t6 cores\t\t6 colunas\t4 linhas\n");
  printf("\n\n\n INSTRUÇÕES PARA JOGAR\n\n\tO objetivo do jogo é destruir o máximo de bolas do tabuleiro. ");
  printf("\n\tSó é possível formando grupos da mesma cor que posteriormente serão destruídos.\n");
  printf("\tPara mudar a organização do tabuleiro\n\tÉ possível trocar uma bola com uma que lhe esteja adjacente ou movê-la para um espaço vazio.\n");
  printf("\tPara trocar duas bolas adjacentes, arrasta-se uma para o lugar da outra\n\tMais claramente:\n");
  printf("\t1º - Clicar numa das bolas de modo a que fique marcada com uma cruz\n");
  printf("\t2º - Mantendo o rato pressionado deslocar o cursor na direção da outra bola até esta também ficar marcada\n");
  printf("\t3º - Largar o botão do rato\n\tPara mover uma bola para um espaço vazio\n\tRepetir o procedimento anterior mas na direção de uma vaga\n");
  printf("\n\n\tPara maximizar a pontuação deve-se formar grupos o maior possível\n\tpois na sua destruição recebe pontos BONUS.\n");
  printf("\n\tEm cada vitória ou gameover\n\to jogador poderá registar o seu nome e ver a tabela de pontuações\n");
  printf("\n--------------------------------------------------------\n");
  printf("\n\t\t\tAUTORES\n\tRoberta Vieira\t\tTiago Martins\n\t89711\t\t\t89718\n\n");
  printf("\n");
  exit(0);
}

void limites_tamanho_janela(BASE *b){
  if(DEFAULTS(b)){
    b->linhas=8;
    b->colunas=12;
    b->raio=30;
    printf("Jogar com a configuracao predefinida? (ENTER)"); CLEANKEYBOARD
  }
  b->largurajanela=2*b->colunas*b->raio;
  b->alturajanela=2*b->linhas*b->raio+40;
}

int DEFAULTS(BASE *b){
  int def=0;
  if (b->raio<10) {
    printf("Raio das Bolhas muito Reduzido (min r=10)\n");
    def++;
  }
  if (b->largurajanela>1200 || b->alturajanela>700) {
    printf("Valores de Altura ou Largura demasiado Elevados (max a=700, l=1200)\n");
    def++;
  }
  if (b->largurajanela<400 || b->alturajanela<400) {
    printf("Valores de Altura ou Largura demasiado Reduzidos (min a=400, l=400)\n");
    def++;
  }
  return def;
}
