#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro
#define NAVIO 3       // Valor do navio
#define TAM_NAVIO 3   // Tamanho dos navios
#define H 5           // Tamanho das matrizes de habilidade
#define HAB 5         // Valor usado para representar habilidades

int main() {
    int tabuleiro[TAM][TAM];
    int i, j;

    // --- Inicializa o tabuleiro com água (0) ---
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // --- NAVIOS (nível aventureiro) ---
    int linhaH = 1, colunaH = 2;
    int linhaV = 4, colunaV = 6;
    int linhaD1 = 6, colunaD1 = 1;
    int linhaD2 = 2, colunaD2 = 8;

    // --- Posiciona o navio horizontal ---
    for (i = 0; i < TAM_NAVIO; i++) tabuleiro[linhaH][colunaH + i] = NAVIO;

    // --- Posiciona o navio vertical ---
    for (i = 0; i < TAM_NAVIO; i++) tabuleiro[linhaV + i][colunaV] = NAVIO;

    // --- Posiciona o navio diagonal principal (\) ---
    for (i = 0; i < TAM_NAVIO; i++) tabuleiro[linhaD1 + i][colunaD1 + i] = NAVIO;

    // --- Posiciona o navio diagonal secundária (/) ---
    for (i = 0; i < TAM_NAVIO; i++) tabuleiro[linhaD2 + i][colunaD2 - i] = NAVIO;

    // --- MATRIZES DE HABILIDADES (5x5) ---
    int cone[H][H];
    int cruz[H][H];
    int octaedro[H][H];

    // --- Criação dinâmica das formas com loops e condicionais ---

    // 1️⃣ Cone (ponta para baixo)
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            if (j >= (H / 2 - i) && j <= (H / 2 + i))
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // 2️⃣ Cruz (forma de +)
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            if (i == H / 2 || j == H / 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // 3️⃣ Octaedro (forma de losango)
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            if (abs(i - H / 2) + abs(j - H / 2) <= H / 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // --- Posições centrais das habilidades no tabuleiro ---
    int centroConeLinha = 0, centroConeColuna = 4;
    int centroCruzLinha = 5, centroCruzColuna = 4;
    int centroOctaLinha = 8, centroOctaColuna = 2;

    // --- Função de sobreposição das habilidades no tabuleiro ---
    // Cada ponto da matriz de habilidade é sobreposto no tabuleiro
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            // Calcula a posição correspondente no tabuleiro
            int linha = centroConeLinha + i;
            int coluna = centroConeColuna + j - H / 2;
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (cone[i][j] == 1 && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = HAB;
            }
        }
    }

    // --- Habilidade em cruz ---
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            int linha = centroCruzLinha + i - H / 2;
            int coluna = centroCruzColuna + j - H / 2;
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (cruz[i][j] == 1 && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = HAB;
            }
        }
    }

    // --- Habilidade em octaedro ---
    for (i = 0; i < H; i++) {
        for (j = 0; j < H; j++) {
            int linha = centroOctaLinha + i - H / 2;
            int coluna = centroOctaColuna + j - H / 2;
            if (linha >= 0 && linha < TAM && coluna >= 0 && coluna < TAM) {
                if (octaedro[i][j] == 1 && tabuleiro[linha][coluna] == 0)
                    tabuleiro[linha][coluna] = HAB;
            }
        }
    }

    // --- Exibe o tabuleiro final ---
    printf("\n=== TABULEIRO BATALHA NAVAL (NÍVEL MESTRE) ===\n\n");
    printf("Legenda: 0 = Água | 3 = Navio | 5 = Área de habilidade\n\n");

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
