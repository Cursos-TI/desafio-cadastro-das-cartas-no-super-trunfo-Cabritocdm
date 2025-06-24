#include <stdio.h>

/*
    Desafio: Nível Mestre – Movimentos complexos no xadrez
    Peças:
    - Torre: recursividade (→ Direita)
    - Rainha: recursividade (← Esquerda)
    - Bispo: recursividade + loops aninhados (↗ Cima Direita)
    - Cavalo: loops aninhados + múltiplas variáveis (↑↑→)
*/

// ========================
// TORRE - MOVIMENTO RECURSIVO
// ========================
void moverTorre(int passoAtual, int totalPassos) {
    if (passoAtual > totalPassos) return;

    printf("Casa %d: Direita\n", passoAtual);
    moverTorre(passoAtual + 1, totalPassos);
}

// ========================
// RAINHA - MOVIMENTO RECURSIVO
// ========================
void moverRainha(int passoAtual, int totalPassos) {
    if (passoAtual > totalPassos) return;

    printf("Casa %d: Esquerda\n", passoAtual);
    moverRainha(passoAtual + 1, totalPassos);
}

// ========================
// BISPO - MOVIMENTO RECURSIVO + LOOPS ANINHADOS
// ========================
void moverBispoRecursivo(int passo, int total) {
    if (passo > total) return;

    // Loops aninhados para representar "Cima Direita"
    for (int vertical = 1; vertical <= 1; vertical++) {
        for (int horizontal = 1; horizontal <= 1; horizontal++) {
            printf("Casa %d: Cima Direita\n", passo);
        }
    }

    moverBispoRecursivo(passo + 1, total);
}

// ========================
// CAVALO - LOOP COMPLEXO (↑↑→)
// ========================
void moverCavalo() {
    const int movimentos = 1; // Apenas 1 movimento em "L"
    int passo = 1;

    printf("\nMovimento do CAVALO (Cima, Cima, Direita):\n");

    for (int tentativa = 0; tentativa < movimentos; tentativa++) {
        for (int i = 0, cima = 0; i < 3; i++) {
            if (i < 2) {
                // Duas vezes para cima
                cima++;
                printf("Passo %d: Cima\n", passo++);
                continue;
            }

            // Terceiro passo: Direita
            if (cima == 2) {
                printf("Passo %d: Direita\n", passo++);
                break;
            }
        }
    }
}

int main() {
    const int passosTorre = 5;
    const int passosRainha = 8;
    const int passosBispo = 5;

    // ========================
    // TORRE
    // ========================
    printf("Movimento da TORRE (Direita):\n");
    moverTorre(1, passosTorre);

    // ========================
    // BISPO
    // ========================
    printf("\nMovimento do BISPO (Cima Direita):\n");
    moverBispoRecursivo(1, passosBispo);

    // ========================
    // RAINHA
    // ========================
    printf("\nMovimento da RAINHA (Esquerda):\n");
    moverRainha(1, passosRainha);

    // ========================
    // CAVALO
    // ========================
    moverCavalo();

    return 0;
}
