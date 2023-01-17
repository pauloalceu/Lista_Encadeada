#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

struct lista
{
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

/* fun��o de inicializa��o: retorna uma lista vazia */
Lista* inicializa();

/* inser��o no in�cio: retorna a lista atualizada */
Lista* insere(Lista *l, int i);

/* fun��o imprime: imprime valores dos elementos */
void imprime(Lista *l);

/* fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia */
int vazia(Lista *l);

/* fun��o busca: busca um elemento na lista */
Lista* busca(Lista *l, int v);

/* fun��o retira: retira elemento da lista */
Lista* retira(Lista *l, int v);

/* fun��o libera: libera a mem�ria ocupada pela lista */
void libera(Lista *l);

/* a) funcao NumeroNos : Determina o numero de n�s de uma lista */
int numeroNos(Lista *l);

/* b) fun��o inserirPreK : insere n� na posi��o anterior a o n� da de valor v */
Lista* inserirPreK(Lista *l, int i, int v);

/* c) fun��o inserirPosK : insere n� na posi��o anterior a o n� de valor v */
Lista* inserirPosK(Lista *l, int i, int v);

/* d) funcao quebralista : Divide a lista em duas a partir de um determinado n� */
void quebralista(Lista *l, int v, Lista *l2);

/* e) funcao sortList : Ordena a lista por valores crescentes */
Lista* sortList(Lista *l);

/* f) funcao comparaListas: Compara duas listas */
int comparaListas(Lista *l1, Lista *l2);

/* g) funcao concatenarListas : concatena duas listas na ordem l1 + l2 */
Lista* concaternarListas(Lista *l1, Lista *l2);

/* 2 Inserir ordenado */
Lista* incluiOrdenado(Lista *l, int v);

#endif // LISTACONTIGUA_H_INCLUDED

