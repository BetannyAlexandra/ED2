#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum Cor
{
  vermelho,
  preto
};
typedef struct node
{
  int num = 0;
  struct node *esq = NULL;
  struct node *dir = NULL;
  struct node *pai = NULL;
  Cor cor = vermelho;
} No;

No *criar_no()
{
  No *node = new No;
  printf("insira um numero");
  scanf("%d", &node->num);

  return node;
}

void mudar_cor(No **node)
{
  if ((*node)->cor == vermelho)
  {
    (*node)->cor = preto;
  }
  else
  {
    (*node)->cor = vermelho;
  }
}

void inserir_no(No *node, No *novo)
{

  if (node == NULL)
  {
    printf("Erro\n");
    return;
  }

  if (node->num == novo->num)
  {
    printf("Número já existe\n");
    return;
  }

  if (node->num < novo->num)
  {
    if (node->dir == NULL)
    {
      node->dir = novo;
      novo->pai = node;
      return;
    }
    inserir_no(node->dir, novo);
  }
  else
  {
    if (node->esq == NULL)
    {
      node->esq = novo;
      novo->pai = node;
      return;
    }
    inserir_no(node->esq, novo);
  }
}

No *buscar_no(No *node, int num)
{
  if (node == NULL)
  {
    // printf("Número não encontrado\n");
    return NULL;
  }

  if (node->num == num)
  {
    return node;
  }

  if (node->num < num)
  {
    return buscar_no(node->dir, num);
  }
  else
  {
    return buscar_no(node->esq, num);
  }
}

void imprimir(No *node, int tab = 0)
{
  if (node == NULL)
    return;

  imprimir(node->dir, tab + 1);
  for (int i = 0; i < tab; i++)
  {
    printf("\t");
  }
  if (node->cor == vermelho)
  {
    printf("v=%d\n", node->num);
  }
  else
  {
    printf("p=%d\n", node->num);
  }

  imprimir(node->esq, tab + 1);
}

void inserir_raiz(No **raiz)
{
  if (*raiz == NULL)
  {
    *raiz = criar_no();
    (*raiz)->cor = preto;
    return;
  }
  No *novo = criar_no();
  inserir_no(*raiz, novo);
}

void buscar_raiz(No *raiz)
{
  int num = 0;
  printf("Digite o numero: ");
  scanf("%d", &num);
  No *res = buscar_no(raiz, num);
  if (res == NULL)
  {
    printf("Numero não encontrado");
  }
  else
  {
    imprimir(res);
  }
}

bool um_filho(No *node)
{
  // return (node->esq == NULL) && (node->dir == NULL);
  if ((node->esq == NULL) && (node->dir != NULL))
  {
    return true;
  }

  if ((node->esq != NULL) && (node->dir == NULL))
  {
    return true;
  }

  return false;
}

int posicao_filho(No *pai, No *filho)
{

  if (pai == NULL || filho == NULL)
    return -1;

  if (pai->esq == filho)
  {
    return 0;
  }
  else if (pai->dir == filho)
  {
    return 1;
  }

  return -1;
}

bool eh_folha(No *node)
{
  // return (node->esq == NULL) && (node->dir == NULL);
  if ((node->esq == NULL) && (node->dir == NULL))
  {
    return true;
  }
  else
  {
    return false;
  }
}

No *maior(No *node)
{
  if (node == NULL)
    return NULL;
  if (node->dir == NULL)
    return node;
  return maior(node->dir);
}

No *menor(No *node)
{
  if (node == NULL)
    return NULL;
  if (node->esq == NULL)
    return node;
  return menor(node->esq);
}

int soma(No *node)
{
  if (node == NULL)
    return 0;

  return node->num + soma(node->dir) + soma(node->esq);
}

int cont(No *node)
{
  if (node == NULL)
    return 0;

  return 1 + cont(node->dir) + cont(node->esq);
}

float media(No *node)
{
  float total = soma(node);
  float qnt = cont(node);
  return total / qnt;
}

int altura(No *node)
{
  if (node == NULL)
    return 0;
  if (node->cor == vermelho)
  {
    return fmax(altura(node->esq), altura(node->dir));
  }
  else
  {
    return 1 + fmax(altura(node->esq), altura(node->dir));
  }
}

