#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void valoresEntrada();
void analiseValor(float valorCompra, float valorRecebido);
int converteEmCentavos(float valorTroco);
void funcaoGulosa(int troco);

int main()
{
   valoresEntrada();
    return 0;
}

void valoresEntrada(){

    float valorCompra, valorRecebido;

    printf("Digite o valor da compra: ");
    scanf("%f", &valorCompra);
    printf("Digite o valor que foi pago: ");
    scanf("%f", &valorRecebido);

    analiseValor(valorCompra, valorRecebido);
}

void analiseValor(float valorCompra, float valorRecebido){
    float valorTroco = valorRecebido - valorCompra;
    if(valorTroco>0){
        printf("\nO Valor do troco eh: %.2f\n\n", valorTroco);
        funcaoGulosa(converteEmCentavos(valorTroco));
    }else if(valorTroco == 0){
        printf("A compra nao possui troco!");
    }else if(valorTroco < 0){
        printf("Valor insuficiente, faltam %.2f", (valorTroco * -1));
        printf("\n\nSolicite ao cliente mais dinheiro e digite novamente os valores! \n\n");
        valoresEntrada();
    }
}

int converteEmCentavos(float valorTroco){
    int troco;
    valorTroco = valorTroco * 100;
    troco = round(valorTroco);
    return troco;
}

void funcaoGulosa(int troco){

    int notas[6] = {10000, 5000, 2000, 1000, 500, 200}; // Valores em centavos
    int moedas[6] = {100, 50, 25, 10, 5, 1}; // Valores em centavos
    int quantidadeNotas[6] = {0};
    int quantidadeMoedas[6] = {0};

    for (int i = 0; i < 6; i++) {
        if (notas[i] <= troco) {
            quantidadeNotas[i] = troco / notas[i];
            troco = troco % notas[i];
            if (quantidadeNotas[i] > 0) {
                printf("%d nota(s) de %d reais\n", quantidadeNotas[i], notas[i] / 100);
            }
        }
    }

    for (int i = 0; i < 6; i++) {
        if (moedas[i] <= troco) {
            quantidadeMoedas[i] = troco / moedas[i];
            troco = troco % moedas[i];
            if (quantidadeMoedas[i] > 0) {
                if(moedas[i] == 100){
                    printf("%d moeda(s) de 1 real\n", quantidadeMoedas[i], moedas[i]);
                }else{
                    printf("%d moeda(s) de %d centavos\n", quantidadeMoedas[i], moedas[i]);
                }
            }
        }
    }
}
