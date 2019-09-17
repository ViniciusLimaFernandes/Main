#include<iostream>
#include<cstdlib>

using namespace std;

struct Game{

  const char *pPlayer1; //Personagem do player 1
  const char *pPlayer2; //Personagem do player 2
  char Vencedor; //Vencedor do jogo
  int winStatus, velha; //Se = 0, niguem ganhou ainda, else = jogador "x" ganhou
  int playerChoice; //Escolhe se quer jogar de novo ou nao
  char hash[3][3]; //Tabuleiro

  Game(const char Personagem1[2], const char Personagem2[2])
  {//Define o personagem de cada jogador
    pPlayer1 = Personagem1;
    pPlayer2 = Personagem2;
  }


  int play(){
start:

    int linha;
    int coluna;
    char Players[2] = {*pPlayer1,*pPlayer2};
    winStatus = 0;
    playerChoice = 0;
    velha = 0;
  
    ZeraMatriz();
    MainMenu();
    system("read -p 'Press Enter to continue...' var");

    Instrucoes();
  
playing:

    for(int i = 0; i<9; i++){ //Preenche matriz de acordo com seleção
      
      for(int j=0;j<=1;j++){

        cout << "Jogador "<< j + 1 <<", onde deseja posicionar o "<< Players[j] <<" ?\n";
        cout << "Linha: \n";
        cin >> linha;
        cout << "Coluna: \n";
        cin >> coluna;

        if(linha > 2 || coluna >2)
        { // Se colocar um numero maior que o permitido, reseta o jogo
          //system("clear");
          cout << "AVISO: Posição nao encontrada, verifique as regras e instruções e tente novamente.\n";
          goto start;
        }

        hash[linha][coluna] = Players[j];
        PrintMatriz();
        
        verificaVencedor();
        
        exibeVencedor();
        verificaVelha();
        if(playerChoice == 1 && winStatus > 0){
          goto start;
        }
        if(playerChoice == 2 && winStatus > 0){
          goto end;
        if(velha == 36 && winStatus == 0){
          goto end;
        }
        }
      }
    }
  end:
    cout << "Obrigado por jogar!\n\n";
    return 0;
  }

  void PrintMatriz(){
    for(int i = 0; i < 3;i++){
      cout << hash[i][0] << "|" << hash[i][1] << "|" << hash[i][2] << "\n";
    }
  }

  void ZeraMatriz(){
    for(int i = 0; i < 3;i++){
      for(int j=0;j<3;j++){
        hash[i][j] = '-';
      }
    }
  }

  int verificaVencedor(){
    int i;

    for(i=0;i<3;i++) //Verifica as linhas
        if(hash[i][0]==hash[i][1] && hash[i][0]==hash[i][2] && hash[i][2] != '-'){
          Vencedor = hash[i][0];
          winStatus = winStatus + 1;
          return Vencedor;
          return winStatus;
        }

    for(i=0;i<3;i++) //Verifica as colunas
        if(hash[0][i]==hash[1][i] && hash[0][i]==hash[2][i] && hash[2][i] != '-'){
          Vencedor = hash[0][i];
          winStatus = winStatus + 1;
          return Vencedor;
          return winStatus;
        }

    // Testa as diagonais
    if(hash[0][0]==hash[1][1] && hash[1][1]==hash[2][2] && hash[2][2] != '-'){
      Vencedor = hash[0][0];
      winStatus = winStatus + 1;
      return Vencedor;
      return winStatus;
    }
    if(hash[0][2]==hash[1][1] && hash[1][1]==hash[2][0] && hash[1][1] != '-'){
      Vencedor = hash[2][0];
      winStatus = winStatus + 1;
      return Vencedor;
      return winStatus;
    }
    return 0;
  }

  int exibeVencedor(){
    if(winStatus > 0){
      cout << "O vencedor é: " << Vencedor << "\n\n";
      cout << "Deseja jogar novamente? \n";
      cout << "[1] Sim \n";
      cout << "[2] Não \n";
      cin >> playerChoice;
    }
    return playerChoice;
  }

  int verificaVelha(){
    for(int i = 0; i<3;i++){
      for(int j=0;j<3;j++){
        if(hash[i][j] != '-'){
          velha = velha + 1;
        }
      }
    }
    return velha;
  }

  void Instrucoes(){
    cout <<" Col.0   Col.1   Col.2" << "\n";
    cout <<"  v       v        v " << "\n";
    cout <<"  ____ | ____ | ____  < Linha 0" << "\n";
    cout <<"  ____ | ____ | ____  < Linha 1" << "\n";
    cout <<"  ____ | ____ | ____  < Linha 2" << "\n";
  }

  void MainMenu(){
    cout <<"-------------------------------------------------" << "\n";
    cout <<"                 JOGO DA VELHA v1.0              " << "\n";
    cout <<"                                                 " << "\n";
    cout <<"                                                 " << "\n";
    cout <<"                                                 " << "\n";
    cout <<"                                                 " << "\n";
    cout <<"                                                 " << "\n";
    cout <<"Desenvolvido por: Vinicius Lima Fernandes        " << "\n";
    cout <<"Curso: BEC - 3º Período                          " << "\n";
    cout <<"Materia: POO                                     " << "\n";
    cout <<"                                                 " << "\n";
    cout <<"                                                 " << "\n";
    cout <<"-------------------------------------------------" << "\n";
  }

  //void Rules(){

  //}


};

