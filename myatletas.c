#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "myatletas.h"

int ContaLinhas(const char* nomearquivo){

    FILE* arquivos = fopen(nomearquivo, "r+");
    if(arquivos == NULL){
        perror("Erro ao abrir arquivo para leitura!\n");
        exit(1);
    }

    int c;
    int tamanho = 0;
    while((c = getc(arquivos)) != EOF){
        if(c == '\n'){
            tamanho++; // verifica o número de linhas do arquivo
        }
    } tamanho++;
    
    fclose(arquivos);
    return tamanho;
} // Conta linhas do programa

void SalvaAtletas(Medalha* jogador, int tamanho){
    
    FILE* arquivobin = fopen("medalhas.bin", "rb");
    if(arquivobin == NULL){
        printf("Abrindo arquivo csv!\n\n");
        FILE* arquivocsv = fopen("medalhas.csv", "r");
        if (arquivocsv == NULL) {
            perror("Erro ao ler arquivo CSV!\n");
            exit(1);
        }

        for (int i = 0; i < tamanho; i++) {
            char resultadoTipo[20];

            // Leitura dos dados do arquivo CSV
            if (fscanf(arquivocsv, " %c, %[^,], %[^,], %d, %c, %[^,], %[^,], %[^\n]",
                    &jogador[i].genero,
                    jogador[i].modalidade,
                    jogador[i].cidade,
                    &jogador[i].ano_da_conquista,
                    &jogador[i].tipo_medalha,
                    jogador[i].nome_atleta,
                    jogador[i].pais_origem,
                    resultadoTipo) != 8) {
                fprintf(stderr, "Erro ao ler dados do arquivo CSV para o atleta %d\n", i + 1);
                break; // Termina o loop se achar erro na leitura
            }

            jogador[i].codigo = i+1;

            // Zera os valores invalidos (none)
            if (strcmp(resultadoTipo, "None") == 0) {
                jogador[i].resultado.distancia = 0.0;
                jogador[i].resultado.tempo.segundos = 0.0;
                jogador[i].resultado.tempo.minutos = 0;
                jogador[i].resultado.tempo.hora = 0;
            } else {
                // Verifica de acordo com o tipo de modalidade
                if (strcmp(jogador[i].modalidade, "100M Men") == 0 ||
                    strcmp(jogador[i].modalidade, "110M Hurdles Men") == 0 ||
                    strcmp(jogador[i].modalidade, "200M Men") == 0 ||
                    strcmp(jogador[i].modalidade, "400M Hurdles Men") == 0 ||
                    strcmp(jogador[i].modalidade, "400M Men") == 0 ||
                    strcmp(jogador[i].modalidade, "4X100M Relay Men") == 0 ||
                    strcmp(jogador[i].modalidade, "4X400M Relay Men") == 0 ||
                    strcmp(jogador[i].modalidade, "100M Hurdles Women") == 0 ||
                    strcmp(jogador[i].modalidade, "100M Women") == 0 ||
                    strcmp(jogador[i].modalidade, "200M Women") == 0 ||
                    strcmp(jogador[i].modalidade, "400M Hurdles Women") == 0 ||
                    strcmp(jogador[i].modalidade, "400M Women") == 0 ||
                    strcmp(jogador[i].modalidade, "4X100M Relay Women") == 0) {
                    jogador[i].resultado.tempo.segundos = atof(resultadoTipo); // STRING - FLOAT
                }else if(strcmp(jogador[i].modalidade, "1500M Men") == 0 ||
                    strcmp(jogador[i].modalidade, "3000M Steeplechase Men") == 0 ||
                    strcmp(jogador[i].modalidade, "5000M Men") == 0 ||
                    strcmp(jogador[i].modalidade, "800M Men") == 0 ||
                    strcmp(jogador[i].modalidade, "10000M Men") == 0 ||
                    strcmp(jogador[i].modalidade, "10000M Women") == 0 ||
                    strcmp(jogador[i].modalidade, "1500M Women") == 0 ||
                    strcmp(jogador[i].modalidade, "3000M Steeplechase Women") == 0 ||
                    strcmp(jogador[i].modalidade, "4X400M Relay Women") == 0 ||
                    strcmp(jogador[i].modalidade, "5000M Women") == 0 ||
                    strcmp(jogador[i].modalidade, "800M Women") == 0) {
                    sscanf(resultadoTipo, "%d:%f", &jogador[i].resultado.tempo.minutos,
                        &jogador[i].resultado.tempo.segundos);
                }else if(strcmp(jogador[i].modalidade, "20Km Race Walk Men") == 0 ||
                    strcmp(jogador[i].modalidade, "20Km Race Walk Women") == 0 ||
                    strcmp(jogador[i].modalidade, "50Km Race Walk Men") == 0 ||
                    strcmp(jogador[i].modalidade, "Marathon Men") == 0 ||
                    strcmp(jogador[i].modalidade, "Marathon Women") == 0){
                    sscanf(resultadoTipo, "%d:%d:%f", &jogador[i].resultado.tempo.hora,
                        &jogador[i].resultado.tempo.minutos,
                        &jogador[i].resultado.tempo.segundos);
                }else{
                    jogador[i].resultado.distancia = atof(resultadoTipo); //CONVERTE STRING - FLOAT
                }
            }
        }

        fclose(arquivocsv);
    }else{
        printf("Abrindo arquivo binário!\n");
        long fileSize = getFileSize("medalhas.bin");
        fread(jogador, 1, fileSize, arquivobin);
    }

    printf("Os jogadores foram salvos com sucesso!\n");
}

