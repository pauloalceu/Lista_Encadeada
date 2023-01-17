#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED

struct lista
{
    int info;
    struct lista *prox;
};

typedef struct lista Lista;

/* função de inicialização: retorna uma lista vazia */
Lista* inicializa();

/* inserção no início: retorna a lista atualizada */
Lista* insere(Lista *l, int i);

/* função imprime: imprime valores dos elementos */
void imprime(Lista *l);

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int vazia(Lista *l);

/* função busca: busca um elemento na lista */
Lista* busca(Lista *l, int v);

/* função retira: retira elemento da lista */
Lista* retira(Lista *l, int v);

/* função libera: libera a memória ocupada pela lista */
void libera(Lista *l);

/* a) funcao NumeroNos : Determina o numero de nós de uma lista */
int numeroNos(Lista *l);

/* b) função inserirPreK : insere nó na posição anterior a o nó da de valor v */
Lista* inserirPreK(Lista *l, int i, int v);

/* c) função inserirPosK : insere nó na posição anterior a o nó de valor v */
Lista* inserirPosK(Lista *l, int i, int v);

/* d) funcao quebralista : Divide a lista em duas a partir de um determinado nó */
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

