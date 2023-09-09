#include <stdio.h>

int main() {

    int tam, status = 1;

    while(status = 1){
        if(tam < 1 || tam > 8){
            printf("Digite o tamanho da base (1 ao 8): ");
            scanf("%d", &tam);
            status = 1;
        }else{
            status = 0;
            break;
        }
    }

    int meio = tam;

    for (int i = 1; i <= tam; i++) {
        for (int j = 1; j <= tam - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("#");
        }

        printf(" ");

        for (int j = 1; j <= i; j++) {
            printf("#");
        }

        for (int j = 1; j <= tam - i; j++) {
            printf(" ");
        }

        printf("\n");
    }

    return 0;
}
