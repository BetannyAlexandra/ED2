


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct cel
{  char nome[30];
  char cpf[12];
  char data[20];
  struct cel *prox;
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
celula *nova_celula()
{
  celula *nova = new celula;
  nova->prox = NULL;

  printf("\nCadastro de comprador: ");
  
  printf("\nNome: ");
  scanf("%s", nova->nome);
   printf("\nCPF: ");
  scanf("%s", nova->cpf);
   printf("\nData do evento: ");
  scanf("%s", nova->data);
  return nova;
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


bool cpf_data(lista *lista1,char *cpf,char *data){
    celula *aux=lista1->cabeca;


    while(aux!=NULL){
        


        if((strcmp(aux->cpf,cpf)==0)&&(strcmp(aux->data,data)==0)){
         return true;
            }
      aux=aux->prox;
    }

}

void buscar_cpf(lista *lista_ingressos,celula *novo_ingresso){

if(lista_ingressos==NULL){


    inserir_inicio(lista_ingressos,novo_ingresso);


}else{
    if(cpf_data(lista_ingressos,novo_ingresso->cpf,novo_ingresso->data)==true){
        printf("Ingresso já existe");

    }else{
         inserir_inicio(lista_ingressos,novo_ingresso);
    }
}


}


celula *novo_elemento(lista *lista1)
{
  celula *nova = new celula;
  nova->prox = NULL;

  printf("\nCadastro de comprador: ");
  
  printf("\nNome: ");
  scanf("%s", nova->nome);
   printf("\nCPF: ");
  scanf("%s", nova->cpf);
   printf("\nData do evento: ");
  scanf("%s", nova->data);

buscar_cpf(lista1,novo_elemento(lista1));

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
// void swap(celula *a, celula *b)
// {
//   char temp[30];
//   strcpy(temp, a->nome);
//   strcpy(a->nome, b->nome);
//   strcpy(b->nome, temp);
// }
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

celula *pos(lista *lista1, int pos)
{
  celula *aux = lista1->cabeca;
  int cont = 0;
  while (aux != NULL)
  {
    if (cont == pos)
    {
      return aux;
    }
    aux = aux->prox;
    cont++;
  }
  return NULL;
}

void troca_pos(lista *lista1, celula *cel1, celula *cel2)
{

  if ((cel1 == NULL) || (cel2 == NULL))
    return;

  celula *ant1 = NULL;
  celula *ant2 = NULL;

  celula *tmp = NULL;

  if (cel1 == lista1->fim)
  {
    lista1->fim = cel2;
  }
  else if (cel2 == lista1->fim)
  {
    lista1->fim = cel1;
  }

  if ((lista1->cabeca == cel2) || (cel2->prox == cel1))
  {
    tmp = cel2;
    cel2 = cel1;
    cel1 = tmp;
  }

  if (lista1->cabeca != cel1)
  {
    ant1 = prev(lista1, cel1);
  }

  ant2 = prev(lista1, cel2);

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

    if (lista1->cabeca == cel1)
    {
      lista1->cabeca = cel2;
    }
  }
}

void shuffle(lista *lista1)
{
  int size = length(lista1->cabeca);
  for (int i = 0; i < size; i++)
  {
    celula *cel1 = pos(lista1, rand() % size);
    celula *cel2 = pos(lista1, rand() % size);
    troca_pos(lista1, cel1, cel2);
  }
}

void swap(lista *lista1, celula *aux)
{
  celula *temp = aux->prox;
  aux->prox = temp->prox;
  temp->prox = aux;

  if (aux == lista1->cabeca)
  {
    lista1->cabeca = temp;
  }
  else
  {
    celula *ant = lista1->cabeca;
    while (ant->prox != aux)
    {
      ant = ant->prox;
    }
    ant->prox = temp;
  }
}

void bubble(lista *lista1)
{
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
        swap(lista1, aux);
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

void selection_sort(lista *lista1)
{
  if (lista1->cabeca == NULL || lista1->cabeca->prox == NULL)
  {
    return;
  }
  celula *inserir = lista1->cabeca;
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
      troca_pos(lista1, inserir, menor);
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
  printf("*\t7 - Merge sort \t*\n");
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
      if (strcmp(aux->nome, troca->nome) > 0)
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
    if (strcmp(valor2->nome, valor1->nome) > 0)
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

lista *mergesort(lista *lista1)
{

  if ((lista1 == NULL) || (lista1->tamanho == 0))
  {
    return NULL;
  }

  if (lista1->tamanho == 1)
  {
    return lista1;
  }

  lista *lista2 = new lista;
  int tam_metade = lista1->tamanho / 2;
  celula *inicio2 = lista1->cabeca;
  for (int i = 0; i < tam_metade; i++)
  {
    inicio2 = inicio2->prox;
  }

  celula *fim1 = prev(lista1, inicio2);
  fim1->prox = NULL;

  lista2->cabeca = inicio2;
  lista2->fim = lista1->fim;

  lista2->fim = lista1->fim;
  lista2->tamanho = lista1->tamanho - tam_metade;

  lista1->fim = fim1;
  lista1->tamanho = tam_metade;

  lista1 = mergesort(lista1);
  lista2 = mergesort(lista2);

  lista *resultante = merge(lista1, lista2);

  return resultante;
}

// void gerar_aleatorios(lista *lst, int qnt)
// {
//   celula *elem;
//   for (int i = 0; i < qnt; i++)
//   {
//     elem = new celula;
//     elem->nome =(char)( rand() % 10);
//     inserir_inicio(lst, elem);
//   }
// }

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
    if (strcmp(pivo->nome, elemento->nome) > 0)
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

int main()
{
  lista *cabeca = new lista;
  srand(time(NULL));

  lista *nova = new lista;
  nova = NULL;
  int opc = 1;
  while (opc != 0)
  {
    imprimir_menu();
    scanf("%d", &opc);
    fflush(stdin);
    switch (opc)
    {
    case 1:
      buscar_cpf(cabeca,nova_celula());
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
      selection_sort(cabeca);
      imprimir(cabeca);
    case 5:
      insertion_sort(cabeca);
      break;
    case 6:
      shuffle(cabeca);
      break;
    case 7:
      // gerar_aleatorios(cabeca, 10);
      imprimir(cabeca);
      nova = mergesort(cabeca);
      imprimir(nova);
      break;
    case 8:
    imprimir(cabeca);
    quickSort(cabeca);
    imprimir(cabeca);
    break;

    case 0:
      break;

    default:
      printf("Opção inválida\n");
      break;
    }
  }

  inserir_inicio(cabeca, nova_celula());
  imprimir(cabeca);

  return 0;
}
