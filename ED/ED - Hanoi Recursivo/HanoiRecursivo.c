#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void hanoiFunc(int qtdDisc,char origem,char destino, char aux){
  if(qtdDisc == 1){
    printf(" Movendo o disco 1 da torre %c para a torre %c",origem,destino);
    return;
  }
  hanoiFunc(qtdDisc-1,origem,aux,destino);
  printf("\n Movendo o disco %d da torre %c para a torre %c\n", qtdDisc, origem,destino);
  hanoiFunc(qtdDisc-1,aux,destino,origem);

}

int main(void) {

  int discQtd;

  printf("Insira a quantidade de discos: \n");
  scanf("%d",&discQtd);

  hanoiFunc(discQtd,'A','C','B');

  
  return 0;
  //Para compilar usar -> make HanoiRecursivo (Sem o .c mesmo)
}