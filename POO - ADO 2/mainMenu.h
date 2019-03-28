#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

int mainMenu(){

  int opcao;

  cout<<"===============================================" << endl;
  cout<<"          CADASTRO DE FUNCIONARIOS             " << endl;
  cout<<"                                               " << endl;
  cout<<"  Escolha uma opção:                           " << endl;
  cout<<"            (1) - Cadastrar Empregado          " << endl;
  cout<<"            (2) - Cadastrar ...                " << endl;
  cout<<"            (3) - Cadastrar ...                " << endl;
  cout<<"            (4) - Cadastrar ...                " << endl;
  cout<<"            (5) - Sair                         " << endl;
  cout<<"                                               " << endl;
  cout<<"                                               " << endl;
  cout<<"  Desenvolvido por: Vinicius Lima Fernandes    " << endl;
  cout<<"              POO - 3º Periodo                 " << endl;
  cout<<"===============================================" << endl;
  cin >> opcao;
  
//validacao do menu
  if(opcao < 1 || opcao > 5){
    cout << "Opção inválida. Execute o programa novamente."<< endl;
    return 0;
  }
  else{
    return opcao;
  }
}