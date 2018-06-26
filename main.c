#include <stdio.h>

int main(void) {
  char mat[4][4];
  int i, j;

  printf("\n");
  mat[1][1] = '*';
  //while(1){
	for(i = 0; i < 4; i++ ){
	   for(j = 0; j < 4; j++){
		mat[i][j] = '*';
	  	printf("%c",mat[i][j]);
	   }
	}    
  //}
  printf("\n\n");
  return 0;
}
