#include <stdio.h>
#include <stdlib.h>

void solicitaDados();
int numDigitos(long long int numCartao);
int analisaValidade(long long int numCartao, int numDigitos);
void verificaBandeira(long long int numCartao);

int main()
{
    solicitaDados();

    return 0;
}

void solicitaDados()
{
    long long int numCartao;
    int status;
    printf("Digite o numero do seu cartao: ");
    scanf("%lld", &numCartao);
    status = analisaValidade(numCartao, numDigitos(numCartao));
    if(status==1)
    {
        verificaBandeira(numCartao);
    }
}

int numDigitos(long long int numCartao)
{

    int contDigitos = 0;
    long long int varAux = numCartao;

    for(int i=0; varAux!=0; i++)
    {
        varAux = varAux / 10;
        contDigitos = contDigitos + 1;
    }

    return contDigitos;
}

int analisaValidade(long long int numCartao, int numDigitos)
{

    int somadorDeAnalise = 0, somador = 0;
    long long int varAux = numCartao;
    int digitoOperacao;

    for(int i=1; i<=numDigitos; i++)
    {
        if(i%2 == 0)
        {
            varAux /= 10;
            digitoOperacao = varAux % 10;
            if(digitoOperacao <= 4)
            {
                somadorDeAnalise = somadorDeAnalise + (digitoOperacao * 2);
            }
            else
            {
                switch(digitoOperacao)
                {
                case 5:
                    somadorDeAnalise = somadorDeAnalise + 1;
                    break;
                case 6:
                    somadorDeAnalise = somadorDeAnalise + 3;
                    break;
                case 7:
                    somadorDeAnalise = somadorDeAnalise + 5;
                    break;
                case 8:
                    somadorDeAnalise = somadorDeAnalise + 7;
                    break;
                case 9:
                    somadorDeAnalise = somadorDeAnalise + 9;
                    break;
                default:
                    break;
                }
            }
        }
        else if (i%2!=0)
        {
            if(i == 1)
            {
                digitoOperacao = varAux % 10;
                somador = somador + digitoOperacao;
            }
            else
            {
                varAux /= 10;
                digitoOperacao = varAux % 10;
                somador = somador + digitoOperacao;
            }
        }
    }

    somador = somador + somadorDeAnalise;

    if(somador % 10 == 0)
    {
        return 1;
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

void verificaBandeira(long long int numCartao)
{

    int digitoInicial, contDigitos;
    long long int varAux = numCartao;

    contDigitos = numDigitos(numCartao);

    varAux = numCartao;

    for(int i=1; i <= contDigitos - 2; i++)
    {
        varAux = varAux / 10;
    }

    digitoInicial = varAux;

    if(digitoInicial == 34 || digitoInicial == 37)
    {
        if(contDigitos == 15)
        {
            printf("AMEX\n");
        }

    }
    else if(digitoInicial == 51 ||
            digitoInicial == 52 ||
            digitoInicial == 53 ||
            digitoInicial == 54 ||
            digitoInicial == 55)
    {
        if(contDigitos == 16)
        {
            printf("MASTERCARD\n");
        }

    }
    else if (digitoInicial == 51 ||
             digitoInicial == 40 ||
             digitoInicial == 41 ||
             digitoInicial == 42 ||
             digitoInicial == 43 ||
             digitoInicial == 44 ||
             digitoInicial == 45 ||
             digitoInicial == 46 ||
             digitoInicial == 47 ||
             digitoInicial == 48 ||
             digitoInicial == 49)
    {
        if (contDigitos == 13 || contDigitos == 16)
        {
            printf("VISA\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
