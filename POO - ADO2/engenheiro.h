class engenheiro:empregado{ // pega por heranca os atributos dos empregados 
  private:

  int qtdEng = 5;
  string *areaAtuacao = new string[qtdEng];
  string *gerencia = new string[qtdEng];
  int aux = 0;

  public:

  void newArea(string *inputArea){
    for(int i=0; i<qtdEng ; i++){
      areaAtuacao[aux] = *inputArea;
      aux++;
    }
    aux = 0; //Depois de processar o laco for zera o aux
  }

  void newGerencia(string *inputGerencia){
    for(int i=0; i<qtdEng; i++){
      gerencia[aux] = *inputGerencia;
      aux++;
    }
    aux = 0; //Depois de processar o laco for zera o aux
  }
}