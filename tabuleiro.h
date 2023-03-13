#ifndef TABULEIRO_H
#define TABULEIRO_H

#include <iostream>

#include "headerfiles.h"

//Mostra o a formatação da carta na tela
void imprime_carta(carta carta){
  if(carta.paraCima){
    if(carta.naipe=='*' || carta.naipe=='#'){
      textcolor(BLACK); // Muda a cor do naipe para preto
      std::cout<<"|"<<carta.simbolo<<carta.naipe<<"|";
    }
    else if(carta.naipe=='+' || carta.naipe=='-'){
      textcolor(RED); // Muda a cor do naipe para vermelho
      std::cout<<"|"<<carta.simbolo<<carta.naipe<<"|";
    }
    else{
      textcolor(LIGHTGRAY); // Cor da carta padrão
      std::cout<<"|"<<carta.simbolo<<carta.naipe<<"|";
    }
  }else{
      textcolor(WHITE);
      std::cout<<"|"<<"o"<<"o"<<"|"; // Carta virada para baixo
  }
  
}

//Imprime os montes de 0 a 6
void imprime_monte(tp_pilha monte, int posicaoX){
	tp_item e;
  int posicaoY = 13+altura_pilha(&monte);
  
	while (!pilha_vazia(&monte)){
		pop(&monte, &e);
    gotoxy(posicaoX,posicaoY);
		imprime_carta(e);
    posicaoY--;
	}
}

//Função do tabuleiro propriamente dito
void tabuleiro(tp_listase *cava, int carta_do_cava, tp_pilha montes[], tp_pilha mgc[]){

  int topo, i=7;
  
  // Cor do fundo
  textbackground(GREEN);
  clrscr();
  
  // Cor dos indices
  textcolor(BLUE);

  // Indice do cava
  gotoxy(11,6);
  std::cout<<"-1";
  
  // Indice dos montes guarda carta
  for(int x=41; x<=71; x+=10){
    gotoxy(x,6);
    std::cout<<i;
    i++;
  }
  
  // Indice da carta do cava
  gotoxy(5,8);
  std::cout<<carta_do_cava;

  // Indice dos montes
  i = 0;
  for(int x=11; x<=71; x+=10){
    gotoxy(x,12);
    std::cout<<i;
    i++;
  }
  
  // Imprime carta do cava
  gotoxy(10,8);
  imprime_carta(buscar_carta(cava, carta_do_cava));
  
  // Imprime monte guarda carta
  i = 0;
  for(int x=40; x<=70; x+=10){
    gotoxy(x,8);
    topo = altura_pilha(&mgc[i]) - 1;
    imprime_carta(mgc[i].item[topo]);
    i++;
  }
  
  // Imprime montes
  i = 0;
  for(int x=10; x<=70; x+=10){
    imprime_monte(montes[i], x);
    i++;
  }
  
  gotoxy(0,30);
  
  textcolor(WHITE);
cprintf("============================================================================================\n");
}

#endif