#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 6
#define COLUNAS 6
#define NUM_BOMBAS 3
#define NUM_TENTATIVAS 5

void inicializa_campo(char campo[LINHAS][COLUNAS]);
void posiciona_bombas(char campo[LINHAS][COLUNAS]);
void exibe_campo(char campo[LINHAS][COLUNAS]);
int verifica_jogada(char campo[LINHAS][COLUNAS], int linha, int coluna);

int main() {
    char campo[LINHAS][COLUNAS];
    int linha, coluna, tentativas = NUM_TENTATIVAS;

    srand(time(NULL)); 

    inicializa_campo(campo);
    posiciona_bombas(campo);

    printf("Bem-vindo ao Campo Minado!\n");
    exibe_campo(campo);

    while (tentativas > 0) {
        printf("\nDigite a linha e coluna da sua jogada (1-%d): ", LINHAS);
        scanf("%d %d", &linha, &coluna);

        linha--; 
        coluna--;

        if (verifica_jogada(campo, linha, coluna)) {
            printf("Você encontrou uma bomba! Você perdeu.\n");
            campo[linha][coluna] = 'X';
            exibe_campo(campo);
            break;
        } else {
            printf("Parabéns! Você acertou!\n");
            campo[linha][coluna] = 'O';
            exibe_campo(campo);
            tentativas--;
        }
    }

    if (tentativas == 0) {
        printf("Parabéns! Você venceu!\n");
    }

    return 0;
}

void inicializa_campo(char campo[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            campo[i][j] = ' ';
        }
    }
}

void posiciona_bombas(char campo[LINHAS][COLUNAS]) {
    int linha, coluna, bombas_colocadas = 0;

    while (bombas_colocadas < NUM_BOMBAS) {
        linha = rand() % LINHAS;
        coluna = rand() % COLUNAS;
        if (campo[linha][coluna] != 'B') {
            campo[linha][coluna] = 'B';
            bombas_colocadas++;
        }
    }
}

void exibe_campo(char campo[LINHAS][COLUNAS]) {
    printf("  A B C D E F\n");
    for (int i = 0; i < LINHAS; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < COLUNAS; j++) {
            printf("[%c] ", campo[i][j]);
        }
        printf("\n");
    }
}

int verifica_jogada(char campo[LINHAS][COLUNAS], int linha, int coluna) {
    return campo[linha][coluna] == 'B';
}