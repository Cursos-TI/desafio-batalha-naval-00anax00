#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    // Declaração da matriz (tabuleiro 10x10)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // Navio horizontal
    int navioHorizontal[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int linhaH = 2;  // Linha onde será posicionado
    int colunaH = 4; // Coluna inicial

    // Verifica se cabe no tabuleiro horizontalmente
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica se há sobreposição
        int podeColocar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != VALOR_AGUA) {
                podeColocar = 0;
                break;
            }
        }

        if (podeColocar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
            }
        } else {
            printf("Erro: sobreposição detectada no navio horizontal!\n");
        }
    } else {
        printf("Erro: navio horizontal fora dos limites do tabuleiro.\n");
    }

    // Navio vertical
    int navioVertical[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int linhaV = 5;  // Linha inicial
    int colunaV = 6; // Coluna onde será posicionado

    // Verifica se cabe no tabuleiro verticalmente
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        // Verifica se há sobreposição
        int podeColocar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != VALOR_AGUA) {
                podeColocar = 0;
                break;
            }
        }

        if (podeColocar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            }
        } else {
            printf("Erro: sobreposição detectada no navio vertical!\n");
        }
    } else {
        printf("Erro: navio vertical fora dos limites do tabuleiro.\n");
    }

    // Exibe o tabuleiro final
    printf("\nTabuleiro Final:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
