#include "library.h"
#include <stdio.h>

int main() {
  int cod;
  char arquivo[] = "ListaDeLembretes";
  ListaDeLembretes ll;

  cod = carregarLista(&ll, arquivo);
  if (cod == 1)
    ll.qtd = 0;
  int opcao;
  do {
    printMenu();
    printf("Escolha uma Opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
      criarLembrete(&ll);
      break;
    case 2:
      deletarLembrete(&ll);
      break;
    case 3:
      listarLembrete(ll);
      break;
    case 4:
      alterarLembrete(&ll);
      break;
    case 5:
      filtrosdeLembretes(&ll);
      break;
    case 6:
      // exportarprioridadeLembrete(&ll);
      break;
    case 7:
      // exportarcategoriaLembrete(&ll);
      break;
    case 8:
      // exportarprioridadeecategoriaLembrete(&ll);
    case 0:
      break;
    default:
      printf("Opção não existe\n");
    }
  } while (opcao != 0);
  cod = salvarLista(ll, arquivo);
  if (cod != 0)
    printf("Erro ao salvar as tarefas");
}
