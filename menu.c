#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"
#include "myatletas.h"
#include "menu.h"

const char* ModalidadeMasculina(int opcao){

    printf("1 - 10000M Men \n2 - 100M Men\n3 - 110M Hurdles Men\n4 - 1500M Men\n5 - 200M Men\n6 - 20Km Race Walk Men\n7 - 3000M Steeplechase Men\n8 - 400M Hurdles Men\n9 - 400M Men\n10 - 4X100M Relay Men\n11 - 4X400 Relay Men\n12 - 5000M Men\n13 - 50Km Race Walk Men\n14 - 800M Men\n15 - Decathlon Men\n16 - Discus Throw Men\n17 - Hammer Throw Men\n18 - High Jump Men\n19 - Javelin Throw Men\n20 - Long Jump Men\n21 - Marathon Men\n22 - Pole Vault Men\n23 - Shot Put Men\n24 - Triple Jump Men\n");
    do{
        printf("Opcao: ");
        scanf("%i", &opcao);
        setbuf(stdin, NULL);
        if (opcao < 1 || opcao > 24) {
            printf("Opção inválida, escolha novamente!\n");
        }
    } while(opcao < 1 || opcao > 24);

    switch (opcao) {
        case 1: return "10000M Men";
        case 2: return "100M Men";
        case 3: return "110M Hurdles Men";
        case 4: return "1500M Men";
        case 5: return "200M Men";
        case 6: return "20Km Race Walk Men";
        case 7: return "3000M Steeplechase Men";
        case 8: return "400M Hurdles Men";
        case 9: return "400M Men";
        case 10: return "4X100M Relay Men";
        case 11: return "4X400 Relay Men";
        case 12: return "5000M Men";
        case 13: return "50Km Race Walk Men";
        case 14: return "800M Men";
        case 15: return "Decathlon Men";
        case 16: return "Discus Throw Men";
        case 17: return "Hammer Throw Men";
        case 18: return "High Jump Men";
        case 19: return "Javelin Throw Men";
        case 20: return "Long Jump Men";
        case 21: return "Marathon Men";
        case 22: return "Pole Vault Men";
        case 23: return "Shot Put Men";
        case 24: return "Triple Jump Men";
        default: return NULL;
    }
}

const char* ModalidadeFeminina(int opcao){

    printf("1 - 10000M Women \n2 - 100M Women\n3 - 1500M Women\n4 - 200M Women\n5 - 20Km Race Walk Women\n6 - 3000M Steeplechase Women\n7 - 400M Hurdles Women\n8 - 400M Women\n9 - 4X100M Relay Women\n10 - 4X400 Relay Women\n11 - 5000M Women\n12 - 800M Women\n13 - Discus Throw Women\n14 - Hammer Throw Women\n15 - High Jump Women\n16 - Javelin Throw Women\n17 - Long Jump Women\n18 - Marathon Women\n19 - Pole Vault Women\n20 - Shot Put Women\n21 - Triple Jump Women\n22 - 100M Hurdles Women\n23 - Heptathlon Women\n");
    do {
        printf("Opcao: ");
        scanf("%i", &opcao);
        setbuf(stdin, NULL);
        if (opcao < 1 || opcao > 23) {
            printf("Opção inválida, escolha novamente!\n");
        }
    } while (opcao < 1 || opcao > 23);

    switch (opcao) {
        case 1: return "10000M Women";
        case 2: return "100M Women";
        case 3: return "1500M Women";
        case 4: return "200M Women";
        case 5: return "20Km Race Walk Women";
        case 6: return "3000M Steeplechase Women";
        case 7: return "400M Hurdles Women";
        case 8: return "400M Women";
        case 9: return "4X100M Relay Women";
        case 10: return "4X400 Relay Women";
        case 11: return "5000M Women";
        case 12: return "800M Women";
        case 13: return "Discus Throw Women";
        case 14: return "Hammer Throw Women";
        case 15: return "High Jump Women";
        case 16: return "Javelin Throw Women";
        case 17: return "Long Jump Women";
        case 18: return "Marathon Women";
        case 19: return "Pole Vault Women";
        case 20: return "Shot Put Women";
        case 21: return "Triple Jump Women";
        case 22: return "100M Hurdles Women";
        case 23: return "Heptathlon Women";
        default: return NULL;
    }
}

