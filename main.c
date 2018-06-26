//
//  Created by Jonathan Pinho and Vinicius Mangueira on 26/06/2018.
//  Copyright © 2018 Jonathan. All rights reserved.
//

#include <stdio.h>
void flush_in();
void imprimir();
char **inicializa();
void **direita();
void **esquerda();
void **cima();
void **baixo();

int x, y;//Coordenadas da matriz
char mat[4][4];//Criação da matriz

int main(void) {
    char tecla;
    int i, j;
    x = 0, y = 0;
    
    **mat = inicializa();//Inicialização da Matriz
    while(1){
        //scanf("%c",&op);
		tecla = getch();
		system("@cls||clear");//Limpando o terminal FUNFA NO DEVC++
		if (tecla == -32){
		    tecla = getch();
		    switch(tecla){
		        case 72: cima();//Seta para cima
		            break;
		        case 75: esquerda();//Seta para esquerda
		            break;
		        case 77: direita();//Seta para direita
		            break;
		        case 80: baixo();//Seta para baixo
		            break;
	
				case 113: 
					exit(0);
					

	            default: printf("Teclas permitidas: \nSeta direcional esquerda \nSeta direcional superior\nSeta direcional direita\nSeta direcional inferior\n 'Q' para sair\n\n");
	                break;
        	}
    	}
        imprimir();
        //flush_in();//Limpando o buffer do teclado T¡ BUGANDO
    }
    
    printf("\n\n");
    return 0;
}

void flush_in() {//Função que limpa o buffer do teclado
    int ch;
    do {
        ch = fgetc(stdin);
    } while (ch != EOF && ch != '\n');
}

char **inicializa(){//Função que inicializa a matriz no início do programa
    int i, j;
    for(i = 0; i < 4; i++ ){
        printf("|");
        
        if(i == 0){
            mat[0][0] = '*';//Origem
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
    return (**mat);
}

void imprimir(){//Função que imprime a matriz completa
    int i, j;
    
    for(i = 0; i < 4; i++){
        printf("|");
        for(j = 0; j < 4; j++){
            if(mat[i][j] == ' ')
                printf(" ");
            else
                printf("%c",mat[i][j]);
        }
        printf("|\n");
    }
}

void **direita(){//Função que move o '*' para a direita
    char aux;

	if(mat[x][y] > mat[x][15]) { //adcionando extremidades pra direita
	
    aux = mat[x][y];
    mat[x][y] = mat[x][y+1];
    mat[x][y+1] = aux;
    
    y +=1;
	}
}

void **esquerda(){//Função que move o '*' para a esquerda
    char aux;
    
    if(mat[x][y] > mat[x][0]) { //adcionando extremidades pra esquerda
	aux = mat[x][y];
    mat[x][y] = mat[x][y-1];
    mat[x][y-1] = aux;
    
    y -=1;
	}
}

void **cima(){//Função que move o '*' para a cima
    char aux;
    
    if(mat[x][y] > mat[0][y]) { //adcionando extremidades pra cima
	
	aux = mat[x][y];
    mat[x][y] = mat[x-1][y];
    mat[x-1][y] = aux;
    
    x -=1;
}

}

void **baixo(){//Função que move o '*' para a baixo
    char aux;
    
    if(mat[x][y] > mat[3][y]) { //adcionando extremidades pra baixo
    aux = mat[x][y];
    mat[x][y] = mat[x+1][y];
    mat[x+1][y] = aux;	
		x +=1;
	}

    
}


