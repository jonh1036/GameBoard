//
//  Created by Jonathan and Mangueira on 26/06/2018.
//  Copyright © 2018 Jonh. All rights reserved.
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
    char op;
    int i, j;
    x = 0, y = 0;
    
    **mat = inicializa();//Inicialização da Matriz
    while(1){
        scanf("%c",&op);
        flush_in();//Limpando o buffer do teclado
        system("@cls||clear");//Limpando o terminal FUNFA NO DEVC++
        
        switch(op){
            case 26: direita();//descobrir qual é o código ASCII das setas do teclado
                break;
                
            case 113: break;
                
            default: printf("\nTeclas permitidas: \nSeta direcional esquerda \nSeta direcional superior\nSeta direcional direita\nSeta direcional inferior\n 'Q' para sair\n");
                break;
        }
        imprimir();
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
    
    aux = mat[x][y];
    mat[x][y] = mat[x][y+1];
    mat[x][y+1] = aux;
    
    y +=1;
    return (**mat);
}

void **esquerda(){//Função que move o '*' para a esquerda
    char aux;
    
    aux = mat[x][y];
    mat[x][y] = mat[x][y-1];
    mat[x][y+-] = aux;
    
    y -=1;
    return (**mat);
}

void **cima(){//Função que move o '*' para a cima
    char aux;
    
    aux = mat[x][y];
    mat[x][y] = mat[x+1][y];
    mat[x+1][y] = aux;
    
    x +=1;
    return (**mat);
}

void **baixo(){//Função que move o '*' para a baixo
    char aux;
    
    aux = mat[x][y];
    mat[x][y] = mat[x-1][y];
    mat[x-1][y] = aux;
    
    x -=1;
    return (**mat);
}