void AlterarCadastros(Medalha* jogador, int tamanho, int codigo) {
    int posicao = -1;

    // Procura o jogador
    for (int i = 0; i < tamanho; i++){
        if (jogador[i].codigo == codigo){
            posicao = i;
            break;
        }
    }

    // Verifica se o jogador foi encontrado
    if (posicao != -1){
        int opcaotemporaria;
        int chooseoption;

        do {
            printf("O que você deseja mudar?\n");
            printf("1- Gênero\n2- Modalidade\n3- Cidade\n4- Ano\n5- Medalha\n6- Nome\n7- País\n0 - Sair\n Opção: ");
            do {
                scanf("%d", &opcaotemporaria);
                setbuf(stdin, NULL);
            } while (opcaotemporaria < 0 || opcaotemporaria > 7);
            printf("\n");

            switch (opcaotemporaria) {
                case 1:
                    do {
                        printf("M - MASCULINO | W - FEMININO\n");
                        printf("Digite o novo gênero: ");
                        scanf(" %c", &jogador[posicao].genero);
                        jogador[posicao].genero = toupper(jogador[posicao].genero);
                        setbuf(stdin, NULL);
                    }while (jogador[posicao].genero != 'W' && jogador[posicao].genero != 'M');
                    printf("Alteração de gênero do atleta concluída!\n\n");
                    break;
                case 2:
                    printf("Escolha a nova modalidade!\n");
                    if (jogador[posicao].genero = 'W'){
                        strcpy(jogador[posicao].modalidade, ModalidadeFeminina(chooseoption));
                    } else if(jogador[posicao].genero = 'M'){
                        strcpy(jogador[posicao].modalidade, ModalidadeMasculina(chooseoption));
                    }
                    printf("Alteração de modalidade do atleta concluída!\n\n");
                    break;
                case 3:
                    printf("Digite a nova cidade: ");
                    LeString(jogador[posicao].cidade, 29);
                    printf("Alteração de cidade do atleta concluída!\n\n");
                    break;
                case 4:
                    do {
                        printf("Digite o novo ano da competição: ");
                        scanf("%d", &jogador[posicao].ano_da_conquista);
                        setbuf(stdin, NULL);
                    } while((jogador[posicao].ano_da_conquista % 4) != 0);
                    printf("Alteração de ano do atleta concluída!\n\n");
                    break;
                case 5:
                    do {
                        printf("G > Gold | S > Silver | B > Bronze\n");
                        printf("Digite a nova medalha: ");
                        scanf(" %c", &jogador[posicao].tipo_medalha);
                        setbuf(stdin, NULL);
                    } while (jogador[posicao].tipo_medalha != 'S' && jogador[posicao].tipo_medalha != 'B' && jogador[posicao].tipo_medalha != 'G');
                    printf("Alteração de medalha do atleta concluída!\n\n");
                    break;
                case 6:
                    printf("Digite o novo nome: ");
                    LeString(jogador[posicao].nome_atleta, 29);
                    printf("Alteração de nome do atleta concluída!\n\n");
                    break;
                case 7:
                    printf("Digite o novo país (EX: FRA): ");
                    LeString(jogador[posicao].pais_origem, 4);
                    printf("Alteração de país do atleta concluída!\n\n");
                    break;
                case 0:
                    LimpaTela();
                    printf("Voltando para o Menu Inicial!\n\n");
                    break;
                default:
                    printf("Opção inválida!\n\n");
                    break;
            }
        } while (opcaotemporaria != 0);
    } else {
        printf("Jogador não encontrado!\n");
    }
}

