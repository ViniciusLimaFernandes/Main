#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>

int mainMenu(){

  int opcao;

  while (opcao < 1 || opcao > 5) {
    cout<<"===============================================" << endl;
    cout<<"          CADASTRO DE FUNCIONARIOS             " << endl;
    cout<<"                                               " << endl;
    cout<<"  Escolha uma opção:                           " << endl;
    cout<<"            (1) - Cadastrar Funcionário        " << endl;
    cout<<"            (2) - Visualizar Funcionário(s)    " << endl;
    cout<<"            (3) - Atualizar Dados              " << endl;
    cout<<"            (4) - Remover Funcionário          " << endl;
    cout<<"            (5) - Sair                         " << endl;
    cout<<"                                               " << endl;
    cout<<"                                               " << endl;
    cout<<"               Desenvolvido por:               " << endl;
    cout<<"            Vinicius Lima Fernandes            " << endl;
    cout<<"             Victor da Silva Costa             " << endl;
    cout<<"                                               " << endl;
    cout<<"               POO - 3º Periodo                " << endl;
    cout<<"===============================================" << endl;
    cout << "" << endl;

    cin >> opcao;
  
    if (opcao < 1 || opcao > 5) {
      cout << "\x1B[2J\x1B[H";
      cout << "Opção inválida! "<< endl;
      cout << "" << endl;
    }
  }

  return opcao;
}