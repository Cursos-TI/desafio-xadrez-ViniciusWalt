#include <stdio.h>

/*
MateCheck — Nível Mestre
- Torre/Bispo/Rainha com recursividade
- Bispo também com loops aninhados (vertical externo, horizontal interno)
- Cavalo com loops aninhados + condições (continue/break)
- Sem entrada do usuário; imprime direções por casa e uma linha em branco entre peças
*/

/* Torre: N casas para a Direita (recursivo). */
static void moverTorreRecursivo(int casasRestantes)
{
    if (casasRestantes <= 0)
    {
        return;
    }

    printf("Direita\n");
    moverTorreRecursivo(casasRestantes - 1);
}

/* Bispo: N casas na diagonal (Cima + Direita) com recursão e loops aninhados. */
static void moverBispoRecursivoComLoopsAninhados(int casasRestantes)
{
    if (casasRestantes <= 0)
    {
        return;
    }

        /* 1 passo diagonal = 1x Cima (externo) + 1x Direita (interno). */
    for (int vertical = 0; vertical < 1; vertical++)
    {
        printf("Cima\n");

        for (int horizontal = 0; horizontal < 1; horizontal++)
        {
            printf("Direita\n");
        }
    }

    moverBispoRecursivoComLoopsAninhados(casasRestantes - 1);
}

/* Rainha: N casas para a Esquerda (recursivo). */
static void moverRainhaRecursivo(int casasRestantes)
{
    if (casasRestantes <= 0)
    {
        return;
    }

    printf("Esquerda\n");
    moverRainhaRecursivo(casasRestantes - 1);
}

/* Cavalo: 1 movimento em L (Cima, Cima, Direita) com loops aninhados + condições. */
static void moverCavaloLoopsComplexos(void)
{
    const int subir = 2;
    const int direita = 1;

    for (int v = 0; v <= subir; v++)
    {
        for (int h = 0; h <= direita; h++)
        {
            if (v < subir)
            {
                if (h > 0)
                {
                    continue;
                }
                printf("Cima\n");
            }
            else
            {
                if (h < direita)
                {
                    continue;
                }
                printf("Direita\n");
                break;
            }
        }
    }
}

int main(void)
{
        /* Valores do enunciado (definidos no código). */
    const int casasTorre = 5;
    const int casasBispo = 5;
    const int casasRainha = 8;

    moverTorreRecursivo(casasTorre);
    printf("\n");

    moverBispoRecursivoComLoopsAninhados(casasBispo);
    printf("\n");

    moverRainhaRecursivo(casasRainha);
    printf("\n");

    moverCavaloLoopsComplexos();

    return 0;
}
