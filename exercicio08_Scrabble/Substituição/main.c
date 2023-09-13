#include <stdio.h>
#include <stdlib.h>
#include "substituicao.h"

int main() {
    char chave[27];  // A chave precisa ter 26 caracteres mais o caractere nulo.
    printf("Digite a chave (26 letras maiusculas ou minusculas): ");
    scanf("%26s", chave);

    if (validaChave(chave)) {
        auxConvert(chave);
    } else {
        printf("Chave invalida.\n");
    }

    return 0;
}
