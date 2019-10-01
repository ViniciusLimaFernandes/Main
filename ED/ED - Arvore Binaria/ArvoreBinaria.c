#include<malloc.h>
#include<stdbool.h>
#include<assert.h>

/* Jah vimos que, usando o algoritmo de busca binaria,
 * podemos verificar se um elemento pertence a um conjunto
 * em tempo log(n) - n eh o tamanho do conjunto.
 *
 * Isso eh muito legal, pois nos permite ter consultas
 * muito rapidas para conjuntos muito grandes. Como dissemos
 * em aula, faremos cerca de 30 passos para verificar
 * a existência de uma pessoa dentre todas as pessoas da terra.
 *
 * Mas a busca binaria tem um defeito fundamental: ela exige uma 
 * lista ordenada. E inserir um elemento em uma lista ordenada
 * pode ser bem caro: se ele entrar no meio da lista, teremos 
 * que mover n/2 elementos. Se, no nosso exemplo do "conjunto
 * de todas as pessoas", nascer uma nova pessoa, teremos que fazer
 * 4 bilhoes de operacoes para ajustar a lista :(
 *
 * Para resolver esse problema, surge a arvore binaria, uma estrutura
 * de dados que promete consultas em tempo O(log n) e insercoes
 * em tempo O(log n).
 *
 * Primeiro vamos implementar essa estrutura, mas depois teremos que
 * verificar se essa promessa se cumpre.*/

   /*
   Uma arvore eh uma estrutura como


         10
        /  \
       5    20
      /\   /  \
     2  7 12  30 

   Observe que 10 tem elementos a sua "esquerda" (5,2 e 7)
   e a sua "direita" (20, 12 e 30)

   Os elementos a esquerda sao numeros menores que 10,
   e os elementos a direita, maiores que 10.
   (O mesmo vale para o 5: a esquerda, temos 2,
   que eh menor, e a direita, 7, que eh maior)
   */

   /*
   Perceba que, para verificar se um numero esta nessa arvore,
   precisamos usar apenas 3 consultas.

   12 esta na arvore?
   Olho pro 10. Se 12 estiver, esta na arvore direita 
   (onde estao todos os numeros maiores que 10 da arvore)
   Olho pro 20, se 12 estiver esta na arvore esquerda
   (onde estao todos os numeros menores que 20 da "subarvore")
   Olho pro 12, e achei!
   A resposta eh True
   A sequencia de numeros visitados foi [10,20,12]

         10
        /  \
       5    20
      /\   /  \
     2  7 12  30 

   9 esta na arvore?
   Olho pro 10. Se 9 estiver, esta na arvore esquerda
   (onde estao todos os numeros menores que 10 da arvore)
   Olho pro 5. Se 9 estiver esta na arvore direita
   (onde estao todos os numeros maiores que 5 da "subarvore")
   Olho pro 7. Queria procurar "a direita" dele, mas nao tem ninguem
   A resposta eh False
   A sequencia de numeros visitados foi [10,5,7]

   EXERCICIO: se eu quiser procurar 40 na arvore, que numeros visitarei?
   */
   int busca40[10]={};

   /*
   E se eu quiser buscar o 15? E o 3? E o 5?
   */
   int busca15[10]={};
   int busca3[10]={};
   int busca5[10]={};

   /*
   Uma outra questao importante eh a insercao.
           20
        /      \
       10      30
      /  \    /  \
     8   C   D    E
    / \
   A  B

   Se eu quiser inserir o numero 40 nessa arvore, a posicao correta para 
   fazer isso eh a posicao E (40 eh maior que 20, tem que estar a direita do
   20. Tambem eh maior que 30, entao tem que estar a direita do 30)

   Se eu quiser inserir o numero 12, a posicao correta eh C (ele tem que estar
   a esquerda do 20, mas à direita do 10)

   Exercicio:
       Se eu te der uma lista de numeros, quero uma lista que diga
       onde eles devem ser inseridos.

       Considere que a arvore eh sempre "rebootada", as insercoes de um exercicio 
       nao interferem no seguinte

       Por exemplo:

   numeros1 = {2,11,25}
   letras1 = {'A','C','D'}
   /*
   Faca o mesmo para as duas listas abaixo
   */
   int numeros2 [10] = {19,21,33,7};;
   char letras2 [10] =  {};
   int numeros3 [10] = {9,11,7,50};
   char letras3 [10] =  {};

   /*
   Para representar arvores em C, usamos duas structs.
   */
   struct noh_arv {
      int     conteudo; 
      struct noh_arv* esquerda;
      struct noh_arv* direita;
   };
   typedef struct noh_arv noh;

   struct arv {
      noh* raiz;
   };
   typedef struct arv arvore;


   noh* cria_noh(int numero) {
      noh* criando;
      criando = malloc(sizeof(noh));
      criando->conteudo = numero;
      criando->direita = criando->esquerda = NULL;
      return criando;
   }

   arvore* cria_arvore() {
      arvore* criando;
      criando = malloc(sizeof(arvore));
      criando->raiz = NULL;
      return criando;
   }

   /* agora vamos construir uma arvore no braco, soh pra 
    * praticar o uso das nossas structs */

