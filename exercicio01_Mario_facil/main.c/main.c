#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tam = 0, status = 0;

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

    for(int i = 0; i<tam; i++){
        for(int j = tam-1; j>=0; j--){
            if(i>=j){
                printf("#");
            }else if (i<j){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
