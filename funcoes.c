#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"
#include "arquivos.h"
#include "funcoes.h"

#define MAX_PAISES 100

void InserirJogador(){

    Medalha* jogador = (Medalha*) malloc(1 * sizeof(Medalha));
    if (jogador == NULL) {
        perror("Erro ao alocar memória!\n");
        exit(1);
    }

    FILE* arquivo = fopen("medalhas.bin", "r");
    if (arquivo == NULL) {
        FILE* arquivo2 = fopen("medalhas.csv", "a");
        if (arquivo2 == NULL) {
            perror("Erro ao abrir arquivo \"medalhas.csv\"!\n");
            free(jogador);
            exit(1);
        }

        printf("Cadastre um novo jogador\n");

        printf("M - MASCULINO | F - FEMININO\n");
        do {
            printf("Digite o genero do jogador: ");
            scanf(" %c", &jogador[0].genero);  // Espaço antes de %c para consumir whitespace
            jogador[0].genero = toupper(jogador[0].genero);
        } while (jogador[0].genero != 'F' && jogador[0].genero != 'M');

        printf("Digite a modalidade do jogador: ");
        setbuf(stdin, NULL);
        LeString(jogador[0].modalidade, 30);

        printf("Digite o nome da cidade: ");
        LeString(jogador[0].cidade, 30);

        printf("Digite o ano da conquista: ");
        scanf("%d", &jogador[0].ano_da_conquista);
        setbuf(stdin, NULL);

        printf("G - GOLD | S - SILVER | B - BRONZE\n");
        do {
            printf("Digite a medalha do jogador: ");
            scanf(" %c", &jogador[0].tipo_medalha);
            setbuf(stdin, NULL);
            jogador[0].tipo_medalha = toupper(jogador[0].tipo_medalha);
        } while (jogador[0].tipo_medalha != 'G' && jogador[0].tipo_medalha != 'S' && jogador[0].tipo_medalha != 'B');

        printf("Digite o nome do atleta: ");
        LeString(jogador[0].nome_atleta, 30);

        printf("Digite a sigla do PAIS (EX: FRA): ");
        LeString(jogador[0].pais_origem, 4);

        char temporaryvar;
        printf("Resultado: P(pontos), T(tempo), M(distancia): ");
        scanf(" %c", &temporaryvar);
        setbuf(stdin, NULL);
        temporaryvar = toupper(temporaryvar);

        if (temporaryvar == 'P'){
            do {
                printf("Digite os pontos do jogador");
                scanf("%f", &jogador[0].resultado.distancia);
                setbuf(stdin, NULL);
            } while(jogador[0].resultado.distancia < 0);
        } else if(temporaryvar == 'T'){
            char input[20];
            printf("Digite o tempo (HH:MM:SS, MM:SS ou SS): ");
            setbuf(stdin, NULL);
            LeString(input, 20);

            int valuesRead = sscanf(input, "%d:%d:%f", &jogador[0].resultado.tempo.hora, &jogador[0].resultado.tempo.minutos, &jogador[0].resultado.tempo.segundos);

            if(valuesRead == 3){
                printf("Tempo lido: %02dh:%02dm:%05.2fs\n", jogador[0].resultado.tempo.hora, jogador[0].resultado.tempo.minutos, jogador[0].resultado.tempo.segundos);
            } else if (valuesRead == 2){
                jogador[0].resultado.tempo.hora = 0;
                sscanf(input, "%d:%f", &jogador[0].resultado.tempo.minutos, &jogador[0].resultado.tempo.segundos);
                printf("Tempo lido: %02dm:%05.2fs\n", jogador[0].resultado.tempo.minutos, jogador[0].resultado.tempo.segundos);
            } else if(valuesRead == 1){
                jogador[0].resultado.tempo.hora = 0;
                jogador[0].resultado.tempo.minutos = 0;
                jogador[0].resultado.tempo.segundos = atof(input);
                printf("Tempo lido: %05.2fs\n", jogador[0].resultado.tempo.segundos);
            } else {
                printf("Formato de tempo inválido!\n");
            }
        } else if(temporaryvar == 'M'){
            do {
                printf("Digite a distância: ");
                scanf("%f", &jogador[0].resultado.distancia);
                setbuf(stdin, NULL);
            } while(jogador[0].resultado.distancia < 0);
        }

        if (temporaryvar == 'M' || temporaryvar == 'P'){
            fprintf(arquivo2, "\n%c, %s, %s, %d, %c, %s, %s, %.2f",
                    jogador[0].genero,
                    jogador[0].modalidade,
                    jogador[0].cidade,
                    jogador[0].ano_da_conquista,
                    jogador[0].tipo_medalha,
                    jogador[0].nome_atleta,
                    jogador[0].pais_origem,
                    jogador[0].resultado.distancia);
        } else {
            if (jogador[0].resultado.tempo.hora != 0){
                fprintf(arquivo2, "\n%c, %s, %s, %d, %c, %s, %s, %02d:%02d:%05.2f",
                        jogador[0].genero,
                        jogador[0].modalidade,
                        jogador[0].cidade,
                        jogador[0].ano_da_conquista,
                        jogador[0].tipo_medalha,
                        jogador[0].nome_atleta,
                        jogador[0].pais_origem,
                        jogador[0].resultado.tempo.hora,
                        jogador[0].resultado.tempo.minutos,
                        jogador[0].resultado.tempo.segundos);
            } else if(jogador[0].resultado.tempo.minutos != 0){
                fprintf(arquivo2, "\n%c, %s, %s, %d, %c, %s, %s, %02d:%05.2f",
                        jogador[0].genero,
                        jogador[0].modalidade,
                        jogador[0].cidade,
                        jogador[0].ano_da_conquista,
                        jogador[0].tipo_medalha,
                        jogador[0].nome_atleta,
                        jogador[0].pais_origem,
                        jogador[0].resultado.tempo.minutos,
                        jogador[0].resultado.tempo.segundos);
            } else {
                fprintf(arquivo2, "\n%c, %s, %s, %d, %c, %s, %s, %0d:%.2f",
                        jogador[0].genero,
                        jogador[0].modalidade,
                        jogador[0].cidade,
                        jogador[0].ano_da_conquista,
                        jogador[0].tipo_medalha,
                        jogador[0].nome_atleta,
                        jogador[0].pais_origem,
                        jogador[0].resultado.tempo.minutos,
                        jogador[0].resultado.tempo.segundos);
            }
        }

        fclose(arquivo2);
        free(jogador);
    } else {
        arquivo = fopen("medalhas.bin", "ab");
        if(arquivo == NULL){
            perror("Erro ao abrir arquivo \"medalhas.bin\"!\n");
            free(jogador);
            exit(1);
        }

        printf("Deseja cadastrar um novo jogador\n");

        printf("M - MASCULINO | F - FEMININO\n");
        do{
            printf("Digite o genero do jogador: ");
            scanf(" %c", &jogador[0].genero);  // Espaço antes de %c para consumir whitespace
            jogador[0].genero = toupper(jogador[0].genero);
        } while(jogador[0].genero != 'F' && jogador[0].genero != 'M');

        printf("Digite a modalidade do jogador: ");
        setbuf(stdin, NULL);
        LeString(jogador[0].modalidade, 30);

        printf("Digite o nome da cidade: ");
        LeString(jogador[0].cidade, 30);

        printf("Digite o ano da conquista: ");
        scanf("%d", &jogador[0].ano_da_conquista);
        setbuf(stdin, NULL);

        printf("G - GOLD | S - SILVER | B - BRONZE\n");
        do{
            printf("Digite a medalha do jogador: ");
            scanf(" %c", &jogador[0].tipo_medalha);
            setbuf(stdin, NULL);
            jogador[0].tipo_medalha = toupper(jogador[0].tipo_medalha);
        } while(jogador[0].tipo_medalha != 'G' && jogador[0].tipo_medalha != 'S' && jogador[0].tipo_medalha != 'B');

        printf("Digite o nome do atleta: ");
        LeString(jogador[0].nome_atleta, 30);

        printf("Digite a sigla do PAIS (EX: FRA): ");
        LeString(jogador[0].pais_origem, 4);

        char temporaryvar;
        printf("Resultado: P(pontos), T(tempo), M(distancia): ");
        scanf(" %c", &temporaryvar);
        setbuf(stdin, NULL);
        temporaryvar = toupper(temporaryvar);

        if(temporaryvar == 'P'){
            do {
                printf("Digite os pontos do jogador: ");
                scanf("%f", &jogador[0].resultado.distancia);
                setbuf(stdin, NULL);
            } while(jogador[0].resultado.distancia < 0);
        } else if(temporaryvar == 'T'){
            char input[20];
            printf("Digite o tempo (HH:MM:SS, MM:SS ou SS): ");
            setbuf(stdin, NULL);
            LeString(input, 20);

            int valuesRead = sscanf(input, "%d:%d:%f", &jogador[0].resultado.tempo.hora, &jogador[0].resultado.tempo.minutos, &jogador[0].resultado.tempo.segundos);

            if(valuesRead == 3){
                printf("Tempo lido: %02dh:%02dm:%0.2fs\n", jogador[0].resultado.tempo.hora, jogador[0].resultado.tempo.minutos, jogador[0].resultado.tempo.segundos);
            }else if(valuesRead == 2){
                jogador[0].resultado.tempo.hora = 0;
                sscanf(input, "%d:%f", &jogador[0].resultado.tempo.minutos, &jogador[0].resultado.tempo.segundos);
                printf("Tempo lido: %02dm:%0.2fs\n", jogador[0].resultado.tempo.minutos, jogador[0].resultado.tempo.segundos);
            }else if(valuesRead == 1){
                jogador[0].resultado.tempo.hora = 0;
                jogador[0].resultado.tempo.minutos = 0;
                printf("Tempo lido: %0.2fs\n", jogador[0].resultado.tempo.segundos);
            }else{
                printf("Formato de tempo inválido!\n");
            }
        }else if(temporaryvar == 'M'){
            do{
                printf("Digite a distância: ");
                scanf("%f", &jogador[0].resultado.distancia);
                setbuf(stdin, NULL);
            } while(jogador[0].resultado.distancia < 0);
        }

        fwrite(jogador, sizeof(Medalha), 1, arquivo);
        
        fclose(arquivo);
        free(jogador);
    }   
}

