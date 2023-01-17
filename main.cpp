#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.c"

int main()
{
    Lista *l = inicializa(); // declara e inicia um lista vazia
    l = insere(l, 23); // insere na lista o elemento 23
    l = insere(l, 45); // insere na lista o elemento 45
    l = insere(l, 56); // insere na lista o elemento 56
    l = insere(l, 78); // insere na lista o elemento 78

    printf("\n\n");
    imprime(l); // imprimirá 78 56 45 23

    l = sortList(l);
    printf("\n\n");
    imprime(l); // imprimirá 23 45 56 78

    l = inserirPreK(l, 67, 78);
    l = inserirPosK(l, 34, 23);

    printf("\n\n");
    imprime(l); // imprimirá 23 34 45 56 67 78

    l = retira(l, 78);
    printf("\n\n");
    imprime(l); // imprimirá 56 45 23

    l = retira(l, 45);
    printf("\n\n");
    imprime(l); // imprimirá 56 23

    libera(l);

    return 0;
}
