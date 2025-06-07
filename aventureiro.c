#include <stdio.h>

int main() {
    // Dados das cartas (fixos, para focar no menu)
    char nome1[100] = "Brasil";
    char nome2[100] = "Argentina";
    int populacao1 = 213000000;
    int populacao2 = 45300000;
    float area1 = 8515767.0;
    float area2 = 2780400.0;
    float pib1 = 14450.0;
    float pib2 = 4880.0;
    int pontosTuristicos1 = 12;
    int pontosTuristicos2 = 10;
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    int op;

    printf("1.Populacao\n2.Area\n3.PIB\n4.PontosTuristicos\n5.Densidade\n");
    printf("Opcao: ");
    scanf("%d", &op);

    switch(op) {
        case 1:
            printf("%d %d\n", populacao1, populacao2);
            if(populacao1 > populacao2) {
                printf("%s venceu\n", nome1);
            } else if(populacao2 > populacao1) {
                printf("%s venceu\n", nome2);
            } else {
                printf("Empate\n");
            }
            break;
        case 2:
            printf("%.2f %.2f\n", area1, area2);
            if(area1 > area2) {
                printf("%s venceu\n", nome1);
            } else if(area2 > area1) {
                printf("%s venceu\n", nome2);
            } else {
                printf("Empate\n");
            }
            break;
        case 3:
            printf("%.2f %.2f\n", pib1, pib2);
            if(pib1 > pib2) {
                printf("%s venceu\n", nome1);
            } else if(pib2 > pib1) {
                printf("%s venceu\n", nome2);
            } else {
                printf("Empate\n");
            }
            break;
        case 4:
            printf("%d %d\n", pontosTuristicos1, pontosTuristicos2);
            if(pontosTuristicos1 > pontosTuristicos2) {
                printf("%s venceu\n", nome1);
            } else if(pontosTuristicos2 > pontosTuristicos1) {
                printf("%s venceu\n", nome2);
            } else {
                printf("Empate\n");
            }
            break;
        case 5:
            printf("%.2f %.2f\n", densidade1, densidade2);
            if(densidade1 < densidade2) {
                printf("%s venceu\n", nome1);
            } else if(densidade2 < densidade1) {
                printf("%s venceu\n", nome2);
            } else {
                printf("Empate\n");
            }
            break;
        default:
            printf("Invalido\n");
            break;
    }

    return 0;
}