void InserirJogador(Medalha** jogador, int* tamanho) {
    int chooseoption;

    printf("Você deseja adicionar um novo jogador?\n");
    do {
        printf("1 - Sim!\n");
        printf("2 - Não\n");
        printf("Opcao: ");
        scanf("%i", &chooseoption);
        setbuf(stdin, NULL);
        if (chooseoption > 2 || chooseoption < 1) {
            printf("Digite uma opção válida!\n");
        }
    } while (chooseoption > 2 || chooseoption < 1);

    if (chooseoption == 1){
        while (1) {
            (*tamanho)++;
            *jogador = (Medalha*)realloc(*jogador, (*tamanho) * sizeof(Medalha));
            if (*jogador == NULL) {
                perror("Erro ao realocar vetor dos atletas!\n");
                exit(1);
            } else {
                printf("Vetor dos atletas realocado para %i\n", *tamanho);
            }
            printf("Digite o nome do(a) atleta %i (\"fim\") para terminar!\n", *tamanho);
            printf("Nome: ");
            LeString((*jogador)[*tamanho - 1].nome_atleta, 29);
            if (strcmp((*jogador)[*tamanho - 1].nome_atleta, "fim") == 0) {
                (*tamanho)--;
                *jogador = (Medalha*)realloc(*jogador, (*tamanho) * sizeof(Medalha));
                if (*jogador == NULL) {
                    perror("Erro ao realocar vetor dos atletas!\n");
                    exit(1);
                } else {
                    printf("Vetor de atletas realocado para %i!\n", *tamanho);
                    printf("Retornando...\n");
                    return;
                }
            } else {
                do {
                    printf("M - MASCULINO | W - FEMININO\n");
                    printf("Digite o genero do(a) atleta \"%s\": ", (*jogador)[*tamanho - 1].nome_atleta);
                    scanf(" %c", &(*jogador)[*tamanho - 1].genero);
                    setbuf(stdin, NULL);
                    if (tolower((*jogador)[*tamanho - 1].genero) != 'm' && tolower((*jogador)[*tamanho - 1].genero) != 'w') {
                        printf("Digite um gênero válido!\n");
                    }
                } while (tolower((*jogador)[*tamanho - 1].genero) != 'm' && tolower((*jogador)[*tamanho - 1].genero) != 'w');
                (*jogador)[*tamanho - 1].genero = toupper((*jogador)[*tamanho - 1].genero);

                printf("Escolha a modalidade do(a) atleta \"%s\"!\n", (*jogador)[*tamanho - 1].nome_atleta);
                if ((*jogador)[*tamanho - 1].genero == 'M') {
                    strcpy((*jogador)[*tamanho - 1].modalidade, ModalidadeMasculina(chooseoption));
                } else if ((*jogador)[*tamanho - 1].genero == 'W') {
                    strcpy((*jogador)[*tamanho - 1].modalidade, ModalidadeFeminina(chooseoption));
                }

                printf("Digite a cidade do(a) atleta \"%s\"!\n", (*jogador)[*tamanho - 1].nome_atleta);
                printf("Cidade: ");
                LeString((*jogador)[*tamanho - 1].cidade, 29);

                (*jogador)[*tamanho - 1].codigo = *tamanho; 

                printf("Digite a sigla do pais do atleta \"%s\" (Ex: BRA)\n", (*jogador)[*tamanho - 1].nome_atleta);
                printf("Sigla: ");
                LeString((*jogador)[*tamanho - 1].pais_origem, 4);

                do{
                    printf("Digite o ano da competição: ");
                    scanf("%i", &(*jogador)[*tamanho - 1].ano_da_conquista);
                    setbuf(stdin, NULL);
                    if ((*jogador)[*tamanho - 1].ano_da_conquista % 4 != 0) {
                        printf("Você não digitou uma edição válida!\nDigite novamente!\n");
                    }
                } while((*jogador)[*tamanho - 1].ano_da_conquista % 4 != 0);

                do{
                    printf("G - GOLD | S - SILVER | B - BRONZE\n");
                    printf("Digite a medalha do(a) atleta \"%s\"!\n", (*jogador)[*tamanho - 1].nome_atleta);
                    printf("Medalha: ");
                    scanf("%c", &(*jogador)[*tamanho - 1].tipo_medalha);
                    setbuf(stdin, NULL); 
                    (*jogador)[*tamanho - 1].tipo_medalha = toupper((*jogador)[*tamanho - 1].tipo_medalha);
                    if ((*jogador)[*tamanho - 1].tipo_medalha != 'G' && (*jogador)[*tamanho - 1].tipo_medalha != 'S' && (*jogador)[*tamanho - 1].tipo_medalha != 'B') {
                        printf("Você não digitou uma medalha válida!\nDigite novamente!\n");
                    }
                } while ((*jogador)[*tamanho - 1].tipo_medalha != 'G' && (*jogador)[*tamanho - 1].tipo_medalha != 'S' && (*jogador)[*tamanho - 1].tipo_medalha != 'B');

                printf("Digite o resultado do(a) atleta \"%s\"!\n", (*jogador)[*tamanho - 1].nome_atleta);
                do{
                    printf("1- Tempo?\n2- Pontos?\n3- Metros?\n");
                    printf("Opcao: ");
                    scanf("%i", &chooseoption);
                    setbuf(stdin, NULL);
                } while (chooseoption > 3 || chooseoption < 1);

                if (chooseoption == 2) {
                    do {
                        printf("Qual foi o resultado em Pontos do atleta: ");
                        scanf("%f", &(*jogador)[*tamanho - 1].resultado.distancia);
                        setbuf(stdin, NULL);
                        if((*jogador)[*tamanho - 1].resultado.distancia < 0){
                            printf("Digitou um valor incorreto!\nDigite novamente!\n");
                        }
                    } while((*jogador)[*tamanho - 1].resultado.distancia < 0);
                }

                if(chooseoption == 3){
                    do{
                        printf("Qual foi o resultado em Metros do atleta: ");
                        scanf("%f", &(*jogador)[*tamanho - 1].resultado.distancia);
                        setbuf(stdin, NULL);
                        if ((*jogador)[*tamanho - 1].resultado.distancia < 0) {
                            printf("Digitou um valor incorreto!\nDigite novamente!\n");
                        }
                    } while((*jogador)[*tamanho - 1].resultado.distancia < 0);
                }

                if (chooseoption == 1){
                    int escolha;
                    printf("Selecione o formato!\n");
                    do{
                        printf("1- HH:MM:SS\n2- MM:SS\n3- SS\n");
                        scanf("%i", &escolha);
                        setbuf(stdin, NULL);
                        if (escolha < 1 || escolha > 3) {
                            printf("Você digitou um valor incorreto!\nDigite novamente!\n");
                        }
                    } while(escolha < 1 || escolha > 3);

                    printf("Digite o tempo\n");
                    if(escolha == 1) {
                            printf("Formato (HH:MM:SS): ");
                            scanf("%d:%d:%f",   &(*jogador)[*tamanho - 1].resultado.tempo.hora,
                                                &(*jogador)[*tamanho - 1].resultado.tempo.minutos,
                                                &(*jogador)[*tamanho - 1].resultado.tempo.segundos);
                            setbuf(stdin, NULL);
                    } else if(escolha == 2) {
                            printf("Formato (MM:SS): ");
                            scanf("%d:%f",  &(*jogador)[*tamanho - 1].resultado.tempo.minutos,
                                            &(*jogador)[*tamanho - 1].resultado.tempo.segundos);
                            setbuf(stdin, NULL);
                    } else if(escolha == 3) {
                            printf("Formato (SS): ");
                            scanf("%f", &(*jogador)[*tamanho - 1].resultado.tempo.segundos);
                            setbuf(stdin, NULL);
                    }
                }
            }
        }

        printf("Atleta adicionado com sucesso!\n");
    } else if(chooseoption == 2) {
        printf("Ok! retornando...\n");
        return;
    }
}

