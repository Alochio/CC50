#include <stdio.h>
#include <stdlib.h>
#include "substituicao.h"

int main()
{


    char chave[26];

    printf("\n\nDigite a chave de criptografia: ");
    scanf("%s", chave);
    validaChave(chave);

    textoSimples(chave);

    return 0;
}

