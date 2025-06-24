#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de cada país
struct Carta {
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

// Função para cadastrar uma carta
void cadastrarCarta(struct Carta *c) {
    printf("Digite o nome do país: ");
    scanf(" %[^\n]", c->nome);
    printf("População: ");
    scanf("%d", &c->populacao);
    printf("Área (km²): ");
    scanf("%f", &c->area);
    printf("PIB (trilhões): ");
    scanf("%f", &c->pib);
    printf("Pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);

    c->densidadeDemografica = (c->area > 0) ? (float)c->populacao / c->area : 0.0;
}

// Função para obter o valor de um atributo
float obterValor(struct Carta c, int atributo) {
    switch(atributo) {
        case 1: return (float)c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return (float)c.pontosTuristicos;
        case 5: return c.densidadeDemografica;
        default: return 0.0;
    }
}

// Função para obter o nome do atributo
const char* nomeAtributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

// Função para mostrar o menu e garantir escolha diferente
int escolherAtributo(int bloqueado) {
    int opcao;
    printf("\nEscolha um atributo para comparação:\n");
    if (bloqueado != 1) printf("1 - População\n");
    if (bloqueado != 2) printf("2 - Área\n");
    if (bloqueado != 3) printf("3 - PIB\n");
    if (bloqueado != 4) printf("4 - Pontos Turísticos\n");
    if (bloqueado != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    // Verificação de repetição
    if (opcao == bloqueado || opcao < 1 || opcao > 5) {
        printf("Opção inválida ou repetida. Tente novamente.\n");
        return escolherAtributo(bloqueado);
    }
    return opcao;
}

// Função principal
int main() {
    struct Carta carta1, carta2;
    printf("===== Cadastro da Carta 1 =====\n");
    cadastrarCarta(&carta1);
    printf("\n===== Cadastro da Carta 2 =====\n");
    cadastrarCarta(&carta2);

    // Escolha dos dois atributos diferentes
    printf("\n===== Comparação Avançada =====\n");
    int attr1 = escolherAtributo(0);
    int attr2 = escolherAtributo(attr1);

    // Obter valores individuais
    float v1a1 = obterValor(carta1, attr1);
    float v2a1 = obterValor(carta2, attr1);
    float v1a2 = obterValor(carta1, attr2);
    float v2a2 = obterValor(carta2, attr2);

    // Verifica se algum atributo é densidade
    int inv1 = (attr1 == 5);
    int inv2 = (attr2 == 5);

    // Comparações individuais com regra da densidade (menor vence)
    const char* vencedor1 = (v1a1 == v2a1) ? "Empate" : ((inv1 ? v1a1 < v2a1 : v1a1 > v2a1) ? carta1.nome : carta2.nome);
    const char* vencedor2 = (v1a2 == v2a2) ? "Empate" : ((inv2 ? v1a2 < v2a2 : v1a2 > v2a2) ? carta1.nome : carta2.nome);

    // Soma dos valores (sem inversão)
    float soma1 = v1a1 + v1a2;
    float soma2 = v2a1 + v2a2;

    const char* vencedorFinal = (soma1 == soma2) ? "Empate!" : (soma1 > soma2 ? carta1.nome : carta2.nome);

    // Exibição do resultado
    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");
    printf("País 1: %s\n", carta1.nome);
    printf("País 2: %s\n", carta2.nome);
    printf("\nAtributo 1: %s\n", nomeAtributo(attr1));
    printf("  %s: %.2f | %s: %.2f => %s venceu\n", carta1.nome, v1a1, carta2.nome, v2a1, vencedor1);
    printf("\nAtributo 2: %s\n", nomeAtributo(attr2));
    printf("  %s: %.2f | %s: %.2f => %s venceu\n", carta1.nome, v1a2, carta2.nome, v2a2, vencedor2);
    printf("\nSoma dos Atributos:\n");
    printf("  %s: %.2f\n", carta1.nome, soma1);
    printf("  %s: %.2f\n", carta2.nome, soma2);
    printf("\n==== VENCEDOR FINAL: %s ====\n", vencedorFinal);

    return 0;
}
