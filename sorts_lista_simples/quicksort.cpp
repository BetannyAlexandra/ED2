#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef struct cel
{
    int num;
    cel *ant;
    cel *prox;
} celula;

typedef struct list
{
    celula *inicio = NULL;
    celula *fim = NULL;
    int tam;
} lista;
lista *cabeca;

void remover(lista *lista1, celula *element)
{

}

void inserir_inicio(lista *lista1, celula *element)
{

    if (lista1 == NULL || element == NULL)
    {
        return;
    }

    if (lista1->tam == 0)
    {
        lista1->inicio = element;
        lista1->fim = element;
        lista1->tam = 1;
        element->prox = NULL;
        element->ant = NULL;
    }
    element->ant = NULL;
    element->prox = lista1->inicio;
    lista1->inicio = element;
    lista1->inicio = element;
    lista1->tam++;
}

void inserir_fim(lista *lista1, celula *element)
{

    if (lista1 == NULL || element == NULL)
    {
        return;
    }

    if (lista1->tam == 0)
    {
        lista1->inicio = element;
        lista1->fim = element;
        lista1->tam = 1;
        element->prox = NULL;
        element->ant = NULL;
    }

    element->prox = NULL;
    element->prox = lista1->inicio;
    lista1->inicio = element;
    lista1->inicio = element;
    lista1->tam++;
}

void anexar_inicio(lista *nova, lista *lista)
{

    if ((lista == NULL) || (lista->tam == 0))
    {
        return;
    }

    nova->tam += lista->tam;
    nova->fim->ant = lista->fim;
    lista->fim->prox = nova->inicio;
    nova->inicio = lista->inicio;
}

void quicksort(lista *lista1)
{
    if ((lista1 == NULL) || (lista1->tam <= 1))
    {
        return;
    }

    int tam_metade = (lista1->tam) / 2;
    celula *pivo = lista1->inicio;
    for (int i = 0; i < tam_metade; i++)
    {
        pivo = pivo->prox;
    }
    lista menores;
    lista maiores;
    celula *aux = lista1->inicio;
    celula *element = NULL;

    while (aux != NULL)
    {
        element = aux;
        aux = aux->prox;
        if (element == pivo)
        {
            continue;
        }
        if (element->num < pivo->num)
        {
            remover(aux);
            inserir_fim(&menores, element);
        }
    }
    else
    {
        inserir_fim(&maiores, element);
    }
    quicksort(&menores);
    quicksort(&maiores);
    anexar_inicio(lista1, &menores);
    anexar_fim(lista1, &maiores);
}

void imprimir(lista *list){
    celula *aux=list->inicio;
    while(aux!=NULL){
    printf("%d->",aux->num);
    aux=aux->prox;

    }
printf("NULL");

}

int main()
{
    return 0;
}