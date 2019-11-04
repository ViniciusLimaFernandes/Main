#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

/* TEORIA
 *
 * Um grafo é uma estrutura composta por pontos (vertices)
 * e ligações entre pontos (arestas)
 *
 * Exemplo:
 *
 * 0 - 2
 * |   
 * 1 - 3
 *
 * Esse grafo tem 4 vertices (0, 1, 2 e 3) e 3 arestas
 * (uma ligação entre 0 e 1, que denotarei {0,1},
 * uma entre 0 e 2 ({0,2}) e {1,3})
 *
 * Uma forma de representar grafos, que usaremos nesse arquivo
 * é usando matrizes
 *
 * Para representar esse grafo, podemos usar a seguinte matriz
 *
 * 0110
 * 1001
 * 1000
 * 0100
 *
 * Estamos usando 1 para representar a existencia de uma aresta, e 
 * 0 para representar a inexistência.
 *
 * Por exemplo, se olharmos para a linha 0 e coluna 1 
 * 0X10
 * Y001
 * 1000
 * 0100
 * (marcada com um X na matriz) vemos que há uma aresta entre 0 e 1
 * a linha 1 coluna 0 (marcada com Y na matriz) diz o mesmo
 *
 * Se olharmos para a linha 2 coluna 3
 * 0110
 * 1001
 * 100X
 * 01Y0
 * vemos que não há aresta entre 2 e 3
 * (a linha 3 coluna 2, marcada com Y, diz o mesmo)
 *
 * Perceba que estamos contando do zero sempre
 * 0110
 * XXXX  -> linha 1 
 * 1001
 * 0100
 *
 *
 * 01X0
 * 10X0
 * 10X1
 * 01X0
 *   |
 *   --> coluna 2
 */

/* Considerando o grafo
 * 0100
 * 1011
 * 0101
 * 0110
 *
 * diga, na lista arestas_1, se estão ligados
 * 0 e 1, 0 e 2, 0 e 3, 1 e 2, 1 e 3, 3 e 2
 * 
 * crie uma lista como no exemplo:
 * bool exemplo[10] = {true, true, false, false, true}; */

bool arestas_1[10]={true,false,false,true,true,true};

/* Considerando o grafo
 * 0111
 * 1001
 * 1000
 * 1100
 *
 * diga, na lista arestas_2, se estão ligados
 * 0 e 1, 0 e 2, 0 e 3, 1 e 2, 1 e 3, 3 e 2
 * 
 * crie uma lista como no exemplo:
 * bool exemplo[10] = {true, true, false, false, true}; */
bool arestas_2[10]={true,true,true,false,true,false};

/* Considerando o grafo
 * 0001
 * 0010
 * 0100
 * 1000
 *
 * diga, na lista arestas_3, se estão ligados
 * 0 e 1, 0 e 2, 0 e 3, 1 e 2, 1 e 3, 3 e 2
 * 
 * crie uma lista como no exemplo:
 * bool exemplo[10] = {true, true, false, false, true}; */
bool arestas_3[10]={};

/* Alias, qual o máximo de arestas que um grafo com
 * 2 vértices pode ter? e com 3? e com 4? e com 5? e com 6?
 *
 * coloque suas respostas em uma lista max_arestas como no exemplo
 * int max_arestas[10]={0,0,0,0,0}; */
int max_arestas[10]={};

/*
 * Escreva uma funcao que recebe um grafo,
 * representado por uma matriz, a quantidade de vertices, e dois vertices,
 * v1 e v2, e devolve true se existe aresta entre eles.
 *

bool existe_aresta(int arestas[6][6],int num_vertices,int v1,int v2){

}
*/

bool existe_aresta(int arestas[6][6],int num_vertices,int v1,int v2){
   return false;
}

/*
 * Escreva uma funcao que recebe um grafo,
 * representado por uma matriz, a quantidade de vertices, e dois vertices,
 * v1 e v2, e altera o grafo para que haja arestas entre os vertices
 *
void adiciona_aresta(int arestas[6][6], int num_vertices, int v1, int v2) {

}*/
void adiciona_aresta(int arestas[6][6], int num_vertices, int v1, int v2) {
}
/* faca o mesmo, agora para remover arestas, em uma funcao remove_aresta */
void remove_aresta(int arestas[6][6], int num_vertices, int v1, int v2) {
}