void altura_no(No *raiz)
{
  int num = 0;
  printf("Digite o numero: ");
  scanf("%d", &num);
  No *res = buscar_no(raiz, num);
  if ((res == NULL) && (res->cor == vermelho))
  {
    printf("Numero não encontrado");
  }
  else
  {
    printf("Altura nó:%d\n", altura(res));
  }
}

void menu()
{
  printf("MENU\n");
  printf("1-Inserir\n");
  printf("2-Buscar\n");
  printf("3-Imprimir Árvore\n");
  printf("4-Remover\n");
  printf("5-Arvore aleatoria\n");
  printf("6-Maior, menor e média\n");
  printf("7-Altura arvore\n");
  printf("8-Altura nó\n");
  printf("9-FB do nó\n");
  printf("10-Imprimir FB\n");
  printf("0-Sair\n");
}

// void arvore_aleatoria(No **root) {
//   for (int i = 0; i < 10; i++) {
//     inserir_raiz(root);
//   }
// }

void rot_simples_esq(No **raiz, No *no, bool dupla = false)
{
  No *filho = no->dir;
  if (filho == NULL)
  {
    printf("Rotação errada\n");
    return;
  }

  No *esq_filho = filho->esq;
  no->dir = esq_filho;
  filho->esq = no;

  if (esq_filho != NULL)
  {
    esq_filho->pai = no;
  }

  filho->pai = no->pai;
  no->pai = filho;

  No *pai = filho->pai;

  if (pai == NULL)
  {
    *raiz = filho;
    (*raiz)->cor = preto;
  }
  else
  {
    if (dupla == true)
    {
      pai->esq = filho;
    }
    else
    {
      if (pai->dir == no)
      {
        pai->dir = filho;
      }
      else
      {
        pai->esq = filho;
      }
    }
  }
}

void rot_simples_dir(No **raiz, No *no, bool dupla = false)
{
  No *filho = no->esq;
  if (filho == NULL)
  {
    printf("Rotação errada\n");
    return;
  }

  No *dir_filho = filho->dir;
  no->esq = dir_filho;
  filho->dir = no;

  if (dir_filho != NULL)
  {
    dir_filho->pai = no;
  }

  filho->pai = no->pai;
  no->pai = filho;

  No *pai = filho->pai;
  if (pai == NULL)
  {
    *raiz = filho;
    (*raiz)->cor = preto;
  }
  else
  {
    if (dupla == true)
    {
      pai->dir = filho;
    }
    else
    {
      if (pai->esq == no)
      {

        pai->esq = filho;
      }
      else
      {
        pai->dir = filho;
      }
    }
  }
}

void rot_dupla_dir(No **raiz, No *no)
{
  No *filho = no->esq;
  if (filho == NULL)
  {
    printf("Rotação errada\n");
    return;
  }
  rot_simples_esq(raiz, filho, true);
  rot_simples_dir(raiz, no);
}

void rot_dupla_esq(No **raiz, No *no)
{
  No *filho = no->dir;
  if (filho == NULL)
  {
    printf("Rotação errada\n");
    return;
  }
  rot_simples_dir(raiz, filho, true);
  rot_simples_esq(raiz, no);
}

void balancear_pretoEvermelho(No **root, No *Node)
{
  if (Node == NULL)
    return;

  if (Node == *root)
  {
    Node->cor = preto;
    return; // se a nó for a raiz
  }

  No *pai = Node->pai;
  if (pai->cor == preto)
  {
    return;
  }

  No *avo = NULL;
  if (pai != NULL)
  {
    avo = pai->pai;
  }

  No *tio = NULL;
  if (avo != NULL)
  {
    if (pai == avo->dir)
    {
      tio = avo->esq;
    }
    else
    {
      tio = avo->dir;
    }
  }

  if (tio != NULL)
  {
    if ((pai->cor == vermelho) && (tio->cor == vermelho))
    {
      pai->cor = preto;
      tio->cor = preto;
      if (avo != (*root))
      {
        avo->cor = vermelho;
      }
      return;
    }
  }

  if ((pai->cor == vermelho) && (tio == NULL || tio->cor == preto))
  {
    if (avo != NULL)
    {
      if ((Node == pai->esq) && (pai == avo->esq))
      {
        pai->cor = preto;
        avo->cor = vermelho;
        rot_simples_dir(root, avo);
        return;
      }

      if ((Node == pai->dir) && (pai = avo->dir))
      {
        pai->cor = preto;
        avo->cor = vermelho;
        rot_simples_esq(root, avo);
        return;
      }

      if ((Node == pai->dir) && (pai == avo->esq))
      {
        Node->cor = preto;
        avo->cor = vermelho;
        rot_dupla_dir(root, avo);
        return;
      }

      if ((Node == pai->esq) && (pai == avo->dir))
      {
        Node->cor = preto;
        avo->cor = vermelho;
        rot_dupla_esq(root, avo);
        return;
      }
    }
  }
}