void PesquisarJogador(Medalha* jogador, int tamanho){
    char buscaNome[30];
    printf("Digite o nome do atleta a ser buscado: ");
    LeString(buscaNome, 29);
    printf("\n");

    int encontrado = 0;
    for (int i = 0; i < tamanho; i++){
        if(strcasecmp(buscaNome, jogador[i].nome_atleta) == 0){
            printf("Atleta encontrado!\n");
            printf("Nome: %s\n", jogador[i].nome_atleta);
            printf("Modalidade: %s\n", jogador[i].modalidade);
            printf("Cidade: %s\n", jogador[i].cidade);
            printf("Ano da conquista: %d\n", jogador[i].ano_da_conquista);
            printf("Tipo de medalha: %c\n", jogador[i].tipo_medalha);
            printf("Gênero: %c\n", jogador[i].genero);
            printf("País de origem: %s\n", jogador[i].pais_origem);
            printf("Codigo: %i\n", jogador[i].codigo);

            if(jogador[i].resultado.distancia){
                printf("Resultado: %.2f\n\n", jogador[i].resultado.distancia);
            }else if(jogador[i].resultado.tempo.segundos && jogador[i].resultado.tempo.minutos == 0 && jogador[i].resultado.tempo.hora == 0){
                printf("Tempo: %0.2f\n\n", jogador[i].resultado.tempo.segundos);
            }else if(jogador[i].resultado.tempo.segundos && jogador[i].resultado.tempo.minutos && jogador[i].resultado.tempo.hora){
                printf("Tempo: %d:%d:%0.2f\n\n", jogador[i].resultado.tempo.hora, jogador[i].resultado.tempo.minutos, jogador[i].resultado.tempo.segundos);
            }else if(jogador[i].resultado.tempo.segundos && jogador[i].resultado.tempo.minutos && jogador[i].resultado.tempo.hora == 0){
                printf("Tempo: %d:%0.2f\n\n", jogador[i].resultado.tempo.minutos, jogador[i].resultado.tempo.segundos);
            }
            encontrado = 1;
        }
    }

    if(!encontrado){
        printf("Jogador não encontrado.\n");
    }
}

