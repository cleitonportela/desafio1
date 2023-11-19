#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define unsigned char armario = 0;

int main() {

    unsigned char alocar;
    int menu = 0, i;

    while(menu!=3){

        printf("Armários disponiveis: ");
            for(i=7;i>=0;i--){
                printf("%d",(armario>>i)&1);
            }
        puts("\nNúmero -------------- 76543210");

        puts("Escolha umas das opções de menu abaixo");
        puts("1. Ocupar armário.");
        puts("2. Liberar armário");
        puts("3. Sair");
        puts("Digite a opção:");
        scanf("%d", &menu);

        if (menu == 1){

                srand (time(NULL));
                do {
                    alocar = rand() % 8;
                } while (armario & (1 << alocar));
                armario |= (1 << alocar);
            
        } else if (menu == 2){
        
            printf("Digite o número do armário para desocupar (0-7): ");
            scanf("%d", &i);
            if (i >= 0 && i < 8 && (armario & (1 << i))) {
                armario &= ~(1 << i);
                printf("Armário %d desocupado\n", i);
            } else {
                printf("Armário inválido ou já está desocupado\n");
            }
        }
    }
}