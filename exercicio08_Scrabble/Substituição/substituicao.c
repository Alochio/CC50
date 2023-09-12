#include<stdio.h>
#include<stdlib.h>

int validaChave(char chave[])
{
    int contCaracteres, analizaCaracteres = 0, status = 0;

    for(contCaracteres = 0; chave[contCaracteres] != '\0'; contCaracteres++)
        if (chave[contCaracteres] >= 'a' && chave[contCaracteres] <= 'z')
            analizaCaracteres += 1;
        else if(chave[contCaracteres] >= 'A' && chave[contCaracteres] <= 'Z')
            analizaCaracteres += 1;

    if(contCaracteres != 26 || analizaCaracteres != 26)
    {
        printf("\n\nA chave nao correspondo ao padrao!\n");
        return 0;
    }
    else
        return 1;
}


void auxConvert(char chave[])
{

    int vetor[26], vetorMaiusculo[26], vetorMinusculo[26], vetorResultante[26];

    for(int i = 0; i < 26; i++)
    {
        if(i == 0)
            vetorMaiusculo[i] = 65;
        else
            vetorMaiusculo[i] = vetorMaiusculo[i-1] + 1;
    }

    for(int i = 0; i < 26; i++)
    {
        if(i == 0)
            vetorMinusculo[i] = 97;
        else
            vetorMinusculo[i] = vetorMinusculo[i-1] + 1;
    }

    for(int i = 0; chave[i] != '\0'; i++)
    {
        if (chave[i] >= 'a' && chave[i] <= 'z')
        {
            vetorResultante[i] = chave[i] - vetorMinusculo[i];
            printf("\minusculo = %d\n",vetorResultante[i]);
        }
        else if(chave[i] >= 'A' && chave[i] <= 'Z')
        {
            vetorResultante[i] = chave[i] - vetorMaiusculo[i];
            printf("\tmaiusculo = %d\n",vetorResultante[i]);
        }
    }

    textoSimples(chave, vetorResultante);
}



void textoSimples(char chave[], int vetorResultante[])
{
    char *buffer = NULL;
    int len = 0;
    int ch;

    printf("Digite o texto que sera criptografado: ");

    buffer = (char *)malloc(1024);

    if (buffer != NULL && scanf(" %[^\n]%*c", buffer) == 1)
    {
        len = strlen(buffer);

        printf("\nTexto simples: \n%s\n\n", buffer);

/*
        for(int i = 0; buffer[i] != '\0'; i++)
        {

            if (buffer[i] >= 'a' && buffer[i] <= 'z')
            {
                for(int j = 97; j < 122; j++)
                {
                    if(buffer[i] == j)
                    {
                        buffer[i] = buffer[i] - vetorResultante[j-97];
                    }
                }
            }

            else if(chave[i] >= 'A' && chave[i] <= 'Z')
            {



            }
        }

        printf("\nTexto sifrado: \n%s\n\n", buffer);
*/
    }
    else
    {
        printf("Erro ao ler o texto.\n");
    }
    free(buffer);
}
