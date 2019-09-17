#include <stdio.h>

int calcFib(n){
  if(n == 1 || n == 2) return 1;
  return calcFib(n-1)+calcFib(n-2);
}

int main(void) {
  int n;
  printf("Digite um numero: \n");
  scanf("%d", &n);

  printf("Fibonacci de %d é: %d \n", n, calcFib(n));
  return 0;
}