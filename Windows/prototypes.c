char mat[MAT][MAT];//CriaÃ§Ã£o da matriz
char tecla = 'd';//Tecla de inÃ­cio de jogo
Snake snake;//VariÃ¡vel global para a cobra
Candy candy;//VariÃ¡vel global para o doce

void gameOptions() {
	int op;
	
	do{
		printf("Welcome to the Snake Game \n Press 1 to start the new Game \n Press 2 to continue game \n");
		scanf("%d",&op);
		system("cls");
	}while(!(op == 1 || op == 2));
	
	switch(op) {
		case 1: inicializa();
			break;
		case 2: inicializaL();
			break;
	}
}

void inicializaL(){//Inicializa a matriz no inÃ­cio do programa
    int i = 1, tamanhoRes, temp;
    
    FILE *arq;
	int verifyArq;
	arq = fopen("settings.txt", "r");
	
	verifyArq = (arq == NULL) ? 1 : 0;
	if(verifyArq == 1) { printf("Problemas em abrir o arquivo"); return; }
	
	fscanf(arq, "%d", &snake.size);
	snake.p = (Position*) malloc(snake.size * sizeof(Position));
	ponteiroNulo(snake.p);

	fseek(arq, 2, SEEK_CUR);
	fscanf(arq, "%d", &snake.p[0].x);
	
	fseek(arq, 1, SEEK_CUR);
	fscanf(arq, "%d", &snake.p[0].y);

	fseek(arq, 1, SEEK_CUR);
	fscanf(arq, "%d", &candy.life);
	
	fseek(arq, 1, SEEK_CUR);
	fscanf(arq, "%d", &candy.position.x);
	
	fseek(arq, 1, SEEK_CUR);
	fscanf(arq, "%d", &candy.position.y);
	
	tamanhoRes = snake.size - 1;
	while(tamanhoRes > 0){
		fseek(arq, 1, SEEK_CUR);
		fscanf(arq, "%d", &temp);
		if(temp >= 0){
			snake.p[i].x = temp % 10;
			snake.p[i].y = temp / 10;
			i++;
			tamanhoRes--;
		}
	}

	fseek(arq, -1, SEEK_END);
	fscanf(arq,"%c",&tecla);
	
	fclose(arq);
	clear();
	mat[candy.position.y][candy.position.x] = '$';
    insert();
    imprimir();
    sleep(1);
    system("cls");
    movimentar();
}

void inicializa(){//Inicializa a matriz no inÃ­cio do programa
    int i;
	snake.size = 3; 
	snake.p = (Position*) malloc(snake.size * sizeof(Position));
	ponteiroNulo(snake.p);
    
	for(i = 0; i < snake.size;i++) {
		snake.p[i].x = snake.size - i - 1;
		snake.p[i].y = 0;
	}
	clear();
    gerarDoce();
    insert();
    movimentar();
}

void movimentar(){//mover
	char tec;
	Position head = snake.p[0];
	while(1){
		imprimir();
		
		if (kbhit()){
			tec = getch();
			if((tecla=='a' && tec != 'd') || (tecla=='d' && tec != 'a') || (tecla=='w' && tec != 's') || (tecla=='s' && tec != 'w') || (tec == 'q')){
				if((tec != 'w' && tec != 's' && tec != 'd' && tec != 'a' && tec != 'q' && tec != 'r') && (tec != 'W' && tec != 'S' && tec != 'D' && tec != 'A' && tec != 'Q' && tec != 'R')){
					printf("Teclas permitidas: \nPara cima (tecla W), \nPara baixo (tecla S),\nPara a esquerda (tecla A)\nPara a direita (tecla D)\nPara sair (tecla Q)\n\n");
					sleep(2);
				}
				else if(tec == 'r' || tec == 'R'){}
				else
					tecla = tec;
			}
		}
		
		switch(tec){
			case 'r':
			case 'R':	fileHelperW(tecla);
				break;
		}
		switch(tecla){
            case 'A':
	    	case 'a':	head.x--;
	    	    break;
            
            case 'D':
	    	case 'd':	head.x++;
	    	    break;
            
            case 'Q':
			case 'q':	free(snake.p);
						exit(0);//Para encerrar o jogo
			
            case 'S':
            case 's':	head.y++;
	    		break;
	    	
            case 'W':
            case 'w':	head.y--;
	    	    break;
            
            case 'R':
	    	case 'r': //fileHelperW();
	    			  break;
	    	default:
	    	    break;
		}
		candy.life--;
		if(candy.life == 0){//Caso a vida do doce acabe, serÃ¡ criado outro doce em outra posiÃ§Ã£o aleatÃ³ria na matriz
    		mat[candy.position.y][candy.position.x] = ' ';
    		gerarDoce();
		}
		colider(head);
    	usleep(225000);//0,225 segundos de delay
    	crescer(head);
		clear();
		mat[candy.position.y][candy.position.x] = '$';
		insert();
		system("cls");
	}
}
