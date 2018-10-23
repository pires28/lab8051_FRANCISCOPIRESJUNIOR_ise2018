#include <at89x52.h>

#define ESTEIRA_CAIXA P2_0
#define ESTEIRA_PRODUTO P2_1
#define CAIXA_CHEIA P2_3


int contador, qtdProduto = 0;

void atendeTimer() interrupt 1 {
		TR0 = 0;
		TH0 = 0x3C;
		TL0 = 0xAF;
		TR0 = 1;
	
	contador++;
	
	if(qtdProduto < 70){
		qtdProduto++;
	} 
	if(qtdProduto == 70){
		CAIXA_CHEIA = 1;
	}
	
	
	if(contador == 50){
			ESTEIRA_CAIXA = 0;
			ESTEIRA_PRODUTO = 1;
	}
	if(contador == 70 && CAIXA_CHEIA == 1){
		CAIXA_CHEIA = 0;
		contador = 0;
		qtdProduto = 0;
		ESTEIRA_CAIXA = 1;
		ESTEIRA_PRODUTO = 0;
	}
}

void main(){
	
	P2 = 0;
	EA = 1;
	ET0 = 1;
	TMOD = 1;
	TR0 = 1;
	
	ESTEIRA_CAIXA = 1;
	ESTEIRA_PRODUTO = 0;
	
	while(1){
		;
		
	}
}