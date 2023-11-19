#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main() {

    unsigned char armario = 0;
    unsigned char alocar;
    int menu = 0, i;


    srand (time(NULL));

    while(menu!=3){

        puts("----------------------------------------");
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

            if(armario == 255){
                puts("Todos os armários já estão ocupados");
            } else {
                do {
                    alocar = rand() % 8;
                  } while (armario & (1 << alocar));
                 armario |= (1 << alocar);
            }
            
        } else if (menu == 2){
        
            if(armario == 0){
                    puts("Todos os armários já estão desocupados");
            } else {
                puts("Digite o número do armário para desocupar (0-7):");
                scanf("%d", &i);
                if (i >= 0 && i < 8 && (armario & (1 << i))) {
                    armario &= ~(1 << i);
                    printf("Armário %d desocupado\n", i);
                } else {
                    puts("Armário inválido ou já está desocupado");
                }
            }
        }
    }

    return 0;
    
}