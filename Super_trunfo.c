#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de cada país
struct Carta {
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;  // será calculada
};

// Função para exibir o resultado da comparação
void exibirResultado(struct Carta c1, struct Carta c2, char atributo[], float valor1, float valor2, int densidadeInversa) {
    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");
    printf("Atributo: %s\n", atributo);
    printf("%s: %.2f\n", c1.nome, valor1);
    printf("%s: %.2f\n", c2.nome, valor2);

    if (valor1 > valor2) {
        if (densidadeInversa)
            printf("Vencedor: %s\n", c2.nome);
        else
            printf("Vencedor: %s\n", c1.nome);
    } else if (valor1 < valor2) {
        if (densidadeInversa)
            printf("Vencedor: %s\n", c1.nome);
        else
            printf("Vencedor: %s\n", c2.nome);
    } else {
        printf("Empate!\n");
    }

    printf("===================================\n");
}

// Função para cadastrar uma carta e calcular densidade demográfica
void cadastrarCarta(struct Carta *carta) {
    printf("Digite o nome do país: ");
    scanf(" %[^\n]", carta->nome);

    printf("População: ");
    scanf("%d", &carta->populacao);

    printf("Área (km²): ");
    scanf("%f", &carta->area);

    printf("PIB (trilhões): ");
    scanf("%f", &carta->pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Cálculo da densidade demográfica = população / área
    if (carta->area > 0) {
        carta->densidadeDemografica = (float)carta->populacao / carta->area;
    } else {
        carta->densidadeDemografica = 0.0; // Evita divisão por zero
    }
}

int main() {
    struct Carta carta1, carta2;
    int opcao;

    printf("===== Cadastro da Carta 1 =====\n");
    cadastrarCarta(&carta1);

    printf("\n===== Cadastro da Carta 2 =====\n");
    cadastrarCarta(&carta2);

    printf("\n======= SUPER TRUNFO: MENU DE COMPARAÇÃO =======\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("===============================================\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            exibirResultado(carta1, carta2, "População", (float)carta1.populacao, (float)carta2.populacao, 0);
            break;
        case 2:
            exibirResultado(carta1, carta2, "Área", carta1.area, carta2.area, 0);
            break;
        case 3:
            exibirResultado(carta1, carta2, "PIB", carta1.pib, carta2.pib, 0);
            break;
        case 4:
            exibirResultado(carta1, carta2, "Pontos Turísticos", (float)carta1.pontosTuristicos, (float)carta2.pontosTuristicos, 0);
            break;
        case 5:
            exibirResultado(carta1, carta2, "Densidade Demográfica", carta1.densidadeDemografica, carta2.densidadeDemografica, 1);
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
    }

    return 0;
}