void PesquisarJogador(Medalha* jogador, int tamanho){
    char buscaNome[30];
    printf("Digite o nome do atleta a ser buscado: ");
    LeString(buscaNome, 29);

    int encontrado = 0;
    for (int i = 0; i < tamanho; i++) {
        if (strcmp(buscaNome, jogador[i].nome_atleta) == 0){
            printf("Jogador encontrado!\n");
            printf("Nome: %s\n", jogador[i].nome_atleta);
            printf("Modalidade: %s\n", jogador[i].modalidade);
            printf("Cidade: %s\n", jogador[i].cidade);
            printf("Ano da conquista: %d\n", jogador[i].ano_da_conquista);
            printf("Tipo de medalha: %c\n", jogador[i].tipo_medalha);
            printf("Gênero: %c\n", jogador[i].genero);
            printf("País de origem: %s\n", jogador[i].pais_origem);

            if(jogador[i].tipo_medalha == 'P'){
                printf("Pontuação: %.2f\n", jogador[i].resultado.distancia);
            }else if(jogador[i].tipo_medalha == 'T'){
                printf("Tempo: %02d:%02d:%0.2f\n", jogador[i].resultado.tempo.hora, jogador[i].resultado.tempo.minutos, jogador[i].resultado.tempo.segundos);
            }else if(jogador[i].tipo_medalha == 'M'){
                printf("Distância: %.2f\n", jogador[i].resultado.distancia);
            }

            encontrado = 1;
            break;
        }
    }

    if (!encontrado){
        printf("Jogador não encontrado.\n");
    }
}

