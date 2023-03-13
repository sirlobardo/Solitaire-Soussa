#include <iostream>
#include <conio.h>

#include "cartas.h"
#include "pilha.h"
#include "listase.h"
#include "funcoes.h"
#include "mecanicas.h"
#include "tabuleiro.h"

int main() {
  //Declara o baralho e a carta void
  carta baralho[52], carta_void;
  criarBaralho(baralho); //Adiciona as cartas ao baralho
  embaralhar(baralho); // Embaralha as cartas

  //Declaração dos montes 
  tp_pilha montes[7], montes_guarda_carta[4];
  inicializar_montes(montes); // Inicializa os montes 0 a 6
  inicializar_mgc(montes_guarda_carta); // Inicializa os montes de 7 a 10
  tp_listase *cava=inicializa_listase(); //Declaração e inicialização do cava
  
  colocar_nos_montes(montes,baralho); // Distribuição de cartas para cada monte ( 0 a 6 )
  colocar_no_cava(&cava,baralho); // O restante das cartas vai para o cava
  colocar_no_mgc(carta_void, montes_guarda_carta); // Coloca a carta void nos montes de 7 a 10
  
  virar_cartas_do_cava(&cava); //Vira as cartas do cava
  virar_cartas_do_mgc(montes_guarda_carta); //Vira as primeiras cartas dos montes finais
  virar_carta_dos_montes(montes); //Vira as primeiras cartas dos montes 
  
  menu(); // Inicializa o jogo e chama o menu inicial

  // Declara variáveis usadas no loop
  int id_monte1, id_monte2, id_cava = 0, topo_m1, quantidade_de_cartas;
  
  //loop do jogo
  while(true){
      //Chama a função tabuleiro
      tabuleiro(cava,id_cava,montes,montes_guarda_carta);
      std::cout<<">";
      std::cin>>id_monte1>>id_monte2>>quantidade_de_cartas;
      
      //Movimentação de cartas cava/montes e exibir cartas do cava
      if(quantidade_de_cartas >= 0 && quantidade_de_cartas<tamanho_listase(cava)){
        // Cava para o montes de 0 a 6
        if(id_monte1==-1 && (id_monte2>=0 && id_monte2<7)){
          mover_carta_do_cava(&cava,&montes[id_monte2],quantidade_de_cartas);
        }
        
        //Passar as cartas do cava para o monte final( 7 a 10 )
        if(id_monte1==-1 && (id_monte2>=7 && id_monte2<=10)){
          
          if(id_monte2==7){
           mover_do_cava_para_o_mgc(&cava,&montes_guarda_carta[0],quantidade_de_cartas);
          } 
           if(id_monte2==8){
           mover_do_cava_para_o_mgc(&cava,&montes_guarda_carta[1],quantidade_de_cartas);
          } 
           if(id_monte2==9){
           mover_do_cava_para_o_mgc(&cava,&montes_guarda_carta[2],quantidade_de_cartas);
          } 
           if(id_monte2==10){
           mover_do_cava_para_o_mgc(&cava,&montes_guarda_carta[3],quantidade_de_cartas);
          } 
        }
        //Passando o cava 
        if(id_monte1==-1 && id_monte2==-1){
          id_cava = quantidade_de_cartas;
        }
        
      }
    //Passando os montes 0 a 6 para os finais ( 7 a 10 ) 
      if(id_monte2==7){
        guardar_cartas_no_mgc(&montes[id_monte1],&montes_guarda_carta[0]);
        topo_m1 = altura_pilha(&montes[id_monte1]) - 1;
        virar_carta(&montes[id_monte1].item[topo_m1]);
        
      }
      else if(id_monte2==8){
        guardar_cartas_no_mgc(&montes[id_monte1],&montes_guarda_carta[1]);
        topo_m1 = altura_pilha(&montes[id_monte1]) - 1;
        virar_carta(&montes[id_monte1].item[topo_m1]);
      }
      else if(id_monte2==9){
        guardar_cartas_no_mgc(&montes[id_monte1],&montes_guarda_carta[2]);
        topo_m1 = altura_pilha(&montes[id_monte1]) - 1;
        virar_carta(&montes[id_monte1].item[topo_m1]);
      }
      else if(id_monte2==10){
        guardar_cartas_no_mgc(&montes[id_monte1],&montes_guarda_carta[3]);
        topo_m1 = altura_pilha(&montes[id_monte1]) - 1;
        virar_carta(&montes[id_monte1].item[topo_m1]);
      }
      if((id_monte1>=0 && id_monte1<=6) && id_monte2>=0 && id_monte2<=6){
        mover_carta(&montes[id_monte1],&montes[id_monte2],quantidade_de_cartas);
        topo_m1 = altura_pilha(&montes[id_monte1]) - 1;
        virar_carta(&montes[id_monte1].item[topo_m1]);  
      }
      
      
    }
  return 0;
}

