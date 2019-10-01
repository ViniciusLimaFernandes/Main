#include<stdbool.h>
#include<assert.h>
#include<stdio.h>
/*
Considere a lista a seguir:
    [10, 20, 30, 40, 90, 110, 400, 900, 1000, 5000, 10000, 15000]


O indice do 10 é 0
O indice do 20 é 1
O indice do 400 é 6
O indice do 5000 é 9 */

/*
Explicacao

Acessar um elemento de uma lista é fácil. É só usar colchetes, como
nos exemplos a seguir

int main() {
   int lista[12] = {10, 20, 30, 40, 90, 110, 400, 900, 1000, 5000, 10000, 15000};
   printf("%d\n",lista[0]); //imprime 10
   printf("%d\n",lista[1]); //imprime 20
   printf("%d\n",lista[6]); //imprime 400
}

*/

/*
EXERCICIO

   Faça uma funcao pega_indice, que recebe uma lista e um indice, e retorna
   o elemento que está nesse indice.

   Por exemplo,
   int lista[4] = {100,102,105,990}
   a=pega_indice(lista,2) //a variavel a tem o numero 105
*/


int pega_indice(int lista [], int indice) {
   return lista[indice];
}


/*
EXERCICIO

    Faça uma funcao que 
    busca um numero na lista, olhando indice a indice.

    Se o numero for encontrado, a funcao deverá retornar o indice

    Se o numero nao for encontrado, a funcao devera retornar false

*/

int busca_linear(int lista[], int numero_a_procurar, int tam_lista) {
    int aux = 0;
    for(int i = 0 ; i<tam_lista ; i++){
        if(lista[i] == numero_a_procurar){
            return i;
        }
    }
    return 0;
}


/*
EXPLICACAO:

    Agora, vamos começar a pensar na busca binária. Ou seja, 
    começar a tentar fazer a busca mais rápida, "quebrando a lista na metade".

    A primeira coisa que temos que saber é calcular a posicao da metade de uma lista

    Dados dois números a e b, a média deles é (a+b)/2

    Por exemplo, a média de:
        *8 e 5 é (8+5) dividido por 2 = 6.5
        *8 e 6 é (8+6) dividido por 2 = 7
        *10 e 0 é (10+0) dividido por 2 = 5

    No nosso caso, nao queremos médias "de verdade", porque
    queremos escolher indices válidos.

    Felizmente, em C, a divisão já arredonda para baixo (*)
    
    Assim, calcular uma média "arredondada para baixo" é facil
    > (12+20)/2
    16
    > (12+19)/2
    15

    (*) existem alguns detalhes que contradizem isso, mas só para numeros
    negativos 
*/
/*
Exercicio: Escreva uma funcao que recebe dois npumeros e devolve sua média
arredondada para baixo
*/

int media_arredondada(int nro1, int nro2) {
    return (nro1+nro2)/2;//altere
}



/*
Lembra da busca binaria?

Se temos uma lista ORDENADA, e queremos saber se o 200 número está 
entre os indices 10 e 20.
podemos fazer o seguinte: 
1) Pegamos o indice do meio (15) e vemos qual número está lá.
2) Se achamos nosso numero, retornamos True
3) Caso o numero do meio seja maior que 200, 
so precisamos procurar na parte de tras da lista, entre os indices 10 e 14
4) Caso o numero do meio seja menor que 200, so precisamos procurar na parte da frente 
da lista: entre os indices 16 e 20
*/

/*
EXERCICIO
Agora, vamos usar essa a media_arredondada para consultar uma lista.


Façamos uma funcao numero do meio que recebe uma 
lista e dois indices, e devolve o numero na posicao do meio,
arredondando pra baixo se for o caso

por exemplo:
    int lista[12] = {100,201,315,405,406,407,500,600,700,900,1000,1003} 
    a = numero_do_meio(lista,2,6)
    a variavel a terá o número 406

O que aconteceu?
Estamos considerando o intevalo do indice 2 ao 6
[100,201,315,405,406,407,500,600,700,900,1000,1003]
  0   1   2   3   4   5   6   7   8   9   10   11
         ___________________

O indice do número do meio é 4 (a média entre 2 e 6)
O número da lista que está nesse indice é o 406.

*/
int numero_do_meio(int lista [],int comeco,int fim) {
    return lista[(comeco+fim)/2];
}


