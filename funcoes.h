#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    char nome[29];
    int ouro;
    int prata;
    int bronze;
} Pais;

void InserirJogador(); // INSERE ATLETA NOVO

void PesquisarJogador(Medalha* jogador, int tamanho); // PESQUISA OS JOGADORES

void AlterarJogador(Medalha* jogador, int tamanho); // ALTERA CADASTROS

void ExcluirJogador(const char *nomeArquivo, const char *nomeJogador, int tamanho); // EXCLUI JOGADORES

void InserirAtleta(const char *nomeArquivo, int tamanho); // INSERE MEDALHAS MANUALMENTE

void AlterarMedalha(int num_linhas, int linha, char novoTipo); // ALTERA MEDALHA DO JOGADOR

void ExcluirMedalha(int num_linhas, int linha); // APAGA MEDALHA NA LINHA

void TabeladeMedalhas(); // TABELA

#endif //FUNCOES.H
