#include "library.h"
#include "string.h"
#include <stdio.h>

// FUNÇÃO BUSCAR
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

// FUNÇÃO CRIAR LEMBRETE
int criarLembrete(ListaDeLembretes *ll) {
  printf("\n-Opção Novo Lembrete\n");
  printf("\nPrioridade: ");
  // Recebe a entrada do usuário e armazena no array da opção prioridade
  scanf("%d", &ll->l[ll->qtd].prioridade);
  // Limpa o buffer
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
  printf("Categoria: ");
  // Recebe a entrada do usuário e armazena no array da opção categoria
  fgets(ll->l[ll->qtd].categoria, sizeof(ll->l[ll->qtd].categoria), stdin);
  // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
  // simbolizar o final da string
  ll->l[ll->qtd].categoria[strcspn(ll->l[ll->qtd].categoria, "\n")] = '\0';
  printf("Descricao: ");
  // Recebe a entrada do usuário e armazena no array da opção descrição
  fgets(ll->l[ll->qtd].descricao, sizeof(ll->l[ll->qtd].descricao), stdin);
  // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
  // simbolizar o final da string
  ll->l[ll->qtd].descricao[strcspn(ll->l[ll->qtd].descricao, "\n")] = '\0';
  printf("Estado do Lembrete: ");
  // Recebe a entrada do usuário e armazena no array da opção estado
  fgets(ll->l[ll->qtd].estado, sizeof(ll->l[ll->qtd].estado), stdin);
  // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
  // simbolizar o final da string
  ll->l[ll->qtd].estado[strcspn(ll->l[ll->qtd].estado, "\n")] = '\0';
  // Aumenta o número do lembrete
  ll->l[ll->qtd].numero = ll->qtd + 1;
  // Aumenta a quantidade de lembretes
  ll->qtd = ll->qtd + 1;
  return 0;
}

// ------------------------------------------------------------------------------------------------------

// FUNÇÃO DELETAR LEMBRETE
int deletarLembrete(ListaDeLembretes *ll) {
  printf("\n-Opção Deletar Lembrete\n");
  // Erro caso não exista lembretes
  if (ll->qtd == 0) {
    printf("Nao ha lembretes, crie um");
  }
  // Variável do numero do lembrete desejado
  int numerodolembrete;
  printf("\nNumero do lembrete: ");
  // Recebe o numero do lembrete e armazena na variável
  scanf("%d", &numerodolembrete);
  // Verifica se o lembrete existe dentre os já existentes
  int numlembrete = buscaLembrete(*ll, numerodolembrete);
  // Erro caso não exista lembrete
  if (numlembrete == -1) {
    printf("\nEsse Lembrete não existe\n");
    return 0;
    // Caso exista o lembrete
  } else {
    // Loop que percorre os elementos da lista de lembretes
    for (int i = numlembrete; i < ll->qtd; i++) {
      // Atribui o valor do lembrete seguinte ao lembrete desejado
      ll->l[i] = ll->l[i + 1];
    }
    // Diminui a quantidade de lembretes
    ll->qtd--;
    printf("\nLembrete %d deletado\n", numerodolembrete);
  }
  return 0;
}
// ------------------------------------------------------------------------------------------------------

// FUNÇÃO LISTAR LEMBRETES
int listarLembrete(ListaDeLembretes ll) {
  printf("\n-Lista de Lembretes\n");
  for (int i = 0; i < ll.qtd; i++) {
    printf("\n%d. %s: %s (Prioridade: %d) | %s\n", i + 1, ll.l[i].categoria,
           ll.l[i].descricao, ll.l[i].prioridade, ll.l[i].estado);
  }
  return 0;
}

// ------------------------------------------------------------------------------------------------------

