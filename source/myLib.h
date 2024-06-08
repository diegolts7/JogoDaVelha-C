#include <stdio.h>
#include <stdlib.h>

void imprimirMatriz();
void zerarMatriz();
void jogada(int player, int rows, int colum);
void inicioJogo();
void fazerJogada(int player);
int verificaJogada(int player);
int calculoLinha(char caractere);
int calculoColuna(char caractere);
int calculoDiagonal(char caractere);