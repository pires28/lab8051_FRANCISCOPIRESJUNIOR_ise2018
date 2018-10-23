#include <at89x52.h>

// PINAGEM CAMERAS DE MONITORAMENTO
#define CAMERA_0 P0_0
#define CAMERA_1 P0_1
#define CAMERA_2 P0_2
#define CAMERA_3 P0_3

// PINAGEM SENSORES DE MONITORAMENTO

#define SENSOR_0 P2_0
#define SENSOR_1 P2_1
#define SENSOR_2 P2_2
#define SENSOR_3 P2_3

// PINAGEM ALARME

#define ALARME P1_0

int contador = 0;

void monitoramento() interrupt 1 {
		TR0 = 0;
		TH0 = 0x3C;
		TL0 = 0xAF;
		TR0 = 1;
	
	contador++;
	
	if(contador == 60){
		CAMERA_0 = 1;
		CAMERA_1 = 0;
		CAMERA_2 = 0;
		CAMERA_3 = 0;
		if(SENSOR_0 == 1){
			CAMERA_0 = 1;
			ALARME = 1;
		}
	}
	
	if(contador == 120){
		CAMERA_0 = 0;
		CAMERA_1 = 1;
		CAMERA_2 = 0;
		CAMERA_3 = 0;
		if(SENSOR_1 == 1){
			CAMERA_1 = 1;
			ALARME = 1;
		}
	}
	
	if(contador == 180){
		CAMERA_0 = 0;
		CAMERA_1 = 0;
		CAMERA_2 = 1;
		CAMERA_3 = 0;
		if(SENSOR_2 == 1){
			CAMERA_2 = 1;
			ALARME = 1;
		}
	}
	
	if(contador == 240){
		CAMERA_0 = 1;
		CAMERA_1 = 0;
		CAMERA_2 = 0;
		CAMERA_3 = 1;
		if(SENSOR_3 == 1){
			CAMERA_3 = 1;
			ALARME = 1;
		}
		contador = 0;
	}

}

void main(){
	
	// inicialização das portas
	P0 = 0;
	P1 = 0;
	P2 = 0;
	
	// inicialização das câmeras e sensores
	CAMERA_0 = 0;
	CAMERA_1 = 0;
	CAMERA_2 = 0;
	CAMERA_3 = 0;
	
	SENSOR_0 = 0;
	SENSOR_1 = 0;
	SENSOR_2 = 0;
	SENSOR_3 = 0;
	
	ALARME = 0;
		
	EA = 1;
	ET0 = 1;
	TMOD = 1;
	TR0 = 1;
	
	while(1){
		
	}
}