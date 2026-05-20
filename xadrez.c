#include <stdio.h>

int main() {

    /* ----------------------------------------------------------
     * Constantes que definem a quantidade de casas por peça.
     * Usar constantes evita "números mágicos" espalhados pelo
     * código e facilita futuras alterações.
     * ---------------------------------------------------------- */
    const int CASAS_BISPO  = 5;
    const int CASAS_TORRE  = 5;
    const int CASAS_RAINHA = 8;

    /* ==========================================================
     * BISPO — 5 casas na diagonal superior direita
     * Estrutura utilizada: FOR
     * O diagonal é representado imprimindo "Cima" e "Direita"
     * a cada iteração, pois o bispo move-se simultaneamente
     * nas duas direções básicas.
     * ========================================================== */
    printf("========================================\n");
    printf("  BISPO — Diagonal Superior Direita\n");
    printf("========================================\n");

    for (int i = 1; i <= CASAS_BISPO; i++) {
        printf("Casa %d: ", i);
        printf("Cima\n");      /* componente vertical   */
        printf("Casa %d: ", i);
        printf("Direita\n");   /* componente horizontal */
    }

    /* ==========================================================
     * TORRE — 5 casas para a direita
     * Estrutura utilizada: WHILE
     * Movimento simples em linha reta horizontal.
     * ========================================================== */
    printf("\n========================================\n");
    printf("  TORRE — Direita\n");
    printf("========================================\n");

    int casaTorre = 1;
    while (casaTorre <= CASAS_TORRE) {
        printf("Casa %d: ", casaTorre);
        printf("Direita\n");
        casaTorre++;
    }

    /* ==========================================================
     * RAINHA — 8 casas para a esquerda
     * Estrutura utilizada: DO-WHILE
     * Movimento simples em linha reta horizontal (sentido oposto).
     * O do-while garante ao menos uma execução antes da verificação
     * da condição, o que é ideal quando há certeza de movimento.
     * ========================================================== */
    printf("\n========================================\n");
    printf("  RAINHA — Esquerda\n");
    printf("========================================\n");

    int casaRainha = 1;
    do {
        printf("Casa %d: ", casaRainha);
        printf("Esquerda\n");
        casaRainha++;
    } while (casaRainha <= CASAS_RAINHA);

    printf("\n========================================\n");
    printf("  Simulação concluída!\n");
    printf("========================================\n");

    return 0;
}