/* faca uma funcao conta_arestas, que conta o numero de arestas
 * de um grafo.
 *
 int conta_arestas(int arestas[6][6], int num_vertices) {
 */
int conta_arestas(int arestas[6][6], int num_vertices) {
   return 12;
}

/* direi que um grafo eh uma "estrela", ou ainda um "asterisco"
 * se todos existe um vertice "central", conectado a todos os
 * demais, e todo vertice nao central so tem uma aresta: aquela
 * que vai para o central.
 *
 * ex:
 *        2
 *        |
 *    0 - 3 - 1
 *        |
 *        4
 * Esse grafo eh uma estrela com vertice central 3
 *
 * Crie uma funcao eh_estrela, que recebe o grafo e seu numero 
 * de vertices
 * */

bool eh_estrela(int arestas[6][6],int num_vertices) {
   return false;
   
}

/*
 * Crie uma função que recebe a matriz que representa
 * um grafo, o numero de vertices, o numero de um
 * vertice V específico e uma lista. 
 * Nessa lista apontada, coloca todos os números dos vizinhos
 * de V. 
 *
 * Ela retorna a quantidade de vizinhos
   int vizinhos(int arestas[6][6], int num_vertices, int V, int list_vizinhos[]) {
 * */
int vizinhos(int arestas[6][6], int num_vertices, int V, int list_vizinhos[]) {
   int vizinho_livre = 0;
   for (int j = 0; j < num_vertices; j++) {
      if (arestas[V][j] == 1)
         list_vizinhos[vizinho_livre++] = j;
   }
   return vizinho_livre;
}

/*
 * Crie uma função que recebe a matriz que representa
 * um grafo, o numero de vertices, o numero de um
 * vertice V específico e uma lista. 
 * Nessa lista apontada, coloca todos os números dos vizinhos
 * de V, mas também os vizinhos de vizinhos. 
 *
 * Nao coloque vizinho de vizinho de vizinho
 *
 * Cuidado para não repetir
 *
 * Uma dica: crie uma lista nova, que sinaliza se um vertice ja foi visto
 *
 * Ela retorna o tamanho da lista.
   int mais_vizinhos(int arestas[6][6], int num_vertices, int V, int list_vizinhos[])
 * */
int mais_vizinhos(int arestas[6][6], int num_vertices, int V, int list_vizinhos[]) {

}
/* agora faca uma funcao todos os vizinhos, que inclui vizinhos imediatos,
 * "de segundo grau", "de terceiro grau" e assim ate o fim do grafo */

int todos_os_vizinhos(int arestas[6][6], int num_vertices, int V, int list_vizinhos[]) {
}

/*
 * Crie uma função que recebe a matriz que representa
 * um grafo, o numero de vertices, o numero de um
 * vertice V específico e duas listas. 
 * Na primeira lista, coloca todos os números dos vizinhos
 * de V, mas também os vizinhos de vizinhos, e os vizinhos
 * de vizinhos de vizinhos, e assim sucessivamente
 *
 * Cuidado para não repetir
 *
 * Na segunda lista, coloque as distancias: um vizinho tem distancia 1,
 * um vizinho de vizinho (se nao for vizinho!) tem distancia 2 e assim por
 * diante
 *
 * Ela retorna o tamanho da lista.
int distancias(int arestas[6][6], int num_vertices, int V, int list_vizinhos[],int distancias[]) {
 * */
int distancias(int arestas[6][6], int num_vertices, int V, int list_vizinhos[],int dist[]) {
}

/* a partir daqui, soh codigo de testes/utilitario
 * Nada para voce fazer*/

int gr1[6][6] = {0,1,0,0,0,1,
                 1,0,1,0,0,0,
                 0,1,0,1,0,0,
                 0,0,1,0,1,0,
                 0,0,0,1,0,1,
                 1,0,0,0,1,0};

