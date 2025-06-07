#include <stdio.h>

int main() {
    // Cartas fixas (só para exemplo)
    char nome1[100] = "Brasil";
    char nome2[100] = "Argentina";
    int populacao1 = 213000000;
    int populacao2 = 45300000;
    float area1 = 8515767.0;
    float area2 = 2780400.0;
    float pib1 = 14450.0;
    float pib2 = 4880.0;
    int pontos1 = 12;
    int pontos2 = 10;
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    // Para o menu dinâmico
    int opcao1 = 0, opcao2 = 0;
    int valido = 0;

    float valor1_a, valor1_b, valor2_a, valor2_b;
    float soma1, soma2;

    // Menu para o primeiro atributo
    while (!valido) {
        printf("1.Populacao\n2.Area\n3.PIB\n4.PontosTuristicos\n5.Densidade\n");
        printf("Escolha o 1o atributo: ");
        scanf("%d", &opcao1);
        if (opcao1 >= 1 && opcao1 <= 5) {
            valido = 1;
        } else {
            printf("Opcao invalida\n");
        }
    }

    // Menu dinâmico para o segundo atributo
    valido = 0;
    while (!valido) {
        printf("Escolha o 2o atributo (diferente do 1o):\n");
        if (opcao1 != 1) printf("1.Populacao\n");
        if (opcao1 != 2) printf("2.Area\n");
        if (opcao1 != 3) printf("3.PIB\n");
        if (opcao1 != 4) printf("4.PontosTuristicos\n");
        if (opcao1 != 5) printf("5.Densidade\n");
        scanf("%d", &opcao2);
        if (opcao2 >= 1 && opcao2 <= 5 && opcao2 != opcao1) {
            valido = 1;
        } else {
            printf("Opcao invalida\n");
        }
    }

    // Função para pegar o valor de cada atributo de cada carta
    // (a = atributo 1, b = atributo 2)
    switch(opcao1) {
        case 1: valor1_a = populacao1; valor2_a = populacao2; break;
        case 2: valor1_a = area1;      valor2_a = area2;      break;
        case 3: valor1_a = pib1;       valor2_a = pib2;       break;
        case 4: valor1_a = pontos1;    valor2_a = pontos2;    break;
        case 5: valor1_a = densidade1; valor2_a = densidade2; break;
        default: valor1_a = 0;         valor2_a = 0;          break;
    }

    switch(opcao2) {
        case 1: valor1_b = populacao1; valor2_b = populacao2; break;
        case 2: valor1_b = area1;      valor2_b = area2;      break;
        case 3: valor1_b = pib1;       valor2_b = pib2;       break;
        case 4: valor1_b = pontos1;    valor2_b = pontos2;    break;
        case 5: valor1_b = densidade1; valor2_b = densidade2; break;
        default: valor1_b = 0;         valor2_b = 0;          break;
    }

    // Exibe os valores de cada atributo escolhido
    printf("\n%s: ", nome1);
    printf(opcao1 == 1 ? "%d " : (opcao1 == 2 ? "%.2f " : (opcao1 == 3 ? "%.2f " : (opcao1 == 4 ? "%d " : "%.2f "))), (opcao1==1)?(int)valor1_a:valor1_a);
    printf(opcao2 == 1 ? "%d\n" : (opcao2 == 2 ? "%.2f\n" : (opcao2 == 3 ? "%.2f\n" : (opcao2 == 4 ? "%d\n" : "%.2f\n"))), (opcao2==1)?(int)valor1_b:valor1_b);

    printf("%s: ", nome2);
    printf(opcao1 == 1 ? "%d " : (opcao1 == 2 ? "%.2f " : (opcao1 == 3 ? "%.2f " : (opcao1 == 4 ? "%d " : "%.2f "))), (opcao1==1)?(int)valor2_a:valor2_a);
    printf(opcao2 == 1 ? "%d\n" : (opcao2 == 2 ? "%.2f\n" : (opcao2 == 3 ? "%.2f\n" : (opcao2 == 4 ? "%d\n" : "%.2f\n"))), (opcao2==1)?(int)valor2_b:valor2_b);

    // Comparação de cada atributo
    int venceu1, venceu2;
    // Para densidade, menor vence
    venceu1 = (opcao1 == 5) ? (valor1_a < valor2_a ? 1 : (valor2_a < valor1_a ? 2 : 0)) :
              (valor1_a > valor2_a ? 1 : (valor2_a > valor1_a ? 2 : 0));
    venceu2 = (opcao2 == 5) ? (valor1_b < valor2_b ? 1 : (valor2_b < valor1_b ? 2 : 0)) :
              (valor1_b > valor2_b ? 1 : (valor2_b > valor1_b ? 2 : 0));

    // Soma dos atributos para cada carta
    soma1 = valor1_a + valor1_b;
    soma2 = valor2_a + valor2_b;

    // Exibe resultados de cada atributo
    printf("\nAtributo 1: %s\n", 
        opcao1 == 1 ? "Populacao" : (opcao1 == 2 ? "Area" : (opcao1 == 3 ? "PIB" : (opcao1 == 4 ? "PontosTuristicos" : "Densidade"))));
    printf("Vencedor: %s\n", venceu1 == 1 ? nome1 : (venceu1 == 2 ? nome2 : "Empate"));

    printf("Atributo 2: %s\n", 
        opcao2 == 1 ? "Populacao" : (opcao2 == 2 ? "Area" : (opcao2 == 3 ? "PIB" : (opcao2 == 4 ? "PontosTuristicos" : "Densidade"))));
    printf("Vencedor: %s\n", venceu2 == 1 ? nome1 : (venceu2 == 2 ? nome2 : "Empate"));

    // Exibe soma dos atributos e resultado final
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", nome1, soma1);
    printf("%s: %.2f\n", nome2, soma2);

    printf("Resultado final: ");
    printf(soma1 > soma2 ? "%s venceu\n" : (soma2 > soma1 ? "%s venceu\n" : "Empate\n"), soma1 > soma2 ? nome1 : nome2);

    return 0;
}
