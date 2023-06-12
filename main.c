#include <stdio.h>
#include <stdlib.h>
#include <iostream.h> //para o ascchar funcionar

using namespace std; //para o ascchar funcionar

int opcao_menu();
void menu();
int alocar_navios();
int navio_jogador1();
int navio_jogador2();

int main()
{
    int inicio;
    printf("BATALHA NAVAL POR RENATO YASUKYO\n");
    printf("UNIFESP - SJC\n");
    printf("Pressione a tecla ENTER para continuar: ");
    getchar();
    menu();
}


void menu()
{
    printf("Selecione:\n");
    printf("1. Alocar navios\n");
    printf("2. Iniciar jogo\n");
    printf("3. Sair do jogo\n");
    opcao_menu();
}


int opcao_menu()
{
    int opc;
    scanf("%d", &opc);
    switch(opc){
        case 1:
            alocar_navios();
            break;
        /*case 2:               
            iniciar_jogo();
            break;*/
        case 3:
            return 0;
        default:
            printf("Opcao invalida.\n");
            menu();
        }
}

int alocar_navios()
{
    int jogador;
    printf("Selecione o jogador para alocar os navios: \n");
    scanf("%d", &jogador);
    switch(jogador){
    case 1:
        navio_jogador1();
        break;
    case 2:
        navio_jogador2();
        break;
    default:
        printf("Jogador invalido\n");
        alocar_navios();
    }
}

int navio_jogador1()
{
    int matriz[10][10];
    for(int i = 0; i < 10; i++){
        printf("O");
        for (int j = 0; j < 10; j++){
            printf("O");
        }
    }
}

int navio_jogador2()
{
    int matriz[10][10];
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            matriz[i][j] = 0;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
        printf("%c", ascChar--);
    }

}
