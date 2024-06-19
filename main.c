#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#include "myatletas.h"
#include "menu.h"

/* Defina uma estrutura Medalha contendo: Código (contador inteiro), Gênero (char),
Modalidade(string), Cidade(string), Ano(int), Tipo Medalha GBS(char), Nome
Atleta(string), Pais Origem (string), Resultado (?). Deverá permitir cadastrar
(inserir/listar/pesquisar/alterar/excluir) as medalhas obtidas por cada atleta. Essa relação
deve aumentar e diminuir dinamicamente;
*/

int feedback;

int main() {

    LimpaTela();

    int opcao;
    int tamanho = 0;
    
    FILE* binorcsv = fopen("medalhas.bin", "rb");
    if(binorcsv == NULL){
        tamanho = ContaLinhas("medalhas.csv");
    }else{
        tamanho = getFileSize("medalhas.bin")/sizeof(Medalha);
    }

    Medalha* atletas = (Medalha*) malloc (tamanho * sizeof(Medalha));
    if(atletas == NULL){
        perror("Erro ao alocar memória!\n");
        exit(1);
    }

    SalvaAtletas(atletas, tamanho); // SALVA OS ATLETAS NA VARIAVEL ATLETAS

    do{ 
        printf("Cadastro de Jogadores!\n");
        printf("1- Inserir jogador\n");
        printf("2- Listar jogadores\n");
        printf("3- Pesquisar jogadores\n");
        printf("4- Alterar jogadores\n");
        printf("5- Excluir jogadores\n");
        printf("6- Excluir Medalhas\n");
        printf("7- Tabela de medalhas\n");
        printf("0 - Sair do programa\n");
        printf("Opcao: ");

        scanf("%i", &opcao);
        setbuf(stdin, NULL);

        switch (opcao){
        case 1:
            LimpaTela();
            InserirJogador(&atletas, &tamanho) ;
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
            AlterarJogador(atletas, tamanho);
            break;
        case 5:
            LimpaTela();
            RemoverElemento(atletas, &tamanho);
            break;
        case 6:
            LimpaTela();
            ExcluirMedalha(atletas, tamanho);
            break;
        case 7:
            LimpaTela();
            TabelaDeMedalhas(atletas, tamanho);
            break;
        case 0:
            LimpaTela();
            printf("Finalizando programa!\nObrigado pela preferência!\n");
            printf("Deixe um feedback (0 a 10)!\n");
            printf("Feedback: ");
            scanf("%i", &feedback);
            printf("Muito obrigado! Até logo...\n\n");
            SalvaBinario(atletas, tamanho);
            break;
        default:
            LimpaTela();
            printf("Nenhum valor válido foi digitado!\n");
            break;
        }
    } while (opcao != 0);
    
    free(atletas);
    fclose(binorcsv);

    return 0;
}