int gr2[6][6] = {0,1,0,0,0,1,
                 1,0,0,0,0,1,
                 0,0,0,1,1,0,
                 0,0,1,0,1,0,
                 0,0,1,1,0,0,
                 1,1,0,0,0,0};

int gr3[6][6] = {0,1,0,1,0,1,
                 1,0,0,0,0,1,
                 0,0,0,1,1,0,
                 1,0,1,0,1,0,
                 0,0,1,1,0,0,
                 1,1,0,0,0,0};

int gr4[6][6] = {0,1,1,1,1,1,
                 1,0,0,0,0,0,
                 1,0,0,0,0,0,
                 1,0,0,0,0,0,
                 1,0,0,0,0,0,
                 1,0,0,0,0,0};

int gr5[6][6] = {0,0,1,0,0,0,
                 0,0,1,0,0,0,
                 1,1,0,1,1,1,
                 0,0,1,0,0,0,
                 0,0,1,0,0,0,
                 0,0,1,0,0,0};

int gr6[6][6] = {0,0,1,0,0,0,
                 0,0,1,0,0,0,
                 1,1,0,0,0,0,
                 0,0,0,0,0,0,
                 0,0,0,0,0,0,
                 0,0,0,0,0,0}; //esse daqui so tem 3 vertices

int gr7[6][6] = {0,0,1,0,0,0,
                 0,0,1,0,0,0,
                 1,1,0,0,0,0,
                 0,0,0,0,1,1,
                 0,0,0,1,0,0,
                 0,0,0,1,0,0};

bool eh_true(bool valor) {
   if (valor == true)
      return true;
   printf("era esperado o valor true, mas veio o false\n");
   return false;
}
bool eh_false(bool valor) {
   if (valor == false)
      return true;
   printf("era esperado o valor false, mas veio o true\n");
   return false;
}

bool sao_iguais(int val1, int val2) {
   if (val1 == val2)
      return true;
   printf("recebi dois valores, %d e %d, que deviam ser iguais\n", val1, val2);
   return false;

}

int verifica_lista(int lista[], int tamanho, int soma_esperada) {
   int potencia = 1;
   int soma = 0;
   for (int i = 0; i < tamanho; i++) {
      soma = soma + lista[i]*potencia;
      potencia = potencia*2;   
   }
   if (soma == soma_esperada)
      return true;
   printf("a lista passada nao correspondeu a lista esperada\n");
   return false;
}
int verifica_lista_b(bool lista[], int tamanho, int soma_esperada) {
   int potencia = 1;
   int soma = 0;
   for (int i = 0; i < tamanho; i++) {
      soma = soma + lista[i]*potencia;
      potencia = potencia*2;   
   }
   if (soma == soma_esperada)
      return true;
   printf("a lista passada nao correspondeu a lista esperada\n");
   return false;
}

bool numero_na_lista(int proc, int lista[], int tam) {
   for (int i = 0; i < tam; i++) {
      if (proc == lista[i])
         return true;
   }
   printf("na lista passada, eu nao achei o número %d\n",proc);
   printf("elementos da lista:\n");
   for (int i = 0; i < tam; i++) {
      printf("%d,",lista[i]);
   }
   printf("\n");
   return false;
   

}

