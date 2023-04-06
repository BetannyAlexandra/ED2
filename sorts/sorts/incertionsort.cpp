
// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <time.h>

// // void sort(int *vetor,int start, int end){

// //     for (int i = end; i > start; i--)
// //     {
// //         vetor[i]=vetor[i-1];
// //     }
    

// // }

// // void insert(){
// // int vetor[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
// //   int n = 10;

  
// //     for (int i = 0; i < n; i++) {
// //          printf("%d ", vetor[i]);
// //      }
// //     printf("\n");
    
// //   for(int i=0;i<n;i++){
// //     for (int j = 0; j <i; j++)
// //     { int aux=vetor[i];
// //         sort(vetor,j,i);
// //          vetor[j]=aux;
// // break;
// //      }
    
// //    }
// //     for (int i = 0; i < n; i++) {
// //          printf("%d ", vetor[i]);
// //      }
// //     printf("\n");
// // }

// // int main(){
// //     insert();
// //     return 0;
// // }


// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// struct cel_ {
//     int conteudo;
//     struct cel_ *prox;
//     struct cel_ *ant;
// };
// typedef struct cel_ celula;

// int tamanho = 0;

// /**FUNÇOES**/
// celula *InserirLista (celula *lst, int n);
// void ImprimeLista (celula *lst);
// void OrdenacaoInsercao (celula *lst);

// int main() {
//     celula *lst;
//     celula *fim;
//     celula *p;
//     celula c, r;
//     int i, n = 10; /**Defina aqui o tamanho da lista**/

//     tamanho += sizeof(celula)*n;

//     lst = &c;
//     fim = &r;
//     lst->prox = fim;
//     lst->ant = NULL;
//     fim->prox = NULL;
//     p = lst;
//     srand(time(NULL));

//     /**Inserindo elementos na lista**/
//     for(i = 1; i <= n; i++)
//         p = InserirLista(p, rand()%100);


//     printf("Antes de Ordenar\n");
//     ImprimeLista(lst);
//     printf("\n\n\n");

//     OrdenacaoInsercao(lst);
   

//     printf("\n Lista Ordenada \n");
//     ImprimeLista(lst);
   
//     printf("\n tamanho = %d \n", tamanho);
//     printf("\n");
//     return 0;
// }

// celula *InserirLista (celula *p, int x) {
//     celula * nova;
//     nova = (celula*)malloc(sizeof(celula));
//     nova->conteudo = x;
//     nova->prox = p->prox;
//     nova->ant = p;
//     p->prox->ant = nova;
//     p->prox = nova;
//     return p;
// }

// void ImprimeLista (celula *lst) {
//     celula *p = lst->prox;
//     while (p->prox != NULL){
//         printf("%d ", p->conteudo);
//         p = p->prox;
//     }
// }

// void OrdenacaoInsercao (celula *lst) {
//     celula *aux = lst->prox->prox;
//     celula *q;
//     int x;

//     tamanho += sizeof(x);

//     while (aux->prox != NULL) {
//         q = aux->ant;
//         x = aux->conteudo;

//         while ((q != lst) && (q->conteudo > x)) {
//             q->prox->conteudo =  q->conteudo;
//             q = q->ant;
//         }
//         q->prox->conteudo = x;
//         aux = aux->prox;
//     }
// }

