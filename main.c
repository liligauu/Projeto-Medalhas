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
    //resultado

} Medalha;

int main(){

    FILE *medalhasFile;
    FILE *medalhasCSV;

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

        long fileSize = getFileSize("medalhas.csv"); // VARIAVEL PARA ARMAZENAR TAMANHO DO ARQUIVO .CSV
        char *temporaryvar = (char*) malloc (fileSize + 1);
        if(temporaryvar == NULL){
            perror("Erro ao alocar memória!\n");
            fclose(medalhasCSV);
            fclose(medalhasFile);
            exit(1);
        }

        fread(temporaryvar, 1, fileSize, medalhasCSV); // LÊ AS INFORMAÇÕES DO ARQUIVO CSV E SALVA EM TEMPORARYVAR
        fwrite(temporaryvar, 1, fileSize, medalhasFile); // TRANSFERE AS INFORMAÇÕES DA VARIAVEL TEMPORARIA PARA O ARQUIVO BIN
        printf("Todas as informações foram transferidas com sucesso no arquivo \"medalhas.bin\"!\n");

        free(temporaryvar); // LIMPA O VETOR DE TRANSFERENCIA TEMPORARIO
        fclose(medalhasCSV); // FECHA O ARQUIVO CSV
        fclose(medalhasFile);
    }else{
        printf("Arquivo \"%s\" carregado com sucesso!\n", "medalhas.bin");
        fclose(medalhasFile); // FECHA O ARQUIVO BIN
    }

    return 0;
}



