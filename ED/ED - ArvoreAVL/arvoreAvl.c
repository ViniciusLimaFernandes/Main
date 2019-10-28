#include<malloc.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>

#include <stdio.h>
#include <stdlib.h>
#define EE 1
#define ED 2
#define DE 3
#define DD 4

/*
 * Nesse arquivo, temos uma funcao subir_no_direito
 * e uma subir_no_esquerdo. Uma delas está implementada
 * Sua missao é fazer a outra
 * */

struct noh_arv {
   int     conteudo; 
   struct noh_arv* esquerda;
   struct noh_arv* direita;
   struct noh_arv* pai;
   int altura;
};
typedef struct noh_arv noh;

struct arv {
   noh* raiz;
};
typedef struct arv arvore;

typedef int caso;


noh* cria_noh(int conteudo) {
  noh *n = malloc(sizeof(noh));
  n->conteudo = conteudo;
  n->esquerda = NULL;
  n->direita = NULL;
  n->pai = NULL;
  n->altura = 1;

  return n;
}

arvore* cria_arvore() {
  arvore *t = malloc(sizeof(arvore));
  t->raiz = NULL;

  return t;
}

int max(int a, int b) {
  if(a > b)
    return a;
  return b;
}

int altura(noh *n) {
  if(n == NULL)
    return 0;
  return n->altura;
}


/*
      x                 y
        y   vira      x
            ---->
   A   B C          A  B    C
*/

void subir_no_direito(arvore *t, noh *x) {
  noh *y = x->direita;
  x->direita = y->esquerda; //mover B
  if(y->esquerda != NULL) { //mover B. 
    y->esquerda->pai = x;
  }
  //Perceba que A e C não precisam de alteração!

  //Agora, temos que ajustar o pai de x: esse pai
  //deve parar de apontar para x e passar a apontar
  //para y
  y->pai = x->pai;
  if(t->raiz == x) { //x is raiz
    t->raiz = y;
  }
  else if(x == x->pai->esquerda) { //x is esquerda child
    x->pai->esquerda = y;
  }
  else { //x is right child
    x->pai->direita = y;
  }

  //por ultimo conectamos x e y
  y->esquerda = x;
  x->pai = y;

  //e recalculamos as alturas
  x->altura = 1 + max(altura(x->esquerda), altura(x->direita));
  y->altura = 1 + max(altura(y->esquerda), altura(y->direita));
}
/*
        x                  y
     y           vira         x
                ---->
    A B      C          A    B C
*/

void subir_no_esquerdo(arvore *t, noh *x) {
}

int balance_factor(noh *n) {
  if(n == NULL)
    return 0;
  return(altura(n->esquerda) - altura(n->direita));
}

bool busca(arvore* a, int procurado) {
   noh* atual;
   atual = a-> raiz;
   while (true) {
      if (atual == NULL)
         return false;
      else if (atual->conteudo ==  procurado)
         return true;
      else if (atual->conteudo < procurado)
         atual = atual->direita;
      else if (atual->conteudo > procurado)
         atual = atual->esquerda;
   }
}

void corrige_alturas(arvore* t, noh* inserido) {
   noh* temp = inserido;
   while(temp != NULL) {
      temp->altura = 1 + max(altura(temp->esquerda), altura(temp->direita));
      temp = temp-> pai;
   }
}

/* vai subindo, a partir do inserido, até achar um nó desbalanceado (avo)
 * e os dois nós "abaixo" dele no caminho da insersão (pai e filho)
 *
 * Usa os ponteiros avo, pai e filho para fornecer a resposta. Retorna
 * true se houve violacao e false se nao houve. Nesse segundo caso,
 * o conteudo dos ponteiros avo, pai e filho nao tem significado*/
bool detecta_violadores(noh* inserido, noh** filho, noh** pai, noh** avo) {
   *filho = inserido;
   while (true) {
      if ((*filho)-> pai == NULL || (*filho)->pai->pai == NULL)
         return false; //nao houve violacao. Para haver, tem que ser no avo
      *pai = (*filho)->pai;
      *avo = (*pai)->pai;
      if(balance_factor(*avo) <= -2 || balance_factor(*avo) >= 2) {
         return true; //houve violacao, avo pai e filho tem os valores corretos
      }
      *filho = (*filho)->pai;
   }
}

caso descobre_caso(noh* filho, noh* pai, noh* avo) {
      if(pai == avo->esquerda) {
        if(filho == avo->esquerda->esquerda) //caso ESQUERDA ESQUERDA
          return EE;

        if(filho == avo->esquerda->direita) {//caso ESQUERDA DIREITA
           return ED;
        }
      }
      if(pai == avo->direita) {
        if(filho == avo->direita->direita) //case DIREITA DIREITA
          return DD;

        else if(filho == avo->direita->esquerda) {//case DIREITA ESQUERDA
           return DE;
        }
      }

}