/*
EXPLICACAO
Agora, façamos algumas pequenas simulações da busca binária.

Digamos que eu estou procurando o número 200.

No momento, acho que ele está entre o indice 20 e 30, se estiver na lista.
Isso quer dizer que eu vou verificar a posicao 25. Se achar o 215 na posicao
25, entao 200 só pode estar para trás. Devo procurar entre 20 e 24.

Vamos sintetizar esse resultado da sequinte forma: 25,(20,24)
Ou seja, escrever o indice que fomos olhar e os novos 2 indices onde nosso
número pode estar.
*/

/*
Digamos que eu estou procurando o número 200.

No momento, acho que ele está entre o indice 10 e 30, se estiver na lista.
Procurei no meio e achei o número 300.

Na nocao acima, tivemos
busca1=20,(10,19)

*/

/* Digamos que eu estou procurando o número 200.

No momento, acho que ele está entre o indice 20 e 26, se estiver na lista.
Procurei no meio e achei o número 100.

Na notação acima, tivemos
busca2=23,(24,26)
*/

/*
Digamos que eu estou procurando o número 200.

No momento, acho que ele está entre o indice 15 e 35, se estiver na lista.
Procurei no meio e achei o número 12.

Na notação acima, tivemos
busca3=25,(26,35)
*/

/*
Agora que já vimos simulamos um passo da busca binaria, implementemos
um passo.

Façamos uma funcao passo_da_busca_binaria, que recebe 4 coisas:
    *uma lista
    *o numero a procurar
    *o menor indice
    *o maior indice

A idéia é que já eliminamos alguns pedaços da lista, de
forma que basta procurar o número entre o menor
e o maior indices.

Vamos achar o indice do meio, verificar se o número
que está lá é maior, menor ou igual ao que queremos.

Se ainda der pra procurar, retornaremos uma tripla (definida abaixo) com dois
numeros: os novos indices maior e menor 
(um deles mudou, por causa do jeito que a busca binaria funciona)

Nao se preocupe ainda com a resp_final
*/
struct bb_ans {
   int     menor; 
   int     maior;
   bool    resp_final;
};
typedef struct bb_ans tripla;


tripla passo_da_busca_binaria(int lista [],int procurando,int menor_i,int maior_i){
   tripla resp;
   resp.menor = menor_i; resp.maior = maior_i;
   int meio_i = (menor_i+maior_i)/2;
   int nro_meio = lista[meio_i];
   if(nro_meio > procurando) {
       resp.maior = meio_i-1;
    }
   if(nro_meio < procurando) {
       resp.menor = meio_i+1;
   }
   return resp;
}

/*
EXPLICACAO
Nosso proximo problema: se temos os dois indices, o do inicio e o do
fim do intervalo, quantos números ainda estão "sob suspeita" de 
serem o número procurado?

Olhando o exemplo a seguir, imagine que estamos procurando entre o
índice 2 e o 6.

[100,201,315,405,406,407,500,600,700,900,1000,1003]
  0   1   2   3   4   5   6   7   8   9   10   11
         ___________________

Nosso intervalo atual de busca contém 5 números (de 315 a 500)
*/
/*
indicaremos o tamanho de alguns intervalos.

Por exemplo, t_intervalo_1_7, tem quantos números existem,
no intervalo que vai do indice 1 até o 7, incluindo
tanto o 1 quanto o 7

t_intervalo_1_7 = 7
t_intervalo_5_8 = 4
t_intervalo_10_11 = 2
t_intervalo_2_1 = 0

*/

/*EXERCICIO
Crie uma funcao tam_do_intervalo(inicio,fim) que
conta quantos números ainda temos "sob suspeita" */

int tam_do_intervalo(int inicio,int fim){
    return fim-inicio+1 < 0 ? 0 : fim-inicio+1;
}

