#include<stdio.h>
#include<stdlib.h>

void readability()
{

    char *buffer = NULL;

    printf("Digite uma string: ");
    int len = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        buffer = (char *)realloc(buffer, (len + 1) * sizeof(char));
        buffer[len++] = ch;
    }

    buffer = (char *)realloc(buffer, (len + 1) * sizeof(char));
    buffer[len] = '\0';

    int numLetras   = conta_letra(buffer);
    int numPalavras = conta_palavras(buffer);
    int numFrases   = conta_frases(buffer);
    calcula_grade(numLetras, numFrases, numPalavras);

    free(buffer);

    return 0;
}

int conta_letra(char string[])
{
    int numLetras = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] >= 'a' && string[i] <= 'z')
            numLetras++;
        else if(string[i] >= 'A' && string[i] <= 'Z')
            numLetras++;
    }

    return numLetras;
}

int conta_palavras(char string[])
{
    int contaPalavras = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if(string[0] != NULL && i == 0)
            contaPalavras++;
        if(string[i] == ' ')
            contaPalavras++;
    }

    return contaPalavras;
}

int conta_frases(char string[])
{
    int contaFrases = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if(string[i] == '.' || string[i] == '!'  || string[i] == '?')
            contaFrases++;
    }

    if(string[0] != NULL && contaFrases == 0)
        contaFrases++;

    return contaFrases;
}

void calcula_grade(int numLetras, int numSentencas, int numPalavras)
{

    float mediaLetras = (100 / (float)numPalavras) * numLetras;
    float mediaSentencas = (100 / (float)numPalavras) * numSentencas;
    float indice = 0.0588 * mediaLetras - 0.296 * mediaSentencas - 15.8;

    int indiceArredondado = round(indice);

    if(indiceArredondado < 1)
        printf("Before Grade 1");
    if(indiceArredondado >= 1 && indiceArredondado <= 16)
        printf("Grade %d", indiceArredondado);
    if(indiceArredondado > 16)
        printf("Grade 16+");
}
