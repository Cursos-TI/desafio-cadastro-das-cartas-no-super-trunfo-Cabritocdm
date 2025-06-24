#include <stdio.h>
#include <stdlib.h> // para abs()

#define TAM 10
#define TAM_HABILIDADE 5

#define AGUA 0
#define NAVIO 3
#define AREA_AFETADA 5

int tabuleiro[TAM][TAM];

// Inicializa tabuleiro com água
void inicializarTabuleiro() {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = AGUA;
}

// Posiciona alguns navios fixos para visualização
void posicionarNavios() {
    // Navio horizontal (linha 4, colunas 3 a 5)
    for (int c = 3; c <= 5; c++)
        tabuleiro[4][c] = NAVIO;

    // Navio vertical (coluna 7, linhas 6 a 8)
    for (int l = 6; l <= 8; l++)
        tabuleiro[l][7] = NAVIO;

    // Navio diagonal principal (3 casas)
    for (int i = 0; i < 3; i++)
        tabuleiro[i][i] = NAVIO;
}

// Constroi a matriz de habilidade em forma de Cone (5x5)
void construirMatrizCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= centro - i && j <= centro + i)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Constroi a matriz de habilidade em forma de Cruz (5x5)
void construirMatrizCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == centro || j == centro)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Constroi a matriz de habilidade em forma de Octaedro (5x5)
void construirMatrizOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int centro = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int dist = abs(i - centro) + abs(j - centro);
            matriz[i][j] = (dist <= centro) ? 1 : 0;
        }
    }
}

// Sobrepõe a matriz de habilidade no tabuleiro, centrada em (origemLinha, origemColuna)
void sobreporHabilidade(int origemLinha, int origemColuna, int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    int meio = TAM_HABILIDADE / 2;
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (matriz[i][j] == 1) {
                int linhaTab = origemLinha - meio + i;
                int colTab = origemColuna - meio + j;
                if (linhaTab >= 0 && linhaTab < TAM && colTab >= 0 && colTab < TAM) {
                    if (tabuleiro[linhaTab][colTab] == AGUA || tabuleiro[linhaTab][colTab] == NAVIO)
                        tabuleiro[linhaTab][colTab] = AREA_AFETADA;
                }
            }
        }
    }
}

// Exibe tabuleiro com símbolos
void exibirTabuleiro() {
    printf("\nTabuleiro ( . = água, N = navio, X = área afetada ):\n\n  ");
    for (int c = 0; c < TAM; c++)
        printf("%d ", c);
    printf("\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAM; j++) {
            switch(tabuleiro[i][j]) {
                case AGUA: printf(". "); break;
                case NAVIO: printf("N "); break;
                case AREA_AFETADA: printf("X "); break;
                default: printf("? "); break;
            }
        }
        printf("\n");
    }
}

int main() {
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro();
    posicionarNavios();

    construirMatrizCone(cone);
    construirMatrizCruz(cruz);
    construirMatrizOctaedro(octaedro);

    // Origem das habilidades no tabuleiro
    int origemConeLinha = 1, origemConeColuna = 4;
    int origemCruzLinha = 7, origemCruzColuna = 7;
    int origemOctaedroLinha = 4, origemOctaedroColuna = 2;

    sobreporHabilidade(origemConeLinha, origemConeColuna, cone);
    sobreporHabilidade(origemCruzLinha, origemCruzColuna, cruz);
    sobreporHabilidade(origemOctaedroLinha, origemOctaedroColuna, octaedro);

    exibirTabuleiro();

    return 0;
}
