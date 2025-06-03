#include <stdio.h>

int main() {

/*
Definindo as variaveis

npt= Numero de pontos turisticos
area= area em km²
pib= PIB
pibpc= PIB per Capita
DP= Densidade Populacional
nc= Nome da Cidade
cc= Codigo da Carta

*/
    int npt1, npt2;
    float area1, pib1, pibpc1, DP1, area2, pib2, pibpc2, DP2;
    char estado1[50], nc1[50], cc1[10], estado2[50], nc2[50],cc2[10];
    unsigned long int populacao1, populacao2;

//mostrando e pedindo os valores de cada variavel
    printf("Carta N1\nDigite o Estado: ");
    scanf("%s", estado1);

    printf("Digite o codigo da carta: ");
    scanf("%s", &cc1);

    printf("Digite a cidade: ");
    scanf("%s", nc1);

    printf("Populacao: ");
    scanf("%lu", &populacao1);

    printf("Area em km2: ");
    scanf("%f", &area1);

    printf("PIB: ");
    scanf("%f", &pib1);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &npt1);

    printf("Carta N2\nDigite o Estado: ");
    scanf("%s", estado2);

    printf("Digite o codigo da carta: ");
    scanf("%s", &cc2);

    printf("Digite a cidade: ");
    scanf("%s", nc2);

    printf("Populacao: ");
    scanf("%lu", &populacao2);

    printf("Area em km2: ");
    scanf("%f", &area2);

    printf("PIB: ");
    scanf("%f", &pib2);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &npt2);

    pibpc1 = (pib1 * 1000000000)/(float)populacao1;
    pibpc2 = (pib2 * 1000000000)/(float)populacao2;
    DP1 = (float)populacao1/area1;
    DP2 = (float)populacao2/area2;

    float inversoDP1 = 1 / DP1;
    float inversoDP2 = 1 / DP2;

    float superpoder1 = populacao1 + area1 + (pib1 * 1000000000) + npt1 + pibpc1 + inversoDP1;
    float superpoder2 = populacao2 + area2 + (pib2 * 1000000000) + npt2 + pibpc2 + inversoDP2;

    int superpoder = superpoder1 > superpoder2;
    int Superpoder = superpoder2 > superpoder1;

    int populacao = populacao1 > populacao2;
    int Populacao = populacao2 > populacao1;

    int npt = npt1 > npt2;
    int Npt = npt2 > npt1;

    int area = area1 > area2;
    int Area = area2 > area1;

    int pib = pib1 > pib2;
    int Pib = pib2 > pib1;

    int pibpc = pibpc1 > pibpc2;
    int Pibpc = pibpc2 > pibpc1;

    int dp = DP1 < DP2;
    int Dp = DP2 < DP1;

    int pontos1 = populacao + npt + area + pib + pibpc + dp + superpoder;
    int pontos2 = Populacao + Npt + Area + Pib + Pibpc + Dp + Superpoder;

//mostrando os valores das variaveis de cada carta
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo da carta: %s%s\n", estado1, cc1);
    printf("Cidade: %s\n", nc1);
    printf("Populacao: %lu habitantes\n", populacao1);
    printf("Area em km2: %.2f km²\n", area1);
    printf("PIB: R$ %.2f Bilhoes \n", pib1);
    printf("Numero de pontos turisticos: %d\n", npt1);
    printf("Densidade Populacional: %.2f hab/km².\n", DP1);
    printf("PIB per Capita: R$ %.2f .\n", pibpc1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo da carta: %s%s\n", estado2, cc2);
    printf("Cidade: %s\n", nc2);
    printf("Populacao: %lu habitantes\n", populacao2);
    printf("Area em km2: %.2f km²\n", area2);
    printf("PIB: R$ %.2f Bilhoes \n", pib2);
    printf("Numero de pontos turisticos: %d\n", npt2);
    printf("Densidade Populacional: %.2f hab/km².\n", DP2);
    printf("PIB per Capita: R$ %.2f .\n\n", pibpc2);

    printf("Pontuação População: \n");
    printf("%s: %d\n",nc1, populacao);
    printf("%s: %d\n\n",nc2, Populacao);

    printf("Pontuação numero de pontos turisticos: \n");
    printf("%s: %d\n",nc1, npt);
    printf("%s: %d\n\n",nc2, Npt);

    printf("Pontuação Area: \n");
    printf("%s: %d\n",nc1, area);
    printf("%s: %d\n\n",nc2, Area);

    printf("Pontuação PIB: \n");
    printf("%s: %d\n",nc1, pib);
    printf("%s: %d\n\n",nc2, Pib);

    printf("Pontuação PIB Per Capita: \n");
    printf("%s: %d\n",nc1, pibpc);
    printf("%s: %d\n\n",nc2, Pibpc);

    printf("Pontuação Densidade Populacional: \n");
    printf("%s: %d\n",nc1, dp);
    printf("%s: %d\n\n",nc2, Dp);

    printf("Pontuação Super Poder: \n");
    printf("%s: %d\n",nc1, superpoder);
    printf("%s: %d\n\n",nc2, Superpoder);

    printf("Super Poder\n\n");
    printf("%s: %f\n",nc1, superpoder1);
    printf("%s: %f\n\n",nc2, superpoder2);

    printf("----------Placar final---------\n");
    printf("%s: %d pontos\n", nc1, pontos1);
    printf("%s: %d pontos\n\n", nc2, pontos2);

//o atributo escolhido foi a pontuação total.
     if (pontos1>pontos2){
        printf("A Carta %s Venceu\n\n", nc1);
    }else {
        printf("A Carta %s Venceu\n\n", nc2);
    }
    return 0;
}