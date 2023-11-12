#include "library.h"
#include "string.h"
#include <stdio.h>

int buscaLembrete(ListaDeLembretes ll, int qtd) {
  int posicao = 0;
  for (posicao; posicao < ll.qtd; posicao++) {
    if (ll.l[posicao].numero == qtd) {
      return posicao;
    }
  }
  return -1;
}

// ------------------------------------------------------------------------------------------------------

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

// ------------------------------------------------------------------------------------------------------

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
// ------------------------------------------------------------------------------------------------------
int listarLembrete(ListaDeLembretes ll) {
  printf("\n-Lista de Lembretes\n");
  for (int i = 0; i < ll.qtd; i++) {
    printf("\n%d. %s: %s (Prioridade: %d) | %s\n", i + 1, ll.l[i].categoria,
           ll.l[i].descricao, ll.l[i].prioridade, ll.l[i].estado);
  }
  return 0;
}

// ------------------------------------------------------------------------------------------------------

int alterarLembrete(ListaDeLembretes *ll) {
  printf("\n-Opção Alterar Lembrete\n");
  if (ll->qtd == 0) {
    printf("\nNão existe nenhum lembrete, crie um\n");
    return 0;
  }
  int numerodolembrete;
  printf("\nNumero do lembrete: ");
  scanf("%d", &numerodolembrete);
  int numlembrete = buscaLembrete(*ll, numerodolembrete);
  if (numlembrete == -1) {
    printf("\nEsse Lembrete não existe\n");
    return 0;
  }
  printMenualteracao();
  int opcao;
  int c;
  printf("Escolha a alteração desejada: ");
  scanf("%d", &opcao);
  switch (opcao) {
  case 1:
    printf("\nPrioridade: ");
    scanf("%d", &ll->l[numlembrete].prioridade);
    printf("\nPrioridade alterada\n");
    break;
  case 2:
    printf("\nCategoria: ");
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    fgets(ll->l[numlembrete].categoria, sizeof(ll->l[numlembrete].categoria),
          stdin);
    ll->l[numlembrete].categoria[strcspn(ll->l[numlembrete].categoria, "\n")] =
        '\0';
    printf("\nCategoria alterada\n");
    break;
  case 3:
    printf("\nDescrição: ");
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    fgets(ll->l[numlembrete].descricao, sizeof(ll->l[numlembrete].descricao),
          stdin);
    ll->l[numlembrete].descricao[strcspn(ll->l[numlembrete].descricao, "\n")] =
        '\0';
    printf("\nDescrição alterada\n");
    break;
  case 4:
    printf("\nEstado: ");
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    fgets(ll->l[numlembrete].estado, sizeof(ll->l[numlembrete].estado), stdin);
    ll->l[numlembrete].estado[strcspn(ll->l[numlembrete].estado, "\n")] = '\0';
    printf("\nEstado alterado\n");
    break;
  default:
    printf("\nOpção inválida\n");
    break;
  }
  return 0;
}

// ------------------------------------------------------------------------------------------------------

int filtrosdeLembretes(ListaDeLembretes *ll) {
  if (ll->qtd == 0) {
    printf("\nNão existe nenhum lembrete, crie um\n");
    return 0;
  }
  printMenufiltros();
  int opcao;
  int c;
  printf("Escolha o Filtro desejado: ");
  scanf("%d", &opcao);
  switch (opcao) {
  case 1:
    printf("\n-Opção Filtrar Prioridade\n");
    int prioridade;
    int prioridadeEncontrada = 0;
    printf("\nPrioridade desejada: ");
    scanf(" %d", &prioridade);
    for (int i = 0; i < ll->qtd; i++) {
      if (ll->l[i].prioridade == prioridade) {
        printf("\n%d. %s: %s | %s\n", i + 1, ll->l[i].categoria,
               ll->l[i].descricao, ll->l[i].estado);
        prioridadeEncontrada = 1;
      }
    }
    if (prioridadeEncontrada == 0) {
      printf("\nNão existem lembretes com a Prioridade desejada\n");
    }
    break;
  case 2:
    printf("\n-Opção Filtrar Estado\n");
    char estado[100];
    int estadoEncontrada = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    printf("\nEstado desejada: ");
    fgets(estado, sizeof(estado), stdin);
    estado[strcspn(estado, "\n")] = '\0';
    for (int i = 0; i < ll->qtd; i++) {
      if (strcmp(ll->l[i].estado, estado) == 0) {
        printf("\n%d. %s: %s (Prioridade: %d)\n", i + 1, ll->l[i].categoria,
               ll->l[i].descricao, ll->l[i].prioridade);
        estadoEncontrada = 1;
      }
    }
    if (estadoEncontrada == 0) {
      printf("\nNão existem lembretes com o Estado desejada\n");
    }
    break;
  case 3:
    printf("\n-Opção Filtrar Categoria\n");
    char categoria[100];
    int categoriaEncontrada = 0;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    printf("\nCategoria desejada: ");
    fgets(categoria, sizeof(categoria), stdin);
    categoria[strcspn(categoria, "\n")] = '\0';
    for (int i = 0; i < ll->qtd; i++) {
      if (strcmp(ll->l[i].categoria, categoria) == 0) {
        printf("\n%d. %s (Prioridade: %d) | %s\n", i + 1, ll->l[i].descricao,
               ll->l[i].prioridade, ll->l[i].estado);
        categoriaEncontrada = 1;
      }
    }
    if (categoriaEncontrada == 0) {
      printf("\nNão existem lembretes com a Categoria desejada\n");
    }
    break;
  case 4:
    printf("\n-Opção Filtrar Prioridade e Categoria\n");
    int prioridadedesejada;
    char categoriadesejada[100];
    int prioridadedesejadaEncontrada = 0;
    int categoriadesejadaEncontrada = 0;
    printf("\nPrioridade desejada: ");
    scanf(" %d", &prioridadedesejada);
    printf("\nCategoria desejada: ");
    while ((c = getchar()) != '\n' && c != EOF) {}
    fgets(categoriadesejada, sizeof(categoriadesejada), stdin);
    categoriadesejada[strcspn(categoriadesejada, "\n")] = '\0';
    for (int i = 0; i < ll->qtd; i++) {
      if (ll->l[i].prioridade == prioridadedesejada &&
          strcmp(ll->l[i].categoria, categoriadesejada) == 0) {
        printf("\n%d. %s | %s\n", i + 1, ll->l[i].descricao, ll->l[i].estado);
        categoriadesejadaEncontrada = 1;
        prioridadedesejadaEncontrada = 1;
      }
    }
    if (categoriadesejadaEncontrada == 0 && prioridadedesejadaEncontrada == 0) {
      printf("\nNão existem lembretes com essa Categoria e/ou Prioridade\n");
    }
    break;
  default:
    printf("Opção não existe\n");
    break;
  }
}

