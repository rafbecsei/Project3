#ifndef PROJECT1_LIBRARY_H
#define PROJECT1_LIBRARY_H

typedef struct lembrete {
  int prioridade;
  char descricao[300];
  char categoria[100];
  char estado[100];
  int numero;
} Lembrete;

typedef struct {
  Lembrete l[100];
  int qtd;
} ListaDeLembretes;

int criarLembrete(ListaDeLembretes *ll);
int deletarLembrete(ListaDeLembretes *ll);
int listarLembrete(ListaDeLembretes ll);

void printMenualteracao();
void printMenufiltros();
int alterarLembrete(ListaDeLembretes *ll);
int filtrosdeLembretes(ListaDeLembretes *ll);
// int exportarprioridadeLembrete(ListaDeLembretes *ll);
// int exportarcategoriaLembrete(ListaDeLembretes *ll);
// int exportarprioridadeecategoriaLembrete(ListaDeLembretes *ll);

void printMenu();
int salvarLista(ListaDeLembretes ll, char nome[]);
int carregarLista(ListaDeLembretes *ll, char nome[]);

#endif // PROJECT1_LIBRARY_H
