#ifndef CARTA_H
#define CARTA_H

//CARTA
typedef struct cta{
    int simbolo; // Numeração
    char naipe; // Naipe mesmo
    bool paraCima; // Se está virada
  //CARTA PADRAO
    cta(){
      simbolo = 0;
      naipe = 'x';
      paraCima = false;
    }
}carta; 

void criarBaralho(carta baralho[]){ // Baralho propriamente dito
  
    //NAIPE DAS CARTAS * ( Preto ) 
    baralho[0].naipe = '*';
    baralho[1].naipe = '*';
    baralho[2].naipe = '*';
    baralho[3].naipe = '*';
    baralho[4].naipe = '*';
    baralho[5].naipe = '*';
    baralho[6].naipe = '*';
    baralho[7].naipe = '*';
    baralho[8].naipe = '*';
    baralho[9].naipe = '*';
    baralho[10].naipe = '*';
    baralho[11].naipe = '*';
    baralho[12].naipe = '*';
   

  //NAIPE DAS CARTAS # ( Preto ) 
    baralho[13].naipe = '#';
    baralho[14].naipe = '#';
    baralho[15].naipe = '#';
    baralho[16].naipe = '#';
    baralho[17].naipe = '#';
    baralho[18].naipe = '#';
    baralho[19].naipe = '#';
    baralho[20].naipe = '#';
    baralho[21].naipe = '#';
    baralho[22].naipe = '#';
    baralho[23].naipe = '#';
    baralho[24].naipe = '#';
    baralho[25].naipe = '#';

  //NAIPE DAS CARTAS + ( Vermelho ) 
    baralho[26].naipe = '+';
    baralho[27].naipe = '+';
    baralho[28].naipe = '+';
    baralho[29].naipe = '+';
    baralho[30].naipe = '+';
    baralho[31].naipe = '+';
    baralho[32].naipe = '+';
    baralho[33].naipe = '+';
    baralho[34].naipe = '+';
    baralho[35].naipe = '+';
    baralho[36].naipe = '+';
    baralho[37].naipe = '+';
    baralho[38].naipe = '+';

  //NAIPE DAS CARTAS - ( Vermelho )
    baralho[39].naipe = '-';
    baralho[40].naipe = '-';
    baralho[41].naipe = '-';
    baralho[42].naipe = '-';
    baralho[43].naipe = '-';
    baralho[44].naipe = '-';
    baralho[45].naipe = '-';
    baralho[46].naipe = '-';
    baralho[47].naipe = '-';
    baralho[48].naipe = '-';
    baralho[49].naipe = '-';
    baralho[50].naipe = '-';
    baralho[51].naipe = '-';

   //Simbolo(Numeração) DAS CARTAS * ( Preto )  
    baralho[0].simbolo = 1;
    baralho[1].simbolo = 2;
    baralho[2].simbolo = 3;
    baralho[3].simbolo = 4;
    baralho[4].simbolo = 5;
    baralho[5].simbolo = 6;
    baralho[6].simbolo = 7;
    baralho[7].simbolo = 8;
    baralho[8].simbolo = 9;
    baralho[9].simbolo = 10;
    baralho[10].simbolo = 11;
    baralho[11].simbolo = 12;
    baralho[12].simbolo = 13;


    //Simbolo(Numeração) DAS CARTAS # ( Preto )
    baralho[13].simbolo = 1;
    baralho[14].simbolo = 2;
    baralho[15].simbolo = 3;
    baralho[16].simbolo = 4;
    baralho[17].simbolo = 5;
    baralho[18].simbolo = 6;
    baralho[19].simbolo = 7;
    baralho[20].simbolo = 8;
    baralho[21].simbolo = 9;
    baralho[22].simbolo = 10;
    baralho[23].simbolo = 11;
    baralho[24].simbolo = 12;
    baralho[25].simbolo = 13;


  //Simbolo(Numeração) DAS CARTAS + ( Vermelho ) 
    baralho[26].simbolo = 1;
    baralho[27].simbolo = 2;
    baralho[28].simbolo = 3;
    baralho[29].simbolo = 4;
    baralho[30].simbolo = 5;
    baralho[31].simbolo = 6;
    baralho[32].simbolo = 7;
    baralho[33].simbolo = 8;
    baralho[34].simbolo = 9;
    baralho[35].simbolo = 10;
    baralho[36].simbolo = 11;
    baralho[37].simbolo = 12;
    baralho[38].simbolo = 13;

  //Simbolo(Numeração) DAS CARTAS - ( Vermelho ) 
    baralho[39].simbolo = 1;
    baralho[40].simbolo = 2;
    baralho[41].simbolo = 3;
    baralho[42].simbolo = 4;
    baralho[43].simbolo = 5;
    baralho[44].simbolo = 6;
    baralho[45].simbolo = 7;
    baralho[46].simbolo = 8;
    baralho[47].simbolo = 9;
    baralho[48].simbolo = 10;
    baralho[49].simbolo = 11;
    baralho[50].simbolo = 12;
    baralho[51].simbolo = 13;

 

}

  
 #endif

