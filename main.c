#include "library.h"
#include <stdio.h>

int main() {
  int cod;
  char arquivo[] = "ListaDeLembretes";
  // Criando uma variável do tipo ListaDeLembretes
  ListaDeLembretes ll;

  // Chamando a função carregar para carregar a lista do arquivo
  cod = carregarLista(&ll, arquivo);
  if (cod == 1)
    // Quatidade de lembretes
    ll.qtd = 0;
  // Variável das opções do menu
  int opcao;
  // Inicio do loop do menu até o usuário digitar 0
  do {
    // Função que escreve o menu
    printMenu();
    printf("Escolha uma Opção: ");
    // Recebe a opção do usuário
    scanf("%d", &opcao);
    switch (opcao) {
    // Opção criar
    case 1:
      criarLembrete(&ll);
      break;
    // Opção deletar
    case 2:
      deletarLembrete(&ll);
      break;
    // Opção listar
    case 3:
      listarLembrete(ll);
      break;
    // Opção alterar
    case 4:
      alterarLembrete(&ll);
      break;
    // Opção filtrar
    case 5:
      filtrosdeLembretes(&ll);
      break;
    // Opção exportar
    case 6:
      exportarLembretes(&ll);
      break;
    // Opção sair
    case 0:
      break;
    // Opção inválida
    default:
      printf("Opção não existe\n");
    }
    // Loop para repetir o menu até que o usuário digitar 0
  } while (opcao != 0);
  // Chamando a função salvar para armazenar a lista no arquivo
  cod = salvarLista(ll, arquivo);
  // Caso a função retornar um erro
  if (cod != 0)
    printf("Erro ao salvar as tarefas");
}
