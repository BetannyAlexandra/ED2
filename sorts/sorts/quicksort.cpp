
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// struct cel_{
//     int conteudo;
//     struct cel_ *seg;
//     struct cel_ *ant;
// };
// typedef struct cel_ celula;

// int tamanho;

// void QuickSort(celula *p, celula *r);
// celula *Separa(celula *p, celula *r);
// celula *inserirLista(celula * lst, int n);
// void ImprimeLista(celula * lst);

// int main(){
//     celula *lst;
//     celula *fim;
//     celula *p;
//     celula c, r;
//     clock_t start, end;
//     double cpu_time_used;

//     int i, n=10;

//     lst = &c;
//     fim = &r;
//     lst->seg = fim;
//     lst->ant = NULL;
//     fim->seg = NULL;
//     fim->ant = lst;
//     p=lst;

//     tamanho += sizeof(celula)*n;

//     srand(time(NULL));
//     for(i=1; i<=n; i++)
//         p = inserirLista(p, rand()%999);

//     printf("Antes de Ordenar\n");
//     ImprimeLista(lst);
//     printf("\n\n\n");

//     start = clock();
//     QuickSort(lst->seg, fim->ant);
//     end = clock();
//     cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
//     printf("\n");
//     printf("Lista Ordenada \n");
//     ImprimeLista(lst);
//     printf("\nEspaco usado : %d", tamanho);
//     printf("\n tempo de execução %.7f", cpu_time_used);
//     printf("\n");
//     return 0;
// }


// void QuickSort(celula *p, celula *r) {
//     celula *j;
//     if((r != NULL)&&(p!=r)&&(p != r->seg)) {
//         j = Separa(p, r);
//         QuickSort(p, j->ant);
//         QuickSort(j->seg, r);
//     }
// }

// celula *Separa(celula *p, celula *r){
//     int aux, x  = r->conteudo;
//     celula *i = p->ant;
//     celula *k;

//     tamanho += sizeof(aux) + sizeof(aux);

//     for (k = p; k != r; k = k->seg)
//     {
//         if (k->conteudo <= x)
//         {
//             i = i->seg;
//             aux = i->conteudo;
//             i->conteudo = k->conteudo;
//             k->conteudo = aux;
//         }
//     }
//     i = i->seg;
//     aux = i->conteudo;
//     i->conteudo = r->conteudo;
//     r->conteudo = aux;

//     return i;
// }
// celula * inserirLista(celula * p, int x){
//     celula * nova;
//     nova=(celula*)malloc(sizeof(celula));
//     nova->conteudo = x;
//     nova->seg=p->seg;
//     nova->ant=p;
//     p->seg->ant=nova;
//     p->seg =nova;
//     return p;
// }
// void ImprimeLista(celula * lst){
//     celula * p = lst->seg;
//     while (p->seg != NULL){
//         printf("%d ", p->conteudo);
//         p=p->seg;
//     }
// }



#include <stdio.h>

typedef struct cel {
  int num;
  cel *ant;
  cel *prox;
} celula;

typedef struct list {
  celula *inicio;
  celula *fim;
  int tamanho;
} lista;
lista *cabeca;
void anexar_fim(lista *nova, lista *lista) {
  nova->tamanho += lista->tamanho;
  nova->fim->prox = lista->inicio;
  lista->inicio->ant = nova->fim;
  nova->fim = lista->fim;
  delete lista;
}

void divide(lista *lista1, lista *lista2) {
  int tam_metade = lista1->tamanho / 2;
  celula *inicio2 = lista1->inicio;
  for (int i = 0; i < tam_metade; i++) {
    inicio2 = inicio2->prox;
  }

  celula *fim1 = inicio2->ant;
  fim1->prox = NULL;
  inicio2->ant = NULL;

  lista2->inicio = inicio2;
  lista2->fim = lista1->fim;
  lista2->tamanho = lista1->tamanho - tam_metade;

  lista1->fim = fim1;
  lista1->tamanho = tam_metade;
}

void inserir_fim(lista *lista, celula *elemento)
{
  lista->fim->prox = elemento;
  elemento->ant = lista->fim;
  lista->fim = elemento;
}
 celula* remover_inicio(lista *lista){
  celula *elemento = lista->inicio;
  elemento->prox = NULL;
  lista->inicio = lista->inicio->prox;
  lista->inicio->ant = NULL;
  return elemento;
}

lista *merge(lista *lista1, lista *lista2) {
  lista *nova = new lista;

  while ((lista1->tamanho > 0) && (lista2->tamanho > 0)) {
    int num1 = lista1->inicio->num;
    int num2 = lista2->inicio->num;
    celula *elemento;
    if (num1 < num2) {
      elemento = remover_inicio(lista1);
    } else {
      elemento = remover_inicio(lista2);
    }
    inserir_fim(nova, elemento);
  }
  if (lista1->tamanho > 0) {
    anexar_fim(nova, lista1);
  }

  if (lista2->tamanho > 0) {
    anexar_fim(nova, lista2);
  }

  return nova;
}

int main(int argc, char const *argv[]) {
  int vetor[] = {8, 7, 3, 9, 2, 5, 6, 1, 4, 10};

 merge(cabeca);
  return 0;
}
