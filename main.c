#include <stdio.h>
void flush_in();

int main(void) {
	char mat[4][4], op;
	int i, j, opT;
	
	while(1){//Inicialização da Matriz
		for(i = 0; i < 4; i++ ){
			printf("|");
			
			if(i == 0){
				mat[0][0] = '*';
				printf("%c",mat[0][0]);
				for(j = 1; j < 4; j++){
					mat[i][j] = ' ';
		  			printf("%c",mat[i][j]);
		   		}	
			}
			else{
				for(j = 0; j < 4; j++){
					mat[i][j] = ' ';
		  			printf("%c",mat[i][j]);
		   		}
			}
			printf("|\n");
		}
		getch(op);
		opT = (int) op;
		flush_in();//Limpando o buffer do teclado
		
		switch(opT){
			case 113: break;
			default: printf("\nTeclas permitidas: \nSeta direcional esquerda \nSeta direcional superior\nSeta direcional direita\nSeta direcional inferior\n 'Q' para sair");
					 break;
		}
		system("@cls||clear");//Limpando o terminal
	}

	printf("\n\n");
	return 0;
}

void flush_in() {
	int ch;
	do {
		ch = fgetc(stdin);
	} while (ch != EOF && ch != '\n');
}
