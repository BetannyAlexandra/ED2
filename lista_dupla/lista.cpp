

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct cel
{
  char nome[30];
  struct cel *prox;
  struct cel *ant;
} celula;
typedef struct lista
{
  celula *cabeca = NULL;
  celula *fim = NULL;
  int tamanho = 0;
} lista;

void imprimir(lista *lista1)
{
  celula *aux = lista1->cabeca;
  while (aux != NULL)
  {
    printf("%s -> ", aux->nome);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void ler_nome(celula *Novo)
{
  printf("\nDigite um nome: ");
  scanf("%s", Novo->nome);
}

celula *novo_elemento()
{
  celula *nova = new celula;
  nova->ant = NULL;
  nova->prox = NULL;

  printf("\nDigite um nome: ");
  scanf("%s", nova->nome);
  return nova;
}

void inserir_fim(lista *lst, celula *elemento)
{
  if ((lst == NULL) || (elemento == NULL))
  {
    return;
  }

  if (lst->tamanho == 0)
  {
    lst->cabeca = elemento;
    lst->fim = elemento;
    lst->tamanho = 1;
    elemento->ant = NULL;
    elemento->prox = NULL;
    return;
  }
  // proximo do novo elemento vai ser nulo, o anterior dele vai ser o fim da antiga lista, e o proximo do fim da antiga lista vai ser o novo elemento. O tamanho da lista é incrementado.
  elemento->prox = NULL;
  elemento->ant = lst->fim;
  lst->fim->prox = elemento;
  lst->fim = elemento;
  lst->tamanho++;
}

void remover(lista *lst, celula *elemento)
{
  if ((lst == NULL) || (elemento == NULL) || (lst->tamanho == 0))
  {
    return;
  }

  if ((lst->cabeca == elemento) && (lst->fim == elemento))
  {
    lst->tamanho = 0;
    lst->cabeca = NULL;
    lst->fim = NULL;
    return;
  }

  lst->tamanho--;

  if (lst->cabeca == elemento)
  {
    lst->cabeca = lst->cabeca->prox;
    lst->cabeca->ant = NULL;
    elemento->prox = NULL;
    return;
  }

  if (lst->fim == elemento)
  {
    lst->fim = lst->fim->ant;
    lst->fim->prox = NULL;
    elemento->ant = NULL;
    return;
  }

  celula *antElem = elemento->ant;
  celula *proxElem = elemento->prox;
  antElem->prox = proxElem;
  proxElem->ant = antElem;

  elemento->ant = NULL;
  elemento->prox = NULL;
}

void anexar_fim(lista *nova, lista *lista)
{
  nova->tamanho += lista->tamanho;
  nova->fim->prox = lista->cabeca;
  lista->cabeca->ant = nova->fim;
  nova->fim = lista->fim;
}

void inserirNoInicio(lista *lista1, celula *elemento)
{

  if ((lista1 == NULL) || (elemento == NULL))
  {
    return;
  }

  if (lista1->tamanho == 0)
  {
    lista1->cabeca = elemento;
    lista1->fim = elemento;
    lista1->tamanho = 1;
    elemento->ant = NULL;
    elemento->prox = NULL;
    return;
  }
  elemento->ant = NULL;
  elemento->prox = lista1->cabeca;
  lista1->cabeca->ant = elemento;
  lista1->cabeca = elemento;
  lista1->tamanho++;
}

void inserirNoFIm(lista *lista1, celula *elemento)
{

  if ((lista1 == NULL) || (elemento == NULL))
  {
    return;
  }

  if (lista1->tamanho == 0)
  {
    lista1->cabeca = elemento;
    lista1->fim = elemento;
    lista1->tamanho = 1;
    elemento->ant = NULL;
    elemento->prox = NULL;
    return;
  }

  lista1->fim->prox = elemento;
  elemento->ant = lista1->fim;
  lista1->fim = elemento;
  elemento->prox = NULL;
  lista1->tamanho++;
}

int length(celula *cabeca)
{
  celula *aux = cabeca;
  int cont = 0;
  while (aux != NULL)
  {
    aux = aux->prox;
    cont++;
  }
  return cont;
}

void troca_posicao(lista *lista1, celula *elem1, celula *elem2)
{
  if (lista1->cabeca == NULL || elem1 == NULL || elem2 == NULL)
  {
    return;
  }

  if (elem2 == lista1->fim)
    lista1->fim = elem1;

  if (lista1->cabeca == elem1)
  {
    lista1->cabeca = elem2;
  }
  else if (lista1->cabeca == elem2)
  {
    lista1->cabeca = elem1;
  }

  if (elem1->ant != NULL)
  {
    elem1->ant->prox = elem2;
  }

  if (elem2->ant != NULL)
  {
    elem2->ant->prox = elem1;
  }

  celula *temp = elem1->ant;
  elem1->ant = elem2->ant;
  elem2->ant = temp;

  temp = elem1->prox;
  elem1->prox = elem2->prox;
  elem2->prox = temp;

  if (elem1->prox != NULL)
  {
    elem1->prox->ant = elem1;
  }

  if (elem2->prox != NULL)
  {
    elem2->prox->ant = elem2;
  }
}

void bubble(lista *lista1)
{
  printf("aqui\n");
  int cont_troca;
  celula *aux = NULL;
  celula *ultimo_no = NULL;

  if (lista1->cabeca == NULL || lista1->cabeca->prox == NULL)
  {
    return;
  }
  do
  {
    cont_troca = 0;
    aux = lista1->cabeca;
    while (aux->prox != ultimo_no)
    {
      if (strcmp(aux->nome, aux->prox->nome) > 0)
      {
        troca_posicao(lista1, aux, aux->prox);
        cont_troca = 1;
      }
      else
      {
        aux = aux->prox;
      }
    }

    ultimo_no = aux;
  } while (cont_troca != 0);

  printf("Lista depois=\n");
  imprimir(lista1);
}

void insertion(lista *lista1, celula *aux, celula *troca)
{

  celula *proxTroca = troca->prox;
  celula *antTroca = troca->ant;
  celula *ant_aux = aux->ant;

  if (troca == lista1->fim)
    lista1->fim = troca->ant;

  if (aux == lista1->cabeca)
  {
    troca->ant = NULL;
    troca->prox = aux;
    aux->ant = troca;
    lista1->cabeca = troca;
  }
  else
  {
    troca->ant = aux->ant;
    troca->prox = aux;
    ant_aux->prox = troca;
    aux->ant = troca;
  }
  // atualizando os nós adjacentes à aux e troca
  if (proxTroca != NULL)
  {
    proxTroca->ant = antTroca;
  }
  if (antTroca != NULL)
  {
    antTroca->prox = proxTroca;
  }
}

void insertion_sort(lista *lista1)
{

  if (lista1->cabeca == NULL || lista1->cabeca->prox == NULL)
    return;
  celula *swap = lista1->cabeca->prox;
  celula *aux = lista1->cabeca;
  celula *proximo = swap->prox;

  while (swap != NULL)
  {
    while (aux != swap)
    {
      if (strcmp(aux->nome, swap->nome) > 0)
      {
        insertion(lista1, aux, swap);
        break;
      }
      aux = aux->prox;
    }
    swap = proximo;
    aux = lista1->cabeca;
    if (swap != NULL)
      proximo = swap->prox;
  }
}
lista *merge(lista *lista1, lista *lista2)
{
  if ((lista1 == NULL) && (lista2 == NULL))
  {
    return NULL;
  }

  if ((lista1 != NULL) && (lista2 == NULL))
  {
    return lista1;
  }

  if ((lista1 == NULL) && (lista2 != NULL))
  {
    return lista2;
  }

  lista *nova = new lista;

  while ((lista1->tamanho > 0) && (lista2->tamanho > 0))
  {

    celula *valor1 = lista1->cabeca;
    celula *valor2 = lista2->cabeca;
    celula *elemento;
    if (valor1->nome < valor2->nome)
    {
      elemento = lista1->cabeca;
      remover(lista1, elemento);
    }
    else
    {
      elemento = lista2->cabeca;
      remover(lista2, elemento);
    }
    inserir_fim(nova, elemento);
  }
  if (lista1->tamanho > 0)
  {
    anexar_fim(nova, lista1);
  }

  if (lista2->tamanho > 0)
  {
    anexar_fim(nova, lista2);
  }

  return nova;
}


lista *merge_sort(lista *lista1)
{
  if ((lista1 == NULL) || (lista1->tamanho == 0))
  {
    return NULL;
  }

  if (lista1->tamanho == 1)
  {
    return lista1;
  }

  // cria uma nova lista para receber a metade da antuga lista.
  // o tamanho da nova lista vai ser igual ao tamanho da antiga dividido por dois. A nova lista vai receber o cabeca da primeira lista e vai atualizar os ponteiros recebendo os elementos da antiga lista enquando i for menor que a metade.Dessa forma, a lista 2 vai ter metaade dos elementos da lista 1;
  lista *lista2 = new lista;

  int tam_metade = lista1->tamanho / 2;
  celula *inicio2 = lista1->cabeca;
  for (int i = 0; i < tam_metade; i++)
  {
    inicio2 = inicio2->prox;
  }

  celula *fim1 = inicio2->ant;
  fim1->prox = NULL;
  inicio2->ant = NULL;

  // cabeca da lista 2 vai ser o cabeca 2,e o fim da lista 2 vai ser o antigo fim da lista ;
  lista2->cabeca = inicio2;
  lista2->fim = lista1->fim;
  lista2->tamanho = lista1->tamanho - tam_metade;

  lista1->fim = fim1;
  lista1->tamanho = tam_metade;
  // repete tudo ate dividir as listas até o fim
  lista1 = merge_sort(lista1);

  lista2 = merge_sort(lista2);
  // ultiliza o merge para unir as duas listas ordenadas
  lista *res = merge(lista1, lista2);

  return res;
}

void selection(lista *lista1)
{

  if (lista1->cabeca == NULL || lista1->cabeca->prox == NULL)
  {
    return;
  }
  celula *inserir = lista1->cabeca;
  celula *menor = NULL;
  celula *aux = menor->prox;

  while (inserir->prox != NULL)
  {
    menor = inserir;
    aux = inserir->prox;

    while (aux != NULL)
    {
      if (strcmp(menor->nome, aux->nome) > 0)
      {
        menor = aux;
      }
      aux = aux->prox;
    }
    if (menor != inserir)
    {
      troca_posicao(lista1, inserir, menor);
      inserir = menor;
    }
    inserir = inserir->prox;
  }
}

void imprimir_menu()
{
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("*\t1 - Inserir nome\t*\n");
  printf("*\t2 - Imprimir \t*\n");
  printf("*\t3 - Bubble sort \t*\n");
  printf("*\t4 - Selection sort \t*\n");
  printf("*\t5 - Insertion sort \t*\n");
  printf("*\t6 - Merge sort \t*\n");
   printf("*\t7 - Quick sort sort \t*\n");
  printf("*\t0 - Sair\t\t*\n");
}

int main()
{
  lista *cabeca = new lista;

  int opc = 1;
  while (opc != 0)
  {
    imprimir_menu();
    scanf("%d", &opc);
    fflush(stdin);
    switch (opc)
    {
    case 1:
      inserirNoInicio(cabeca, novo_elemento());
      break;

    case 2:
      imprimir(cabeca);
      break;

    case 3:
      printf("Lista antes=\n");
      imprimir(cabeca);
      bubble(cabeca);
      printf("Lista depois=\n");
      imprimir(cabeca);
      break;

    case 4:

      printf("Lista antes=\n");
      imprimir(cabeca);
      selection(cabeca);
      printf("Lista depois=\n");

      imprimir(cabeca);
    case 5:

      printf("Lista antes=\n");
      imprimir(cabeca);

      insertion_sort(cabeca);
      printf("Lista depois=\n");

      imprimir(cabeca);
      break;
    case 6:

      printf("Lista antes=\n");
      imprimir(cabeca);

      merge_sort(cabeca);
      printf("Lista depois=\n");
      imprimir(cabeca);
      break;

      //  case 7:
      //   merge_sort(cabeca);
      //       imprimir(cabeca);
      //  break;

    case 0:
      break;

    default:
      printf("Opção inválida\n");
      break;
    }
  }

  return 0;
}
