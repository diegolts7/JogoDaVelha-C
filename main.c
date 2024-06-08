#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myLib.h"

int main()
{

    int parada = 0;
    inicioJogo();

    do
    {
        imprimirMatriz();

        fazerJogada(1);
        if (verificaJogada(1) == 1)
        {
            int opcao = -1;

            printf("Deseja começar outra rodada (digite 1) ou sair (digite qualquer outro numero): ");
            scanf(" %d", &opcao);
            if (opcao == 1)
            {
                zerarMatriz();
                continue;
            }
            else
            {
                parada = 1;
                continue;
            }
        }

        fazerJogada(2);

        if (verificaJogada(2) == 1)
        {
            int opcao = -1;

            printf("Deseja começar outra rodada (digite 1) ou sair (digite qualquer outro numero): ");
            scanf("%d", &opcao);
            if (opcao == 1)
            {
                zerarMatriz();
                continue;
            }
            else
            {
                parada = 1;
                continue;
            }
        }

    } while (parada != 1);

    return 0;
}