void AlterarJogador(Medalha* jogador, int tamanho){

    Medalha* atleta = (Medalha*) malloc (tamanho * sizeof(Medalha));
    if(atleta == NULL){
        perror("Erro ao alocar memória\n");
        exit(1);
    }

    char buscaNome[30];
    printf("Digite o nome/número do jogador a ser buscado: ");
    LeString(buscaNome, 29);

    int jogadorEncontrado = 0;
    for (int i = 0; i < tamanho; i++){
        if (strcmp(buscaNome, jogador[i].nome_atleta) == 0) {
            printf("Jogador encontrado! Detalhes do jogador:\n");
            printf("Genero: %c\n", jogador[i].genero);
            printf("Modalidade: %s\n", jogador[i].modalidade);
            printf("Cidade: %s\n", jogador[i].cidade);
            printf("Ano: %d\n", jogador[i].ano_da_conquista);
            printf("Medalha: %c\n", jogador[i].tipo_medalha);
            printf("Nome: %s\n", jogador[i].nome_atleta);
            printf("País: %s\n", jogador[i].pais_origem);
            
            if(jogador[i].tipo_medalha == 'P'){
                printf("Pontuação: %.2f\n", jogador[i].resultado.distancia);
            }else if(jogador[i].tipo_medalha == 'T'){
                printf("Tempo: %02d:%02d:%0.2f\n", jogador[i].resultado.tempo.hora, jogador[i].resultado.tempo.minutos, jogador[i].resultado.tempo.segundos);
            }else if(jogador[i].tipo_medalha == 'M'){
                printf("Distância: %.2f\n", jogador[i].resultado.distancia);
            }

            jogadorEncontrado = 1;
            int opcaotemporaria;

            printf("O que você deseja mudar?\n");
            do{
                printf("1- Genero\n2- Modalidade\n3- Cidade\n4- Ano\n5- Medalha\n6- Nome\n7- Pais\n0 - Sair\n Opcao: ");
                do{
                    scanf("%i", &opcaotemporaria);
                    setbuf(stdin, NULL);
                } while(opcaotemporaria < 0);

                switch (opcaotemporaria)
                {
                case 1:
                    printf("Digite o novo gênero: ");
                    scanf("%c", &jogador[i].genero);
                    setbuf(stdin, NULL);
                    printf("Alteração de gênero do atleta concluida!\n");
                    break;
                case 2:
                    printf("Digite a nova modalidade: ");
                    LeString(jogador[i].modalidade, 29);
                    printf("Alteração de modalidade do atleta concluida!\n");
                    break;
                case 3:
                    printf("Digite a nova cidade: ");
                    LeString(jogador[i].cidade, 29);
                    printf("Alteração de cidade do atleta concluida!\n");
                    break;
                case 4:
                    printf("Digite o novo ano: ");
                    scanf("%i", &jogador[i].ano_da_conquista);
                    setbuf(stdin, NULL);
                    printf("Alteração de ano do atleta concluida!\n");
                    break;
                case 5: 
                    do{
                        printf("Digite a nova medalha: ");
                        scanf("%c", &jogador[i].tipo_medalha);
                        setbuf(stdin, NULL);
                    } while(jogador[i].tipo_medalha != 'S' && jogador[i].tipo_medalha != 'B' && jogador[i].tipo_medalha != 'G');
                    printf("Alteração de medalhas do atleta concluida!\n");
                    break;
                case 6:
                    printf("Digite o novo nome: ");
                    LeString(jogador[i].nome_atleta, 29);
                    printf("Alteração de nome do atleta concluida!\n");
                    break;
                case 7:
                    printf("Digite o novo pais (EX: FRA): ");
                    LeString(jogador[i].pais_origem, 4);
                    printf("Alteração do pais do atleta concluida!\n");
                    break;
                case 0:
                    LimpaTela();
                    printf("Voltando para o Menu Inicial!\n");
                    break;
                default:
                    printf("Você não digitou nenhuma opcão válida!\n");
                    break;
                }
            }while(opcaotemporaria != 0);

            break; 
        }
    }
    if (!jogadorEncontrado){
        printf("Jogador não encontrado!\n");
    }

}