// FUNÇÃO ALTERAR LEMBRETE
int alterarLembrete(ListaDeLembretes *ll) {
  printf("\n-Opção Alterar Lembrete\n");
  // Erro caso não exista lembretes
  if (ll->qtd == 0) {
    printf("\nNão existe nenhum lembrete, crie um\n");
    return 0;
  }
  // Variável do numero do lembrete desejado
  int numerodolembrete;
  printf("\nNumero do lembrete: ");
  // Recebe o numero do lembrete e armazena na variável
  scanf("%d", &numerodolembrete);
  // Verifica se o lembrete existe dentre os já existentes
  int numlembrete = buscaLembrete(*ll, numerodolembrete);
  // Erro caso não exista lembrete
  if (numlembrete == -1) {
    printf("\nEsse Lembrete não existe\n");
    return 0;
  }
  // printa o menu de alterações
  printMenualteracao();
  // Variável opções
  int opcao;
  int c;
  printf("Escolha a alteração desejada: ");
  // Recebe a opção desejada
  scanf("%d", &opcao);
  switch (opcao) {
  // Opção alteração de prioridade
  case 1:
    printf("\nPrioridade: ");
    // Recebe o novo número da prioridade e sobreescreve a prioridade antiga
    scanf("%d", &ll->l[numlembrete].prioridade);
    printf("\nPrioridade alterada\n");
    break;
  // Opção alteração de categoria
  case 2:
    printf("\nCategoria: ");
    // Limpa buffer
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    // Recebe a nova categoria e sobreescreve a categoria antiga
    fgets(ll->l[numlembrete].categoria, sizeof(ll->l[numlembrete].categoria),
          stdin);
    // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
    // simbolizar o final da string
    ll->l[numlembrete].categoria[strcspn(ll->l[numlembrete].categoria, "\n")] =
        '\0';
    printf("\nCategoria alterada\n");
    break;
  // Opção alteração de descrição
  case 3:
    printf("\nDescrição: ");
    // Limpa buffer
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    // Recebe a nova descrição e sobreescreve a descrição antiga
    fgets(ll->l[numlembrete].descricao, sizeof(ll->l[numlembrete].descricao),
          stdin);
    // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
    // simbolizar o final da string
    ll->l[numlembrete].descricao[strcspn(ll->l[numlembrete].descricao, "\n")] =
        '\0';
    printf("\nDescrição alterada\n");
    break;
  // Opção alteração de estado
  case 4:
    printf("\nEstado: ");
    // Limpa buffer
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    // Recebe a nova descrição e sobreescreve a descrição antiga
    fgets(ll->l[numlembrete].estado, sizeof(ll->l[numlembrete].estado), stdin);
    // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
    // simbolizar o final da string
    ll->l[numlembrete].estado[strcspn(ll->l[numlembrete].estado, "\n")] = '\0';
    printf("\nEstado alterado\n");
    break;
  // Opção inválida
  default:
    printf("\nOpção inválida\n");
    break;
  }
  return 0;
}

// ------------------------------------------------------------------------------------------------------

