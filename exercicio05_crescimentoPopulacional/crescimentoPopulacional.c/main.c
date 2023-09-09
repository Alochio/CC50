#include<stdio.h>
#include<stdlib.h>

void crescimentoPopulacional(int numInicial, int numFinal);

int main(void)
{
    int numInicialLhamas = 0, numFinalLhamas = 0, status = 0, alert = 0;

    while(status = 1)
    {
        if(numInicialLhamas <= 0 || numFinalLhamas <= numInicialLhamas)
        {
            if(alert == 1){
                printf("\nValor invalido, digite novamente!!\n\n");
            }
            printf("Digite a quantidade inicial de Lhamas: ");
            scanf("%d", &numInicialLhamas);
            printf("Digite quantas Lhamas deseja ter: ");
            scanf("%d", &numFinalLhamas);
            status = 1;
            alert = 1;
        }
        else
        {
            status = 0;
            break;
        }
    }


    crescimentoPopulacional(numInicialLhamas, numFinalLhamas);
}

void crescimentoPopulacional(int numInicial, int numFinal)
{

    int somatorio = numInicial, contAnos = 0;

    do
    {
        somatorio = somatorio + (somatorio / 3) - (somatorio / 4);
        contAnos = contAnos+1;
        printf("Ano = %d,\tQtd de lhamas = %d\n", contAnos, somatorio);
    }
    while(somatorio < numFinal);
}
