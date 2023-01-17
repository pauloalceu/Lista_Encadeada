#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

/* função de inicialização: retorna uma lista vazia */
Lista* inicializa()
{
    return NULL;
}

/* inserção no início: retorna a lista atualizada */
Lista* insere(Lista *l, int i)
{
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}
/* função imprime: imprime valores dos elementos */
void imprime(Lista *l)
{
    Lista *p; /* variável auxiliar para percorrer a lista */
    for(p = l; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int vazia(Lista *l)
{
    return (l == NULL);
}
/* função busca: busca um elemento na lista */
Lista* busca(Lista *l, int v)
{
    Lista *p;
    for(p = l; p != NULL; p = p->prox)
        if(p->info == v)
            return p;
    return NULL; /* não achou o elemento */
}

/* função retira: retira elemento da lista */
Lista* retira(Lista *l, int v)
{
    Lista *ant = NULL; /* ponteiro para elemento anterior */
    Lista *p = l; /* ponteiro para percorrer a lista*/
    /* procura elemento na lista, guardando anterior */
    while(p != NULL && p->info != v)
    {
        ant = p;
        p = p->prox;
    }
    /* verifica se achou elemento */
    if(p == NULL)
        return l; /* não achou: retorna lista original */
    /* retira elemento */
    if(ant == NULL)
    {
        /* retira elemento do inicio */
        l = p->prox;
    }
    else
    {
        /* retira elemento do meio da lista */
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

/* função libera: libera a memória ocupada pela lista */
void libera(Lista *l)
{
    Lista *p = l;
    while(p != NULL)
    {
        /* guarda referência p/ próximo elemento */
        Lista *t = p->prox;
        free(p); /* libera a memória apontada por p */
        p = t; /* faz p apontar para o próximo */
    }
}

/* 2 */

/* a) funcao NumeroNos : Determina o numero de nós de uma lista */
int numeroNos(Lista *l){
  Lista *p = l;
  int count = 0;
  while(p != NULL){
      p = p->prox;
      count++;
  }
  return count;
}

/* b) função inserirPreK : insere nó na posição anterior a o nó da de valor v */
Lista* inserirPreK(Lista *l, int i, int v){
  Lista *p = l;
  Lista *anterior = NULL;

  while( (p->info != v) && (p != NULL)){
     anterior = p;
     p = p->prox;
  };

  if (p != NULL){
    if (anterior == NULL){
      l = insere(l, i);
    }
    else{
      Lista *novo = (Lista*) malloc(sizeof(Lista));
      novo->info = i;
      novo->prox = p;
      anterior->prox = novo;
    }
  }

  return l;

}

/* c) função inserirPosK : insere nó na posição anterior a o nó de valor v */
Lista* inserirPosK(Lista *l, int i, int v){
  Lista *p = busca(l,v);

  if (p != NULL)  {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = p->prox;
    p->prox = novo;
  }

  return l;
}

/* d) funcao quebralista : Divide a lista em duas a partir de um determinado nó */
void quebralista(Lista *l, int v, Lista *l2){
    Lista *p = busca(l, v);
    if (p!=NULL){
       l2 = p->prox;
       p->prox = NULL;
    }
}

/* e) funcao sortList : Ordena a lista por valores crescentes */
Lista* sortList(Lista *l){
    Lista *sortedList = NULL;
    sortedList = insere(sortedList, l->info);
    Lista *s;
    Lista * ant;
    l = retira(l, l->info);
    while(l != NULL){
        s = sortedList;
      while((s != NULL) && (s->info < l->info)){
          ant = s;
          s = s->prox;
      }
      if (s != NULL){
        sortedList = inserirPreK(sortedList, l->info, s->info);
      }else{
        sortedList = inserirPreK(sortedList, l->info, ant->info);
      }
      l =retira(l, l->info);
    }
  l = sortedList;
  return l;
}

/* f) funcao comparaListas: Compara duas listas */
int comparaListas(Lista *l1, Lista *l2){
  Lista *a, *b;
  a = l1;
  b = l2;
  if (numeroNos(l1) != numeroNos(l2)){
    return 0;
  } else {
    while ((a == b)  && (a != NULL)){
      a = l1->prox;
      b = l2->prox;
    }
    if (a == NULL){
      return 1;
    }else{
      return 0;
    }
  }
}

/* g) funcao concatenarListas : concatena duas listas na ordem l1 + l2 */
Lista* concaternarListas(Lista *l1, Lista *l2){
  Lista *p = l1;
  while(p->prox != NULL){
    p = p->prox;
  }

  p->prox = l2;
  return l1;
}

/* 2 */

Lista* incluiOrdenado(Lista *l, int v){
  Lista *p; Lista *ant;
  p = l;
  while((p->info < v) && (p!=NULL)){
    ant = p;
    p = p->prox;
  }
  if (p != NULL){
    l = inserirPreK(l, v, p->info);
  }else{
    l = inserirPreK(l, v, ant->info);
  }
}