// FUNÇÃO FILTRAR LEMBRETES
int filtrosdeLembretes(ListaDeLembretes *ll) {
  // Erro caso não exista lembretes
  if (ll->qtd == 0) {
    printf("\nNão existe nenhum lembrete, crie um\n");
    return 0;
  }
  // Printa o menu de filtros
  printMenufiltros();
  // Variável opções
  int opcao;
  int c;
  printf("Escolha o Filtro desejado: ");
  // Recebe a opção desejada
  scanf("%d", &opcao);
  switch (opcao) {
  // Opção filtrar por prioridade
  case 1:
    printf("\n-Opção Filtrar Prioridade\n");
    // Variável prioridade
    int prioridade;
    // Variável prioridade pra verificar se há lembretes com a prioridade
    // desejada
    int prioridadeEncontrada = 0;
    printf("\nPrioridade desejada: ");
    // Recebe a prioridade desejada
    scanf(" %d", &prioridade);
    // Loop que percorre a lista de lembretes
    for (int i = 0; i < ll->qtd; i++) {
      // Verifica se a prioridade desejada é igual a prioridade dos lembretes da
      // lista
      if (ll->l[i].prioridade == prioridade) {
        printf("\n%d. %s: %s | %s\n", i + 1, ll->l[i].categoria,
               ll->l[i].descricao, ll->l[i].estado);
        // Torna a variável prioridade verdadeira
        prioridadeEncontrada = 1;
      }
    }
    // Caso a variável prioridade seja falsa, ou seja, não foi encontrada
    if (prioridadeEncontrada == 0) {
      printf("\nNão existem lembretes com a Prioridade desejada\n");
    }
    break;
  // Opção filtrar por estado
  case 2:
    printf("\n-Opção Filtrar Estado\n");
    // Variável estado
    char estado[100];
    // Variável estado pra verificar se há lembretes com o estado desejada
    int estadoEncontrada = 0;
    // Limpa buffer
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    printf("\nEstado desejada: ");
    // Recebe o estado desejado
    fgets(estado, sizeof(estado), stdin);
    // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
    // simbolizar o final da string
    estado[strcspn(estado, "\n")] = '\0';
    // Loop que percorre a lista de lembretes
    for (int i = 0; i < ll->qtd; i++) {
      // Verifica se o estado desejada é igual o estado dos lembretes da lista
      if (strcmp(ll->l[i].estado, estado) == 0) {
        printf("\n%d. %s: %s (Prioridade: %d)\n", i + 1, ll->l[i].categoria,
               ll->l[i].descricao, ll->l[i].prioridade);
        // Torna a variável estado verdadeira
        estadoEncontrada = 1;
      }
    }
    // Caso a variável estado seja falsa, ou seja, não foi encontrada
    if (estadoEncontrada == 0) {
      printf("\nNão existem lembretes com o Estado desejada\n");
    }
    break;
  // Opção filtrar por categoria
  case 3:
    printf("\n-Opção Filtrar Categoria\n");
    // Variável categoria
    char categoria[100];
    // Variável categoria pra verificar se há lembretes com a categoria desejada
    int categoriaEncontrada = 0;
    printf("\nCategoria desejada: ");
    // Limpa buffer
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    // Recebe a categoria desejada
    fgets(categoria, sizeof(categoria), stdin);
    // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
    // simbolizar o final da string
    categoria[strcspn(categoria, "\n")] = '\0';
    // Loop que percorre as prioridades e vai do maior para o menor
    for (int j = 10; j > -1; j--) {
      // Loop que percorre a lista de lembretes
      for (int i = 0; i < ll->qtd; i++) {
        // Verifica se a categoria desejada é igual a categoria dos lembretes da
        // lista
        int buscacategoria = strcmp(ll->l[i].categoria, categoria);
        // Verifica se a prioridade dos lembretes da lista é igual a variável j
        if (ll->l[i].prioridade == j) {
          // Caso as comparações sejam verdadeiras, imprime o lembrete
          if (buscacategoria == 0) {
            printf("\n%d. %s (Prioridade: %d) | %s\n", i + 1,
                   ll->l[i].descricao, ll->l[i].prioridade, ll->l[i].estado);
            // Torna a variável categoria verdadeira
            categoriaEncontrada = 1;
          }
        }
      }
    }
    // Caso a variável categoria seja falsa, ou seja, não foi encontrada
    if (categoriaEncontrada == 0) {
      printf("\nNão existem lembretes com a Categoria desejada\n");
    }
    break;
  // Opção filtrar por prioridade e categoria
  case 4:
    printf("\n-Opção Filtrar Prioridade e Categoria\n");
    // Variável prioridade desejada
    int prioridadedesejada;
    // Variável categoria desejada
    char categoriadesejada[100];
    // Variável prioridade e categoria pra verificar se há lembretes com a
    // prioridade e categoria desejada
    int prioridadedesejadaEncontrada = 0;
    int categoriadesejadaEncontrada = 0;
    printf("\nPrioridade desejada: ");
    // Recebe a prioridade desejada
    scanf(" %d", &prioridadedesejada);
    printf("\nCategoria desejada: ");
    // Limpa buffer
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    // Recebe a categoria desejada
    fgets(categoriadesejada, sizeof(categoriadesejada), stdin);
    // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
    // simbolizar o final da string
    categoriadesejada[strcspn(categoriadesejada, "\n")] = '\0';
    // Loop que percorre a lista
    for (int i = 0; i < ll->qtd; i++) {
      // Verifica se a prioridade e categoria desejada é igual a prioridade e
      // categoria dos lembretes da lista
      if (ll->l[i].prioridade == prioridadedesejada &&
          strcmp(ll->l[i].categoria, categoriadesejada) == 0) {
        printf("\n%d. %s | %s\n", i + 1, ll->l[i].descricao, ll->l[i].estado);
        // Torna a variável prioridade e categoria verdadeira
        categoriadesejadaEncontrada = 1;
        prioridadedesejadaEncontrada = 1;
      }
    }
    // Caso a variável prioridade e categoria sejam falsas, ou seja, não foram
    // encontradas
    if (categoriadesejadaEncontrada == 0 && prioridadedesejadaEncontrada == 0) {
      printf("\nNão existem lembretes com essa Categoria e/ou Prioridade\n");
    }
    break;
  // Opção inválida
  default:
    printf("Opção não existe\n");
    break;
  }
}

