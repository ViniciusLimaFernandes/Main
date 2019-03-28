#include <iostream>
#include <fstream>
#include <cstdlib>
#include <empregado.h>
#include <importexport.h>
#include <mainMenu.h>

using namespace std;
 
int main () {
  empregado emp;
  int qtdEmp = 5;
  string *empNames = new string[qtdEmp], *empSobrenome = new string[qtdEmp];
  string *dataadm = new string[qtdEmp];
  double *empSalario = new double[qtdEmp];
  int opcaomenu, qtdEmpregados;
    
  opcaomenu = mainMenu(); //exibe o menu com as opcoes

  //escolha do menu
  switch(opcaomenu){
    case 0: //Condicao de encerramento de codigo para numeros escolhidos fora dos parametros do menu
      return 0;
    case 1:
      goto empregados;
      break;
    case 5:
      cout << "Você escolheu sair do programa, até logo!"<< endl;
      return 0;
  }

empregados:
  //Seta todos os nomes da string de empregados para x
  for(int i = 0; i<qtdEmp;i++){
      empNames[i] = "x";
  }

  cin.ignore(); 
  //Laço for que recebe os nomes dos empregados inputados pelo usuário
  for(int i = 0; i < qtdEmp; i++){
    cout <<  "\nDigite o nome e o primeiro sobrenome do empregado " << (i+1) <<":"<< endl;
    cin >> empNames[i];
    cin >> empSobrenome[i];
    cout <<  "\nData de admissão do funcionario "<< empNames[i]<< ":" << endl;
    cout <<  "Digite a data no formato DD/MM/YYYY" << endl;
    cin >> dataadm[i];
    cout <<  "\nSalario do funcionario "<< empNames[i]<< ":" << endl;
    cin>> empSalario[i];
  }

  //Laço for que upa os nomes inputados para a classe
  for(int i = 0; i < qtdEmp; i++){
    if(empNames[i] != "x"){
      emp.insertNome(&empNames[i]);
      emp.insertSobrenome(&empSobrenome[i]);
      emp.insertDataadm(&dataadm[i]);
      emp.insertSalario(&empSalario[i]);
    }
  }

  emp.printEmpregados();
  exit(EXIT_FAILURE);

  cout << "Hello world!";
}