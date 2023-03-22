
// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// void sort(int *vetor,int start, int end){

//     for (int i = end; i > start; i--)
//     {
//         vetor[i]=vetor[i-1];
//     }
    

// }

// void insert(){
// int vetor[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//   int n = 10;

  
//     for (int i = 0; i < n; i++) {
//          printf("%d ", vetor[i]);
//      }
//     printf("\n");
    
//   for(int i=0;i<n;i++){
//     for (int j = 0; j <i; j++)
//     { int aux=vetor[i];
//         sort(vetor,j,i);
//          vetor[j]=aux;
// break;
//      }
    
//    }
//     for (int i = 0; i < n; i++) {
//          printf("%d ", vetor[i]);
//      }
//     printf("\n");
// }

// int main(){
//     insert();
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct cel_ {
    int conteudo;
    struct cel_ *seg;
    struct cel_ *ant;
};
typedef struct cel_ celula;

int tamanho = 0;

/**FUNÇOES**/
celula *InserirLista (celula *lst, int n);
void ImprimeLista (celula *lst);
void OrdenacaoInsercao (celula *lst);

int main() {
    celula *lst;
    celula *fim;
    celula *p;
    celula c, r;
    clock_t start, end;
    double cpu_time_used;
    int i, n = 10; /**Defina aqui o tamanho da lista**/

    tamanho += sizeof(celula)*n;

    lst = &c;
    fim = &r;
    lst->seg = fim;
    lst->ant = NULL;
    fim->seg = NULL;
    p = lst;
    srand(time(NULL));

    /**Inserindo elementos na lista**/
    for(i = 1; i <= n; i++)
        p = InserirLista(p, rand()%100);


    printf("Antes de Ordenar\n");
    ImprimeLista(lst);
    printf("\n\n\n");

    start = clock();
    OrdenacaoInsercao(lst);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n Lista Ordenada \n");
    ImprimeLista(lst);
    printf("\n tempo de execução %.7f", cpu_time_used);
    printf("\n tamanho = %d \n", tamanho);
    printf("\n");
    return 0;
}

celula *InserirLista (celula *p, int x) {
    celula * nova;
    nova = (celula*)malloc(sizeof(celula));
    nova->conteudo = x;
    nova->seg = p->seg;
    nova->ant = p;
    p->seg->ant = nova;
    p->seg = nova;
    return p;
}

void ImprimeLista (celula *lst) {
    celula *p = lst->seg;
    while (p->seg != NULL){
        printf("%d ", p->conteudo);
        p = p->seg;
    }
}

void OrdenacaoInsercao (celula *lst) {
    celula *p = lst->seg->seg;
    celula *q;
    int x;

    tamanho += sizeof(x);

    while (p->seg != NULL) {
        q = p->ant;
        x = p->conteudo;

        while ((q != lst) && (q->conteudo > x)) {
            q->seg->conteudo =  q->conteudo;
            q = q->ant;
        }
        q->seg->conteudo = x;
        p = p->seg;
    }
}