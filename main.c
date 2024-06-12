#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "arquivos.h"
#include "funcoes.h"

/* Defina uma estrutura Medalha contendo: Código (contador inteiro), Gênero (char),
Modalidade(string), Cidade(string), Ano(int), Tipo Medalha GBS(char), Nome
Atleta(string), Pais Origem (string), Resultado (?). Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) as medalhas obtidas por cada atleta. Essa relação
deve aumentar e diminuir dinamicamente;
*/

int feedback;

int main() {

    int opcao;
    int tamanho = 0;
    tamanho = ContaLinhas("medalhas.csv");
    printf("Jogadores: %i\n", tamanho); // APAGAR

    Medalha* atletas = (Medalha*) malloc (tamanho * sizeof(Medalha));
    if(atletas == NULL){
        perror("Erro ao alocar memória!\n");
        exit(1);
    }

    SalvaAtletas(atletas, tamanho); // SALVA OS ATLETAS NA VARIAVEL ATLETAS

    do{ 
        char temporaryvar[30];
        int linha;
        char novamedalha;

        printf("Cadastro de Jogadores!\n");
        printf("1- Inserir jogador\n");
        printf("2- Listar jogadores\n");
        printf("3- Pesquisar jogadores\n");
        printf("4- Alterar jogadores\n");
        printf("5- Excluir jogadores\n");
        printf("6- Alterar Jogador\n");
        printf("7- Alterar Medalhas\n"); // MANUTENÇÃO
        printf("8- Excluir Medalhas\n");
        printf("9- Tabela de medalhas\n");
        printf("0 - Sair do programa\n");

        scanf("%i", &opcao);
        setbuf(stdin, NULL);

        switch (opcao){
        case 1:
            LimpaTela();
            InserirJogador();
            break;
        case 2: 
            LimpaTela();
            ListaAtletas(atletas, tamanho);
            break;
        case 3:
            LimpaTela();
            PesquisarJogador(atletas, tamanho);
            break;
        case 4: 
            LimpaTela();
            InserirAtleta("medalhas.csv", tamanho);
            printf("Medalha inserida com sucesso!\n");
            break;
        case 5: 
            LimpaTela();
            printf("Digite o nome do atleta que deseja excluir: ");
            LeString(temporaryvar, 28);
            ExcluirJogador("medalhas.csv", temporaryvar, tamanho);
            break;
        case 6:
//            AlterarJogador(atletas, tamanho);
            break;
        case 7:
            LimpaTela();
            printf("Digite a linha que você quer alterar: ");
            scanf("%i", &linha);
            setbuf(stdin, NULL);
            printf("Digite a nova medalha: ");
            scanf(" %c", &novamedalha);
            setbuf(stdin, NULL);
            AlterarMedalha(tamanho, linha, novamedalha);
            break;  
        case 8:
            LimpaTela();
            printf("Qual atleta vai ter a medalha excluida?\n");
            printf("Digite: ");
            scanf("%i", &linha);
            setbuf(stdin, NULL);
            ExcluirMedalha(tamanho, linha);
            break;
        case 9:
            LimpaTela();
            TabeladeMedalhas();
            break;
        case 0:
            LimpaTela();
            printf("Finalizando programa!\n Obrigado por utilizar!\n");
            printf("Deixe um feedback: (0 a 10)\n");
            scanf("%i", &feedback);
            printf("Muito obrigado! Até logo...\n\n");
//            Feedback();
            break;
        default:
            LimpaTela();
            printf("Nenhum valor válido foi digitado!\n");
            break;
        }
    } while (opcao != 0);

    free(atletas); // Liberar memória alocada

    return 0;
}

//   rewind(medalhasCSV); // VOLTA O PONTEIRO DO ARQUIVO PARA O INICIO

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