arvore* constroi_arvore_no_braco () {
   //criamos uma arvore
   arvore* a = cria_arvore();
   //criamos uma arvore cuja raiz vale 30
   a->raiz = cria_noh(30); 
   //adicionamos um noh 20 (que tem que entrar a esquerda do 30)
   a->raiz->esquerda = cria_noh(20);
   //para adicionar o 40, fazemos o seguinte'
   a->raiz->direita = cria_noh(40);
   //'para adicionar o 35, fazemos o seguinte'
   noh * aux;
   aux = a->raiz;
   aux = aux->direita;
   aux->esquerda = cria_noh(35);
   //para adicionar o 45, fazemos o seguinte'
   aux = a->raiz;
   aux = aux->direita;
   aux->direita = cria_noh(45);
   return a;
}
    
   /*
   Agora voce monta uma arvore.
   Insira o 100, depois o 30, depois o 40, depois o 110
   Ja vou iniciar pra voce
   */
arvore*  constroi_sua_arvore() {
   arvore* a = cria_arvore();
   a->raiz = cria_noh(100);//TODO deletar daqui ao comment
   a->raiz->esquerda = cria_noh(30);
   a->raiz->esquerda->direita = cria_noh(40);
   a->raiz->direita = cria_noh(110);
   //continue a criacao
   return a;
}


   /*
   Faca uma funcao que 
   recebe uma arvore e retorna o numero presente na sua raiz

   Nao se preocupe com o caso da arvore vazia.
   */

int raiz(arvore* a) {
   return 12;
}

   /*
   A raiz de arvore eh um noh. Ele tem tipicamente 2 nohs "pendurados"
   nele, o da direita e o da esquerda.

   Faca uma funcao que, dada uma arvore, retorna o valor do 
   noh da esquerda da raiz.

   */

int noh_esquerdo(arvore* a) {
   return 12;
}   

   /*
   O proximo passo:
       Uma funcao que recebe uma arvore A,
       vai andando para a esquerda "ate nao poder mais" (ate estar
       em um noh que nao tem filho esquerdo) e
       devolve valor correspondente a esse noh.
       

   */
int tudo_a_esquerda(arvore* a) {
   return 12;
}

   /*
   Agora, facamos uma funcao que recebe uma arvore e um numero, e faz uma busca
   para ver se o numero esta ou nao na arvore. 

   Ela retorna true se o numero esta na arvore, false caso contrario
   */

bool busca(arvore* a, int procurado) {
   return false;
}

   /*
   Agora, vamos fazer uma funcao para inserir um elemento em uma arvore.

   Por exemplo, ao pegarmos a arvore

         10
        /  \
       5    20
      /\   /  \
     2  7 12  30 

   e inserirmos o elemento 15, temos
         
         10
        /  \
       5    20
      /\   /  \
     2  7 12  30 
           \
           15

(Estamos mantendo as propriedades: o 15 tem que estar a direita do 10, a esquerda do 20
e a direita do 12)

(outra coisa: se inserirmos o 5, nada acontece, porque ele jah esta na arvore)
*/

void insere(arvore* a,int elemento) {
}

/*
Agora, faca uma funcao que recebe uma arvore e diz quantos elementos ela tem
Acho que recursao pode te ajudar...
*/


int conta(arvore* a) {
}

/*
Agora, vamos fazer uma funcao para calcular a soma de todos os numeros presentes
em uma arvore. Acho que recursao pode ser util aqui
*/

int soma(arvore* a) {
}


