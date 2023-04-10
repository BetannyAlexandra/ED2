
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct cel
{
  char nome[30];
  char cpf[12];
  char data[20];
  struct cel *prox;
  int cont = 0;
} celula;
typedef struct lista
{
  celula *cabeca = NULL;
  celula *fim = NULL;
  int tamanho = 0;
} lista;

void imprimir_cont(lista *lista1)
{
  celula *aux = lista1->cabeca;

  while (aux != NULL)
  {
    printf("Existem %d eventos na data %s.\n", aux->cont, aux->data);
    aux = aux->prox;
  }
}

void imprimir(lista *lista1)
{
  celula *aux = lista1->cabeca;

  while (aux != NULL)
  {
    printf("\nnome:%s -> ", aux->nome);
    printf(" cpf:%s -> ", aux->cpf);
    printf("data do evento:%s -> \n", aux->data);
    aux = aux->prox;
  }

  printf("NULL\n");
}
celula *nova_celula()
{
  celula *nova = new celula;
  nova->prox = NULL;

  printf("\nCadastro para Evento: ");

  printf("\nNome: ");
  scanf("%s", nova->nome);
  printf("\nCPF: ");
  scanf("%s", nova->cpf);
  printf("\nData do evento (ano/mes/dia): ");
  scanf("%s", nova->data);
  return nova;
}
void anexar_inicio(lista *lista1, lista *nova)
{
  if ((lista1 == NULL) || (nova == NULL) || (nova->tamanho == 0))
    return;
  lista1->tamanho += nova->tamanho;
  nova->fim->prox = lista1->cabeca;
  lista1->cabeca = nova->cabeca;
}
void anexar_fim(lista *lista1, lista *nova)
{
  if ((lista1 == NULL) || (nova == NULL) || (nova->tamanho == 0))
    return;
  lista1->tamanho += nova->tamanho;
  lista1->fim->prox = nova->cabeca;
  lista1->fim = nova->fim;
}
void inserir_inicio(lista *lista1, celula *Novo)
{
  if (lista1 == NULL || Novo == NULL)
    return;
  if (lista1->tamanho == 0)
  {
    lista1->cabeca = Novo;
    lista1->fim = Novo;
    lista1->tamanho = 1;
    Novo->prox = NULL;
    return;
  }
  Novo->prox = lista1->cabeca;
  lista1->cabeca = Novo;
  lista1->tamanho++;
}
bool cpf_data(lista *lista1, char *cpf, char *data)
{
  celula *aux = lista1->cabeca;

  while (aux != NULL)
  {

    if ((strcmp(aux->cpf, cpf) == 0) && (strcmp(aux->data, data) == 0))
    {
      return true;
    }
    aux = aux->prox;
  }
  return false;
}

