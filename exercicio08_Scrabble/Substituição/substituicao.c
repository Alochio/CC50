#include<stdio.h>
#include<stdlib.h>

void validaChave(char chave[])
{
    int aux;
    for(aux = 0; chave[aux] != '\0'; aux++);

    if(aux != 26)
        printf("ERRO, numero de caracteres invalidos!");
}

void textoSimples(char chave[])
{
    char *buffer = NULL;
    int len = 0;
    int ch;

    printf("Digite o texto que sera criptografado: ");

    buffer = (char *)malloc(1024);

    if (buffer != NULL && scanf(" %[^\n]%*c", buffer) == 1) {
        len = strlen(buffer);


    for(int i = 0; chave[i] != '\0'; i++){
        if (chave[i] >= 'a' && chave[i] <= 'z')
        {
            printf("0");
        }
        else if(chave[i] >= 'A' && chave[i] <= 'Z')
        {
            printf("1");
        }
    }






/*

        for (int i = 0; buffer[i] != '\0'; i++)
    {

    }
*/

        printf("%s\n", buffer);
    } else {
        printf("Erro ao ler o texto.\n");
    }
    free(buffer);
}