void insere(arvore *t, int valor) {
  noh* n;
  n = cria_noh(valor);
  noh *pai_inserido = NULL;//pai do inserido
  noh *temp = t->raiz;
  //temp vai procurando, pai_inserido fica 1 para trás
  while(temp != NULL) {
    pai_inserido = temp;//aqui está pai_inserido ficando 1 para trás
    if(n->conteudo < temp->conteudo)
      temp = temp->esquerda;
    else
      temp = temp->direita;
  }
  n->pai = pai_inserido;
  //pai_inserido é o pai do novo nó

  if(pai_inserido == NULL) //nesses 3 ifs, coloco o inserido na posicao certa 
                           //(raiz da arvore, direita do pai ou esquerda do pai)
    t->raiz = n;
  else if(n->conteudo < pai_inserido->conteudo)
    pai_inserido->esquerda = n;
  else
    pai_inserido->direita = n;

  noh* temp_pai; noh* temp_avo;
  corrige_alturas(t,n);
  bool violacao = detecta_violadores(n,&temp, &temp_pai, &temp_avo);
  caso caso_da_violacao;
  if(violacao) {
      caso_da_violacao = descobre_caso(temp, temp_pai,temp_avo);
      if(caso_da_violacao == EE) //caso ESQUERDA ESQUERDA
        subir_no_esquerdo(t, temp_avo);

      if(caso_da_violacao == ED) {//caso ESQUERDA DIREITA
        subir_no_direito(t, temp_pai);
        subir_no_esquerdo(t, temp_avo);
      }
      if(caso_da_violacao == DD) //case DIREITA DIREITA
        subir_no_direito(t, temp_avo);

      if(caso_da_violacao == DE) {//case DIREITA ESQUERDA
        subir_no_esquerdo(t, temp_pai);
        subir_no_direito(t, temp_avo);
      }
      corrige_alturas(t,temp);
      corrige_alturas(t,temp_pai);
      corrige_alturas(t,temp_avo);
  }
}



int* gera_elementos(int tamanho) {
   int * elementos;
   int elemento = 0;
   elementos = malloc(sizeof(int)*tamanho);

   for(int i=0; i<tamanho; i++) {
      elemento += (1+rand()%2);
      elementos[i] = elemento;
   }
   return elementos;

}
arvore* gera_arvore(int tamanho, int* elementos) {
   arvore* a = cria_arvore();
   for(int i=0; i<tamanho; i++) {
      insere(a,elementos[i]);
   }
   return a ;

}

bool verifica_elementos(int tamanho, arvore* a, int* elementos) {
   for (int i = 0; i < tamanho; i++) {
      if (!busca(a,elementos[i]))
         return false;
   }
   for (int i = 0; i < tamanho-1; i++) {
      if (elementos[i+1] != elementos[i]+1)
         if (busca(a,elementos[i]+1))
            return false;
   }
   return true;

}
bool verifica_lados(noh* n) {
    if (n == NULL) 
        return true;
    if (n->direita != NULL && 
          !(n->direita->conteudo >= n->conteudo))
        return false;
    if (n->esquerda != NULL && 
          !(n->esquerda->conteudo <= n->conteudo))
        return false;
    if ((!verifica_lados(n->direita)) || (! verifica_lados(n->esquerda)))
        return false;
    return true;
}
bool verifica_pai(noh* n, arvore* a) {
    if (n == NULL)
        return true;
    if (n->direita != NULL && ! (n->direita->pai == n))
        return false;
    if (n->esquerda != NULL && ! (n->esquerda->pai == n))
        return false;
    if (n != a->raiz) {
        if (n->pai->esquerda != n &&
            n->pai->direita != n)
            return false;
    }
    if ((! verifica_pai(n->direita,a)) || ! (verifica_pai(n->esquerda,a)))
        return false;
    return true;
}

int verifica_altura(noh* n) {
   if (n == NULL)
      return 0;
   int altura;
   altura = verifica_altura(n->direita);
   if (verifica_altura(n->esquerda) > altura)
      altura = verifica_altura(n->esquerda);
   altura += 1; //altura do proprio noh
   if (n-> altura != altura) {
      printf("altura no noh nao corresponde a altura calculada\n");
      printf("%d,%d",n->altura,altura);
      assert(false);
   }
   return altura;
}
bool verifica_avl(noh* n){
    if (n == NULL)
        return true;
    int alt_e = 0; int alt_d = 0;
    if (n->esquerda != NULL) 
      alt_e = n->esquerda->altura;
    if (n->direita != NULL) 
      alt_d = n->direita->altura;
    int diff = alt_e-alt_d;
    if (diff != 0 && diff != -1 && diff != 1)
        return false;
    if (! verifica_avl(n->direita))
      return false;
    if (! verifica_avl(n->esquerda))
      return false;
    return true;
}

void testa() {
   int* elementos;
   int tamanho = 100;
   arvore* a;
   srand(time(NULL));
   elementos = gera_elementos(tamanho);
   a = gera_arvore(tamanho,elementos);
   assert(verifica_elementos(tamanho,a,elementos));
   printf("todos os elementos colocados estao na arvore!\n");
   assert(verifica_lados(a->raiz));
   printf("e ela parece coerente com os lados!\n");
   assert(verifica_pai(a->raiz,a));
   printf("e ela parece coerente com os pais!\n");
   verifica_altura(a->raiz);
   printf("e ela parece coerente em termos de alturas!\n");
   assert(verifica_avl(a->raiz));
   printf("e ela parece coerente em termos da propriedade AVL!!!\n");
}

int main() {
   srand(time(NULL));
   testa();
}

