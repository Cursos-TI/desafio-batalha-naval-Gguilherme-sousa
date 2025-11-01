#include <stdio.h>

#define TAM 10     // Tamanho do tabuleiro 10x10
#define NAVIO 3    // Valor que representa o navio
#define TAM_NAVIO 3 // Cada navio ocupa 3 posições

int main() {
    int tabuleiro[TAM][TAM]; // Matriz do tabuleiro
    int i, j;

    // --- Inicializa o tabuleiro com 0 (água) ---
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // --- Declara os navios ---
    int navioHorizontal[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};
    int navioVertical[TAM_NAVIO] = {NAVIO, NAVIO, NAVIO};

    // --- Define as posições iniciais (linha, coluna) ---
    int linhaH = 2; // Navio horizontal começará na linha 2
    int colunaH = 4; // e na coluna 4

    int linhaV = 5; // Navio vertical começará na linha 5
    int colunaV = 7; // e na coluna 7

    // --- Validação simples dos limites ---
    if (colunaH + TAM_NAVIO <= TAM && linhaV + TAM_NAVIO <= TAM) {
        // --- Posiciona o navio horizontal ---
        for (i = 0; i < TAM_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }

        // --- Posiciona o navio vertical ---
        for (i = 0; i < TAM_NAVIO; i++) {
            // Verifica se não há sobreposição
            if (tabuleiro[linhaV + i][colunaV] == 0) {
                tabuleiro[linhaV + i][colunaV] = navioVertical[i];
            } else {
                printf("Erro: sobreposição de navios detectada!\n");
                return 1; // Encerra o programa
            }
        }

        // --- Exibe o tabuleiro ---
        printf("\n=== TABULEIRO BATALHA NAVAL ===\n\n");
        for (i = 0; i < TAM; i++) {
            for (j = 0; j < TAM; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Erro: coordenadas inválidas. O navio ultrapassa o limite do tabuleiro.\n");
    }

    return 0;
}