// ------------------------------------------------------------------------------------------------------

// FUNÇÃO EXPORTAR LEMBRETES
int exportarLembretes(ListaDeLembretes *ll) {
  // Erro caso não exista lembretes
  if (ll->qtd == 0) {
    printf("\nNão existe nenhum lembrete, crie um\n");
    return 0;
  }
  // Printa o menu de exportação
  printMenuexportar();
  // Variável opção
  int opcao;
  int c;
  printf("Escolha uma opção: ");
  // Recebe a opção
  scanf("%d", &opcao);
  switch (opcao) {
  // Opção exportar por prioridade
  case 1: {
    // Abre o arquivo
    FILE *f = fopen("exportar.txt", "w");
    // Variável prioridade
    int prioridade;
    // Variável prioridade pra verificar se há lembretes com a prioridade
    // desejada
    int prioridadeEncontrada = 0;
    printf("\nPrioridade desejada: ");
    // Recebe a prioridade
    scanf("%d", &prioridade);
    // Loop que percorre a lista
    for (int i = 0; i < ll->qtd; i++) {
      // Verifica se a prioridade desejada é igual a prioridade dos lembretes da
      // lista
      if (ll->l[i].prioridade == prioridade) {
        fprintf(f, "\n(Prioridade: %d) %s: %s | %s\n", ll->l[i].prioridade,
                ll->l[i].categoria, ll->l[i].estado, ll->l[i].descricao);
        // Torna a variável prioridade pra verdadeira
        prioridadeEncontrada = 1;
      }
    }
    // Caso a variável seja falsa, ou seja, não foi encontrado lembretes com a
    // prioridade desejada
    if (prioridadeEncontrada == 0) {
      printf("\nNão existem lembretes com a Prioridade desejada\n");
    }
    // Fecha o arquivo
    fclose(f);
    break;
  }
  // Opção exportar por categoria
  case 2: {
    // Abre o arquivo
    FILE *f = fopen("exportar.txt", "w");
    // Variável categoria
    char categoria[100];
    // Variável categoria pra verificar se há lembretes com a categoria desejada
    int categoriaEncontrada = 0;
    printf("\nCategoria desejada: ");
    // Limpa buffer
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    // Recebe a categoria
    fgets(categoria, sizeof(categoria), stdin);
    // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
    // simbolizar o final da string
    categoria[strcspn(categoria, "\n")] = '\0';
    // Loop que percorre as prioridades e vai do maior para o menor
    for (int j = 10; j > -1; j--) {
      // Loop que percorre a lista
      for (int i = 0; i < ll->qtd; i++) {
        // Verifica se a categoria desejada é igual a categoria dos lembretes da
        int buscacategoria = strcmp(ll->l[i].categoria, categoria);
        // Verifica se a prioridade dos lembretes da lista é igual a variável j
        if (ll->l[i].prioridade == j) {
          // Caso as comparações sejam verdadeiras, imprime o lembrete
          if (buscacategoria == 0) {
            fprintf(f, "\n%d. %s (Prioridade: %d) | %s\n", i + 1,
                    ll->l[i].descricao, ll->l[i].prioridade, ll->l[i].estado);
            // Torna a variável categoria pra verdadeira
            categoriaEncontrada = 1;
          }
        }
      }
    }
    // Caso a variável seja falsa, ou seja, não foi encontrado lembretes com a
    // categoria desejada
    if (categoriaEncontrada == 0) {
      printf("\nNão existem lembretes com a Categoria desejada\n");
    }
    // Fecha o arquivo
    fclose(f);
  } break;
  // Opção exportar por prioridade e categoria
  case 3: {
    // Abre o arquivo
    FILE *f = fopen("exportar.txt", "w");
    // Variável prioridade
    int prioridade;
    // Variável categoria
    char categoria[100];
    // Variável prioridade e categoria pra verificar se há lembretes com a
    // prioridade e categoria desejada
    int prioridadeEncontrada = 0;
    int categoriaEncontrada = 0;
    printf("\nPrioridade desejada: ");
    // Recebe a prioridade
    scanf("%d", &prioridade);
    printf("\nCategoria desejada: ");
    // Limpa buffer
    while ((c = getchar()) != '\n' && c != EOF) {
    }
    // Recebe a categoria
    fgets(categoria, sizeof(categoria), stdin);
    // Substitui qualquer caractere que não seja letra, no caso \n, por \0 para
    // simbolizar o final da string
    categoria[strcspn(categoria, "\n")] = '\0';
    // Loop que percorre a lista de lembretes
    for (int i = 0; i < ll->qtd; i++) {
      // Verifica se a prioridade e categoria desejada é igual a prioridade e
      // categoria dos lembretes da lista
      if (ll->l[i].prioridade == prioridade &&
          strcmp(ll->l[i].categoria, categoria) == 0) {
        fprintf(f, "\n(Prioridade: %d) %s: %s | %s\n", ll->l[i].prioridade,
                ll->l[i].categoria, ll->l[i].estado, ll->l[i].descricao);
        // Torna a variável prioridade e categoria pra verdadeira
        prioridadeEncontrada = 1;
        categoriaEncontrada = 1;
      }
    }
    // Caso a variável seja falsa, ou seja, não foi encontrado lembretes com a
    // prioridade e categoria desejada
    if (categoriaEncontrada == 0 && prioridadeEncontrada == 0) {
      printf("\nNão existem lembretes com essa Categoria e/ou Prioridade\n");
    }
    // Fecha o arquivo
    fclose(f);
  } break;
  }
}

