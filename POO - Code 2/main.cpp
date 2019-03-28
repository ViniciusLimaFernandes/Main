#include<vetores.h>
#include<iostream>

using namespace std;

int main() {
  vetores v1,v2(6,10),v3(5,1,6),v4(10);

  //v1.mostraVetorpos(0);

  //v2.mostraVetorpos(2);

  //v3.mostraVetorpos(2);

  v1.busca(88);
  v1.printVetor();

  v1.mostraVetorpos(5);
  v1.deletar(5);
  v1.mostraVetorpos(5);

  v1.printVetor();

  v1.combinar(v2);



}