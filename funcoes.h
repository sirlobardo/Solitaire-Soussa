#ifndef FUNCOES_H
#define FUNCOES_H

//Bibliotecas 
#include <iostream>
#include <stdlib.h>
#include <time.h>

//Bibliotecas
#include "headerfiles.h"


//Para trocar as cartas
void swap(carta *a, carta *b) {
    carta temp = *a;
    *a = *b;
    *b = temp;
}

// Embaralhar usando srand
void embaralhar(carta arr[]) {
    srand(time(NULL));
    int i;
    for(i = 51; i > 0; i--) {
        int j = rand() % (i+1);
        swap(&arr[i], &arr[j]);
    }
}

// Inicializa pilha dos montes 
void inicializar_montes(tp_pilha montes[]){
  for(int i=0;i<7;i++){
    inicializa_pilha(&montes[i]);
  }
}

//Inicializa a pilha dos montes finais (de cada naipe)
void inicializar_mgc(tp_pilha mgc[]){
  for(int i=0;i<4;i++){
    inicializa_pilha(&mgc[i]);
  }
}

//Preenche os montes 
void colocar_nos_montes(tp_pilha montes[],carta baralho[]){
  
  carta carta_void; // Para quando o monte estiver vazio
  for(int i=0;i<7;i++){
    push(&montes[i], carta_void);
  }
  
  push(&montes[0], baralho[0]);
  
  for(int i=1;i<=2;i++){
    push(&montes[1], baralho[i]);
  }

  for(int i=3;i<=5;i++){
    push(&montes[2], baralho[i]);
  }

  for(int i=6;i<=9;i++){
    push(&montes[3], baralho[i]);
  }

  for(int i=10;i<=14;i++){
    push(&montes[4], baralho[i]);
  }

  for(int i=15;i<=20;i++){
    push(&montes[5], baralho[i]);
  }

  for(int i=21;i<=27;i++){
    push(&montes[6], baralho[i]);
  }
}

//Preenche o cava com o restante das cartas
void colocar_no_cava(tp_listase **cava, carta baralho[]){
  carta carta_void;
  for(int i=28;i<=51;i++){
    insere_listase_no_fim(cava, baralho[i]);
  }
  insere_listase_no_fim(cava,carta_void);
}

//Preenche os montes finais com uma carta void
void colocar_no_mgc(carta carta, tp_pilha mgc[]){
  for(int i=0;i<4;i++){
    push(&mgc[i], carta);
  }
}

//Vira uma carta
void virar_carta(carta *carta){
  carta->paraCima = true;
}

//Vira a primeira carta de cada monte
void virar_carta_dos_montes(tp_pilha montes[]){
  for(int i = 0; i<7; i++){
    int indice = altura_pilha(&montes[i])-1;
    virar_carta(&montes[i].item[indice]);
  }
}

//Vira todas as cartas do cava
void virar_cartas_do_cava(tp_listase **cava){
  tp_listase *atu = *cava;
  while(atu!=NULL){
    atu->info.paraCima = true;
    atu=atu->prox;
  }
}

//Mostra a carta do topo no monte final
void virar_cartas_do_mgc(tp_pilha mgc[]){
  int topo;
  for(int i=0; i<4;i++){
    topo = altura_pilha(&mgc[i]) - 1;
    mgc[i].item[topo].paraCima = true;
  }
}

// Menu do Jogo

void menu(){
  textbackground(WHITE); // Munda a cor do fundo
  clrscr(); // Limpa a tela 
  textcolor(BLACK); //Muda a cor do texto

  // Texto em fonte maior
  std::cout<<"     -----   -----   |        °   -----   -----   °   -----   -----"<<std::endl;
  std::cout<<"     |      |     |  |        |     |     |   |   |   |   |   |"<<std::endl;
  std::cout<<"     |      |     |  |        |     |     |---|   |   |----   -----"<<std::endl;
  std::cout<<"-----|       -----   |-----   |     |     |   |   |   |  |    |____"<<std::endl;
    
  
  gotoxy(0,10); // Posição das intruções na tela

  // Intruções do jogo
  std::cout<<"Instruções\n"<<"Para mover uma carta basta informar o \n"<<" Id do monte de partida, Id monte final\n"<<" e a quantidade de cartas nessa ordem.\n"<<"Os Ids estão representados por números\nacima dos montes com a cor azul.\n"<<"Para percorrer o cava, utilize do número azul\na sua esquerda como um indicador do quanto que foi percorrido.\nEX:\n"<<"-1 -1 1 Para avançar da posição 0 para 1\n-1 -1 2 Para avançar da posição 1 para 3\nPara mover do cava para um monte escreva o Id do cava para o monte de destino\nfinalizando com o indicador. EX: -1 0 3 (Moveria o elemento 3 do cava para o monte 0) ";
   
  gotoxy(0,25); // Posição das intruções na tela
  std::cout<<"\n\nDeseja começar a jogar?\n0 para nao e 1 para sim.\n";
  std::cout<<"> ";
  
  int comecajogo; // Confirmação de jogo
  
  std::cin>>comecajogo;
  
  if(comecajogo==0) exit(0); // caso 0 aborta o provesso
    
}



#endif