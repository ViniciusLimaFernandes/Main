#include<iostream>
#include<cstdlib>
using namespace std;

class empregado{
  
  private: //Parte privada do codigo

  int qtd = 5; //Quantidade de empregados
  int numFunc, numID, numSobrenome, numData, numSalario; //Variaveis auxiliares
  int *id = new int[qtd]; //ID do funcionario
  string *nome = new string[qtd];
  string *sobrenome = new string[qtd];
  string *dtadm = new string[qtd]; //data de admissão do funcionario
  double *salario = new double[qtd]; //Salario dos empregados

  public: // parte publica do objeto com construtores e funcoes

  empregado() {
    //Limpa variaveis antes do uso
    for(int i= 0; i <qtd; i++){
      nome[i] = "x";
    }
    for(int i= 0; i <qtd; i++){
      sobrenome[i] = "x";
    }
    for(int i= 0; i < qtd; i++){
      id[i] = 0;
    }
    numData = 0;
    numSobrenome=0;
    numID=0;
    numFunc=0;
  }

  void insertId(int *id_user){
    for(int i=0; i<qtd;i++){
      if(id[i] != '\0'){
        id[i] = *id_user;
      }
    }
  }

  //insere os nomes dos usuarios
  void insertNome(string *user_name){ 
    nome[numFunc] = *user_name;
    id[numFunc] = numID++; 
    numFunc++;    
  }

  void printEmpregados(){
    for(int i=0; i< qtd;i++){
      if(nome[i] != "x"){
        cout << id[i] << " " << nome[i] << " " <<sobrenome[i] << " " << dtadm[i] << " " << salario[i]  << " " << endl;
      }
    } 
  }

  void insertSobrenome(string *user_nickname){
    sobrenome[numSobrenome] = *user_nickname;
    numSobrenome++;   
  }

  void insertDataadm(string *user_date){
    dtadm[numData] = *user_date;
    numData++;      
  }

  void insertSalario(double *user_salario){
    salario[numSalario] = *user_salario;
    numSalario++;
  }


};