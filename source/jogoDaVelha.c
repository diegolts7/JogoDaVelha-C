#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "myLib.h"

const int tam = 3;

char mat[3][3] = {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}};

int contEmpate = 0;

void imprimirMatriz()
{
    system("clear");
    printf("--------------------------------------------------------------\n\n");
    printf("     0   1   2\n\n");

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (j == 0)
            {

                printf("%d   ", i);
            }
            printf(" %c ", mat[i][j]);
            if (j < 2)
            {
                printf("│");
            }
        }
        if (i < tam - 1)
        {
            printf("\n   ⎺⎺⎺⎺│⎺⎺⎺│⎺⎺⎺⎺\n");
        }
    }
    printf("\n\n--------------------------------------------------------------\n\n");
}

void jogada(int player, int rows, int colum)
{
    if (player == 1)
    {
        mat[rows][colum] = 'X';
    }
    else
    {
        mat[rows][colum] = 'O';
    }
    contEmpate++;
    imprimirMatriz();
}

void inicioJogo()
{
    system("clear");
    printf("-----------------------------------------------\n\n▀▄▀▄▀▄ SEJA BEM VINDO AO JOGO DA VELHA ▀▄▀▄▀▄\n\n-----------------------------------------------\n\n");

    sleep(1.5);
    printf("Clique para começar 😃👍 ");
    getchar();
}

void fazerJogada(int player)
{
    int linha = -1;
    int coluna = -1;
    if (player == 1)
    {
        printf("\nVez do jogador X. Informe as coordenadas linha e coluna (EX: 0 2): ");
        scanf("%d %d", &linha, &coluna);
        while ((linha < 0 || linha >= tam) || (coluna < 0 || coluna >= tam) || (mat[linha][coluna] == 'O' || mat[linha][coluna] == 'X'))
        {
            printf("\nO jogador X precisa informar coordenadas válidas : ");
            scanf("%d %d", &linha, &coluna);
        }
        jogada(player, linha, coluna);
    }
    else
    {
        printf("\nVez do jogador O - bolinha. Informe as coordenadas linha e coluna (EX: 0 2): ");
        scanf("%d %d", &linha, &coluna);
        while ((linha < 0 || linha >= tam) || (coluna < 0 || coluna >= tam) || (mat[linha][coluna] == 'O' || mat[linha][coluna] == 'X'))
        {
            printf("\nO jogador O - bolinha precisa informar coordenadas válidas : ");
            scanf("%d %d", &linha, &coluna);
        }
        jogada(player, linha, coluna);
    }
}

void zerarMatriz()
{
    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            mat[i][j] = ' ';
        }
    }
}

int verificaJogada(int player)
{

    if (player == 1)
    {
        if (calculoLinha('X') == 1 || calculoColuna('X') == 1 || calculoDiagonal('X'))
        {
            printf("*************************************\n\nParábens jogador X, você venceu!!!! 😃👍\n\n*************************************\n\n");
            contEmpate = 0;
            return 1;
        }
        else if (contEmpate == 9)
        {
            printf("*************************************\n\nJogo empatado!!!!  😞😞\n\n*************************************\n\n");
            contEmpate = 0;
            return 1;
        }
    }
    else
    {
        if (calculoLinha('O') == 1 || calculoColuna('O') == 1 || calculoDiagonal('O'))
        {
            printf("*************************************\n\nParábens jogador O - bolinha, você venceu!!!! 😃👍\n\n*************************************\n\n");
            contEmpate = 0;
            return 1;
        }
        else if (contEmpate == 9)
        {
            printf("*************************************\n\nJogo empatado!!!!  😞😞\n\n*************************************\n\n");
            contEmpate = 0;
            return 1;
        }
    }

    return 0;
}

int calculoLinha(char caractere)
{

    for (int i = 0; i < tam; i++)
    {
        int contLinha = 0;
        for (int j = 0; j < tam; j++)
        {
            if (mat[i][j] == caractere)
            {
                contLinha++;
            }
        }
        if (contLinha == 3)
        {
            return 1;
        }
    }
    return 0;
}
int calculoColuna(char caractere)
{

    for (int i = 0; i < tam; i++)
    {
        int contColuna = 0;
        for (int j = 0; j < tam; j++)
        {
            if (mat[j][i] == caractere)
            {
                contColuna++;
            }
        }
        if (contColuna == 3)
        {
            return 1;
        }
    }
    return 0;
}

int calculoDiagonal(char caractere)
{

    if (mat[0][0] == caractere && mat[1][1] == caractere && mat[2][2] == caractere)
    {
        return 1;
    }
    if (mat[0][2] == caractere && mat[1][1] == caractere && mat[2][0] == caractere)
    {
        return 1;
    }
    return 0;
}