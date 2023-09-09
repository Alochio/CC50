#include<stdio.h>
#include<stdlib.h>

void criptoCaesar()
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

    int key = inserirChave();

    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if (buffer[i] >= 'a' && buffer[i] <= 'z')
        {
            buffer[i] = 'a' + (buffer[i] - 'a' + key) % 26;
        }
        else if (buffer[i] >= 'A' && buffer[i] <= 'Z')
        {
            buffer[i] = 'A' + (buffer[i] - 'A' + key) % 26;
        }
    }

    printf("%s", buffer);
}

int inserirChave()
{
    int k, aux = 0;
    int limiteSuperior = (pow(2,31)) - 26;

    while(aux == 0)
    {
        printf("Digite a chave de criptografia: ");
        scanf("%d", &k);

        if(k < 1 || k > limiteSuperior)
        {
            printf("\nERRO!!\n");
        }
        else
        {
            aux = 1;
        }
    }

    return k;
}

int pow(int base, int expoente)
{

    int resultado = base;

    for(int i = 1; i <= expoente; i++)
    {
        resultado = resultado * base;
    }
    return resultado;
}
