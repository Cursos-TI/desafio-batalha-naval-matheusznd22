#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro
#define TAM_NAVIO 3   // Tamanho fixo dos navios
#define NAVIO 3       // Valor usado para representar parte de um navio
#define AGUA 0        // Valor usado para representar água

// Função para imprimir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("Tabuleiro Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se é possível posicionar um navio sem ultrapassar limites e sem sobreposição
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int tipoDiagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (tipoDiagonal ? i : (direcao == 1 ? i : 0));
        int c;

        if (tipoDiagonal == 1) // ↘
            c = coluna + i;
        else if (tipoDiagonal == 2) // ↙
            c = coluna - i;
        else // horizontal ou vertical
            c = coluna + (direcao == 0 ? i : 0);

        // Valida se a posição está dentro dos limites
        if (l < 0 || l >= TAM || c < 0 || c >= TAM)
            return 0;

        // Verifica sobreposição
        if (tabuleiro[l][c] != AGUA)
            return 0;
    }
    return 1;
}

// Função para posicionar um navio no tabuleiro
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int tipoDiagonal) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linha + (tipoDiagonal ? i : (direcao == 1 ? i : 0));
        int c;

        if (tipoDiagonal == 1) // ↘
            c = coluna + i;
        else if (tipoDiagonal == 2) // ↙
            c = coluna - i;
        else // horizontal ou vertical
            c = coluna + (direcao == 0 ? i : 0);

        tabuleiro[l][c] = NAVIO;
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa o tabuleiro com água

    // Navio 1 - horizontal
    if (podePosicionar(tabuleiro, 2, 1, 0, 0))
        posicionarNavio(tabuleiro, 2, 1, 0, 0);

    // Navio 2 - vertical
    if (podePosicionar(tabuleiro, 5, 5, 1, 0))
        posicionarNavio(tabuleiro, 5, 5, 1, 0);

    // Navio 3 - diagonal ↘
    if (podePosicionar(tabuleiro, 0, 0, 0, 1))
        posicionarNavio(tabuleiro, 0, 0, 0, 1);

    // Navio 4 - diagonal ↙
    if (podePosicionar(tabuleiro, 0, 9, 0, 2))
        posicionarNavio(tabuleiro, 0, 9, 0, 2);

    // Exibir tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}