void ListaAtletas(Medalha* jogador, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("Atleta %d: ", jogador[i].codigo);
        printf("%c, ", jogador[i].genero);
        printf("%s, ", jogador[i].modalidade);
        printf("%s, ", jogador[i].cidade);
        printf("%d, ", jogador[i].ano_da_conquista);
        printf("%c, ", jogador[i].tipo_medalha);
        printf("%s, ", jogador[i].nome_atleta);
        printf("%s, ", jogador[i].pais_origem);
        
        // Verificar o tipo de resultado e imprimir de acordo com a modalidade
        if(strcmp(jogador[i].modalidade, "100M Men") == 0 || 
            strcmp(jogador[i].modalidade, "110M Hurdles Men") == 0 ||
            strcmp(jogador[i].modalidade, "200M Men") == 0 ||
            strcmp(jogador[i].modalidade, "400M Hurdles Men") == 0 ||
            strcmp(jogador[i].modalidade, "400M Men") == 0 || 
            strcmp(jogador[i].modalidade, "4X100M Relay Men") == 0 ||
            strcmp(jogador[i].modalidade, "4X400M Relay Men") == 0 ||
            strcmp(jogador[i].modalidade, "100M Hurdles Women") == 0 ||
            strcmp(jogador[i].modalidade, "100M Women") == 0 ||
            strcmp(jogador[i].modalidade, "200M Women") == 0 ||
            strcmp(jogador[i].modalidade, "400M Hurdles Women") == 0 ||
            strcmp(jogador[i].modalidade, "400M Women") == 0 ||
            strcmp(jogador[i].modalidade, "4X100M Relay Women") == 0){
            
            // Resultado em segundos
            printf("0:%.2f\n", jogador[i].resultado.tempo.segundos);
            
        }else if(strcmp(jogador[i].modalidade, "1500M Men") == 0 ||
            strcmp(jogador[i].modalidade, "3000M Steeplechase Men") == 0 ||
            strcmp(jogador[i].modalidade, "5000M Men") == 0 ||
            strcmp(jogador[i].modalidade, "800M Men") == 0 ||
            strcmp(jogador[i].modalidade, "10000M Men") == 0 ||
            strcmp(jogador[i].modalidade, "10000M Women") == 0 ||
            strcmp(jogador[i].modalidade, "1500M Women") == 0 ||
            strcmp(jogador[i].modalidade, "3000M Steeplechase Women") == 0 ||
            strcmp(jogador[i].modalidade, "4X400M Relay Women") == 0 ||
            strcmp(jogador[i].modalidade, "5000M Women") == 0 ||
            strcmp(jogador[i].modalidade, "800M Women") == 0){
            
            // Resultado em minutos e segundos
            printf("%d:%.2f\n", jogador[i].resultado.tempo.minutos, jogador[i].resultado.tempo.segundos);
            
        }else if(strcmp(jogador[i].modalidade, "20Km Race Walk Men") == 0 ||
            strcmp(jogador[i].modalidade, "20Km Race Walk Women") == 0 ||
            strcmp(jogador[i].modalidade, "50Km Race Walk Men") == 0 ||
            strcmp(jogador[i].modalidade, "Marathon Men") == 0 || 
            strcmp(jogador[i].modalidade, "Marathon Women") == 0){
            
            // Resultado em horas, minutos e segundos
            printf("%d:%d:%.1f\n", jogador[i].resultado.tempo.hora, jogador[i].resultado.tempo.minutos, jogador[i].resultado.tempo.segundos);
            
        }else if(strcmp(jogador[i].modalidade, "Decathlon Men") == 0 ||
            strcmp(jogador[i].modalidade, "Discus Throw Men") == 0 ||
            strcmp(jogador[i].modalidade, "Hammer Throw Men") == 0 ||
            strcmp(jogador[i].modalidade, "High Jump Men") == 0 ||
            strcmp(jogador[i].modalidade, "Javelin Throw Men") == 0 ||
            strcmp(jogador[i].modalidade, "Long Jump Men") == 0 ||
            strcmp(jogador[i].modalidade, "Pole Vault Men") == 0 ||
            strcmp(jogador[i].modalidade, "Shot Put Men") == 0 ||
            strcmp(jogador[i].modalidade, "Triple Jump Men") == 0 ||
            strcmp(jogador[i].modalidade, "Discus Throw Women") == 0 ||
            strcmp(jogador[i].modalidade, "Hammer Throw Women") == 0 ||
            strcmp(jogador[i].modalidade, "Heptathlon Women") == 0 ||
            strcmp(jogador[i].modalidade, "High Jump Women") == 0 ||
            strcmp(jogador[i].modalidade, "Javelin Throw Women") == 0 ||
            strcmp(jogador[i].modalidade, "Long Jump Women") == 0 ||
            strcmp(jogador[i].modalidade, "Pole Vault Women") == 0 ||
            strcmp(jogador[i].modalidade, "Shot Put Women") == 0 ||
            strcmp(jogador[i].modalidade, "Triple Jump Women") == 0){
            
            // Resultado em distância ou pontos
            printf("%.2f\n", jogador[i].resultado.distancia);
            
        }else{
            printf("NULL\n"); // Imprime NULL se nenhum resultado válido for encontrado
        }

        printf("\n");
    }
}

void SalvaBinario(Medalha* atletas, int tamanho){

    FILE *medalhasFile;

        medalhasFile = fopen("medalhas.bin", "wb");
        if(medalhasFile == NULL){
            perror("Erro ao criar arquivo binário \"medalhas.bin\" !\n");
            exit(1);
        }

        fwrite(atletas, sizeof(Medalha), tamanho, medalhasFile);
        printf("Todas as informações foram transferidas com sucesso no arquivo \"medalhas.bin\"!\n");

        fclose(medalhasFile);
}