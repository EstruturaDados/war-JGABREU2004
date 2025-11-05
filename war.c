// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//
// INICIANDO O NIVEL NOVATO DO JOGO WAR

// inclusão das bibliotecas
#include <stdio.h>
#include <string.h>

// definindo o tamanho das string
#define TOTAL_MAPA 5
#define TAM_STRING 100

// Criando a estrutura da Struct
struct Territorio {
    char nome [TAM_STRING];
    char cor [TAM_STRING];
    int tropas;
};

// Remove o '\n' deixado pelo fgets, deixando o código mais limpo e rápido
void removerNovaLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Função Principal (main) ---
int main() {

    struct Territorio mapa [TOTAL_MAPA]; // Utilizando a Struct e definindo a variavel i
        int i;

    printf("\n===================================================\n");
    printf("          WAR ESTRUTURADO - CADASTRO INICIAL         \n");
    printf("=====================================================\n");

    printf("\nVamos cadastrar os 5 territorios iniciais do nosso mundo.\n");

    // Vamos utilizar o For para poder fazer o loop e poder incluir todos os territorios de uma vez
    for (i = 0 ; i < TOTAL_MAPA; i++) { 

    // Iniciando o cadastro dos territorios
    printf("\n --- Cadastrando Territorio %d ---\n", i + 1);
    printf("Nome do Territorio: ");
    fgets(mapa[i].nome, TAM_STRING, stdin); // Usando o fgets e stdin para armazenar e ler os dados
    removerNovaLinha(mapa[i].nome); // Usando o void para remover \n deixado pelo fgets
    printf("Cor do Exercito (ex: Azul, Verde): ");
    fgets(mapa[i].cor, TAM_STRING, stdin); // Usando o fgets e stdin para armazenar e ler os dados
    removerNovaLinha(mapa[i].cor); // Usando o void para remover \n deixado pelo fgets
    printf("Numero de Tropas: ");
    scanf("%d", &mapa[i].tropas); // Gravando os dados usando o scanf
    getchar(); //Limpa o \n deixado pelo scanf
    }  

    printf("\nCadastro inicial concluido com sucesso!\n\n");

    printf("===================================================\n");
    printf("            MAPA DO MUNDO - ESTADO ATUAL           \n");
    printf("===================================================\n\n");

    // Vamos utilizar o For para poder fazer o loop e listar todos os territorios inseridos de uma vez
    for (i = 0 ; i < TOTAL_MAPA; i++) {
    
    // Iniciando a impressão do resultado
    printf("TERRITORIO %d\n", i + 1);
    printf("  - Nome: %s\n", mapa[i].nome);
    printf("  - Dominado por: Exercito %s\n", mapa[i].cor);
    printf("  - Tropas: %d\n\n", mapa[i].tropas);
    }
    
return 0; // Finalizando o jogo War
}