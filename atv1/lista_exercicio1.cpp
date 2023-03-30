#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct cel
{
  char nome[30];
  struct cel *prox;
} celula;

celula *cabeca = NULL;

void imprimir(celula *aux)
{
  while (aux != NULL)
  {
    printf("%s -> ", aux->nome);
    aux = aux->prox;
  }
  printf("NULL\n");
}

void inserir(celula **ptr_cabeca)
{
  celula *nova = (celula *)malloc(sizeof(celula));
  printf("Digite o nome do produto: ");
  scanf("%30[^\n]s", nova->nome);

  nova->prox = *ptr_cabeca;

  *ptr_cabeca = nova;
}

// void swap(celula *a, celula *b)
// {
//   char temp[30];
//   strcpy(temp, a->nome);
//   strcpy(a->nome, b->nome);
//   strcpy(b->nome, temp);
// }

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

celula *pos(int p)
{
  celula *aux = cabeca;
  int cont = 0;
  while (aux != NULL)
  {
    if (cont == p)
    {
      return aux;
    }
    aux = aux->prox;
    cont++;
  }
  return NULL;
}

celula *prev(celula *referencia)
{
  if (referencia == NULL || referencia == cabeca)
    return NULL;
  celula *aux = cabeca;
  while (aux != NULL)
  {
    if (aux->prox == referencia)
    {
      return aux;
    }
    aux = aux->prox;
  }
  return NULL;
}

void troca_pos(celula *cel1, celula *cel2)
{
  if ((cel1 == NULL) || (cel2 == NULL))
    return;

  celula *ant1 = NULL;
  celula *ant2 = NULL;

  celula *tmp = NULL;

  if ((cabeca == cel2) || (cel2->prox == cel1))
  {
    tmp = cel2;
    cel2 = cel1;
    cel1 = tmp;
  }

  if (cabeca != cel1)
  {
    ant1 = prev(cel1);
  }

  ant2 = prev(cel2);

  if (cel1 != cel2)
  {
    tmp = cel2->prox;

    if (ant1 != NULL)
    {
      ant1->prox = cel2;
    }

    if (cel1 != ant2)
    {
      ant2->prox = cel1;
      cel2->prox = cel1->prox;

      if (cel2->prox == cel1)
      {
        cel1->prox = cel2;
      }
      else
      {
        cel1->prox = tmp;
      }
    }
    else
    {
      cel2->prox = cel1;
      cel1->prox = tmp;
    }

    if (cabeca == cel1)
    {
      cabeca = cel2;
    }
  }
}

void shuffle()
{
  int size = length(cabeca);
  for (int i = 0; i < size; i++)
  {
    celula *cel1 = pos(rand() % size);
    celula *cel2 = pos(rand() % size);
    troca_pos(cel1, cel2);
  }
}

void swap(celula *aux)
{
  celula *temp = aux->prox;
  aux->prox = temp->prox;
  temp->prox = aux;

  if (aux == cabeca)
  {
    cabeca = temp;
  }
  else
  {
    celula *ant = cabeca;
    while (ant->prox != aux)
    {
      ant = ant->prox;
    }
    ant->prox = temp;
  }
}

void bubble()
{
  int cont_troca;
  celula *aux = NULL;
  celula *ultimo_no = NULL;

  if (cabeca == NULL || cabeca->prox == NULL)
  {
    return;
  }
  do
  {
    cont_troca = 0;
    aux = cabeca;
    while (aux->prox != ultimo_no)
    {
      if (strcmp(aux->nome, aux->prox->nome) > 0)
      {
        swap(aux);
        cont_troca = 1;
      }
      else
      {
        aux = aux->prox;
      }
    }
    ultimo_no = aux;
  } while (cont_troca != 0);
}

void selection_sort()
{
  if (cabeca == NULL || cabeca->prox == NULL)
  {
    return;
  }
  celula *inserir = cabeca;
  celula *menor;
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
      troca_pos(inserir, menor);
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
  printf("*\t6 - Shuffle \t*\n");
  printf("*\t0 - Sair\t\t*\n");
}

void troca_insertion(celula *aux, celula *troca, celula *proximo, celula *anterior)
{
  if (aux == cabeca)
  {
    troca->prox = cabeca;
    cabeca = troca;
    anterior->prox = proximo;
  }
  else
  {
    troca->prox = aux;
    anterior->prox = proximo;
    anterior = prev(aux);
    if (anterior != NULL)
    {
      anterior->prox = troca;
    }
  }
}

void insertion_sort()
{
  if (cabeca == NULL || cabeca->prox == NULL)
    return;
  celula *troca = cabeca->prox;
  celula *anterior = prev(troca);
  celula *aux = cabeca;
  celula *proximo = troca->prox;

  while (troca != NULL)
  {
    while (aux != troca)
    {
      if (strcmp(aux->nome, troca->nome) > 0)
      {
        troca_insertion(aux, troca, proximo, anterior);
        break;
      }
      aux = aux->prox;
    }
    troca = proximo;
    aux = cabeca;
    anterior = prev(troca);
    if (troca != NULL)
      proximo = troca->prox;
  }
}

int main()
{

  int opc = 1;
  while (opc != 0)
  {
    imprimir_menu();
    scanf("%d", &opc);
    fflush(stdin);
    switch (opc)
    {
    case 1:
      inserir(&cabeca);
      break;

    case 2:
      imprimir(cabeca);
      break;

    case 3:
      printf("Lista antes=\n");
      imprimir(cabeca);
      bubble();
      printf("Lista depois=\n");
      imprimir(cabeca);
      break;

    case 4:
      selection_sort();
      imprimir(cabeca);
    case 5:
      insertion_sort();
      break;
    case 6:
      shuffle();
      break;

    case 0:
      break;

    default:
      printf("Opção inválida\n");
      break;
    }
  }

  inserir(&cabeca);

  imprimir(cabeca);

  return 0;
}
