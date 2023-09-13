#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int validaChave(char chave[]) {
    int contCaracteres, analizaCaracteres = 0, status = 0;

    for (contCaracteres = 0; chave[contCaracteres] != '\0'; contCaracteres++) {
        if ((chave[contCaracteres] >= 'a' && chave[contCaracteres] <= 'z') ||
            (chave[contCaracteres] >= 'A' && chave[contCaracteres] <= 'Z')) {
            analizaCaracteres += 1;
        }
    }

    if (contCaracteres != 26 || analizaCaracteres != 26) {
        printf("\n\nA chave nao corresponde ao padrao!\n");
        return 0;
    } else {
        return 1;
    }
}

void auxConvert(char chave[]) {
    int vetorMaiusculo[26], vetorMinusculo[26], vetorResultante[26];

    for (int i = 0; i < 26; i++) {
        vetorMaiusculo[i] = 'A' + i;
        vetorMinusculo[i] = 'a' + i;
    }

    for (int i = 0; chave[i] != '\0'; i++) {
        if (chave[i] >= 'a' && chave[i] <= 'z')
            vetorResultante[i] = chave[i] - vetorMinusculo[i];
        else if (chave[i] >= 'A' && chave[i] <= 'Z')
            vetorResultante[i] = chave[i] - vetorMaiusculo[i];
    }

    textoSimples(chave, vetorResultante);
}

void textoSimples(char chave[], int vetorResultante[]) {
    char *buffer = NULL;
    int len = 0;

    printf("Digite o texto que sera criptografado: ");

    buffer = (char *)malloc(1024);

    if (buffer != NULL && scanf(" %[^\n]%*c", buffer) == 1) {
        len = strlen(buffer);

        printf("\nTexto simples: \n%s\n\n", buffer);

        for (int i = 0; i < len; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = 'a' + (buffer[i] - 'a' - vetorResultante[i]);
                if (buffer[i] < 'a') {
                    buffer[i] += 26;
                }
            } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = 'A' + (buffer[i] - 'A' - vetorResultante[i]);
                if (buffer[i] < 'A') {
                    buffer[i] += 26;
                }
            }
        }

        printf("\nTexto criptografado: \n%s\n\n", buffer);
    } else {
        printf("Erro ao ler o texto.\n");
    }
    free(buffer);
}