/*
EXERCICIO

Estamos quase lá.

Façamos uma função passo_melhor_da_busca_binaria.

Quando o número ainda pode estar na lista, ela faz o mesmo que
o passo_da_busca_binaria: retorna uma tripla com o 
novo intervalo onde ele pode estar

Nesse caso, coloque 122 em resp_final 
(só pra nao deixar um valor indefinido)

Mas, quando ela acabou de ver o meio e achou o número, ela retorna uma
tripla, com resp_final=true

E, quando ela já tem certeza que o número não está na lista 
(tamanho do intervalo é 0, ou é 1 mas o elemento não
é o procurado) ela retorna uma tripla com resp_final=false

*/

tripla passo_melhor_da_busca_binaria(int lista [],int procurando,int menor_i, int maior_i) {
   tripla resp;
   resp.menor = menor_i; resp.maior = maior_i;
   int meio_i;
   int nro_meio;
   meio_i = (menor_i+maior_i)/2;
   nro_meio = lista[meio_i];
   if(nro_meio > procurando) {
       resp.maior = meio_i-1;
    }
   if(nro_meio < procurando) {
       resp.maior = meio_i+1;
   }
   return resp;
}

/*
EXERCICIO
Escreva uma funcao busca_binaria(lista,procurado)

Implementamos a ideia descrita acima da seguinte forma:
    Comecamos com duas variaveis, comeco = 0 e fim = len(lista)-1
    Definimos o meio como (comeco + fim)//2
    Verificamos se lista[meio] eh o numero que queremos.
    Se for, ja achamos 
    Se nao for, e o meio for maior, entao podemos pegar um novo fim: meio-1
    Se nao for, e o meio for menor, entao podemos pegar um novo comeco
*/
bool busca_binaria(int lista [] , int procurado, int tam_lista){
    return false;
}





void test_003_pega_indice() {
        int lista1[12] = {10, 20, 30, 40, 90, 110, 400, 900, 1000, 5000, 10000, 15000};
        assert(pega_indice(lista1,4) == 90);
        assert(pega_indice(lista1,5) == 110);
        assert(pega_indice(lista1,7) == 900);
        int lista2[13] = {9,10, 20, 30, 40, 90, 110, 400, 900, 1000, 5000, 10000, 15000};
        assert(pega_indice(lista2,4) == 40);
}

void test_004_busca_linear(){
        int lista1[12] = {10, 20, 30, 40, 90, 110, 400, 900, 1000, 5000, 10000, 15000};
        assert(busca_linear(lista1,90,11) == 4);
        assert(busca_linear(lista1,110,11) == 5);
        assert(busca_linear(lista1,900,11) == 7);
        assert(busca_linear(lista1,901,11) == false);
        int lista2[13] = {1,10, 20, 30, 40, 90, 110, 400, 900, 1000, 5000, 10000, 15000};
        assert(busca_linear(lista2,90,12) == 5);
}

    
    void test_010_media_arredondada() {
        assert(media_arredondada(5,7) == 6);
        assert(media_arredondada(4,7) == 5);
        assert(media_arredondada(4,6) == 5);
        assert(media_arredondada(4,5) == 4);
    }

    void test_011_numero_do_meio() {
        int lista[100] = {100,201,315,405,406,407,500,600,700,900,1000,1003};
        assert(numero_do_meio(lista,4,6) == 407);
        assert(numero_do_meio(lista,3,7) == 407);
        assert(numero_do_meio(lista,1,5) == 405);
        assert(numero_do_meio(lista,0,5) == 315);
    }

