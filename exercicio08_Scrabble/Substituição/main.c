<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include "substituicao.h"

int main()
{

    char chave[26];
    int analizeChave;

    printf("Digite a chave de criptografia: ");
    scanf("%s", chave);

    analizeChave = validaChave(chave);

    if(analizeChave == 1)
        auxConvert(chave);
    else
        printf("Fim do programa!\n");

    return 0;
}

=======
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

>>>>>>> 75ad35fc9baae2a24d1cb7946a2d0c17e4737d88