/*
Agora, facamos uma funcao que retorna o maior numero presente
na arvore. Voce nao precisa usar recursao (e se usar
seu algoritmo vai funcionar, mas talvez fique lento)
*/


int maior(arvore* a) {
}


/*
A partir daqui nao existe nada para voce implementar
tem algumas funcoes utilitarias minhas, e depois 
a main, que contem os testes
*/

arvore* ex1() {
   arvore* a = cria_arvore();
   a->raiz = cria_noh(10);
   a->raiz->direita = cria_noh(15);
   a->raiz->direita->direita = cria_noh(20);
   a->raiz->direita->esquerda = cria_noh(12);
   a->raiz->esquerda = cria_noh(5);
   a->raiz->esquerda->direita = cria_noh(7);
   a->raiz->esquerda->esquerda = cria_noh(2);
   return a;
}
arvore* ex2() {
   arvore* a = cria_arvore();
   a->raiz = cria_noh(10);
   a->raiz->esquerda = cria_noh(3);
   a->raiz->esquerda->esquerda = cria_noh(2);
   return a;
}
arvore* ex3() {
   arvore* a = cria_arvore();
   a->raiz = cria_noh(90);
   a->raiz->direita = cria_noh(120);
   a->raiz->direita->esquerda = cria_noh(110);
   a->raiz->esquerda = cria_noh(5);
   a->raiz->esquerda->direita = cria_noh(10);
   return a;
}
arvore* arvore2() {
   arvore* a = cria_arvore();
   a->raiz = cria_noh(2);
   return a;
}
arvore* arvore7() {
   arvore* a = cria_arvore();
   a->raiz = cria_noh(7);
   return a;
}
arvore* arvore5() {
   arvore* a = cria_arvore();
   a->raiz = cria_noh(5);
   a->raiz->direita = cria_noh(7);
   a->raiz->esquerda = cria_noh(2);
   return a;
}
arvore* arvore12() {
   arvore* a = cria_arvore();
   a->raiz = cria_noh(12);
   return a;
}
arvore* arvore30() {
   arvore* a = cria_arvore();
   a->raiz = cria_noh(30);
   return a;
}
arvore* arvore20() {
   arvore* a = cria_arvore();
   a->raiz = cria_noh(20);
   a->raiz->direita = cria_noh(30);
   a->raiz->esquerda = cria_noh(12);
   return a;
}
arvore* arvore10() {
   arvore* a = cria_arvore();
   a->raiz = cria_noh(10);
   a->raiz->direita = cria_noh(20);
   a->raiz->direita->direita = cria_noh(30);
   a->raiz->direita->esquerda = cria_noh(12);
   a->raiz->esquerda = cria_noh(5);
   a->raiz->esquerda->direita = cria_noh(7);
   a->raiz->esquerda->esquerda = cria_noh(2);
   return a;
}
arvore* arv_torta() {
   arvore* a = cria_arvore();
   a->raiz = cria_noh(12);
   a->raiz->esquerda = cria_noh(11);
   a->raiz->esquerda->esquerda = cria_noh(10);
   a->raiz->esquerda->esquerda->esquerda = cria_noh(9);
   return a;
}


int testa_busca(int busca[], int tam) {
   int conta_secreta = 0;
   for (int i=0; i <= tam; i++) {
      conta_secreta += busca[i]*(i+2)*(i+2);
   }
   return conta_secreta;
}

int testa_letras(char letras[], int tam) {
   int conta_secreta = 0;
   for (int i=0; i <= tam; i++) {
      conta_secreta += ((int) letras[i])*(i+2)*(i+2);
   }
   return conta_secreta;
}

bool arv_iguais_rec(noh* n1, noh* n2) {
   if (n1 == NULL && n2 == NULL)
      return true;
   if (n1 == NULL || n2 == NULL)
      return false;
   if (n1->conteudo != n2-> conteudo)
      return false;
   if (!arv_iguais_rec(n1->esquerda,n2->esquerda))
      return false;
   if (!arv_iguais_rec(n1->direita,n2->direita))
      return false;
   return true;
   
}

bool arvores_iguais(arvore* a1, arvore* a2) {
   return arv_iguais_rec(a1->raiz,a2->raiz);
}

