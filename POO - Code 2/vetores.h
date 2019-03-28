#include<iostream>
#include<time.h> // Biblioteca pra usar o relogio do pc pra gerar um num. aleatorio
using namespace std;

struct vetores{
  
  int *vetor; //Ponteiro para inteiros que define um vetor
  int tamVetor; //Tamanho do vetor
  int numElementos; //Numero de elementos em um vetor

  //numero aleatorio = rand()%101 < gera um numero aleatorio entre 0 e 100
  
  vetores()
  { //Construtor para um vetor
    srand(time(NULL)); //Usa o relogio do pc pra gerar um numero aleatório

    tamVetor = 20;
    vetor = new int [tamVetor]; //<<< A partir desse momento ele vira um vetor de 20 pos.

    for(int i = 0; i < 101; i++){
      vetor[i] = rand()%100 + 1;
    }

  }

  vetores(int tamanho)
  { //Define um vetor com um tamanho especifico
    srand(time(NULL)); //Usa o relogio do pc pra gerar um numero aleatório
    tamVetor = tamanho;
    vetor = new int [tamVetor];

    for(int i = 0; i <= tamanho; i++){
      vetor[i] = rand()%100 + 1;
    }
    
  }

  vetores(int tamanho, int max)
  { //determina tam do vetor e preenche com valores entre 0 e max aleatoriamente
    srand(time(NULL)); //Usa o relogio do pc pra gerar um numero aleatório
    tamVetor = tamanho;
    vetor = new int [tamVetor];

    for(int i = 0; i <= tamanho; i++){
      vetor[i] = rand()%max;
    }
    
  }

  vetores(int tamanho, int min, int max)
  { //Vetor com passagens 
    srand(time(NULL)); //Usa o relogio do pc pra gerar um numero aleatório
    tamVetor = tamanho;
    vetor = new int [tamVetor];
    
     for(int i = 0; i <= tamanho; i++){
      vetor[i] = rand()%max + min; // Define um aleatório entre o minimo e maximo da funcao
    }

  }

  void busca(int chave) 
  { //Busca um elemento no vetor e retorna sua posição, retorna -1 se nao encontrar
    int posicao;

    for(int i = 0; i <= tamVetor; i++){
      if(vetor[i] == chave){
        posicao = i;
      }
    }

    cout << "A posicao do elemento é: " << posicao << "\n";
  }

  void mostraVetorpos(int a){
    cout << vetor[a]<<"\n";

  }

  int deletar(int posicao)
  { // Deleta o elemento de acordo com a pos. solicitada 
    for(int i = posicao; i<=tamVetor; i++)
    { //"Empurra" o elemento pro final da array
      vetor[i] = vetor[i + 1];
    }
    //Diminui o tamanho da array (-1) "deletando" o ultimo elemento
    return tamVetor = tamVetor - 1;
    //CUIDADO: ESSA FUNCAO ALTERA O TAMANHO DA ARRAY
  }

  void combinar(vetores vet)
  { //Combina 2 vetores. (Falta terminar)
    int aux;
    int vetaux[aux];
    aux = tamVetor + vet.tamVetor; //define o tamanho do vetor resultante
    
    cout << "tam do vetor: " << aux << "\n";
    
  }

  void printVetor()
  {//Funcao que mostra o vetor completo
    int i;
    cout << "Vetor: ";
    for(i = 0; i<tamVetor; i++){
        cout << vetor[i] << ", ";
    }
    cout << vetor[i + 1] << ".\n";  
  }

};