void ExcluirJogador(const char *nomeArquivo, const char *nomeJogador, int tamanho){

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    FILE *temp = fopen("temp.csv", "w");
    if (temp == NULL) {
        fclose(arquivo);
        perror("Erro ao criar o arquivo temporário");
        return;
    }

    char linha[tamanho];
    int encontrado = 0;

    while(fgets(linha, sizeof(linha), arquivo)){
        // Verifica se a linha contém o jogador que queremos excluir
        if(strstr(linha, nomeJogador) != NULL){
            encontrado = 1;
            continue; // Pular a linha a ser excluída
        }
        // Escreve a linha no arquivo temporário
        fputs(linha, temp);
    }

    fclose(arquivo);
    fclose(temp);

    // Renomeia o arquivo temporário para o nome original
    remove(nomeArquivo);
    rename("temp.csv", nomeArquivo);

    if (encontrado){
        printf("Jogador excluído com sucesso.\n");
    } else {
        printf("Jogador não encontrado no arquivo.\n");
    }

    printf("Jogador %s excluido com sucesso!\n", nomeJogador);
}

void InserirAtleta(const char *nomeArquivo, int tamanho){
    
    Medalha novaMedalha;

    printf("Digite o genero do jogador (M/F): ");
    scanf(" %c", &novaMedalha.genero);
    setbuf(stdin, NULL);

    printf("Digite a modalidade: ");
    LeString(novaMedalha.modalidade, tamanho);

    printf("Digite a cidade: ");
    LeString(novaMedalha.cidade, tamanho);

    printf("Digite o ano da conquista: ");
    scanf("%d", &novaMedalha.ano_da_conquista);
    setbuf(stdin, NULL);

    printf("Digite a medalha (G/S/B): ");
    scanf(" %c", &novaMedalha.tipo_medalha);
    setbuf(stdin, NULL);

    printf("Digite o nome do atleta: ");
    LeString(novaMedalha.nome_atleta, tamanho);

    printf("Digite o país (EX: FRA): ");
    LeString(novaMedalha.pais_origem, tamanho);

    if (novaMedalha.tipo_medalha == 'M' || novaMedalha.tipo_medalha == 'P'){
        printf("Digite a distância: ");
        scanf("%f", &novaMedalha.resultado.distancia);
        setbuf(stdin, NULL);
    } else {
        printf("Digite o tempo (HH:MM:SS, MM:SS ou SS): ");
        scanf("%d:%d:%f", &novaMedalha.resultado.tempo.hora, &novaMedalha.resultado.tempo.minutos, &novaMedalha.resultado.tempo.segundos);
        setbuf(stdin, NULL);
    }

    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    fprintf(arquivo, "\n%c,%s,%s,%d,%c,%s,%s",
        novaMedalha.genero,
        novaMedalha.modalidade,
        novaMedalha.cidade,
        novaMedalha.ano_da_conquista,
        novaMedalha.tipo_medalha,
        novaMedalha.nome_atleta,
        novaMedalha.pais_origem);

    if (novaMedalha.tipo_medalha == 'M' || novaMedalha.tipo_medalha == 'P') {
        fprintf(arquivo, ",%.2f", novaMedalha.resultado.distancia);
    } else {
        fprintf(arquivo, ",%02d:%02d:%05.2f",
            novaMedalha.resultado.tempo.hora,
            novaMedalha.resultado.tempo.minutos,
            novaMedalha.resultado.tempo.segundos);
    }

    fclose(arquivo);

    printf("Atleta inserido com sucesso!\n");
}