void AlterarJogador(Medalha* jogador, int tamanho){
    int jogadorEncontrado = 0;
    int maisdeumAtleta = 0;
    int option;
    int codigoatleta;

    char buscaNome[30];
    printf("Alterar dados dos atletas!\n");
    printf("Busca(Nome): ");
    LeString(buscaNome, 29);

    // Inicialização de jogadorrepetido
    Medalha* jogadorrepetido = NULL;

    for(int j = 0; j < tamanho; j++){
        if(strcasecmp(buscaNome, jogador[j].nome_atleta) == 0){
            jogadorEncontrado = 1;
            maisdeumAtleta++;

            // Realocando memória para armazenar os jogadores repetidos
            jogadorrepetido = (Medalha*)realloc(jogadorrepetido, maisdeumAtleta * sizeof(Medalha));
            if(jogadorrepetido == NULL){
                perror("Erro ao realocar memória!\n");
                exit(1);
            }
            jogadorrepetido[maisdeumAtleta - 1] = jogador[j];
        }
    }

    if (maisdeumAtleta > 1){
        printf("Foram encontrados mais de um atleta!\n");
        printf("Escolha uma das opções:\n");

        for(int i = 0; i < maisdeumAtleta; i++){
            printf("%i - NOME: %s | ANO: %d\n", i + 1, jogadorrepetido[i].nome_atleta, jogadorrepetido[i].ano_da_conquista);
        }

        do{
            printf("Opcao: ");
            scanf("%i", &option);
            setbuf(stdin, NULL);
        } while(option < 1 || option > maisdeumAtleta);

        // Exibe detalhes do jogador selecionado
        printf("\nDetalhes do jogador:\n");
        printf("Genero: %c\n", jogadorrepetido[option - 1].genero);
        printf("Modalidade: %s\n", jogadorrepetido[option - 1].modalidade);
        printf("Cidade: %s\n", jogadorrepetido[option - 1].cidade);
        printf("Ano: %d\n", jogadorrepetido[option - 1].ano_da_conquista);
        printf("Medalha: %c\n", jogadorrepetido[option - 1].tipo_medalha);
        printf("Nome: %s\n", jogadorrepetido[option - 1].nome_atleta);
        printf("País: %s\n", jogadorrepetido[option - 1].pais_origem);
        printf("Codigo: %i\n", jogadorrepetido[option - 1].codigo);
        if(jogadorrepetido[option - 1].resultado.distancia){
            printf("Resultado: %.2f\n\n", jogadorrepetido[option - 1].resultado.distancia);
        }else if(jogadorrepetido[option - 1].resultado.tempo.segundos && jogadorrepetido[option - 1].resultado.tempo.minutos == 0 && jogadorrepetido[option - 1].resultado.tempo.hora == 0) {
            printf("Tempo: %.2f\n\n", jogadorrepetido[option - 1].resultado.tempo.segundos);
        }else if(jogadorrepetido[option - 1].resultado.tempo.segundos && jogadorrepetido[option - 1].resultado.tempo.minutos && jogadorrepetido[option - 1].resultado.tempo.hora) {
            printf("Tempo: %d:%d:%.2f\n\n", jogadorrepetido[option - 1].resultado.tempo.hora, jogadorrepetido[option - 1].resultado.tempo.minutos, jogadorrepetido[option - 1].resultado.tempo.segundos);
        }else if(jogadorrepetido[option - 1].resultado.tempo.segundos && jogadorrepetido[option - 1].resultado.tempo.minutos && jogadorrepetido[option - 1].resultado.tempo.hora == 0) {
            printf("Tempo: %d:%.2f\n\n", jogadorrepetido[option - 1].resultado.tempo.minutos, jogadorrepetido[option - 1].resultado.tempo.segundos);
        }

        // Código do jogador
        codigoatleta = jogadorrepetido[option - 1].codigo;

        // Chama a função para alterar os cadastros do jogador
        AlterarCadastros(jogador, tamanho, codigoatleta);
    }else if(maisdeumAtleta == 1){
        printf("Atleta encontrado!\n");
        printf("\nDetalhes do jogador:\n\n");
        printf("Genero: %c\n", jogadorrepetido[0].genero);
        printf("Modalidade: %s\n", jogadorrepetido[0].modalidade);
        printf("Cidade: %s\n", jogadorrepetido[0].cidade);
        printf("Ano: %d\n", jogadorrepetido[0].ano_da_conquista);
        printf("Medalha: %c\n", jogadorrepetido[0].tipo_medalha);
        printf("Nome: %s\n", jogadorrepetido[0].nome_atleta);
        printf("País: %s\n", jogadorrepetido[0].pais_origem);
        printf("Codigo: %i\n", jogadorrepetido[0].codigo);
        if(jogadorrepetido[0].resultado.distancia){
            printf("Resultado: %.2f\n\n", jogadorrepetido[0].resultado.distancia);
        }else if(jogadorrepetido[0].resultado.tempo.segundos && jogadorrepetido[0].resultado.tempo.minutos == 0 && jogadorrepetido[0].resultado.tempo.hora == 0) {
            printf("Tempo: %.2f\n\n", jogadorrepetido[0].resultado.tempo.segundos);
        }else if(jogadorrepetido[0].resultado.tempo.segundos && jogadorrepetido[0].resultado.tempo.minutos && jogadorrepetido[0].resultado.tempo.hora) {
            printf("Tempo: %d:%d:%.2f\n\n", jogadorrepetido[0].resultado.tempo.hora, jogadorrepetido[0].resultado.tempo.minutos, jogadorrepetido[0].resultado.tempo.segundos);
        }else if(jogadorrepetido[0].resultado.tempo.segundos && jogadorrepetido[0].resultado.tempo.minutos && jogadorrepetido[0].resultado.tempo.hora == 0) {
            printf("Tempo: %d:%.2f\n\n", jogadorrepetido[0].resultado.tempo.minutos, jogadorrepetido[0].resultado.tempo.segundos);
        }

        // Código do jogador
        codigoatleta = jogadorrepetido[0].codigo;

        // Chama a função para alterar os cadastros do jogador
        AlterarCadastros(jogador, tamanho, codigoatleta);
    }

    // Libera a memória alocada
    free(jogadorrepetido);

    if(!jogadorEncontrado){
        printf("Jogador não encontrado!\n");
    }
}