void balancear(No **root, No *node)
{
  if ((*root) == NULL)
  {
    return;
  }
  if (eh_folha((*root)))
  {
    (*root)->cor = preto;
    return;
  }
  if (um_filho(*root))
  {
    if ((*root)->esq == NULL)
    {
      ((*root)->dir)->cor = vermelho;
    }
    else
    {
      ((*root)->esq)->cor = vermelho;
    }
    return;
  }
  balancear(root, node->dir);
  balancear(root, node->esq);

  if ((node->cor) == vermelho)
  {
    balancear_pretoEvermelho(root, node);
  }
}

No *encontrarSucessor(No *no)
{
  No *atual = no->dir;

  while (atual->esq != NULL)
  {
    atual = atual->esq;
  }

  return atual;
}

void remover_rubro_negro(No **root, No *node)
{
  if (*root == NULL)
  {
    return;
  }
  No *pai = node->pai;
  if (eh_folha(node))
  {

    if ((*root) == node)
    {
      (*root) = NULL;
      return;
    }

    No *irmao_node = NULL;

    if (pai != NULL)
    {
      if (pai->dir == node)
      {
        irmao_node = (pai->esq);
      }
      else if ((pai->esq) == node)
      {
        irmao_node = (pai->dir);
      }
    }

    if (pai->esq == node)
    {
      pai->esq = NULL;
    }
    else
    {
      pai->dir = NULL;
    }
    node->pai = NULL;

    if (irmao_node != NULL)
    {
      if (node->cor == vermelho)
      {
        return;
      }
    }
    if (irmao_node == NULL || irmao_node->cor == preto)
    {
      if (irmao_node == NULL || eh_folha(irmao_node))
      {
        if (pai != (*root))
        {

          mudar_cor(&pai);
        }
        mudar_cor(&irmao_node);
        return;
      }
      if (irmao_node->esq->cor == vermelho)
      {
        irmao_node->esq->cor = preto;
        rot_simples_dir(root, pai);
        return;
      }
      else if (irmao_node->dir->cor == vermelho)
      {
        irmao_node->dir->cor = preto;
        rot_simples_esq(root, pai);
        return;
      }
    }
    if (irmao_node->cor == vermelho)
    {
      if (posicao_filho(pai, irmao_node) == 0)
      {
        if (irmao_node->pai->cor == preto)
        {
          irmao_node->dir->cor = vermelho;
        }
        rot_simples_dir(root, pai);
      }
      else if (posicao_filho(pai, irmao_node) == 1)
      {
        if (irmao_node->pai->cor == preto)
        {
          irmao_node->esq->cor = vermelho;
        }
        rot_simples_esq(root, pai);
      }
      return;
    }
  }
  if (um_filho(node))
  {
    if (node == *root)
    {
      if (node->esq != NULL)
      {
        *root = node->esq;
        node->esq->pai = NULL;
      }
      else if (node->dir != NULL)
      {
        *root = node->dir;
        node->dir->pai = NULL;
      }
      pai->esq->cor = node->cor;
      node->esq = node->dir;
      node->dir = node->pai;
      node->pai = NULL;
      return;
    }
    if (pai->esq == node)
    {
      if (node->esq != NULL)
      {
        pai->esq = node->esq;
        node->esq->pai = pai;
      }
      else if (node->dir != NULL)
      {
        pai->esq = node->dir;
        node->dir->pai = pai;
      }
      pai->esq->cor = node->cor;
      node->esq = node->dir;
      node->dir = node->pai;
      node->pai = NULL;
      return;
    }
    else if (pai->dir == node)
    {
      if (node->esq != NULL)
      {
        pai->dir = node->esq;
        node->esq->pai = pai;
      }
      else if (pai->dir != NULL)
      {
        pai->dir = node->dir;
        node->dir->pai = pai;
      }
      pai->dir->cor = node->cor;
      node->esq = node->dir;
      node->dir = node->pai;
      node->pai = NULL;
      return;
    }
  }  No *substituto = NULL;

  if (remover->esq != NULL)
  {
    substituto = maior(remover->esq);
  }
  else if (remover->dir != NULL)
  {
    substituto = menor(remover->dir);
  }

  No *irmao_substituto = irmao(substituto->pai, substituto);
  int cor_remover = substituto->cor;

  remover_no(root, substituto);

  substituto->pai = pai_remover;
  substituto->cor = remover->cor;

  substituto->esq = remover->esq;

  if (remover->esq != NULL)
  {
    remover->esq->pai = substituto;
  }

  substituto->dir = remover->dir;

  if (remover->dir != NULL)
  {
    remover->dir->pai = substituto;
  }

  remover->esq = remover->dir = remover->pai = NULL;

  if (remover == (*root))
  {
    (*root) = substituto;
  }
  else
  {
    if (posicao_filho(pai_remover, remover) == 0)
    { // remover esta na esquerda do pai
      pai_remover->esq = substituto;
    }
    else if (posicao_filho(pai_remover, remover) == 1)
    { // remover esta na direita do pai
      pai_remover->dir = substituto;
    }
  }

  // casos de balanceamento

  // remoção de nó vermelho nao faz nada
  if (cor_remover == vermelho)
    return;

  No *pai_substituto = irmao_substituto->pai;
  // irmão preto, sem filhos
  //   recolorir pai e irmão
  if (irmao_substituto == NULL || irmao_substituto->cor == preto)
  {
    if (irmao_substituto == NULL || eh_folha(irmao_substituto))
    {
      if (pai_substituto != (*root))
      {
        trocar_cor(pai_substituto);
      }
      trocar_cor(irmao_substituto);
      return;
    }
    if (irmao_substituto->esq->cor == vermelho)
    {
      if (pai_substituto->cor == preto)
      {
        irmao_substituto->esq->cor = preto;
      }
      else
      {
        irmao_substituto->esq->cor = vermelho;
      }
      rot_simples_dir(root, pai_substituto);
      return;
    }
    else if (irmao_substituto->dir->cor == vermelho)
    {
      if (pai_substituto->cor == preto)
      {
        irmao_substituto->dir->cor = preto;
      }
      else
      {
        irmao_substituto->dir->cor = vermelho;
      }
      rot_simples_esq(root, pai_substituto);
      return;
    }
  }
  if (irmao_substituto->cor == vermelho)
  {
    if (posicao_filho(pai_substituto, irmao_substituto) == 0)
    {
      if (irmao_substituto->pai->cor == preto)
      {
        irmao_substituto->dir->cor = vermelho;
      }
      rot_simples_dir(root, pai_substituto);
    }
    else if (posicao_filho(pai_substituto, irmao_substituto) == 1)
    {
      if (irmao_substituto->pai->cor == preto)
      {
        irmao_substituto->esq->cor = vermelho;
      }
      rot_simples_esq(root, irmao_substituto->pai);
    }
    return;
  }
}

int main()
{

  srand(time(NULL));

  // No *no = criar_no(2);
  No *root = NULL;

  // imprimir(root);
  // printf("================\n");
  // balancear(&root, root);
  // imprimir(root);

  int opc = 1;
  while (opc != 0)
  {
    menu();
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
      inserir_raiz(&root);
      balancear(&root, root);
      break;
    case 2:
      buscar_raiz(root);
      break;
    case 3:
      imprimir(root);
      // balancear(&root, root);
      // printf("------------------------------------------------");
      // imprimir(root);
      break;
    case 5:
      balancear_pretoEvermelho(&root, root);
      imprimir(root);
      break;
    case 6:
      printf("Maior:%d, Menor:%d, Média:%.2f\n", maior(root)->num,
             menor(root)->num, media(root));
      break;
    case 7:
      printf("Altura: %d\n", altura(root));
      break;
    case 8:
      altura_no(root);
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