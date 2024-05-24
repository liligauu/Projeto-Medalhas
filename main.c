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

    FILE *arq1;

    arq1 = fopen("medalhas.bin", "rb+");
    if (arq1 == NULL){
        perror("Erro ao abrir arquivo");
        exit(1);
    }else{
        printf("Arquivo \"%s\" carregado com sucesso!\n", "medalhas.bin");
    }

    fclose(arq1);

    return 0;
}