void RemoverElemento(Medalha* jogador, int* tamanho){
    int posicao;

    do{
        printf("Escolha a linha a ser removida (%i-%i): ", 1, *tamanho);
        scanf("%i", &posicao);
    } while(posicao < 1 || posicao > *tamanho);

    posicao--; // Reajusta para mexer nas tabelas

    for(int i = posicao; i < *tamanho - 1; i++){
        jogador[i] = jogador[i + 1]; // JOGADOR NA POSIÇÂO I VIRA JOGADOR NA POSIÇÃO I + 1
        jogador[i].codigo--; // AJUSTA CODIGO DO ATLETA
    }

    (*tamanho)--;

    jogador = realloc(jogador, *tamanho * sizeof(Medalha)); 
    if (jogador == NULL && *tamanho > 0){
        perror("Erro ao realocar memória!\n");
        exit(1);
    }

    printf("Vetor de jogadores realocado para %i!\n", *tamanho);
    printf("Linha %i removida com sucesso!\n", posicao + 1);
}

void ExcluirMedalha(Medalha* jogador, int tamanho){
    int linha;

    printf("Digite o código do atleta que terá a sua medalha deletada!\n");
    do{
        printf("Código: ");
        scanf("%i", &linha);
    } while(linha < 0 || linha > tamanho);

    for (int i = 0; i < tamanho; i++){
        if(i == linha-1){
            jogador[i].tipo_medalha = 0; // DELETA MEDALHA
        }
    }

    printf("Medalha do atleta %i, apagada com sucesso!\n", linha);

}