// ------------------------------------------------------------------------------------------------------

int exportarLembretes(ListaDeLembretes *ll) {
  if (ll->qtd == 0) {
    printf("\nNão existe nenhum lembrete, crie um\n");
    return 0;
  }
  printMenuexportar();
  int opcao;
  int c;
  printf("Escolha uma opção: ");
  scanf("%d", &opcao);
  switch (opcao) {
    case 1: 
      {
        FILE *f = fopen("exportar.txt", "w");
        int prioridade;
        int prioridadeEncontrada = 0;
        printf("\nPrioridade desejada: ");
        scanf("%d", &prioridade);
        for (int i = 0; i < ll->qtd; i++) {
          if (ll->l[i].prioridade == prioridade) {
            fprintf(f, "\n(Prioridade: %d) %s: %s | %s\n",
                    ll->l[i].prioridade, ll->l[i].categoria, ll->l[i].estado,
                    ll->l[i].descricao);
            prioridadeEncontrada = 1;
          }
        }
        if (prioridadeEncontrada == 0) {
          printf("\nNão existem lembretes com a Prioridade desejada\n");
        }
        fclose(f);
        break;
      }
    case 2: 
      {
        FILE *f = fopen("exportar.txt", "w");
        char categoria[100];
        int categoriaEncontrada = 0;
        printf("\nCategoria desejada: ");
        while ((c = getchar()) != '\n' && c != EOF) {
        }
        fgets(categoria, sizeof(categoria), stdin);
        categoria[strcspn(categoria, "\n")] = '\0';
        for (int i = 0; i < ll->qtd; i++) {
          if (strcmp(ll->l[i].categoria, categoria) == 0) {
            fprintf(f, "\n(Prioridade: %d) %s: %s | %s\n",
                    ll->l[i].prioridade, ll->l[i].categoria, ll->l[i].estado,
                    ll->l[i].descricao);
            categoriaEncontrada = 1;
          }
        }
        if (categoriaEncontrada == 0) {
          printf("\nNão existem lembretes com a Categoria desejada\n");
        }
        fclose(f);
      } 
      break;
    case 3: 
      {
        FILE *f = fopen("exportar.txt", "w");
        int prioridade;
        char categoria[100];
        int prioridadeEncontrada = 0;
        int categoriaEncontrada = 0;
        printf("\nPrioridade desejada: ");
        scanf("%d", &prioridade);
        printf("\nCategoria desejada: ");
        while ((c = getchar()) != '\n' && c != EOF) {}
        fgets(categoria, sizeof(categoria), stdin);
        categoria[strcspn(categoria, "\n")] = '\0';
        for (int i = 0; i < ll->qtd; i++) {
          if (ll->l[i].prioridade == prioridade && strcmp(ll->l[i].categoria, categoria) == 0) {
            fprintf(f, "\n(Prioridade: %d) %s: %s | %s\n", ll->l[i].prioridade, ll->l[i].categoria, ll->l[i].estado, ll->l[i].descricao);
            prioridadeEncontrada = 1;
            categoriaEncontrada = 1;
          }
        }
        if (categoriaEncontrada == 0 && prioridadeEncontrada == 0) {
          printf("\nNão existem lembretes com essa Categoria e/ou Prioridade\n");
        }
        fclose(f);
      }
      break;
  }
}

void printMenu() {
  printf("\n======== Menu ========\n1. Criar novo Lembrete\n2. Deletar um "
         "Lembrete\n3. Listar os Lembretes\n4. Alterar os Lembrete\n5. Filtrar "
         "Lembretes\n6. Exportar Lembretes\n0. Sair\n======================\n");
}

void printMenualteracao() {
  printf("\n==== Alteração ====\n1. Prioridade\n2. Categoria\n3. "
         "Descrição\n4. Estado\n===================\n");
}

void printMenufiltros() {
  printf("\n============ Filtros ============\n1. Filtrar por Prioridade\n2. "
         "Filtrar por Estado\n3. Filtrar por Categotia\n4. Filtrar Prioridade "
         "e Categoria\n=================================\n");
}

void printMenuexportar() {
  printf("\n============ Exportar ============\n1. Exportar por Prioridade\n2. "
         "Exportar por Categoria\n3. Exportar Prioridade e "
         "Categoria\n==================================\n");
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