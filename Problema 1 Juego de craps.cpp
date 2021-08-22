#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*El juego de dados conocido como “craps” (tiro perdedor)
es muy popular, realice un programa que simule dicho juego, 
a continuación se muestran las reglas para los jugadores.*/ 
	
int determinante();

int main(){
	
	srand(time(NULL));
	
	printf("  CRAPS \n\n");
	//Imprimir los puntos 
	int juego = determinante();
	
	if (juego == 1){
		
		printf("\n\n ¡Felicidades! Ganaste. \n");
		
	}		
	else if (juego == 0){
		
		printf("\n\n Lo siento :(. Haz perdido. \n");
		
	}
}
int tiradas(){
	
	int total = 0, n = 0;
	
	//rand 
	for (int i = 0; i<2; i++){
		
		total = 1 + rand()%(7-1); 
		printf(" %i +", total); //Los numeros que salieron
		n+= total;
	}
	
	printf(" = %i", n);
	return n;
}
int determinante(){
	
	system("cls");
	// 7 o 11 jugador gana
	// 2, 3 o 12 casa gana, jugador pierde
	// 4, 5, 6, 7, 9 o 10 dicha suma se vuelve el punto
	// Si despues de la juegos tirada sale un 7 el jugador pierde
	//0 pierde 1 gana 2 continua
	
	int prim_estado;
	int puntos = tiradas();
	
	if ((puntos == 7)||(puntos == 11)){
		
		prim_estado = 1;
		
	}else if ((puntos == 2)||(puntos == 3)||(puntos == 12)){
		
		prim_estado = 0;
		
	}else{
		
		printf("\n\nNadie gana, el juego continua.");
		printf("\n\nEl %i", puntos);
		printf(" pasa a ser el nuevo punto ganador.\n\n ");
		prim_estado = 2;
	}
	
	
	int juegos = prim_estado;
	int estado = juegos;
	
	fflush(stdin);

	if (juegos == 2){
		
		while (estado == 2){ //hasta que se pierda o se gane
				
			estado = puntos; 
			juegos = tiradas(); 
			puntos = juegos; 	
				
			if (juegos == estado){
					
				estado = 1;
				
			}else if (juegos == 7){
				
				estado = 0;
				
			}else{
				
				printf("\n\nNadie gana, el juego continua.");
				printf("\n\nEl %i", puntos);
				printf(" pasa a ser el nuevo punto ganador.\n\n ");
				estado = 2;
				
			}
		}
	}
	return estado;
} 
