#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

/* Defina uma estrutura Medalha contendo: Código (contador inteiro), Gênero (char),
Modalidade(string), Cidade(string), Ano(int), Tipo Medalha GBS(char), Nome
Atleta(string), Pais Origem (string), Resultado (?). Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) as medalhas obtidas por cada atleta. Essa relação
deve aumentar e diminuir dinamicamente;
*/

typedef struct
{
    char genero;
    char modalidade[30];
    char cidade[30];
    int ano_da_conquista;
    char tipo_medalha;
    char nome_atleta[50];
    char pais_origem[3];
    int codigo;
    char resultado[10];

} Medalha;

int main(){

    int c; 
    int tamanho = 0;
    FILE *medalhasCSV;
    medalhasCSV = fopen("medalhas.csv", "r+");
    if(medalhasCSV == NULL){
        perror("Erro ao abrir arquivo \"medalhas.csv\"!\n\n");
        exit(1);
    }

    while((c = getc(medalhasCSV)) != EOF){
        if(c == '\n'){
            tamanho++; // VERIFICA O TANTO DE LINHAS(ATLETAS);
        }
    } tamanho++;

    rewind(medalhasCSV); // VOLTA O PONTEIRO DO ARQUIVO PARA O INICIO

    printf("Jogadores: %i\n", tamanho); // APAGAR

    Medalha* atletas = (Medalha*) malloc (tamanho * sizeof(Medalha));
    if(atletas == NULL){
        perror("Erro ao alocar memória dos \"atletas\"!");
        fclose(medalhasCSV);
        exit(1);
    } // ALOCAMENTO DOS JOGADORES

    rewind(medalhasCSV); // RESETA PONTEIRO DE POSIÇÃO DO ARQUIVO PARA O COMEÇO

    for (int i = 0; i < tamanho; i++) {
    fscanf(medalhasCSV, " %c, %29[^,], %29[^,], %i, %c, %49[^,], %3[^,], %[^\n]",
                &atletas[i].genero,
                atletas[i].modalidade,
                atletas[i].cidade,
                &atletas[i].ano_da_conquista,
                &atletas[i].tipo_medalha,
                atletas[i].nome_atleta,
                atletas[i].pais_origem,
                atletas[i].resultado);
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%c, %s, %s, %d, %c, %s, %s, %s\n",
               atletas[i].genero,
               atletas[i].modalidade,
               atletas[i].cidade,
               atletas[i].ano_da_conquista,
               atletas[i].tipo_medalha,
               atletas[i].nome_atleta,
               atletas[i].pais_origem,
               atletas[i].resultado);
    }
    
    free(atletas);

    return 0;
}

/* CRIA MEDALS BIN
    FILE *medalhasFile;

    medalhasFile = fopen("medalhas.bin", "rb");
    if (medalhasFile == NULL){
        perror("Erro ao abrir arquivo binário para leitura!\n");

        medalhasCSV = fopen("medalhas.csv", "r");
        if(medalhasCSV == NULL){
            perror("Erro ao abrir arquivo \"medalhas.csv\" para leitura\n");
            exit(1);
        }

        medalhasFile = fopen("medalhas.bin", "wb");
        if(medalhasFile == NULL){
            perror("Erro ao criar arquivo binário \"medalhas.bin\" !\n");
            exit(1);
        }

        long fileSize = getFileSize("medalhas.csv");
        char *temporaryvar = (char*) malloc (fileSize + 1);

        if(temporaryvar == NULL){
            perror("Erro ao alocar memória!\n");
            fclose(medalhasCSV);
            fclose(medalhasFile);
            exit(1);
        }

        fread(temporaryvar, 1, fileSize, medalhasCSV);
        fwrite(temporaryvar, 1, fileSize, medalhasFile);
        printf("Todas as informações foram transferidas com sucesso no arquivo \"medalhas.bin\"!\n");

        free(temporaryvar);
        fclose(medalhasCSV);
        fclose(medalhasFile);
    }else{
        printf("Arquivo \"%s\" carregado com sucesso!\n", "medalhas.bin");
        fclose(medalhasFile);
    }
*/