// FUNÇÃO PRINT MENU PRINCIPAL
void printMenu() {
  printf("\n======== Menu ========\n1. Criar novo Lembrete\n2. Deletar um "
         "Lembrete\n3. Listar os Lembretes\n4. Alterar Lembrete\n5. Filtrar "
         "Lembretes\n6. Exportar Lembretes\n0. Sair\n======================\n");
}

// FUNÇÃO PRINT MENU ALTERAÇÕES
void printMenualteracao() {
  printf("\n==== Alteração ====\n1. Prioridade\n2. Categoria\n3. "
         "Descrição\n4. Estado\n===================\n");
}

// FUNÇÃO PRINT MENU FILTROS
void printMenufiltros() {
  printf("\n============ Filtros ============\n1. Filtrar por Prioridade\n2. "
         "Filtrar por Estado\n3. Filtrar por Categoria\n4. Filtrar Prioridade "
         "e Categoria\n=================================\n");
}

// FUNÇÃO PRINT MENU EXPORTAR
void printMenuexportar() {
  printf("\n============ Exportar ============\n1. Exportar por Prioridade\n2. "
         "Exportar por Categoria\n3. Exportar Prioridade e "
         "Categoria\n==================================\n");
}

// FUNÇÃO QUE SALVA LISTA DE LEMBRETES EM ARQUIVO
int salvarLista(ListaDeLembretes ll, char nome[]) {
  FILE *f = fopen(nome, "wb");
  if (f == NULL) {
    return 1;
  }
  fwrite(&ll, sizeof(ListaDeLembretes), 1, f);
  fclose(f);
  return 0;
}
// FUNÇÃO QUE LE LISTA DE LEMBRETES DO ARQUIVO
int carregarLista(ListaDeLembretes *ll, char nome[]) {
  FILE *f = fopen(nome, "rb");
  if (f == NULL) {
    return 1;
  }
  fread(ll, sizeof(ListaDeLembretes), 1, f);
  fclose(f);
  return 0;
}
