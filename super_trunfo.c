#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados de uma carta
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int numPontosTuristicos;
    float densidadePopulacional; // Novo campo calculado
    float pibPerCapita;         // Novo campo calculado
};

// Função para calcular densidade populacional e PIB per capita
void calcularMetricas(struct Carta *carta) {
    carta->densidadePopulacional = carta->populacao / carta->area;
    carta->pibPerCapita = (carta->pib * 1000000000) / carta->populacao; // Convertendo bilhões para reais
}

// Função para comparar duas cartas com base no atributo escolhido
void compararCartas(struct Carta carta1, struct Carta carta2) {
    // Escolha do atributo para comparação (altere aqui para testar diferentes atributos)
    const int ATRIBUTO_COMPARACAO = 1; 
    /* Opções:
       1 - População
       2 - Área
       3 - PIB
       4 - Densidade Populacional
       5 - PIB per capita
       6 - Número de pontos turísticos
    */
    
    char *nomeAtributo;
    float valor1, valor2;
    
    // Determina qual atributo será comparado e obtém os valores
    switch(ATRIBUTO_COMPARACAO) {
        case 1:
            nomeAtributo = "População";
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            break;
        case 2:
            nomeAtributo = "Área";
            valor1 = carta1.area;
            valor2 = carta2.area;
            break;
        case 3:
            nomeAtributo = "PIB";
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            break;
        case 4:
            nomeAtributo = "Densidade Populacional";
            valor1 = carta1.densidadePopulacional;
            valor2 = carta2.densidadePopulacional;
            break;
        case 5:
            nomeAtributo = "PIB per capita";
            valor1 = carta1.pibPerCapita;
            valor2 = carta2.pibPerCapita;
            break;
        case 6:
            nomeAtributo = "Número de pontos turísticos";
            valor1 = carta1.numPontosTuristicos;
            valor2 = carta2.numPontosTuristicos;
            break;
        default:
            nomeAtributo = "População"; // Padrão
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
    }
    
    // Exibe os dados da comparação
    printf("\nComparação de cartas (Atributo: %s):\n", nomeAtributo);
    printf("Carta 1 - %s (%c): ", carta1.nomeCidade, carta1.estado);
    
    // Formata a saída conforme o tipo do atributo
    if (ATRIBUTO_COMPARACAO == 1 || ATRIBUTO_COMPARACAO == 6) {
        printf("%.0f\n", valor1);
    } else if (ATRIBUTO_COMPARACAO == 5) {
        printf("R$ %.2f\n", valor1);
    } else {
        printf("%.2f\n", valor1);
    }
    
    printf("Carta 2 - %s (%c): ", carta2.nomeCidade, carta2.estado);
    if (ATRIBUTO_COMPARACAO == 1 || ATRIBUTO_COMPARACAO == 6) {
        printf("%.0f\n", valor2);
    } else if (ATRIBUTO_COMPARACAO == 5) {
        printf("R$ %.2f\n", valor2);
    } else {
        printf("%.2f\n", valor2);
    }
    
    // Determina a carta vencedora
    int vencedora = 0; // 0 = empate, 1 = carta1, 2 = carta2
    
    // Lógica de comparação (para densidade populacional, o menor valor vence)
    if (ATRIBUTO_COMPARACAO == 4) {
        if (valor1 < valor2) {
            vencedora = 1;
        } else if (valor2 < valor1) {
            vencedora = 2;
        }
    } 
    // Para todos os outros atributos, o maior valor vence
    else {
        if (valor1 > valor2) {
            vencedora = 1;
        } else if (valor2 > valor1) {
            vencedora = 2;
        }
    }
    
    // Exibe o resultado
    if (vencedora == 0) {
        printf("Resultado: Empate!\n");
    } else if (vencedora == 1) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    }
}

int main() {
    // Declaração de duas cartas
    struct Carta carta1;
    struct Carta carta2;

    // Cadastro da Carta 1
    printf("Cadastro da Carta 1:\n");

    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta1.estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta1.codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta1.nomeCidade);

    printf("Digite a população da cidade: ");
    scanf("%d", &carta1.populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta1.area);

    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta1.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta1.numPontosTuristicos);

    // Cadastro da Carta 2
    printf("\nCadastro da Carta 2:\n");

    printf("Digite o estado (A-H): ");
    scanf(" %c", &carta2.estado);

    printf("Digite o código da carta (ex: B03): ");
    scanf("%s", carta2.codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta2.nomeCidade);

    printf("Digite a população da cidade: ");
    scanf("%d", &carta2.populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &carta2.area);

    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &carta2.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta2.numPontosTuristicos);

    // Calcula métricas adicionais
    calcularMetricas(&carta1);
    calcularMetricas(&carta2);

    // Impressão dos dados da carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Nome da Cidade: %s\n", carta1.nomeCidade);
    printf("População: %d\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões de reais\n", carta1.pib);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta1.pibPerCapita);
    printf("Número de Pontos Turísticos: %d\n", carta1.numPontosTuristicos);

    // Impressão dos dados da carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Nome da Cidade: %s\n", carta2.nomeCidade);
    printf("População: %d\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões de reais\n", carta2.pib);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per capita: R$ %.2f\n", carta2.pibPerCapita);
    printf("Número de Pontos Turísticos: %d\n", carta2.numPontosTuristicos);

    // Compara as duas cartas
    compararCartas(carta1, carta2);

    return 0;
}