void TabelaDeMedalhas(Medalha* jogador, int tamanho){
  
    int contagempais = 0;
    int contador = 100;
    int totalmedals = 0;

    Medals* medalsrank = (Medals*) malloc(contador * sizeof(Medals));
    if (medalsrank == NULL){
        perror("Erro ao alocar memória para medalsrank!\n");
        exit(1);
    }

    for (int i = 0; i < contador; i++){
        medalsrank[i].gold = 0;
        medalsrank[i].silver = 0;
        medalsrank[i].bronze = 0;
        medalsrank[i].total = 0;
    } // ZERA TODOS OS VETORES

    for (int i = 0; i < tamanho; i++){
        int flag = 0;
        for (int j = 0; j < contagempais; j++){
            if (strcmp(medalsrank[j].pais, jogador[i].pais_origem) == 0){
                flag = 1;
                break;
            }
        } // SE O PAIS JA EXISTIR EM MEDALS RANK NÃO VAI SER ADICIONADO

        if (flag == 0){
            if (contagempais == contador){
                contador *= 2;
                medalsrank = (Medals*) realloc(medalsrank, contador * sizeof(Medals));
                if (medalsrank == NULL) {
                    perror("Erro ao realocar memória!\n");
                    exit(1);
                }
            } // REALOCA VETOR PARA O DOBRO

            strcpy(medalsrank[contagempais].pais, jogador[i].pais_origem);
            for (int k = 0; k < tamanho; k++){
                if (strcmp(jogador[k].pais_origem, medalsrank[contagempais].pais) == 0){
                    if(jogador[k].tipo_medalha == 'G') {
                        medalsrank[contagempais].gold++;
                    }else if (jogador[k].tipo_medalha == 'S'){
                        medalsrank[contagempais].silver++;
                    }else if (jogador[k].tipo_medalha == 'B'){
                        medalsrank[contagempais].bronze++;
                    }
                }
            } // SOMA AS MEDALHAS
            contagempais++; // TROCA DE PAIS
        }
    }

    for (int i = 0; i < contagempais; i++){
        medalsrank[i].total = medalsrank[i].gold + medalsrank[i].silver + medalsrank[i].bronze;
    }
    
    for (int i = 0; i < contagempais; i++){
        totalmedals = totalmedals + medalsrank[i].total;
    }
    

    medalsrank = (Medals*) realloc(medalsrank, contagempais * sizeof(Medals));
    if (medalsrank == NULL) {
        perror("Erro ao realocar memória!\n");
        exit(1);
    } // REALOCA O VETOR PARA O TAMANHO CERTO

    printf("Tabela de Medalhas!\n\n");
    printf("%-4s | %-5s | %-6s | %-6s | %-4s: %d\n", "País", "Gold", "Silver", "Bronze", "TOTAL", totalmedals);
    for (int i = 0; i < contagempais; i++) {
        printf("%-4s | %-5d | %-6d | %-6d | %d\n", medalsrank[i].pais, medalsrank[i].gold, medalsrank[i].silver, medalsrank[i].bronze, medalsrank[i].total);
    }

    free(medalsrank);
    printf("\n");
}