void AlterarMedalha(int num_linhas, int linha, char novoTipo) {
    // Verificar se o novo tipo é válido
    if (novoTipo != 'S' && novoTipo != 'G' && novoTipo != 'B') {
        printf("Tipo de medalha inválido. Apenas 'S', 'G' ou 'B' são permitidos.\n");
        return;
    }

    // Carregar os registros do arquivo
    FILE* arquivo = fopen("medalhas.csv", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    // Abrir um arquivo temporário para escrita
    FILE* temp = fopen("temp.csv", "w");
    if (temp == NULL) {
        perror("Erro ao criar arquivo temporário");
        fclose(arquivo);
        exit(1);
    }

    Medalha* medalha = (Medalha*) malloc (num_linhas * sizeof(Medalha));
    if(medalha == NULL){
        perror("Erro ao alocar memória!\n");
        exit(1);
    }

    char Resultado[num_linhas][30];

    // Ler e processar cada linha do arquivo
    for (int i = 0; i < num_linhas; i++){
        // Ler uma linha do arquivo original
        if (fscanf(arquivo, " %c, %[^,], %[^,], %i, %c, %[^,], %[^,], %[^\n]",
            &medalha[i].genero,
            medalha[i].modalidade,
            medalha[i].cidade,
            &medalha[i].ano_da_conquista,
            &medalha[i].tipo_medalha,
            medalha[i].nome_atleta,
            medalha[i].pais_origem,
            &Resultado[i]) != 8) {
            fprintf(stderr, "Erro ao ler linha %d do arquivo\n", i + 1);
            fclose(arquivo);
            fclose(temp);
            exit(1);
        }

        // Verificar se estamos na linha que queremos modificar
        if (i+1 == linha){
            // Atualizar o tipo de medalha
            medalha[i].tipo_medalha = novoTipo;
        }

        // Escrever a linha no arquivo temporário
        if(i == num_linhas-1){
            fprintf(temp, "%c,%s,%s,%d,%c,%s,%s,%s", 
            medalha[i].genero, medalha[i].modalidade, medalha[i].cidade,
            medalha[i].ano_da_conquista, medalha[i].tipo_medalha, medalha[i].nome_atleta,
            medalha[i].pais_origem, Resultado[i]);
        }else{
            fprintf(temp, "%c,%s,%s,%d,%c,%s,%s,%s\n", 
                medalha[i].genero, medalha[i].modalidade, medalha[i].cidade,
                medalha[i].ano_da_conquista, medalha[i].tipo_medalha, medalha[i].nome_atleta,
                medalha[i].pais_origem, Resultado[i]);
        }
    }

    // Fechar os arquivos
    fclose(arquivo);
    fclose(temp);

    // Substituir o arquivo original pelo temporário
    remove("medalhas.csv"); // Remove o arquivo original
    rename("temp.csv", "medalhas.csv"); // Renomeia o arquivo temporário para o nome do arquivo original

    printf("Medalha inserida com sucesso!\n");
    free(medalha);
}

void ExcluirMedalha(int num_linhas, int linha) {
    // Carregar os registros do arquivo
    FILE* arquivo = fopen("medalhas.csv", "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    // Abrir um arquivo temporário para escrita
    FILE* temp = fopen("temp.csv", "w");
    if (temp == NULL) {
        perror("Erro ao criar arquivo temporário");
        fclose(arquivo);
        exit(1);
    }

    Medalha* medalha = (Medalha*) malloc (num_linhas * sizeof(Medalha));
    if(medalha == NULL){
        perror("Erro ao alocar memória!\n");
        exit(1);
    }

    char Resultado[num_linhas][30];

    // Ler e processar cada linha do arquivo
    for (int i = 0; i < num_linhas; i++){
        // Ler uma linha do arquivo original
        if (fscanf(arquivo, " %c, %[^,], %[^,], %i, %c, %[^,], %[^,], %[^\n]",
            &medalha[i].genero,
            medalha[i].modalidade,
            medalha[i].cidade,
            &medalha[i].ano_da_conquista,
            &medalha[i].tipo_medalha,
            medalha[i].nome_atleta,
            medalha[i].pais_origem,
            &Resultado[i]) != 8) {
            fprintf(stderr, "Erro ao ler linha %d do arquivo\n", i + 1);
            fclose(arquivo);
            fclose(temp);
            exit(1);
        }

        // Verificar se estamos na linha que queremos modificar
        if (i+1 == linha){
            // Atualizar o tipo de medalha
            medalha[i].tipo_medalha = 0;
        }

        // Escrever a linha no arquivo temporário
        if(i == num_linhas-1){
            fprintf(temp, "%c,%s,%s,%d,%c,%s,%s,%s", 
            medalha[i].genero, medalha[i].modalidade, medalha[i].cidade,
            medalha[i].ano_da_conquista, medalha[i].tipo_medalha, medalha[i].nome_atleta,
            medalha[i].pais_origem, Resultado[i]);
        }else{
            fprintf(temp, "%c,%s,%s,%d,%c,%s,%s,%s\n", 
                medalha[i].genero, medalha[i].modalidade, medalha[i].cidade,
                medalha[i].ano_da_conquista, medalha[i].tipo_medalha, medalha[i].nome_atleta,
                medalha[i].pais_origem, Resultado[i]);
        }
    }

    // Fechar os arquivos
    fclose(arquivo);
    fclose(temp);

    // Substituir o arquivo original pelo temporário
    remove("medalhas.csv"); // Remove o arquivo original
    rename("temp.csv", "medalhas.csv"); // Renomeia o arquivo temporário para o nome do arquivo original

    printf("Medalha excluida com sucesso!\n");
    free(medalha);
}

void TabeladeMedalhas(){
    // Abrir o arquivo de medalhas para leitura
    FILE* arquivo = fopen("medalhas.csv", "r");
    if (arquivo == NULL){
        perror("Erro ao abrir arquivo");
        exit(1);
    }

    Pais paises[MAX_PAISES] = {0}; // Inicializa todas as medalhas com 0

    // Le e processa cada linha do arquivo
    while (!feof(arquivo)){
        char pais[29];
        char medalha;

        // Le o país e o tipo de medalha
        if (fscanf(arquivo, "%*[^,],%*[^,],%[^,],%*d,%c%*[^,]", pais, &medalha) != 2) {
            break; // Sai do loop se não conseguir ler corretamente
        }

        // Encontrar o país na lista de países
        int index = -1;
        for (int i = 0; i < MAX_PAISES; i++) {
            if (strcmp(pais, paises[i].nome) == 0) {
                index = i;
                break;
            }
            else if (paises[i].nome[0] == '\0') {
                index = i;
                strcpy(paises[i].nome, pais);
                break;
            }
        }

        // Incrementar a contagem de medalhas do país correspondente
        if (index != -1) {
            switch (medalha){
                case 'G':
                    paises[index].ouro++;
                    break;
                case 'S':
                    paises[index].prata++;
                    break;
                case 'B':
                    paises[index].bronze++;
                    break;
            }
        } else {
            printf("Limite máximo de países atingido.\n");
            break;
        }
    }

    // Fechar o arquivo
    fclose(arquivo);

    // Imprimir a tabela de medalhas
    printf("País\tOuro\tPrata\tBronze\n");
    for (int i = 0; i < MAX_PAISES; i++){
        if (paises[i].nome[0] != '\0') {
            printf("%s: %d\t%d\t%d\n", paises[i].nome, paises[i].ouro, paises[i].prata, paises[i].bronze);
        }
    }
}