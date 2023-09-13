#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int pontosJogador01 = 0, pontosJogador02 = 0;
int rodada = 1;

void game();
void imprimeResultado();

int main() {
    game();
    return 0;
}

void game() {
    int continua = 1;

    while (continua == 1) {
        int pontosRoundJogador01 = 0, pontosRoundJogador02 = 0;

        char *palavra = NULL;
        int len = 0;
        int ch;

        printf("Jogador 1 - Digite a sua palavra: ");

        palavra = (char *)malloc(1024);

        if (palavra != NULL && scanf(" %[^\n]%*c", palavra) == 1) {
            len = strlen(palavra);
        }

        for (int i = 0; palavra[i] != '\0'; i++) {
            if (isalpha(palavra[i])) {
                int index = tolower(palavra[i]) - 'a';
                pontosRoundJogador01 += POINTS[index];
            }
        }

        free(palavra);

        palavra = NULL;
        len = 0;

        printf("Jogador 2 - Digite a sua palavra: ");

        palavra = (char *)malloc(1024);

        if (palavra != NULL && scanf(" %[^\n]%*c", palavra) == 1) {
            len = strlen(palavra);
        }

        for (int i = 0; palavra[i] != '\0'; i++) {
            if (isalpha(palavra[i])) {
                int index = tolower(palavra[i]) - 'a';
                pontosRoundJogador02 += POINTS[index];
            }
        }

        free(palavra);

        pontosJogador01 += pontosRoundJogador01;
        pontosJogador02 += pontosRoundJogador02;

        imprimeResultado();

        printf("\nDeseja continuar: 1 = sim, 0 = nao ");
        scanf("%d", &continua);

        if (continua != 0 && continua != 1) {
            continua = 1;
            printf("Valor invalido, fim do jogo!\n\n");
        } else if (continua == 0) {
            if (pontosJogador01 > pontosJogador02)
                printf("\n\nJogador 1 - WIN!\n\n");
            else if (pontosJogador01 < pontosJogador02)
                printf("\n\nJogador 2 - WIN!\n\n");
            else
                printf("\n\nEmpate\n\n");
        }

        rodada++;
    }
}

void imprimeResultado() {
    printf("\n\nRodada %d\nPontuacao gamer 01 = %d\nPontuacao gamer 02 = %d\n\n", rodada, pontosJogador01, pontosJogador02);
}
