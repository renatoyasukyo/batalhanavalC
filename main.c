#include <stdio.h>
#include <stdlib.h>

int opcao_menu();
void menu();
int alocar_navios();
int navio_jogador1();
int navio_jogador2();
void imprimir_matriz(int matriz[10][10]);
void preencher_intervalo(int matriz[10][10], int linha_inicial, int coluna_inicial, int linha_final, int coluna_final);

int main()
{
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
    switch (opc)
    {
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
    switch (jogador)
    {
    case 1:
        navio_jogador1();
        menu();
    case 2:
        navio_jogador2();
        menu();
    default:
        printf("Jogador invalido\n");
        alocar_navios();
    }
}

int navio_jogador1()
{
    int matriz[10][10] = {0};
    int linhaInicial, colunaInicial, linhaFinal, colunaFinal;

    printf("Digite as coordenadas, da menor para a maior, do porta-avioes de 4 casas (exemplo: a1 e depois a4):\n");
    do
    {
        // Lendo a entrada do usuário
        char coordenadaInicial[3], coordenadaFinal[3];
        scanf("%s %s", coordenadaInicial, coordenadaFinal);

        // Obtendo as coordenadas em formato de números
        linhaInicial = coordenadaInicial[1] - '1';
        colunaInicial = coordenadaInicial[0] - 'a';
        linhaFinal = coordenadaFinal[1] - '1';
        colunaFinal = coordenadaFinal[0] - 'a';

        // Verificando a validade do intervalo
        if ((linhaInicial == linhaFinal && (colunaFinal - colunaInicial == 3 || colunaInicial - colunaFinal == 3)) ||
            (colunaInicial == colunaFinal && (linhaFinal - linhaInicial == 3 || linhaInicial - linhaFinal == 3)))
        {
            // Intervalo válido, preencher com 1
            preencher_intervalo(matriz, linhaInicial, colunaInicial, linhaFinal, colunaFinal);
            imprimir_matriz(matriz);
            break;
        }
        else
        {
            // Intervalo inválido, solicitar novamente
            printf("Intervalo inválido. Por favor, digite outro intervalo (exemplo: a1-a4):\n");
        }
    } while (1);

    for (int i = 0; i < 2; i++)
    {
        printf("Digite as coordenadas, da menor para a maior, do navio-tanque de 3 casas (exemplo: b1 e depois b3):\n");
        do
        {
            // Lendo a entrada do usuário
            char coordenadaInicial[3], coordenadaFinal[3];
            scanf("%s %s", coordenadaInicial, coordenadaFinal);

            // Obtendo as coordenadas em formato de números
            linhaInicial = coordenadaInicial[1] - '1';
            colunaInicial = coordenadaInicial[0] - 'a';
            linhaFinal = coordenadaFinal[1] - '1';
            colunaFinal = coordenadaFinal[0] - 'a';

            // Verificando a validade do intervalo
            if ((linhaInicial == linhaFinal && (colunaFinal - colunaInicial == 2 || colunaInicial - colunaFinal == 2)) ||
                (colunaInicial == colunaFinal && (linhaFinal - linhaInicial == 2 || linhaInicial - linhaFinal == 2)))
            {
                // Intervalo válido, preencher com 1
                preencher_intervalo(matriz, linhaInicial, colunaInicial, linhaFinal, colunaFinal);
                imprimir_matriz(matriz);
                break;
            }
            else
            {
                // Intervalo inválido, solicitar novamente
                printf("Intervalo inválido. Por favor, digite outro intervalo (exemplo: b1-b3):\n");
            }
        } while (1);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Digite as coordenadas, da menor para a maior, do contratorpedeiro de 2 casas (exemplo: c1 e depois c2):\n");
        do
        {
            // Lendo a entrada do usuário
            char coordenadaInicial[3], coordenadaFinal[3];
            scanf("%s %s", coordenadaInicial, coordenadaFinal);

            // Obtendo as coordenadas em formato de números
            linhaInicial = coordenadaInicial[1] - '1';
            colunaInicial = coordenadaInicial[0] - 'a';
            linhaFinal = coordenadaFinal[1] - '1';
            colunaFinal = coordenadaFinal[0] - 'a';

            // Verificando a validade do intervalo
            if ((linhaInicial == linhaFinal && (colunaFinal - colunaInicial == 1 || colunaInicial - colunaFinal == 1)) ||
                (colunaInicial == colunaFinal && (linhaFinal - linhaInicial == 1 || linhaInicial - linhaFinal == 1)))
            {
                // Intervalo válido, preencher com 1
                preencher_intervalo(matriz, linhaInicial, colunaInicial, linhaFinal, colunaFinal);
                imprimir_matriz(matriz);
                break;
            }
            else
            {
                // Intervalo inválido, solicitar novamente
                printf("Intervalo inválido. Por favor, digite outro intervalo (exemplo: c1-c2):\n");
            }
        } while (1);
    }

    for (int i = 0; i < 4; i++)
    {
        printf("Digite as coordenadas do submarino de 1 casa (exemplo: d1):\n");
        do
        {
            char coordenada[3];
            scanf("%s", coordenada);

            linhaFinal = coordenada[1] - '1';
            colunaFinal = coordenada[0] - 'a';

            if (linhaFinal >= 0 && linhaFinal < 10 && colunaFinal >= 0 && colunaFinal < 10)
            {
                matriz[linhaFinal][colunaFinal] = 1;
                imprimir_matriz(matriz);
                break;
            }
            else
            {
                printf("Coordenada inválida. Por favor, digite outra coordenada (exemplo: a1):\n");
            }
        } while (1);
    }
}

int navio_jogador2()
{
    int matriz[10][10] = {0};
    int linhaInicial, colunaInicial, linhaFinal, colunaFinal;

    printf("Digite as coordenadas, da menor para a maior, do porta-avioes de 4 casas (exemplo: a1 e depois a4):\n");
    do
    {
        // Lendo a entrada do usuário
        char coordenadaInicial[3], coordenadaFinal[3];
        scanf("%s %s", coordenadaInicial, coordenadaFinal);

        // Obtendo as coordenadas em formato de números
        linhaInicial = coordenadaInicial[1] - '1';
        colunaInicial = coordenadaInicial[0] - 'a';
        linhaFinal = coordenadaFinal[1] - '1';
        colunaFinal = coordenadaFinal[0] - 'a';

        // Verificando a validade do intervalo
        if ((linhaInicial == linhaFinal && (colunaFinal - colunaInicial == 3 || colunaInicial - colunaFinal == 3)) ||
            (colunaInicial == colunaFinal && (linhaFinal - linhaInicial == 3 || linhaInicial - linhaFinal == 3)))
        {
            // Intervalo válido, preencher com 1
            preencher_intervalo(matriz, linhaInicial, colunaInicial, linhaFinal, colunaFinal);
            imprimir_matriz(matriz);
            break;
        }
        else
        {
            // Intervalo inválido, solicitar novamente
            printf("Intervalo inválido. Por favor, digite outro intervalo (exemplo: a1-a4):\n");
        }
    } while (1);

    for (int i = 0; i < 2; i++)
    {
        printf("Digite as coordenadas, da menor para a maior, do navio-tanque de 3 casas (exemplo: b1 e depois b3):\n");
        do
        {
            // Lendo a entrada do usuário
            char coordenadaInicial[3], coordenadaFinal[3];
            scanf("%s %s", coordenadaInicial, coordenadaFinal);

            // Obtendo as coordenadas em formato de números
            linhaInicial = coordenadaInicial[1] - '1';
            colunaInicial = coordenadaInicial[0] - 'a';
            linhaFinal = coordenadaFinal[1] - '1';
            colunaFinal = coordenadaFinal[0] - 'a';

            // Verificando a validade do intervalo
            if ((linhaInicial == linhaFinal && (colunaFinal - colunaInicial == 2 || colunaInicial - colunaFinal == 2)) ||
                (colunaInicial == colunaFinal && (linhaFinal - linhaInicial == 2 || linhaInicial - linhaFinal == 2)))
            {
                // Intervalo válido, preencher com 1
                preencher_intervalo(matriz, linhaInicial, colunaInicial, linhaFinal, colunaFinal);
                imprimir_matriz(matriz);
                break;
            }
            else
            {
                // Intervalo inválido, solicitar novamente
                printf("Intervalo inválido. Por favor, digite outro intervalo (exemplo: b1-b3):\n");
            }
        } while (1);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Digite as coordenadas, da menor para a maior, do contratorpedeiro de 2 casas (exemplo: c1 e depois c2):\n");
        do
        {
            // Lendo a entrada do usuário
            char coordenadaInicial[3], coordenadaFinal[3];
            scanf("%s %s", coordenadaInicial, coordenadaFinal);

            // Obtendo as coordenadas em formato de números
            linhaInicial = coordenadaInicial[1] - '1';
            colunaInicial = coordenadaInicial[0] - 'a';
            linhaFinal = coordenadaFinal[1] - '1';
            colunaFinal = coordenadaFinal[0] - 'a';

            // Verificando a validade do intervalo
            if ((linhaInicial == linhaFinal && (colunaFinal - colunaInicial == 1 || colunaInicial - colunaFinal == 1)) ||
                (colunaInicial == colunaFinal && (linhaFinal - linhaInicial == 1 || linhaInicial - linhaFinal == 1)))
            {
                // Intervalo válido, preencher com 1
                preencher_intervalo(matriz, linhaInicial, colunaInicial, linhaFinal, colunaFinal);
                imprimir_matriz(matriz);
                break;
            }
            else
            {
                // Intervalo inválido, solicitar novamente
                printf("Intervalo inválido. Por favor, digite outro intervalo (exemplo: c1-c2):\n");
            }
        } while (1);
    }

    for (int i = 0; i < 4; i++)
    {
        printf("Digite as coordenadas do submarino de 1 casa (exemplo: d1):\n");
        do
        {
            char coordenada[3];
            scanf("%s", coordenada);

            linhaFinal = coordenada[1] - '1';
            colunaFinal = coordenada[0] - 'a';

            if (linhaFinal >= 0 && linhaFinal < 10 && colunaFinal >= 0 && colunaFinal < 10)
            {
                matriz[linhaFinal][colunaFinal] = 1;
                imprimir_matriz(matriz);
                break;
            }
            else
            {
                printf("Coordenada inválida. Por favor, digite outra coordenada (exemplo: a1):\n");
            }
        } while (1);
    }
}

void imprimir_matriz(int matriz[10][10])
{
    printf("\nMatriz resultante:\n");

    printf("\t");
    for (int coluna = 0; coluna < 10; coluna++)
    {
        printf("%c\t", 'A' + coluna);
    }
    printf("\n");

    for (int linha = 0; linha < 10; linha++)
    {
        printf("%d\t", linha + 1);

        for (int coluna = 0; coluna < 10; coluna++)
        {
            printf("%d\t", matriz[linha][coluna]);
        }
        printf("\n");
    }
}

void preencher_intervalo(int matriz[10][10], int linha_inicial, int coluna_inicial, int linha_final, int coluna_final)
{
    for (int linha = linha_inicial; linha <= linha_final; linha++)
    {
        for (int coluna = coluna_inicial; coluna <= coluna_final; coluna++)
        {
            matriz[linha][coluna] = 1;
        }
    }
}