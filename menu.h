#ifndef MENU_H
#define MENU_H
#include "myatletas.h"

typedef struct{
    char pais[3];
    int bronze;
    int silver;
    int gold;
    int total;
} Medals;

void InserirJogador(Medalha** jogador, int* tamanho); // INSERE ATLETA NOVO

void PesquisarJogador(Medalha* jogador, int tamanho); // PESQUISA ATLETA

void AlterarJogador(Medalha* jogador, int tamanho); // ALTERA DADOS DO ATLETA

void RemoverElemento(Medalha* jogador, int* tamanho); // DELETA UMA LINHA

void ExcluirMedalha(Medalha* jogador, int tamanho); // DELETA MEDALHA

void TabelaDeMedalhas(Medalha* jogador, int tamanho); // TABELA DE MEDALHAS

void ExportaCSV(Medalha* atletas, int tamanho); // EXPORTA PARA ARQUIVO CSV

#endif //FUNCOES.H