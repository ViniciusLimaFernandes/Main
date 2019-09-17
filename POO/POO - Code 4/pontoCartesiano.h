#include <iostream>
#include <cmath>
#include <cstdlib> 
using namespace std;

class pontoCartesiano{ //Definição do objeto
  
  private: //Parte privada do codigo (Onde o usuário nao tem acesso)
  /*Os dados contidos na definicao private so podem ser alterados por
  funcoes criadas no objeto*/

  double x,y;

  public: //Parte publica do codigo (Onde o usuário tem acesso)
  pontoCartesiano(){ //Construtor
    x=y=0.0;
  }

  void imprimePonto(){
    cout<<"x = "<<x<<" ; "<<"y = "<<y<<endl;
  }
  
  void alteraX(double X){ //Funcao para alerar o X (Só é possivel aterar na main chamando esta função)
    if(X < 0){
      cout << "ERRO: Nao e possivel inserir números negativos em x" << endl;
      exit (EXIT_FAILURE);
    }
    else{
      x=X;
    }
  }
  
  void alteraY(double Y){ //Funcao para alerar o Y (Só é possivel aterar na main chamando esta função)
    if(Y < 0){
      cout << "ERRO: Nao e possivel inserir números negativos em y" << endl;
      exit (EXIT_FAILURE);
    }
    else{
      y=Y;
    }
  }
  
  void translacao(double dx, double dy){
    x+=dx;
    y+=dy;
  }
  
  void rotacao(double angulo){
    double x_novo, y_novo;
    x_novo=x*cos(angulo)-y*sin(angulo);
    y_novo=x*sin(angulo)+y*cos(angulo);
    x=x_novo;
    y=y_novo;
  }
};