void test_015_passo_da_busca_binaria() {
        int lista1[100] = {10, 20, 30, 40, 90, 110, 400, 900, 1000, 5000, 10000, 15000};
        tripla resposta;
        resposta = passo_da_busca_binaria(lista1,200,2,7);
        assert(resposta.menor == 5);
        assert(resposta.maior == 7);
        resposta = passo_da_busca_binaria(lista1,900,0,11);
        assert(resposta.menor == 6);
        assert(resposta.maior == 11);
        resposta = passo_da_busca_binaria(lista1,9,0,6);
        assert(resposta.menor == 0);
        assert(resposta.maior == 2);
}

    void test_020_tam_do_intervalo() {
        assert(tam_do_intervalo(1,2) == 2);
        assert(tam_do_intervalo(10,15) == 6);
        assert(tam_do_intervalo(9,9) == 1);
        assert(tam_do_intervalo(9,8) == 0);
        assert(tam_do_intervalo(9,4) == 0);
    }


    void test_021_passo_melhor_da_busca_binaria(){
        int lista1[100] = {10, 20, 30, 40, 90, 110, 400, 900, 1000, 5000, 10000, 15000};
        tripla resposta;
        resposta = passo_melhor_da_busca_binaria(lista1,200,2,7);
        assert(resposta.menor == 5);
        assert(resposta.maior == 7);
        resposta = passo_melhor_da_busca_binaria(lista1,900,0,11);
        assert(resposta.menor == 6);
        assert(resposta.maior == 11);
        resposta = passo_melhor_da_busca_binaria(lista1,9,0,6);
        assert(resposta.menor == 0);
        assert(resposta.maior == 2);
    }

    void test_022_passo_melhor_da_busca_binaria2(){
        int lista1[199] = {10, 20, 30, 40, 90, 110, 400, 900, 1000, 5000, 10000, 15000};
        tripla resposta;
        resposta = passo_melhor_da_busca_binaria(lista1,110,3,7);
        assert(resposta.resp_final == true);
        resposta = passo_melhor_da_busca_binaria(lista1,110,5,5);
        assert(resposta.resp_final == true);
        resposta = passo_melhor_da_busca_binaria(lista1,12,7,5);
        assert(resposta.resp_final == false);
        resposta = passo_melhor_da_busca_binaria(lista1,12,5,5);
        assert(resposta.resp_final == false);
    }

    void test_023_passo_melhor_da_busca_binaria3() {
        int lista1[100] = {10, 20, 30, 40, 90, 110, 400, 900, 1000, 5000, 10000, 15000};
        tripla resposta;
        resposta = passo_melhor_da_busca_binaria(lista1,12,5,4);
        assert(resposta.resp_final == false);
    }

    void test_024_busca_funciona() {
        int lista1[10] = {0,1,2,3,4};
        assert(busca_binaria(lista1,2,5) ==  true);
        assert(busca_binaria(lista1,4,5) ==  true);
        assert(busca_binaria(lista1,5,5) ==  false);
        int lista2[10] = {0,1,2,4,5,6,7,8};
        assert(busca_binaria(lista2,2,8) ==  true);
        assert(busca_binaria(lista2,3,8) ==  false);
        int lista3[10]={0,1,2,3,4,5,6};
        assert(busca_binaria(lista3,4,7) ==  true);
        int lista4[100] = {0, 1, 2, 3, 4, 9, 10, 11, 12, 25, 32, 54, 56, 67, 72, 76, 87, 89, 100, 112, 400};
        assert(busca_binaria(lista4,5,21) == false);
        assert(busca_binaria(lista4,32,21) == true);
        int lista5[100] = {0, 101, 102, 103, 104, 109, 1010, 1011, 1012, 1025, 1032, 1054, 1056, 1067, 1072, 1076, 1087, 1089, 1100, 1112, 1400};
        assert(busca_binaria(lista5,500,21) == false);
        assert(busca_binaria(lista5,5,21) == false);
        assert(busca_binaria(lista5,103,21) == true);
        assert(busca_binaria(lista5,1400,21) == true);
    }

int main() {
   int testes = 1;
   test_003_pega_indice();
   printf("passou %d teste!\n",testes++);
   test_004_busca_linear();
   printf("passou %d testes!\n",testes++);
   test_010_media_arredondada();
   printf("passou %d testes!\n",testes++);
   test_011_numero_do_meio();
   printf("passou %d testes!\n",testes++);
   test_015_passo_da_busca_binaria();
   printf("passou %d testes!\n",testes++);
   test_020_tam_do_intervalo();
   printf("passou %d testes!\n",testes++);
   test_021_passo_melhor_da_busca_binaria();
   printf("passou %d testes!\n",testes++);
   test_022_passo_melhor_da_busca_binaria2();
   printf("passou %d testes!\n",testes++);
   test_023_passo_melhor_da_busca_binaria3();
   printf("passou %d testes!\n",testes++);
   test_024_busca_funciona();
   printf("passaram todos os testes!\n");
   
}