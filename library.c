#include "library.h"
#include "string.h"
#include <stdio.h>

int buscaLembrete(ListaDeLembretes ll, int qtd) {
  int posicao = 0;
  for (posicao; posicao < ll.qtd; posicao++) {
    if (ll.l[posicao].numero == qtd) {
      return posicao;
      printf(posicao);
    }
  }
  return -1;
}

int criarLembrete(ListaDeLembretes *ll) {
  printf("\n-Opção Novo Lembrete\n");
  printf("\nPrioridade: ");
  scanf("%d", &ll->l[ll->qtd].prioridade);
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  printf("Categoria: ");
  fgets(ll->l[ll->qtd].categoria, sizeof(ll->l[ll->qtd].categoria), stdin);
  ll->l[ll->qtd].categoria[strcspn(ll->l[ll->qtd].categoria, "\n")] = '\0';
  printf("Descricao: ");
  fgets(ll->l[ll->qtd].descricao, sizeof(ll->l[ll->qtd].descricao), stdin);
  ll->l[ll->qtd].descricao[strcspn(ll->l[ll->qtd].descricao, "\n")] = '\0';
  printf("Estado do Lembrete: ");
  fgets(ll->l[ll->qtd].estado, sizeof(ll->l[ll->qtd].estado), stdin);
  ll->l[ll->qtd].estado[strcspn(ll->l[ll->qtd].estado, "\n")] = '\0';
  ll->l[ll->qtd].numero = ll->qtd + 1;
  ll->qtd = ll->qtd + 1;
  return 0;
}

int deletarLembrete(ListaDeLembretes *ll) {
  printf("\n-Opção Deletar Lembrete\n");
  if (ll->qtd == 0) {
    printf("Nao ha lembretes, crie um");
  }
  int numerodolembrete;
  printf("\nNumero do lembrete: ");
  scanf("%d", &numerodolembrete);
  int numlembrete = buscaLembrete(*ll, numerodolembrete);
  if (numlembrete == -1) {
    printf("\nEsse Lembrete não existe\n");
    return 0;
  } else {
    for (int i = numlembrete; i < ll->qtd; i++) {
      ll->l[i] = ll->l[i + 1];
    }
    ll->qtd--;
    printf("\nLembrete %d deletado\n", numerodolembrete);
  }
  return 0;
}

int listarLembrete(ListaDeLembretes ll) {
  printf("\n-Lista de Lembretes\n");
  for (int i = 0; i < ll.qtd; i++) {
    printf("\n%d. %s: %s (Prioridade: %d) | %s\n", i + 1, ll.l[i].categoria,
           ll.l[i].descricao, ll.l[i].prioridade, ll.l[i].estado);
  }
  return 0;
}

void printMenu() {
  printf(
      "\n======= Menu =======\n1. Criar Lembrete\n2. Deletar Lembrete\n3. "
      "Listar Lembretes\n4. Alterar Lembrete\n0. Sair\n====================\n");
}

int salvarLista(ListaDeLembretes ll, char nome[]) {
  FILE *f = fopen(nome, "wb");
  if (f == NULL) {
    return 1;
  }
  fwrite(&ll, sizeof(ListaDeLembretes), 1, f);
  fclose(f);
  return 0;
}
int carregarLista(ListaDeLembretes *ll, char nome[]) {
  FILE *f = fopen(nome, "rb");
  if (f == NULL) {
    return 1;
  }
  fread(ll, sizeof(ListaDeLembretes), 1, f);
  fclose(f);
  return 0;
}