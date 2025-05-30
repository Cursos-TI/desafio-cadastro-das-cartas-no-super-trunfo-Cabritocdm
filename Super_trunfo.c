#include <stdio.h>

int main() {

//definindo as variaveis 
    int populacao1, npt1, cc1;
    float area1, pib1;
    char estado1[50], nc1[50];
    int populacao2, npt2, cc2;
    float area2, pib2;
    char estado2[50], nc2[50];

//mostrando e pedindo os valores de casa variavel
    printf("Carta N1\nDigite o Estado (A-H): ");
    scanf("%s", estado1);

    printf("Digite o codigo da carta (num 1-4): ");
    scanf("%d", &cc1);

    printf("Digite a cidade: ");
    scanf("%s", nc1);

    printf("Populacao: ");
    scanf("%d", &populacao1);

    printf("Area em km2: ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &npt1);

    printf("Carta N2\nDigite o Estado (A-H): ");
    scanf("%s", estado2);

    printf("Digite o codigo da carta (num 1-4): ");
    scanf("%d", &cc2);

    printf("Digite a cidade: ");
    scanf("%s", nc2);

    printf("Populacao: ");
    scanf("%d", &populacao2);

    printf("Area em km2: ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &npt2);

//mostrando os valores das variaveis de cada carta
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo da carta: %s%d\n", estado1, cc1);
    printf("Cidade: %s\n", nc1);
    printf("Populacao: %.3d habitantes\n", populacao1);
    printf("Area em km2: %.2f km²\n", area1);
    printf("PIB: %.2f Milhões de reais\n", pib1);
    printf("Numero de pontos turisticos: %d\n", npt1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo da carta: %s%d\n", estado2, cc2);
    printf("Cidade: %s\n", nc2);
    printf("Populacao: %.3d habitantes\n", populacao2);
    printf("Area em km2: %.2f km²\n", area2);
    printf("PIB: %.2f Milhões de reais\n", pib2);
    printf("Numero de pontos turisticos: %d\n", npt2);

    return 0;
}