void buscar_e_inserir_cpf(lista *lista_ingressos, celula *novo_ingresso)
{

  if (lista_ingressos == NULL)
  {

    inserir_inicio(lista_ingressos, novo_ingresso);
  }
  else
  {
    if (cpf_data(lista_ingressos, novo_ingresso->cpf, novo_ingresso->data) == true)
    {
      printf("Ingresso já existe");
    }
    else
    {
      inserir_inicio(lista_ingressos, novo_ingresso);
    }
  }
}
void inserir_fim(lista *lista1, celula *nova)
{
  if ((lista1 == NULL) || (nova == NULL))
    return;
  if (lista1->tamanho == 0)
  {
    lista1->cabeca = nova;
    lista1->fim = nova;
    lista1->tamanho = 1;
    nova->prox = NULL;
    return;
  }
  nova->prox = NULL;
  lista1->fim->prox = nova;
  lista1->fim = nova;
  lista1->tamanho += 1;
}
celula *prev(lista *lista1, celula *referencia)
{
  if (referencia == NULL || referencia == lista1->cabeca || (lista1 == NULL))
    return NULL;
  celula *aux = lista1->cabeca;
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
void remover(lista *lista1, celula *elemento)
{
  if ((lista1 == NULL) || (elemento == NULL) || (lista1->tamanho == 0))
    return;
  if ((lista1->cabeca == elemento) && (lista1->fim == elemento))
  {
    lista1->tamanho = 0;
    lista1->cabeca = NULL;
    lista1->fim = NULL;
    return;
  }
  lista1->tamanho--;
  if (lista1->cabeca == elemento)
  {
    lista1->cabeca = lista1->cabeca->prox;
    elemento->prox = NULL;
    return;
  }
  if (lista1->fim == elemento)
  {
    lista1->fim = prev(lista1, elemento);
    lista1->fim->prox = NULL;
    return;
  }
  celula *ant_elem = prev(lista1, elemento);
  celula *prox_elem = elemento->prox;

  if (ant_elem != NULL)
  {

    ant_elem->prox = prox_elem;
  }
  elemento->prox = NULL;
}
void imprimir_menu()
{
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("*\t1 - Adicionar novo Evento\t*\n");
  printf("*\t2 - Imprimir todos os ingressos \t*\n");
  printf("*\t3 - Ordenar e contar ingressos por data\t*\n");
  printf("*\t4 - Buscar Ingressos por cpf\t*\n");
  printf("*\t0 - Sair\t\t*\n");
}
void troca_insertion(lista *lista1, celula *aux, celula *troca, celula *proximo, celula *anterior)
{
  if (aux == lista1->cabeca)
  {
    troca->prox = lista1->cabeca;
    lista1->cabeca = troca;
    anterior->prox = proximo;
  }
  else
  {
    troca->prox = aux;
    anterior->prox = proximo;
    anterior = prev(lista1, aux);
    if (anterior != NULL)
    {
      anterior->prox = troca;
    }
  }
}
void insertion_sort(lista *lista1)
{
  if (lista1->cabeca == NULL || lista1->cabeca->prox == NULL)
    return;
  celula *troca = lista1->cabeca->prox;
  celula *anterior = prev(lista1, troca);
  celula *aux = lista1->cabeca;
  celula *proximo = troca->prox;

  while (troca != NULL)
  {
    while (aux != troca)
    {
      if (strcmp(aux->cpf, troca->cpf) > 0)
      {
        troca_insertion(lista1, aux, troca, proximo, anterior);
        break;
      }
      aux = aux->prox;
    }
    troca = proximo;
    aux = lista1->cabeca;
    anterior = prev(lista1, troca);
    if (troca != NULL)
      proximo = troca->prox;
  }
}
void imprimir_pelo_cpf(lista *lista_ingressos, char *cpf_2)
{

  if (lista_ingressos == NULL)
  {

    return;
  }
  printf("todos os eventos nesse cpf\n");

  celula *aux = lista_ingressos->cabeca;
  while (aux != NULL)
  {

    if ((strcmp(aux->cpf, cpf_2) == 0))
    {

      printf("\n%s -> ", aux->nome);
      printf("\n%s -> ", aux->cpf);
      printf("\n%s -> ", aux->data);
      printf("\n");
    }
    aux = aux->prox;
  }
}

void quickSort(lista *lista1)
{
  if ((lista1 == NULL) || (lista1->tamanho <= 1))
  {
    return;
  }
  int metade = lista1->tamanho / 2;
  celula *pivo = lista1->cabeca;
  for (int i = 0; i < metade; i++)
  {
    pivo = pivo->prox;
  }
  lista menores;
  lista maiores;

  celula *aux = lista1->cabeca;
  celula *elemento = NULL;

  while (aux != NULL)
  {
    elemento = aux;
    aux = aux->prox;
    if (elemento == pivo)
    {
      continue;
    }
    remover(lista1, elemento);
    if (strcmp(pivo->data, elemento->data) > 0)
    {
      inserir_inicio(&menores, elemento);
    }
    else
    {
      inserir_inicio(&maiores, elemento);
    }
  }
  quickSort(&menores);
  anexar_inicio(lista1, &menores);
  quickSort(&maiores);
  anexar_fim(lista1, &maiores);
}

void copiar_elemento(lista *lista1, celula *elemento)
{
  celula *nova = new celula;
  strcpy(nova->data, elemento->data);
  nova->cont = 1;
  inserir_inicio(lista1, nova);
}

void data(lista *lista1)
{

  celula *aux = lista1->cabeca;
  lista *datas_contadas = new lista;

  while (aux != NULL)
  {
    if (datas_contadas == NULL)
    {
      copiar_elemento(datas_contadas, aux);
      aux = aux->prox;
      continue;
    }
    celula *aux_datas = datas_contadas->cabeca;
    bool existe = false;
    while (aux_datas != NULL)
    {
      if (strcmp(aux_datas->data, aux->data) == 0)
      {
        aux_datas->cont++;
        existe = true;
        break;
      }

      aux_datas = aux_datas->prox;
    }
    if (!existe)
    {
      copiar_elemento(datas_contadas, aux);
    }
    aux = aux->prox;
  }
  imprimir_cont(datas_contadas);
}

int main()
{
  lista *cabeca = new lista;
  char cpf[20];

  int opc = 1;
  while (opc != 0)
  {
    imprimir_menu();
    scanf("%d", &opc);
    fflush(stdin);
    switch (opc)
    {
    case 1:
      buscar_e_inserir_cpf(cabeca, nova_celula());
      break;

    case 2:
      imprimir(cabeca);
      break;

    case 3:

      quickSort(cabeca);
      imprimir(cabeca);
      data(cabeca);
      break;

    case 4:

      printf("Ingressos oredenados");
      insertion_sort(cabeca);
      // imprimir(cabeca);
      printf("\n");
      printf("Informe o cpf que deseja buscar");
      scanf("%s", cpf);
      imprimir_pelo_cpf(cabeca, cpf);
      break;

    case 0:
      break;

    default:
      printf("Opção inválida\n");
      break;
    }
  }

  return 0;
}
