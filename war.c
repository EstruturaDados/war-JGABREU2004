// ============================================================================
//         PROJETO WAR ESTRUTURADO - DESAFIO DE CÓDIGO
// ============================================================================
//
// INICIANDO O NIVEL INTERMEDIARIO DO JOGO WAR

// inclusão das bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// definindo o tamanho das string
#define TOTAL_MAPA 5
#define TAM_STRING 100

// Criando a estrutura da Struct
struct Territorio {
    char nome [TAM_STRING];
    char cor [TAM_STRING];
    int tropas;
};

// Criando Void para atacar o território.
void atacar(struct Territorio* atacante, struct Territorio* defensor) {
    int dadosAtacante, dadosDefensor;

    // Começando a batalha até que um dos dois territórios fiquem sem tropas.
    while (atacante->tropas > 0 && defensor->tropas > 0) {
    dadosAtacante = (rand() % 6) + 1;
    dadosDefensor = (rand() % 6) + 1;

    printf("\n--- RESULTADO DA BATALHA ---\n");
    printf("O atacante %s rolou um dado e tirou: %d\n", atacante->nome, dadosAtacante);
    printf("O defensor %s rolou um dado e tirou: %d\n", defensor->nome, dadosDefensor);

    // Usando o IF e ELSE para definir quem ganhou a rodada.
    if (dadosAtacante > dadosDefensor) {
        defensor->tropas--;
        printf("VITÓRIA DO ATAQUE! O defensor perdeu uma tropa.\n");             
    } else if (dadosAtacante < dadosDefensor) {
        atacante->tropas--;    
        printf("VITÓRIA DO DEFENSOR! O atacante perdeu uma tropa.\n");
    } else {
        printf("EMPATE! Role o dado novamente.\n");            
    }

    printf("\nPressione ENTER para continuar para o próximo turno...\n");
    getchar();
}
    // Finalizando o jogo e mostrando o resultado final
    if (defensor->tropas <= 0) {
        printf("CONQUISTA! O território %s foi dominado pelo Exército %s.\n", defensor->nome, atacante->cor);
}   else if (atacante->tropas <= 0) {
        printf("CONQUISTA! O território %s foi dominado pelo Exército %s.\n", atacante->nome, defensor->cor);
}
}

// Remove o '\n' deixado pelo fgets, deixando o código mais limpo e rápido
void removerNovaLinha(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

// Função Principal (main) ---
int main() {
    // Criando o ponteiro dinamico
    struct Territorio *mapa;
    int i;

    srand(time(NULL));

    // Usamos malloc para o array
    mapa = (struct Territorio *) malloc (TOTAL_MAPA * sizeof(struct Territorio));

    // VERIFICAÇÂO: É crucial verificar se a alocação da memória deu certo
    if (mapa == NULL) {
        printf("Erro: Falha ao alocar a memória.\n");
        return 1; // Retorna 1 para indicar um erro
    }

    printf("\n===================================================\n");
    printf("          WAR ESTRUTURADO - CADASTRO INICIAL         \n");
    printf("=====================================================\n");

    printf("\nVamos cadastrar os 5 territórios iniciais do nosso mundo.\n");

    // Vamos utilizar o For para poder fazer o loop e poder incluir todos os territorios de uma vez
    for (i = 0 ; i < TOTAL_MAPA; i++) { 

    // Iniciando o cadastro dos territorios
    printf("\n --- Cadastrando Território %d ---\n", i + 1);
    printf("Nome do Território: ");
    fgets(mapa[i].nome, TAM_STRING, stdin); // Usando o fgets e stdin para armazenar e ler os dados
    removerNovaLinha(mapa[i].nome); // Usando o void para remover \n deixado pelo fgets
    printf("Cor do Exército (ex: Azul, Verde): ");
    fgets(mapa[i].cor, TAM_STRING, stdin); // Usando o fgets e stdin para armazenar e ler os dados
    removerNovaLinha(mapa[i].cor); // Usando o void para remover \n deixado pelo fgets
    printf("Número de Tropas: ");
    scanf("%d", &mapa[i].tropas); // Gravando os dados usando o scanf
    getchar(); //Limpa o \n deixado pelo scanf
    }  

    printf("\nCadastro inicial concluído com sucesso!\n\n");

    // Vamos fazer o lopp do jogo WAR.
    while (1) {
        printf("\n===================================================\n");
        printf("            MAPA DO MUNDO - ESTADO ATUAL           \n");
        printf("===================================================\n");

        // Imprimindo o territorio, cor e tropas.
        for (i = 0; i < TOTAL_MAPA; i++) {
            printf("\n%d. %s (Exército %s, Tropas: %d)",
                   i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
        }
        // definindo as variaveis para o ataque.
        int a;
        int d;

        // Vamos para fase de ataque aos territórios.
        printf("\n\n--- FASE DE ATAQUE ---\n\n");
        printf("Escolha o território do atacante (1 a 5, 0 para sair): ");
        scanf("%d", &a);

        if (a == 0)
        break; // Sai do jogo
        
        if (a < 1 || a > TOTAL_MAPA) {
            printf("Número inválido! Tente novamente.\n");
            continue;
        }

        printf("Escolha o território do defensor (1 a 5, 0 para sair): ");
        scanf("%d", &d);
        getchar();

        if (d == 0)
        break;
        
        if (d < 1 || d > TOTAL_MAPA) {
            printf("Número inválido! Tente novamente.\n");
            continue;
        }

        if (a == d) {
            printf("Um território não pode atacar a si mesmo!\n");
            continue;
        }

        atacar(&mapa[a - 1], &mapa[d - 1]);
    }

    free(mapa);
    printf("\n--- JOGO ENCERRADO ---\n");
    printf("Memória liberada, até a próxima...\n");

    return 0;
}