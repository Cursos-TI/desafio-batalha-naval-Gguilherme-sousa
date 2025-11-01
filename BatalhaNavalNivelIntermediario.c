#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro 10x10
#define NAVIO 3       // Valor que representa o navio
#define TAM_NAVIO 3   // Cada navio ocupa 3 posições

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // --- Inicializa o tabuleiro com 0 (água) ---
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // --- Declara navios (todos com 3 partes) ---
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioDiagonal1[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};  // Diagonal principal (\)
    int navioDiagonal2[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};  // Diagonal secundária (/)

    // --- Coordenadas iniciais dos navios ---
    int linhaH = 1, colunaH = 2;  // Horizontal
    int linhaV = 4, colunaV = 6;  // Vertical
    int linhaD1 = 6, colunaD1 = 1; // Diagonal principal (\)
    int linhaD2 = 2, colunaD2 = 8; // Diagonal secundária (/)

    // --- Validação simples de limites ---
    if (colunaH + TAM_NAVIO <= TAM &&
        linhaV + TAM_NAVIO <= TAM &&
        linhaD1 + TAM_NAVIO <= TAM && colunaD1 + TAM_NAVIO <= TAM &&
        linhaD2 + TAM_NAVIO <= TAM && colunaD2 - (TAM_NAVIO - 1) >= 0) {

        // --- Posiciona o navio horizontal ---
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] == 0)
                tabuleiro[linhaH][colunaH + i] = NAVIO;
            else {
                printf("Erro: sobreposição detectada no navio horizontal!\n");
                return 1;
            }
        }

        // --- Posiciona o navio vertical ---
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == 0)
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            else {
                printf("Erro: sobreposição detectada no navio vertical!\n");
                return 1;
            }
        }

        // --- Posiciona o navio diagonal principal (\) ---
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] == 0)
                tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;
            else {
                printf("Erro: sobreposição detectada na diagonal principal!\n");
                return 1;
            }
        }

        // --- Posiciona o navio diagonal secundária (/) ---
        for (i = 0; i < TAM_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] == 0)
                tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;
            else {
                printf("Erro: sobreposição detectada na diagonal secundária!\n");
                return 1;
            }
        }

        // --- Exibe o tabuleiro ---
        printf("\n=== TABULEIRO BATALHA NAVAL (NÍVEL AVENTUREIRO) ===\n\n");
        for (i = 0; i < TAM; i++) {
            for (j = 0; j < TAM; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }

    } else {
        printf("Erro: coordenadas inválidas. Algum navio ultrapassa o limite do tabuleiro.\n");
    }

    return 0;
}