void ExportaCSV(Medalha* atletas, int tamanho){

    int opcao;

    FILE* archivecsv;

    archivecsv = fopen("medalhas.csv", "r");
    if(archivecsv == NULL){
        perror("Erro ao ler arquivo csv!\n");
        exit(1);
    }else{
        printf("O arquivo medalhas.csv já existe!\n");
        do{
            printf("1- Sobrescrever dados\n2- Retornar ao menu!\n");
            printf("Opcao: ");
            scanf("%i", &opcao);
            setbuf(stdin, NULL);
        }while(opcao < 1 || opcao > 2);

        if(opcao == 1){
            archivecsv = fopen("medalhas.csv", "w");
            if(archivecsv == NULL){
                perror("Erro ao alocar memória!\n");
                exit(1);
            }
            printf("Exportando dados para arquivo \"medalhas.csv\"!\n");


            for (int i = 0; i < tamanho; i++){
                fprintf(archivecsv, "%c,%s,%s,%d,%c,%s,%s",
                    atletas[i].genero,
                    atletas[i].modalidade,
                    atletas[i].cidade,
                    atletas[i].ano_da_conquista,
                    atletas[i].tipo_medalha,
                    atletas[i].nome_atleta,
                    atletas[i].pais_origem
                );

                if(i == tamanho-1){
                    if(atletas[i].resultado.distancia){
                        fprintf(archivecsv, ",%.2f", atletas[i].resultado.distancia);
                    }else if(atletas[i].resultado.tempo.segundos && atletas[i].resultado.tempo.minutos == 0 && atletas[i].resultado.tempo.hora == 0) {
                        fprintf(archivecsv, ",%.2f", atletas[i].resultado.tempo.segundos);
                    }else if(atletas[i].resultado.tempo.segundos && atletas[i].resultado.tempo.minutos && atletas[i].resultado.tempo.hora) {
                        fprintf(archivecsv, ",%d:%d:%.2f", atletas[i].resultado.tempo.hora, atletas[i].resultado.tempo.minutos, atletas[i].resultado.tempo.segundos);
                    }else if(atletas[i].resultado.tempo.segundos && atletas[i].resultado.tempo.minutos && atletas[i].resultado.tempo.hora == 0) {
                        fprintf(archivecsv, ",%d:%.2f", atletas[i].resultado.tempo.minutos, atletas[i].resultado.tempo.segundos);
                    }else{
                        fprintf(archivecsv, ", None");
                    }
                }else{
                    if(atletas[i].resultado.distancia){
                        fprintf(archivecsv, ",%.2f\n", atletas[i].resultado.distancia);
                    }else if(atletas[i].resultado.tempo.segundos && atletas[i].resultado.tempo.minutos == 0 && atletas[i].resultado.tempo.hora == 0) {
                        fprintf(archivecsv, ",%.2f\n", atletas[i].resultado.tempo.segundos);
                    }else if(atletas[i].resultado.tempo.segundos && atletas[i].resultado.tempo.minutos && atletas[i].resultado.tempo.hora) {
                        fprintf(archivecsv, ",%d:%d:%.2f\n", atletas[i].resultado.tempo.hora, atletas[i].resultado.tempo.minutos, atletas[i].resultado.tempo.segundos);
                    }else if(atletas[i].resultado.tempo.segundos && atletas[i].resultado.tempo.minutos && atletas[i].resultado.tempo.hora == 0) {
                        fprintf(archivecsv, ",%d:%.2f\n", atletas[i].resultado.tempo.minutos, atletas[i].resultado.tempo.segundos);
                    }else{
                        fprintf(archivecsv, ", None\n");
                    }
                }
            }
        } else if(opcao == 2){
            printf("Ok! Retornando...\n");
            return;
        }
    }

    printf("Os dados foram salvos com sucesso em \"medalhas.csv\"!\n");
    fclose(archivecsv);
}