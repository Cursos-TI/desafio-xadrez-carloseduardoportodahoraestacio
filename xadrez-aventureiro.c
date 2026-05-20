#include <stdio.h>

int main() {

    /* ----------------------------------------------------------
     * Constantes que definem o movimento em "L" do cavalo:
     *   CASAS_VERTICAL   = 2 → o cavalo desce 2 casas
     *   CASAS_HORIZONTAL = 1 → o cavalo vai 1 casa para a esquerda
     * ---------------------------------------------------------- */
    const int CASAS_VERTICAL   = 2;  /* pernas longas do L  */
    const int CASAS_HORIZONTAL = 1;  /* perna curta do L    */

    printf("============================================\n");
    printf("   CAVALO — Movimento em L\n");
    printf("   (2 casas para Baixo + 1 para Esquerda)\n");
    printf("============================================\n\n");

    /* ----------------------------------------------------------
     * Variável de controle do loop externo.
     * 'passo' representa cada uma das casas percorridas
     * na direção vertical (Baixo).
     * ---------------------------------------------------------- */
    int passo;

    /* ==========================================================
     * LOOP EXTERNO — FOR
     * Responsável pelo movimento vertical: 2 casas para Baixo.
     * Itera de 1 até CASAS_VERTICAL (inclusive).
     * ========================================================== */
    for (passo = 1; passo <= CASAS_VERTICAL; passo++) {

        printf("  Passo vertical %d de %d:\n", passo, CASAS_VERTICAL);
        printf("    Baixo\n");

        /* ------------------------------------------------------
         * LOOP INTERNO — WHILE (aninhado dentro do FOR)
         * Responsável pelo movimento horizontal: 1 casa Esquerda.
         * Só é executado APÓS o cavalo completar as 2 casas
         * verticais, ou seja, quando passo == CASAS_VERTICAL.
         *
         * Lógica: o cavalo primeiro termina toda a subida/descida
         * vertical e, ao atingir a última casa vertical, realiza
         * o passo lateral que completa o "L".
         * ------------------------------------------------------ */
        if (passo == CASAS_VERTICAL) {

            int lateral = 1;        /* contador do passo horizontal */

            printf("\n  --> Completou as %d casas verticais!\n", CASAS_VERTICAL);
            printf("      Executando passo horizontal:\n\n");

            while (lateral <= CASAS_HORIZONTAL) {
                printf("    Passo horizontal %d de %d:\n", lateral, CASAS_HORIZONTAL);
                printf("    Esquerda\n");
                lateral++;
            }
        }

        printf("\n");
    }

    printf("============================================\n");
    printf("   Movimento em L concluído!\n");
    printf("   Cavalo saiu: 2x Baixo + 1x Esquerda\n");
    printf("============================================\n");

    return 0;
}
