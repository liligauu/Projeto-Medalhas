#ifndef MYATLETAS_H
#define MYATLETAS_H

typedef struct{
    int hora;
    int minutos;
    float segundos;
} Tempo; // ARMAZENA TEMPO

typedef struct{
    char genero;
    char modalidade[30];
    char cidade[30];
    int ano_da_conquista;
    char tipo_medalha;
    char nome_atleta[50];
    char pais_origem[4];
    int codigo;
    union {
        float distancia;
        Tempo tempo;
    } resultado;
} Medalha; // STRUCT ATLETAS

// Funções de Manipulação de Arquivos
int ContaLinhas(const char* arquivo);

void SalvaAtletas(Medalha* jogador, int tamanho);

void ListaAtletas(Medalha* jogador, int tamanho);

void SalvaBinario(Medalha* atletas, int tamanho);

#endif //MYATLETAS.H
