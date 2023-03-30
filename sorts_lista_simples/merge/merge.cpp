#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct cel {
  int valor;
  cel *prox;
} celula;
celula *cabeca;
celula *end;

int length() { 
  celula *aux = cabeca;
  int cont = 0;
  while (aux != NULL) {
    aux = aux->prox;
    cont++;
  }
  return cont;
}

void separar(celula **head1, celula **head2) {
  *head1 = cabeca;
  *head2 = cabeca->prox;

  int tam = length();
  int cont = tam / 2.0;
  int fim = 0;
  celula *aux=*head1;


  while (fim != cont) {
    aux = (aux)->prox;
   ( aux)->prox=NULL;

    fim++;

  }
  aux =(aux)->prox;
}

celula *merge(celula *head1, celula *head2) {
  if (head1 == NULL) {
    return head2;
  } else if (head2 == NULL) {
    return head1;
  }

   celula *merge_lista = new celula;
  celula *merge_lista = NULL;

  if (head1->valor <= head2->valor) {
    merge_lista = head1;
    merge_lista->prox = merge(head1->prox, head2);
  } else {
    merge_lista = head2;
    merge_lista->prox = merge(head1, head2->prox);
  }

  head1=head1->prox;
  head2=head2->prox;
  return merge_lista;
}

void mergesort(celula *aux) {
  
  if (aux == NULL || aux->prox == NULL) {
    return;
  }
  celula *head1;
  celula *head2;
  separar(&head1, &head2);
  mergesort(head1);
  mergesort(head2);

  cabeca = merge(head1, head2);
}


void imprimir()
{
    celula *aux = cabeca;
    while (aux != NULL)
    {
        printf("%d ->  ", aux->valor);
        aux = aux->prox;
    }
    printf("\n\n");
}
void gera_num(celula *Novo)
{
    Novo->valor = rand() % 100;
    while (Novo->valor == 0)
    {
        Novo->valor = rand() % 100;
    }
}
void inserir()
{
    celula *Novo = (celula *)malloc(sizeof(celula));
    gera_num(Novo);
    Novo->prox = cabeca;
    cabeca = Novo;
}


int main()
{
    srand(time(NULL));
    celula *cabeca = NULL;
    for (int i = 0; i < 10; i++)
    {
        inserir();
    }
    imprimir();

    mergesort(cabeca);
    printf("\n");
    imprimir();
    return 0;
}
