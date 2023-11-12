#ifndef PROJECT1_LIBRARY_H
#define PROJECT1_LIBRARY_H

// Definindo a estrutura do lembrete
typedef struct lembrete {
  // Variável da prioridad
  int prioridade;
  // Variável da descrição
  char descricao[300];
  // Variável da categoria
  char categoria[100];
  // Variável do estado
  char estado[100];
  // Variável do numero
  int numero;
} Lembrete;

// Define a estrtura da lista com lembretes
typedef struct {
  // Quantidade de lembretes
  Lembrete l[100];
  // Variável da quantidade
  int qtd;
} ListaDeLembretes;

// Função que cria lembretes
int criarLembrete(ListaDeLembretes *ll);
// Função que deleta lembretes
int deletarLembrete(ListaDeLembretes *ll);
// Função que lista lembretes
int listarLembrete(ListaDeLembretes ll);

// Função que printa o menu principal
void printMenu();
// Função que printa o menu de alterações
void printMenualteracao();
// Função que printa o menu de filtros
void printMenufiltros();
// Função que printa o menu de exportações
void printMenuexportar();

// Função que altera os lembretes
int alterarLembrete(ListaDeLembretes *ll);
// Função que filtra os lembretes
int filtrosdeLembretes(ListaDeLembretes *ll);
// Função que exporta os lembretes
int exportarLembretes(ListaDeLembretes *ll);

// Função que salva a çista de lembretes
int salvarLista(ListaDeLembretes ll, char nome[]);
// Função que carrega a lista de lembretes
int carregarLista(ListaDeLembretes *ll, char nome[]);

#endif // PROJECT1_LIBRARY_H