int main() {
   assert(testa_busca(busca40,3) == 700);
   assert(testa_busca(busca15,3) == 412);
   assert(testa_busca(busca3,3) == 117);
   assert(testa_busca(busca5,2) == 85);
   assert(testa_letras(letras2,4) == 3609);
   assert(testa_letras(letras3,4) == 3632);

   /*arvore que voce montou*/
   /*Relembrando: Insira o 100, depois o 30, depois o 40, depois o 110 */
   arvore* a;
   a = constroi_sua_arvore();
   assert(a->raiz->conteudo == 100);
   assert(a->raiz->esquerda->conteudo == 30);
   assert(a->raiz->esquerda->esquerda == NULL);
   assert(a->raiz->esquerda->direita->conteudo == 40);
   assert(a->raiz->esquerda->direita->esquerda == NULL);
   assert(a->raiz->esquerda->direita->direita == NULL);
   assert(a->raiz->direita->conteudo == 110);

   /*funcao raiz*/
   assert(raiz(arvore5()) == 5);
   assert(raiz(ex1()) == 10);
   assert(raiz(ex2()) == 10);
   assert(raiz(ex3()) == 90);
        
   /*funcao noh_esquerdo*/
   assert(noh_esquerdo(arvore5()) == 2);
   assert(noh_esquerdo(arvore10()) == 5);
   assert(noh_esquerdo(arvore20()) == 12);
    
   /*funcao tudo_a_esquerda*/
   assert(tudo_a_esquerda(arvore5()) == 2);
   assert(tudo_a_esquerda(arvore10()) == 2);
   assert(tudo_a_esquerda(arvore20()) == 12);

   /* primeiros testes busca */
   assert (true == busca(arvore10(),10));
   assert (false == busca(arvore10(),15));
   assert (false == busca(ex3(),91));
   assert (true == busca(ex3(),90));
   assert (true == busca(arvore5(),5));
   assert (true == busca(arvore10(),20));
   assert (true == busca(arvore10(),7));
   assert (false == busca(arvore10(),8));

   /*mais testes busca*/
   assert (true == busca(arvore10(),12));
   assert (true == busca(arv_torta(),10));
   assert (true == busca(arv_torta(),9));
   assert (false == busca(arv_torta(),8));

   /*testes insere*/
   a->raiz = cria_noh(5);
   insere(a,2);
   insere(a,7);
   assert (true == arvores_iguais(a,arvore5()));
   arvore* d10;
   d10 = cria_arvore();
   d10->raiz = cria_noh(10);
   insere(d10,5);
   insere(d10,2);
   insere(d10,7);
   insere(d10,20);
   insere(d10,12);
   insere(d10,30);
   assert(true == arvores_iguais(d10, arvore10()));

   /*insere comecando vazio*/
   arvore* d2;
   d2 = cria_arvore();
   insere(d2,2);
   assert(true == arvores_iguais(d2, arvore2()));
   arvore* d5;
   d5 = cria_arvore();
   insere(d5,5);
   insere(d5,2);
   insere(d5,7);
   assert(true == arvores_iguais(d5, arvore5()));
   d10 = cria_arvore();
   insere(d10,10);
   insere(d10,5);
   insere(d10,2);
   insere(d10,7);
   insere(d10,20);
   insere(d10,12);
   insere(d10,30);
   assert(true == arvores_iguais(d10, arvore10()));

   /* insere repetido */
   d10 = cria_arvore();
   insere(d10,10);
   insere(d10,5);
   insere(d10,2);
   insere(d10,7);
   insere(d10,20);
   insere(d10,12);
   insere(d10,30);
   insere(d10,10);
   insere(d10,5);
   insere(d10,20);
   insere(d10,30);
   assert(true == arvores_iguais(d10, arvore10()));

   /* conta elementos */
   assert(conta(arvore10()) == 7);
   assert(conta(arvore5()) == 3);
   assert(conta(arvore2()) == 1);
   assert(conta(ex3()) == 5);
   assert(conta(cria_arvore()) == 0); 

   /* soma elementos */
   assert(soma(ex1()) == 71);
   assert(soma(ex2()) == 15);
   assert(soma(ex3()) == 335);
   assert(soma(cria_arvore()) == 0);

  /*maior elemento*/ 
   assert(maior(ex1()) == 20);
   assert(maior(ex2()) == 10);
   assert(maior(ex3()) == 120);

   printf("parabeins\n");
   
}


    
    