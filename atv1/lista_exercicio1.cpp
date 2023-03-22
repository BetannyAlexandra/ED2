#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cel
{
  char nome[30];
  struct cel *prox;
  int indice;
} celula;


 celula *cabeca = NULL;
int indice = 1;


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

  nova->indice = indice;

  nova->prox = *ptr_cabeca;

  *ptr_cabeca = nova;

  printf("indice=%d", indice);
}

// void swap(celula *a, celula *b)
// {
//   char temp[30];
//   strcpy(temp, a->nome);
//   strcpy(a->nome, b->nome);
//   strcpy(b->nome, temp);
// }

void swap(celula *aux){
  celula *temp=aux->prox;
  aux->prox=temp->prox;
  temp->prox=aux;

  if(aux==cabeca){
    cabeca=temp;

  }else{
    celula *ant=cabeca;
    while(ant->prox!=aux){
      ant=ant->prox;
    }
    ant->prox=temp;
  }

}


void bubble()
{
  int cont_troca;
  celula *aux=NULL;
  celula *ultimo_no = NULL;

  if (cabeca == NULL||cabeca->prox==NULL)
{    return;
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
      }else{
      aux = aux->prox;}
    }
    ultimo_no = aux;
  } while (cont_troca!=0);
}

// void insert(celula *cabeca){
// celula *lista=NULL;
// celula *aux=cabeca;
// while (aux!=NULL)
// {
//   celula *prox=aux->prox;
// if(lista==NULL ||  (strcmp(lista->nome, aux->nome) > 0)){
//   aux->prox=lista;
//   lista=aux;
// }
// }




void imprimir_menu()
{
  printf("\n\n");
  printf("*******\t\tMENU\t********\n");
  printf("*\t1 - Inserir nome\t*\n");
  printf("*\t2 - Imprimir \t*\n");
   printf("*\t3 - Bubble sort \t*\n");
  printf("*\t0 - Sair\t\t*\n");
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
      indice++;
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

      //   case 0:
      //     break;

    default:
      printf("Opção inválida\n");
      break;
    }
  }

  inserir(&cabeca);

  imprimir(cabeca);

  return 0;
}


// void insertionSort(Node **head_ref) {
//     Node *sorted = NULL;
//     Node *current = *head_ref;

//     while (current != NULL) {
//         Node *next = current->next;

//         if (sorted == NULL || sorted->data >= current->data) {
//             current->next = sorted;
//             sorted = current;
//         } else {
//             Node *temp = sorted;
//             while (temp->next != NULL && temp->next->data < current->data) {
//                 temp = temp->next;
//             }
//             current->next = temp->next;
//             temp->next = current;
//         }

//         current = next;
//     }

//     *head_ref = sorted;
// }
// Explicação do código:

// Inicializa um nó sorted que armazenará a lista ordenada.
// Inicializa um ponteiro current que percorrerá a lista encadeada original.
// Percorre a lista encadeada original usando um loop while, que termina quando todos os nós foram percorridos.
// Armazena o próximo nó em uma variável temporária next, para evitar perda de referência.
// Verifica se o nó atual é menor ou igual ao primeiro nó da lista ordenada (ou se a lista ordenada é vazia). Se sim, o nó atual é inserido no início da lista ordenada. Se não, procura a posição correta para inserir o nó atual.
// Percorre a lista ordenada usando um loop while para encontrar o nó anterior à posição de inserção.
// Insere o nó atual na posição correta atualizando os ponteiros dos nós.
// Atualiza o ponteiro current para o próximo nó da lista original.
// Atualiza o ponteiro do cabeçalho da lista encadeada para a lista ordenada.