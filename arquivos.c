#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "arquivos.h"
#include "funcoes.h"

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
            tamanho++; // VERIFICA O TANTO DE LINHAS(ATLETAS);
        }
    } tamanho++;
    
    fclose(arquivos);
    return tamanho;
} //CONTA LINHAS DO PROGRAMA;

void SalvaAtletas(Medalha* jogador, int tamanho){

    FILE* arquivocsv = fopen("medalhas.csv", "r");
    if(arquivocsv == NULL){
        perror("Erro ao ler arquivo csv!\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        char resultadoTipo[20];

        fscanf(arquivocsv, " %c, %[^,], %[^,], %i, %c, %[^,], %[^,], %[^\n]",
            &jogador[i].genero,
            jogador[i].modalidade,
            jogador[i].cidade,
            &jogador[i].ano_da_conquista,
            &jogador[i].tipo_medalha,
            jogador[i].nome_atleta,
            jogador[i].pais_origem,
            &resultadoTipo
        );

                if(strcmp(resultadoTipo, "None") == 0){
            jogador[i].resultado.distancia = 0;
        }else{
        // SEGUNDOS
            if(
            strcmp(jogador[i].modalidade, "100M Men") == 0 || 
            strcmp(jogador[i].modalidade, "110M Hurdles Men") ||
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
            strcmp(jogador[i].modalidade, "4X100M Relay Women") == 0
            ){
                sscanf(resultadoTipo, "%f", 
                &jogador[i].resultado.tempo.segundos);
            }

        // MINUTOS E SEGUNDOS
        
            if(
            strcmp(jogador[i].modalidade, "1500M Men") == 0 ||
            strcmp(jogador[i].modalidade, "3000M Steeplechase Men") == 0 ||
            strcmp(jogador[i].modalidade, "5000M Men") == 0 ||
            strcmp(jogador[i].modalidade, "800M Men") == 0 ||
            strcmp(jogador[i].modalidade, "10000M Men") == 0 ||
            strcmp(jogador[i].modalidade, "10000M Women") == 0 ||
            strcmp(jogador[i].modalidade, "1500M Women") == 0 ||
            strcmp(jogador[i].modalidade, "3000M Steeplechase Women") == 0 ||
            strcmp(jogador[i].modalidade, "4X400M Relay Women") == 0 ||
            strcmp(jogador[i].modalidade, "5000M Women") == 0 ||
            strcmp(jogador[i].modalidade, "800M Women") == 0)
            {
                sscanf(resultadoTipo, "%d:%f",
                &jogador[i].resultado.tempo.minutos, 
                &jogador[i].resultado.tempo.segundos);
            }

        // HORAS, MINUTOS E SEGUNDOS

            if(
            strcmp(jogador[i].modalidade, "20Km Race Walk Men") == 0 ||
            strcmp(jogador[i].modalidade, "20Km Race Walk Women") == 0 ||
            strcmp(jogador[i].modalidade, "50Km Race Walk Men") == 0 ||
            strcmp(jogador[i].modalidade, "Marathon Men") == 0 || 
            strcmp(jogador[i].modalidade, "Marathon Women") == 0)
            {
                sscanf(resultadoTipo, "%d:%d:%f",
                &jogador[i].resultado.tempo.hora,
                &jogador[i].resultado.tempo.minutos,
                &jogador[i].resultado.tempo.segundos);
            }

        // DISTANCIA / PONTOS

            if(
            strcmp(jogador[i].modalidade, "Decathlon Men") == 0 ||
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
            strcmp(jogador[i].modalidade, "Triple Jump Women") == 0)
            {
                sscanf(resultadoTipo, "%f",
                &jogador[i].resultado.distancia);
            }
        }
    }

    fclose(arquivocsv);
    
} // SALVA OS ATLETAS;

void ListaAtletas(Medalha* jogador, int tamanho){
    for (int i = 0; i < tamanho; i++) {
        printf("Atleta %d: ", i + 1);
        printf("%c, ", jogador[i].genero);
        printf("%s, ", jogador[i].modalidade);
        printf("%s, ", jogador[i].cidade);
        printf("%d, ", jogador[i].ano_da_conquista);
        printf("%c, ", jogador[i].tipo_medalha);
        printf("%s, ", jogador[i].nome_atleta);
        printf("%s, ", jogador[i].pais_origem);
        
        // Verificar o tipo de resultado e imprimir de acordo
        if (jogador[i].resultado.distancia) {
            printf("%.2f\n", jogador[i].resultado.distancia);
        }else if(jogador[i].resultado.tempo.segundos){
            printf("%.2f\n", jogador[i].resultado.tempo.minutos);
        } else if (jogador[i].resultado.tempo.segundos && jogador[i].resultado.tempo.minutos) {
            printf("%d:%.2f\n", jogador[i].resultado.tempo.minutos, jogador[i].resultado.tempo.segundos);
        } else if (jogador[i].resultado.tempo.segundos && jogador[i].resultado.tempo.minutos && jogador[i].resultado.tempo.segundos) {
            printf("%d:%d:%.2f\n", jogador[i].resultado.tempo.hora, jogador[i].resultado.tempo.minutos, jogador[i].resultado.tempo.segundos);
        }

        printf("\n");
    }
} // LISTA OS ATLETAS;