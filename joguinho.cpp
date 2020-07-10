#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

class Jogo {
	
	public:
		
		char nome[30], campo[20][20];
		int vida, pos, tempo, valor, obs, novo, pont;
		
		void Temporizador() {
			
			while (tempo != 0) {
				
				Obstaculos();
				Esquerda();
				Direita();
				Vida();
				Sair();
				pont++;
				Mostrar();
				
			}
			
		}
		
		void Obstaculos() {
			
			for (int i = 0; i < 1; i++) {
				
				obs = rand() % 20;
				campo[19][obs] = 'K';
				
			}
			
			for (int y = 0; y < 20; y++) {
				
				for (int x = 0; x < 20; x++) {
					
					if (campo[y][x] == 'K') {
						
						campo[y][x] = ' ';
						
						if (y > 4) {
							
							novo = y - 1;
							campo[novo][x] = 'K';
							
						}
						
					}
					
				}
				
			}
			
		}
		
		void Vida() {
			
			if (vida == 0) {
				
				tempo = 0;
				
			}
			
		}
		
		int Mostrar() {
			
			system("cls");
			
			for (int y = 0; y < 20; y++) {
				
				for (int x = 0; x < 20; x++) {
					
					printf("%c", campo[y][x]);
					
				}
				
				printf("\n");
				
			}
			
			printf("\nVida: %d       Pontuacao: %d", vida, pont);
			
		}
		
		void Esquerda() {
			
			if(GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/) {
				
			    if (pos > 0) {
			    	
			    	campo[5][pos] = ' ';
			    	pos--;
			    	
			    	if (campo[5][pos] == 'K') {
			    		
			    		campo[5][pos] = 'O';
			    		vida--;
			    		
					} else {
				    	
				    	campo[5][pos] = 'v';
						
					}
			    	
				}
			    
			}
			
		}
		
		void Direita() {
			
			if(GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/) {
				
			    if (pos < 19) {
			    	
			    	campo[5][pos] = ' ';
			    	pos++;
			    	
			    	if (campo[5][pos] == 'K') {
			    		
			    		campo[5][pos] = 'O';
			    		vida--;
			    		
					} else {
				    	
				    	campo[5][pos] = 'v';
						
					}
			    	
				}
			    
			}
			
		}
		
		void Sair() {
			
			if (GetKeyState('P') & 0x8000) {
				
				tempo = 0;
				
			}
			
		}
		
	
};

int main() {
	
	Jogo jogo;
	
	for (int y = 0; y < 20; y++) {
		
		for (int x = 0; x < 20; x++) {
			
			jogo.campo[y][x] = ' ';
			
		}
		
	}
	
	jogo.pos = 12;
	jogo.campo[5][jogo.pos] = 'v';
	jogo.Obstaculos();
	jogo.pont = 0;
	jogo.vida = 3;
	jogo.Mostrar();
	jogo.tempo = 1;
	jogo.Temporizador();
	
}
