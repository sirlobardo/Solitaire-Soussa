#ifndef MECANICAS_H
#define MECANICAS_H

//Bibliotecas 
#include <iostream>
#include <stdio.h>

#include "headerfiles.h" // Biblioteca das bibliotecas

// Busca uma carta na lista
carta buscar_carta(tp_listase *cava, int ordem_da_carta){
  tp_listase *atu = cava;
  for(int i=0;i<ordem_da_carta;i++){
    atu=atu->prox;
  }
  return atu->info;
}

/*Função booleana que verifica se é possivel realizar a
movimentação da carta inicial para final */
bool pode_mover_carta(carta carta_partida,carta carta_final)  {
  if(carta_partida.paraCima){
    if (carta_partida.simbolo==13 && carta_final.naipe=='x' ) {
      carta_final.paraCima=false;
      return true;}
    if( // Naipes de mesmo tipo ou iguais nao empilha
    
        (carta_partida.naipe=='*' && carta_final.naipe=='*') ||
        (carta_partida.naipe=='*' && carta_final.naipe=='#') ||
        (carta_partida.naipe=='#' && carta_final.naipe=='*') ||
        (carta_partida.naipe=='#' && carta_final.naipe=='#') ||
        (carta_partida.naipe=='+' && carta_final.naipe=='+') ||
        (carta_partida.naipe=='+' && carta_final.naipe=='-') || 
        (carta_partida.naipe=='-' && carta_final.naipe=='-') || 
        (carta_partida.naipe=='-' && carta_final.naipe=='+') 
      )return false; 
  
    else{
      if(carta_partida.simbolo  == carta_final.simbolo-1){
        return true;
        }else return false; // Se a carta for maior nao empilha
             }


  }

  return false;

}

// Move carta entre os montes de 0 a 6
bool mover_carta(tp_pilha *monte_partida, tp_pilha *monte_final, int quantidade_de_cartas){
  
  tp_item e;
  int topo_mf = altura_pilha(monte_final) - 1;
  tp_pilha cartas_a_serem_movidas;
  inicializa_pilha(&cartas_a_serem_movidas);

  for(int i=0;i<quantidade_de_cartas;i++){
    pop(monte_partida, &e);
    push(&cartas_a_serem_movidas,e);
  }
  int topo_cam = altura_pilha(&cartas_a_serem_movidas) - 1;
  
  if(pode_mover_carta(cartas_a_serem_movidas.item[topo_cam],monte_final->item[topo_mf])){
    while(!pilha_vazia(&cartas_a_serem_movidas)){
      pop(&cartas_a_serem_movidas, &e);
      push(monte_final,e);
    }
    return true;
  }
  while(!pilha_vazia(&cartas_a_serem_movidas)){
      pop(&cartas_a_serem_movidas, &e);
      push(monte_partida,e);
    }
  return false;
  
}

// Remove uma carta do cava 
bool remover_do_cava(tp_listase **cava, int ordem_da_carta, tp_item &carta_retirada){
  tp_listase * ant, *atu;
	atu=*cava;
	ant=NULL;
	for(int i=0;i<ordem_da_carta;i++){
		ant=atu;
		atu=atu->prox;	
		}
    carta_retirada=atu->info;
	
	if (ant==NULL){
		*cava=atu->prox; 
	}
	else{
		ant->prox=atu->prox;
	}
	free(atu);
	atu=NULL;
	return 1;
}

//Função para passar a carta do cava
bool mover_carta_do_cava(tp_listase **cava, tp_pilha *monte, int ordem_da_carta_do_cava){
  
  carta temp;
  
  tp_listase *atu = *cava;
  int indice = altura_pilha(monte) - 1;
  for(int i = 0; i<ordem_da_carta_do_cava; i++){
    atu = atu->prox;
  }
  if(pode_mover_carta(atu->info, monte->item[indice])){
    remover_do_cava(cava, ordem_da_carta_do_cava,temp);
    push(monte,temp);
    return true;
  }
  return false;
}

//Verifica se é possivel armazenar as cartas nos montes 7 a 10
bool pode_guardar_cartas_no_mgc(carta carta_partida, carta carta_final){
  if(carta_final.naipe=='x' && carta_partida.simbolo!=1) return false;
  if(carta_partida.paraCima){
    
    if(carta_final.naipe != 'x'){
      if(carta_partida.naipe != carta_final.naipe) return false;
      if(carta_final.simbolo == carta_partida.simbolo-1) return true;  
      return false;  
    }
    return true; 
  }
  return false;
  
}

//Armazena as cartas dos montes 0 a 6 no monte final
bool guardar_cartas_no_mgc(tp_pilha *monte, tp_pilha *mgc){
  if(pode_guardar_cartas_no_mgc(monte->item[monte->topo], mgc->item[monte->topo])){
    tp_item e;
    pop(monte, &e);
    push(mgc, e);
    return true;
  }
  return false;
}

//Função usada para mover a carta do cava para o monte final de maneira direta
bool mover_do_cava_para_o_mgc(tp_listase **cava, tp_pilha *mgc, int ordem_da_carta_do_cava){
    
  carta temp;
  
  tp_listase *atu = *cava;
  int indice = altura_pilha(mgc) - 1;
  for(int i = 0; i<ordem_da_carta_do_cava; i++){
    atu = atu->prox;
  }
  if(pode_guardar_cartas_no_mgc(atu->info, mgc->item[indice])){
    remover_do_cava(cava, ordem_da_carta_do_cava,temp);
    push(mgc,temp);
    return true;
  }
  return false;
}

#endif