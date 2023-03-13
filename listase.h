#ifndef LISTASE_H
#define LISTASE_H

#include <stdio.h>
#include <stdlib.h>

#include "cartas.h"

typedef carta tp_item;

typedef struct tp_no{
  tp_item info;
  struct tp_no *prox;
}tp_listase;


tp_listase * inicializa_listase(){
		return NULL;
	}
	
int listase_vazia(tp_listase *lista){
	if(lista==NULL) return 1;
	return 0;
}

tp_listase * aloca_listase(){ // ela ir� alocar um espa�o na mem�ria;
	tp_listase *novo_no;
	novo_no=(tp_listase*) malloc(sizeof(tp_listase));
	return novo_no;
}

/* Esse **l � um ponteiro que est� apontando para outro ponteiro 
para o endere�o de mem�ria original da listase*, 
o que est� apontando para o NULL */

int insere_listase_no_fim(tp_listase **l, tp_item e){ 
tp_listase *novo_no, *atu;
novo_no=aloca_listase(); // aqui est� pegando o novo n� e apontando para o NULL;
if(novo_no==NULL) return 0; // N�o alocou mem�ria
// atribuir os valores para o novo n�;
novo_no->info= e;
novo_no->prox=NULL;
//finaliza o encadeamento do n�
if(listase_vazia(*l)){// se for o primeiro n� entra aqui
	*l=novo_no;
} else{
	atu = *l;
	while(atu->prox!=NULL){ 
	  atu=atu->prox; // aponta para o ultimo n�
	}
	atu->prox=novo_no;	
}
return 1;
}


/*
void imprime_listase(tp_listase *lista){
	tp_listase *atu;
	atu=lista;
	while (atu!=NULL){
		std::cout<<atu->info.nome<<std::endl;
		atu=atu->prox;
	}
}
*/



/*
tp_listase *busca_listase(tp_listase *lista, 
                                 tp_item e){
	tp_listase *atu;
	atu=lista;
	while((atu!=NULL)&&(atu->info!=e)){
		atu=atu->prox;
	}
	if (atu==NULL) return NULL;
	return atu;
}
*/

int tamanho_listase(tp_listase *lista){
    int cont=0;        
    tp_listase *atu;
    atu=lista;
    while(atu!=NULL){
        cont++;
        atu=atu->prox;
    }
    return cont;
}


void destroi_listase(tp_listase **l){
	tp_listase *atu;
	atu=*l;
	while (atu!=NULL){
		*l=atu->prox;
		free(atu);
		atu=*l;
	}
	*l=NULL;
}

#endif



