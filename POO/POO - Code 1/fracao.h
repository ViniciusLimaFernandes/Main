#include <iostream>

using namespace std;

struct fracao{ //Def. da Struct
  int Numerador;
  int Denominador;

  fracao(){ //Construtor
    Numerador = 1;
    Denominador = 1;
  }

  fracao(int a, int b){ //Construtor
    if(b != 0) {
      verificaSinal(&a,&b); 
      Numerador = a;
      Denominador = b;
    }
    else{
      cout << "Erro: O denominador nao pode ser zero!\n";
    }
  }

  void mostraFracao() //Funcao para printar  a Fracao
  {
    cout << Numerador << "/" << Denominador << "\n";
  }

  void verificaSinal(int* a, int* b)//funcao para verificar os sinais da fracao
  {
    if(((*a<0)&&(*b<0)) || ((*a>0)&&(*b<0))){
      *a = *a * -1;
      *b = *b * -1;
    }
  }
  
  void alteraNumerador(int a)
  {
      Numerador = a;
  }

  void alteraDenominador(int a)
  {
    Denominador = a;
  }

  fracao multiplicacao(fracao f)
  {//Construtor para multiplicacao
    fracao fr;
    int num1 = Numerador;
    int num2 = Denominador;

    int num3 = f.Numerador;
    int num4 = f.Denominador;

    fr.Numerador = num1 * num3;
    fr.Denominador = num2 * num4;

    return fr;
  }

  fracao divisao(fracao f)
  //Construtor para divisao
  {
    fracao fr;
    
    int num1 = Numerador;
    int num2 = Denominador;

    int num3 = f.Numerador;
    int num4 = f.Denominador;

    fr.Numerador = num1 * num4;
    fr.Denominador = num2 * num3;

    return fr;    
  }

  fracao soma(fracao f)
  //Construtor para soma 
  {
    fracao fr;

    int num1 = Numerador;
    int num2 = Denominador;

    int num3 = f.Numerador;
    int num4 = f.Denominador;

    fr.Numerador = (num1 * num4) + (num3 * num2);
    fr.Denominador = num2 * num4;

    return fr;
  }

  fracao subtracao(fracao f)
  //Construtor para soma 
  {
    fracao fr;

    int num1 = Numerador;
    int num2 = Denominador;

    int num3 = f.Numerador;
    int num4 = f.Denominador;

    fr.Numerador = (num1 * num4) - (num3 * num2);
    fr.Denominador = num2 * num4;

    return fr;
  }

  //Falta criar funcao para mostrar operacao
  
};


