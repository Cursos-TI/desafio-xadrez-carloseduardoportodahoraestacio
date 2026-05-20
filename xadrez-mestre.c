#include <stdio.h>

/* ============================================================
 * CONSTANTES GLOBAIS
 * Centralizam todos os limites de movimento; alterar aqui
 * reflete automaticamente em todas as funções.
 * ============================================================ */
#define CASAS_BISPO       5
#define CASAS_TORRE       5
#define CASAS_RAINHA      8
#define CAVALO_VERTICAL   2   /* perna longa do L  */
#define CAVALO_HORIZONTAL 1   /* perna curta do L  */


/* ============================================================
 * BISPO — Recursão com loop aninhado interno
 * ------------------------------------------------------------
 * Cada chamada recursiva representa 1 casa na diagonal.
 * Dentro de cada chamada, um loop aninhado (for externo ×
 * for interno) imprime os dois componentes do diagonal:
 *   - loop externo : 1 iteração por casa atual
 *   - loop interno : imprime "Cima" e depois "Direita"
 *
 * Parâmetro:
 *   casasRestantes → quantas casas ainda faltam percorrer.
 *   casaAtual      → número da casa sendo exibida (para log).
 * ============================================================ */
void moverBispo(int casasRestantes, int casaAtual) {

    /* caso base: sem casas restantes, encerra a recursão */
    if (casasRestantes == 0) {
        return;
    }

    printf("  Casa %d:\n", casaAtual);

    /*
     * Loop aninhado obrigatório:
     * O loop EXTERNO (eixo) garante que ambos os componentes
     * do diagonal sejam impressos para cada casa.
     * O loop INTERNO (componente) itera sobre os dois
     * comandos de direção que formam a diagonal.
     *
     * direcao: 0 → "Cima" | 1 → "Direita"
     */
    for (int eixo = 1; eixo <= 1; eixo++) {          /* loop externo — 1 casa por chamada  */
        for (int componente = 0; componente <= 1; componente++) {  /* loop interno — 2 direções */
            if (componente == 0) {
                printf("    Cima\n");
            } else {
                printf("    Direita\n");
            }
        }
    }

    /* chamada recursiva: diminui 1 casa, avança o contador */
    moverBispo(casasRestantes - 1, casaAtual + 1);
}


/* ============================================================
 * TORRE — Recursão simples
 * ------------------------------------------------------------
 * Cada chamada imprime "Direita" para uma casa e chama
 * a si mesma com casasRestantes - 1.
 *
 * Parâmetros:
 *   casasRestantes → casas ainda a percorrer.
 *   casaAtual      → número da casa para exibição.
 * ============================================================ */
void moverTorre(int casasRestantes, int casaAtual) {

    /* caso base */
    if (casasRestantes == 0) {
        return;
    }

    printf("  Casa %d: Direita\n", casaAtual);

    moverTorre(casasRestantes - 1, casaAtual + 1);
}


/* ============================================================
 * RAINHA — Recursão simples
 * ------------------------------------------------------------
 * Idêntica em estrutura à Torre, mas imprime "Esquerda"
 * e usa CASAS_RAINHA como limite.
 *
 * Parâmetros:
 *   casasRestantes → casas ainda a percorrer.
 *   casaAtual      → número da casa para exibição.
 * ============================================================ */
void moverRainha(int casasRestantes, int casaAtual) {

    /* caso base */
    if (casasRestantes == 0) {
        return;
    }

    printf("  Casa %d: Esquerda\n", casaAtual);

    moverRainha(casasRestantes - 1, casaAtual + 1);
}


/* ============================================================
 * CAVALO — Loop aninhado com múltiplas variáveis e condições
 * ------------------------------------------------------------
 * Movimento em L: 2 casas para Cima + 1 casa para Direita.
 *
 * Loop EXTERNO (for): controla as casas verticais (Cima).
 *   - múltiplas variáveis na inicialização: passo e totalPassos
 *   - condição composta: passo <= totalPassos && passo > 0
 *   - uso de 'continue': pula a impressão do passo lateral
 *     enquanto o movimento vertical ainda não terminou
 *
 * Loop INTERNO (for): controla as casas horizontais (Direita).
 *   - múltiplas variáveis: lateral e totalLateral
 *   - uso de 'break': encerra o loop interno após executar
 *     o único passo lateral permitido pelo movimento em L
 * ============================================================ */
void moverCavalo(void) {

    /*
     * Declaração com múltiplas variáveis no for externo:
     *   passo       → contador corrente (1 a CAVALO_VERTICAL)
     *   totalPassos → limite máximo de passos verticais
     */
    for (int passo = 1, totalPassos = CAVALO_VERTICAL;
         passo <= totalPassos && passo > 0;   /* condição múltipla */
         passo++) {

        printf("  Passo vertical %d de %d: Cima\n", passo, totalPassos);

        /*
         * 'continue': enquanto não chegamos ao último passo
         * vertical, pulamos o bloco do movimento horizontal
         * e voltamos imediatamente ao início do loop externo.
         */
        if (passo < totalPassos) {
            continue;
        }

        /* --- chegou ao último passo vertical: faz o L --- */
        printf("\n  --> Concluiu %d casas para Cima. Executando passo lateral:\n\n",
               totalPassos);

        /*
         * Loop INTERNO com múltiplas variáveis:
         *   lateral      → contador do passo horizontal
         *   totalLateral → limite (CAVALO_HORIZONTAL = 1)
         */
        for (int lateral = 1, totalLateral = CAVALO_HORIZONTAL;
             lateral <= totalLateral;
             lateral++) {

            printf("  Passo horizontal %d de %d: Direita\n", lateral, totalLateral);

            /*
             * 'break': o movimento em L exige exatamente
             * CAVALO_HORIZONTAL passos laterais. Ao atingi-los,
             * encerramos explicitamente o loop interno.
             */
            if (lateral == totalLateral) {
                break;
            }
        }
    }
}


/* ============================================================
 * MAIN — Orquestra a execução de todas as peças
 * ============================================================ */
int main(void) {

    /* --------------------------------------------------------
     * BISPO
     * -------------------------------------------------------- */
    printf("============================================\n");
    printf("  BISPO — Diagonal Superior Direita\n");
    printf("  %d casas | Recursão + Loops Aninhados\n", CASAS_BISPO);
    printf("============================================\n");
    moverBispo(CASAS_BISPO, 1);

    /* --------------------------------------------------------
     * TORRE
     * -------------------------------------------------------- */
    printf("\n============================================\n");
    printf("  TORRE — Direita\n");
    printf("  %d casas | Recursão\n", CASAS_TORRE);
    printf("============================================\n");
    moverTorre(CASAS_TORRE, 1);

    /* --------------------------------------------------------
     * RAINHA
     * -------------------------------------------------------- */
    printf("\n============================================\n");
    printf("  RAINHA — Esquerda\n");
    printf("  %d casas | Recursão\n", CASAS_RAINHA);
    printf("============================================\n");
    moverRainha(CASAS_RAINHA, 1);

    /* --------------------------------------------------------
     * CAVALO
     * -------------------------------------------------------- */
    printf("\n============================================\n");
    printf("  CAVALO — L (Cima + Direita)\n");
    printf("  %d vertical + %d horizontal\n",
           CAVALO_VERTICAL, CAVALO_HORIZONTAL);
    printf("  Loops aninhados | continue & break\n");
    printf("============================================\n");
    moverCavalo();

    printf("\n============================================\n");
    printf("  Nível Mestre concluído!\n");
    printf("============================================\n");

    return 0;
}