void imprime_grafo(int arestas[6][6],int tam) {
   printf("\n");
   for (int i = 0; i < tam; i++) {
      for (int j = 0; j < tam; j++)
         printf("%d,",arestas[i][j]);
      printf("\n");
   }
      
}
int main() {
   //imprime_grafo(gr1,6);
   /*calcula codigos para cada lista. Nao se preocupe
    * com como esses testes funcionam por dentro */
   assert(verifica_lista_b(arestas_1,6,57));
   assert(verifica_lista_b(arestas_2,6,39));
   assert(verifica_lista_b(arestas_3,6,12));
   printf("suas listas de true e false estao ok\n");
   assert(verifica_lista(max_arestas,6,351));
   printf("suas lista de tamanhos está ok\n");
   assert(eh_true(existe_aresta(gr1,6,0,1)));
   assert(eh_false(existe_aresta(gr1,6,0,2)));
   assert(eh_true(existe_aresta(gr1,6,1,2)));
   assert(eh_true(existe_aresta(gr1,6,5,4)));
   assert(eh_false(existe_aresta(gr1,6,1,4)));
   assert(eh_false(existe_aresta(gr1,6,1,5)));
   assert(eh_false(existe_aresta(gr1,6,2,4)));

   assert(eh_true(existe_aresta(gr2,6,0,1)));
   assert(eh_false(existe_aresta(gr2,6,0,2)));
   assert(eh_false(existe_aresta(gr2,6,1,2)));
   assert(eh_false(existe_aresta(gr2,6,5,4)));
   assert(eh_false(existe_aresta(gr2,6,1,4)));
   assert(eh_true(existe_aresta(gr2,6,1,5)));
   assert(eh_true(existe_aresta(gr2,6,2,4)));
   assert(eh_false(existe_aresta(gr2,6,0,3)));
   
   assert(eh_true(existe_aresta(gr3,6,0,3)));
   printf("sua funcao existe_aresta esta ok\n");


   assert(eh_false(existe_aresta(gr3,6,1,2)));
   adiciona_aresta(gr3,6,1,2);
   assert(eh_true(existe_aresta(gr3,6,1,2)));
   assert(eh_true(existe_aresta(gr3,6,2,1)));
   
   assert(eh_false(existe_aresta(gr3,6,5,4)));
   adiciona_aresta(gr3,6,5,4);
   assert(eh_true(existe_aresta(gr3,6,5,4)));
   assert(eh_true(existe_aresta(gr3,6,4,5)));
   printf("sua funcao adiciona_aresta esta ok\n");
   remove_aresta(gr3,6,5,4);
   remove_aresta(gr3,6,1,2);
   assert(eh_false(existe_aresta(gr3,6,5,4)));
   assert(eh_false(existe_aresta(gr3,6,4,5)));
   assert(eh_false(existe_aresta(gr3,6,1,2)));
   assert(eh_false(existe_aresta(gr3,6,2,1)));
   remove_aresta(gr1,6,0,1);
   assert(eh_false(existe_aresta(gr1,6,0,1)));
   assert(eh_false(existe_aresta(gr1,6,1,0)));
   adiciona_aresta(gr1,6,0,1);
   assert(eh_true(existe_aresta(gr1,6,0,1)));
   assert(eh_true(existe_aresta(gr1,6,1,0)));
   printf("sua funcao remove_aresta esta ok\n");

   assert(sao_iguais(conta_arestas(gr1,6),6));
   assert(sao_iguais(conta_arestas(gr2,6),6));
   assert(sao_iguais(conta_arestas(gr3,6),7));
   assert(sao_iguais(conta_arestas(gr4,6),5));
   assert(sao_iguais(conta_arestas(gr5,6),5));
   assert(sao_iguais(conta_arestas(gr6,3),2));
   printf("sua funcao conta_arestas esta ok\n");
   assert(eh_false(eh_estrela(gr1,6)));
   assert(eh_false(eh_estrela(gr2,6)));
   assert(eh_false(eh_estrela(gr3,6)));
   assert(eh_true(eh_estrela(gr4,6)));
   assert(eh_true(eh_estrela(gr5,6)));
   assert(eh_true(eh_estrela(gr6,3)));
   printf("sua funcao eh_estrela esta ok\n");

   int l_vizinhos[100];   
   assert(sao_iguais(vizinhos(gr1,6,1,l_vizinhos),2));
   int tam_lista = 2;
   assert(numero_na_lista(0,l_vizinhos,tam_lista));
   assert(numero_na_lista(2,l_vizinhos,tam_lista));
   assert(sao_iguais(vizinhos(gr3,6,0,l_vizinhos),3));
   tam_lista = 3;
   assert(numero_na_lista(1,l_vizinhos,tam_lista));
   assert(numero_na_lista(5,l_vizinhos,tam_lista));
   assert(numero_na_lista(3,l_vizinhos,tam_lista));

   assert(sao_iguais(vizinhos(gr3,6,1,l_vizinhos),2));
   tam_lista = 2;
   assert(numero_na_lista(0,l_vizinhos,tam_lista));
   assert(numero_na_lista(5,l_vizinhos,tam_lista));
   printf("sua funcao vizinhos parece ok\n");

   assert(sao_iguais(mais_vizinhos(gr3,6,1,l_vizinhos),3));
   tam_lista = 3;
   assert(numero_na_lista(0,l_vizinhos,tam_lista));
   assert(numero_na_lista(5,l_vizinhos,tam_lista));
   assert(numero_na_lista(3,l_vizinhos,tam_lista));

   assert(sao_iguais(mais_vizinhos(gr1,6,1,l_vizinhos),4));
   tam_lista = 4;
   assert(numero_na_lista(0,l_vizinhos,tam_lista));
   assert(numero_na_lista(5,l_vizinhos,tam_lista));
   assert(numero_na_lista(3,l_vizinhos,tam_lista));
   assert(numero_na_lista(2,l_vizinhos,tam_lista));

   assert(sao_iguais(mais_vizinhos(gr7,6,2,l_vizinhos),2));
   tam_lista = 2;
   assert(numero_na_lista(0,l_vizinhos,tam_lista));
   assert(numero_na_lista(1,l_vizinhos,tam_lista));
   assert(sao_iguais(mais_vizinhos(gr7,6,1,l_vizinhos),2));
   tam_lista = 2;
   assert(numero_na_lista(0,l_vizinhos,tam_lista));
   assert(numero_na_lista(2,l_vizinhos,tam_lista));
   assert(sao_iguais(mais_vizinhos(gr7,6,5,l_vizinhos),2));
   tam_lista = 2;
   assert(numero_na_lista(3,l_vizinhos,tam_lista));
   assert(numero_na_lista(4,l_vizinhos,tam_lista));
   printf("sua funcao mais vizinhos parece ok\n");
   
   assert(sao_iguais(todos_os_vizinhos(gr1,6,1,l_vizinhos),5));
   tam_lista = 5;
   assert(numero_na_lista(0,l_vizinhos,tam_lista));
   assert(numero_na_lista(5,l_vizinhos,tam_lista));
   assert(numero_na_lista(3,l_vizinhos,tam_lista));
   assert(numero_na_lista(2,l_vizinhos,tam_lista));
   assert(numero_na_lista(4,l_vizinhos,tam_lista));

   assert(sao_iguais(todos_os_vizinhos(gr3,6,1,l_vizinhos),5));
   tam_lista = 5;
   assert(numero_na_lista(0,l_vizinhos,tam_lista));
   assert(numero_na_lista(5,l_vizinhos,tam_lista));
   assert(numero_na_lista(3,l_vizinhos,tam_lista));
   assert(numero_na_lista(2,l_vizinhos,tam_lista));
   assert(numero_na_lista(4,l_vizinhos,tam_lista));

   assert(sao_iguais(todos_os_vizinhos(gr7,6,2,l_vizinhos),2));
   tam_lista = 2;
   assert(numero_na_lista(0,l_vizinhos,tam_lista));
   assert(numero_na_lista(1,l_vizinhos,tam_lista));
   assert(sao_iguais(todos_os_vizinhos(gr7,6,1,l_vizinhos),2));
   tam_lista = 2;
   assert(numero_na_lista(0,l_vizinhos,tam_lista));
   assert(numero_na_lista(2,l_vizinhos,tam_lista));
   assert(sao_iguais(todos_os_vizinhos(gr7,6,5,l_vizinhos),2));
   tam_lista = 2;
   assert(numero_na_lista(3,l_vizinhos,tam_lista));
   assert(numero_na_lista(4,l_vizinhos,tam_lista));
   printf("sua funcao todos os vizinhos parece ok\n");

   int dist[100];
   assert(sao_iguais(distancias(gr3,6,1,l_vizinhos,dist),5));
   assert(sao_iguais(dist[0],1));
   assert(sao_iguais(dist[5],1));
   assert(sao_iguais(dist[3],2));
   assert(sao_iguais(dist[2],3));
   assert(sao_iguais(dist[4],3));
   printf("sua funcao distancias parece ok\n");

   printf("você chegou ao fim :)\n");
}
