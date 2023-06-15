#include <stdio.h>
#include <stdlib.h>


int menu(int matriz1[10][10], int matriz2[10][10]);
int alocar_navios(int matriz1[10][10], int matriz2[10][10]);
int navio_jogador1(int matriz[10][10]);
int navio_jogador2(int matriz[10][10]);
int ataque_jogador1(int matriz[10][10], int matriz_ataque[10][10], int *ponto1);
int ataque_jogador2(int matriz[10][10], int matriz_ataque[10][10], int *ponto2);
int iniciar_jogo(int matriz1[10][10], int matriz2[10][10]);
void imprimir_matriz(int matriz[10][10]);
void preencher_intervalo(int matriz[10][10], int linha_inicial, int coluna_inicial, int linha_final, int coluna_final);


int main()
{
    int matriz1[10][10] = {0};
    int matriz2[10][10] = {0};
    printf("BATALHA NAVAL POR RENATO YASUKYO\n");
    printf("UNIFESP - SJC\n");
    printf("Pressione a tecla ENTER para continuar: ");
    getchar();
    menu(matriz1, matriz2);
}


int menu(int matriz1[10][10], int matriz2[10][10])
{
    int opc;
    printf("Selecione:\n");
    printf("1. Alocar navios\n");
    printf("2. Iniciar jogo\n");
    printf("3. Sair do jogo\n");
    scanf("%d", &opc);
    switch (opc)
    {
    case 1:
        alocar_navios(matriz1, matriz2);
        break;
    case 2:
        iniciar_jogo(matriz1, matriz2);
        menu(matriz1, matriz2);
        break;
    case 3:
        printf("Finalizando o jogo...");
        return 0;
    default:
        printf("Opcao invalida.\n");
        menu(matriz1, matriz2);
    }
    return 0;
}


int alocar_navios(int matriz1[10][10], int matriz2[10][10])
{
    int jogador;

    printf("Selecione o jogador para alocar os navios: \n");
    scanf("%d", &jogador);
    switch (jogador)
    {
    case 1:
        navio_jogador(matriz1);
        menu(matriz1, matriz2);
        break;
    case 2:
        navio_jogador(matriz2);
        menu(matriz1, matriz2);
        break;
    default:
        printf("Jogador invalido\n");
        menu(matriz1, matriz2);
    }
    return 0;
}

int navio_jogador(int matriz[10][10])
{
    int linhaInicial, colunaInicial, linhaFinal, colunaFinal;

    printf("Digite as coordenadas, da menor para a maior, do porta-avioes de 4 casas (exemplo: a1 e depois a4):\n");
    do
    {
        char coordenadaInicial[4], coordenadaFinal[4]; // Aumentando o tamanho dos arrays para 4 caracteres
        scanf("%3s %3s", coordenadaInicial, coordenadaFinal); // Limitando a leitura a no máximo 3 caracteres

        colunaInicial = coordenadaInicial[0] - 'a';
        colunaFinal = coordenadaFinal[0] - 'a';

        linhaInicial = atoi(coordenadaInicial + 1) - 1;
        linhaFinal = atoi(coordenadaFinal + 1) - 1;

        if (((linhaInicial == linhaFinal && (colunaFinal - colunaInicial == 3)) ||
            (colunaInicial == colunaFinal && (linhaFinal - linhaInicial == 3))) &&
            linhaInicial >= 0 && linhaInicial <= 9 && linhaFinal >= 0 && linhaFinal <= 9 &&
            colunaInicial >= 0 && colunaInicial <= 9 && colunaFinal >= 0 && colunaFinal <= 9)
        {
            preencher_intervalo(matriz, linhaInicial, colunaInicial, linhaFinal, colunaFinal);
            imprimir_matriz(matriz);
            break;
        }
        else
        {
            printf("Intervalo invalido. Por favor, digite outro intervalo:\n");
        }
    } while (1);

    for (int i = 0; i < 2; i++)
    {
        printf("Digite as coordenadas, da menor para a maior, do navio-tanque de 3 casas (exemplo: b1 e depois b3):\n");
        do
        {
            char coordenadaInicial[4], coordenadaFinal[4]; // Aumentando o tamanho dos arrays para 4 caracteres
            scanf("%3s %3s", coordenadaInicial, coordenadaFinal); // Limitando a leitura a no máximo 3 caracteres

            colunaInicial = coordenadaInicial[0] - 'a';
            colunaFinal = coordenadaFinal[0] - 'a';

            linhaInicial = atoi(coordenadaInicial + 1) - 1;
            linhaFinal = atoi(coordenadaFinal + 1) - 1;

            if (((linhaInicial == linhaFinal && (colunaFinal - colunaInicial == 2)) ||
            (colunaInicial == colunaFinal && (linhaFinal - linhaInicial == 2))) &&
            linhaInicial >= 0 && linhaInicial <= 9 && linhaFinal >= 0 && linhaFinal <= 9 &&
            colunaInicial >= 0 && colunaInicial <= 9 && colunaFinal >= 0 && colunaFinal <= 9)
            {
            int posicaoInvalida = 0;
            for (int linha = linhaInicial; linha <= linhaFinal; linha++)
            {
                for (int coluna = colunaInicial; coluna <= colunaFinal; coluna++)
                {
                    if (matriz[linha][coluna] == 2)
                    {
                        posicaoInvalida = 1;
                        break;
                    }
                }
                if (posicaoInvalida)
                    break;
            }

            if (posicaoInvalida)
            {
                printf("Ja existe um navio nessa posicao. Por favor, digite outro intervalo :\n");
            }
            else
            {
                preencher_intervalo(matriz, linhaInicial, colunaInicial, linhaFinal, colunaFinal);
                imprimir_matriz(matriz);
                break;
            }
            }
        else
        {
            printf("Intervalo invalido. Por favor, digite outro intervalo:\n");
        }
    } while (1);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("Digite as coordenadas, da menor para a maior, do contratorpedeiro de 2 casas (exemplo: c1 e depois c2):\n");
        do
        {
            char coordenadaInicial[4], coordenadaFinal[4]; // Aumentando o tamanho dos arrays para 4 caracteres
            scanf("%3s %3s", coordenadaInicial, coordenadaFinal); // Limitando a leitura a no máximo 3 caracteres

            colunaInicial = coordenadaInicial[0] - 'a';
            colunaFinal = coordenadaFinal[0] - 'a';

            linhaInicial = atoi(coordenadaInicial + 1) - 1;
            linhaFinal = atoi(coordenadaFinal + 1) - 1;

            if (((linhaInicial == linhaFinal && (colunaFinal - colunaInicial == 1)) ||
            (colunaInicial == colunaFinal && (linhaFinal - linhaInicial == 1))) &&
            linhaInicial >= 0 && linhaInicial <= 9 && linhaFinal >= 0 && linhaFinal <= 9 &&
            colunaInicial >= 0 && colunaInicial <= 9 && colunaFinal >= 0 && colunaFinal <= 9)
            {
            int posicaoInvalida = 0;
            for (int linha = linhaInicial; linha <= linhaFinal; linha++)
            {
                for (int coluna = colunaInicial; coluna <= colunaFinal; coluna++)
                {
                    if (matriz[linha][coluna] == 2)
                    {
                        posicaoInvalida = 1;
                        break;
                    }
                }
                if (posicaoInvalida)
                    break;
            }

            if (posicaoInvalida)
            {
                printf("Ja existe um navio nessa posicao. Por favor, digite outro intervalo:\n");
            }
            else
            {
                preencher_intervalo(matriz, linhaInicial, colunaInicial, linhaFinal, colunaFinal);
                imprimir_matriz(matriz);
                break;
            }
            }
        else
        {
            printf("Intervalo invalido. Por favor, digite outro intervalo:\n");
        }
    } while (1);
    }

    for (int i = 0; i < 4; i++)
    {
        printf("Digite as coordenadas do submarino de 1 casa (exemplo: d1):\n");
        do
        {
            char coordenada[4];
            scanf("%3s", coordenada);

            linhaFinal = atoi(coordenada + 1) - 1;
            colunaFinal = coordenada[0] - 'a';

            if (linhaFinal >= 0 && linhaFinal < 10 && colunaFinal >= 0 && colunaFinal < 10)
            {
                if (matriz[linhaFinal][colunaFinal] == 2)
            {
                printf("Ja existe um navio nessa posicao. Por favor, digite outra coordenada:\n");
            }
            else
            {
                matriz[linhaFinal][colunaFinal] = 2;
                imprimir_matriz(matriz);
                break;
            }
        }
        else
        {
            printf("Coordenada invalida. Por favor, digite outra coordenada:\n");
        }
        } while (1);
    }
    return 0;
}


void imprimir_matriz(int matriz[10][10])
{
    printf("\n");
    printf("   ");
    for (int coluna = 0; coluna < 10; coluna++)
    {
        printf("%c ", 'A' + coluna);
    }
    printf("\n");

    for (int linha = 0; linha < 10; linha++)
    {
        printf("%2d ", linha + 1);

        for (int coluna = 0; coluna < 10; coluna++)
        {
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }
    printf("\n");
}

void preencher_intervalo(int matriz[10][10], int linha_inicial, int coluna_inicial, int linha_final, int coluna_final)
{
    for (int linha = linha_inicial; linha <= linha_final; linha++)
    {
        for (int coluna = coluna_inicial; coluna <= coluna_final; coluna++)
        {
            matriz[linha][coluna] = 2;
        }
    }
}


int iniciar_jogo(int matriz1[10][10], int matriz2[10][10])
{
    int matriz_ataque1[10][10] = {0};
    int matriz_ataque2[10][10] = {0};
    int ponto1 = 0;
    int ponto2 = 0;
    do
    {
        ataque_jogador1(matriz1, matriz_ataque1, &ponto1);
        ataque_jogador2(matriz2, matriz_ataque2, &ponto2);
    }while(ponto1 < 20 && ponto2 < 20);
    if(ponto1 = 20){
        printf("O JOGADOR 1 VENCEU!!!\n\n\n");
    }
    else if(ponto2 = 20){
        printf("O JOGADOR 2 VENCEU!!!\n\n\n");
    }
    return 0;
}

int ataque_jogador1(int matriz[10][10], int matriz_ataque[10][10], int *ponto1)
{
    printf("\nJogador 1, ataque.\n");
    int linha;
    char coluna;
    printf("Digite a coordenada do ataque (exemplo: a1): ");
    char coordenada[4];
    scanf("%3s", coordenada);

    linha = atoi(coordenada + 1) - 1;
    coluna = coordenada[0] - 'a';

    if (matriz_ataque[linha][coluna] == 1 || matriz_ataque[linha][coluna] == 2) {
        printf("Posicao ja foi atacada.\n");
    }
    else if (matriz[linha][coluna] == 2) {
        printf("Acertou!\n");
        matriz_ataque[linha][coluna] = 2;
        (*ponto1)++;
    }
    else {
        printf("Errou!\n");
        matriz_ataque[linha][coluna] = 1;
    }
    imprimir_matriz(matriz_ataque);
    printf("\n");
    return 0;
}

int ataque_jogador2(int matriz[10][10], int matriz_ataque[10][10], int *ponto2)
{
    printf("\nJogador 2, ataque.\n");
    int linha;
    char coluna;
    printf("Digite a coordenada do ataque (exemplo: a1): ");
    char coordenada[4];
    scanf("%3s", coordenada);

    linha = atoi(coordenada + 1) - 1;
    coluna = coordenada[0] - 'a';

    if (matriz_ataque[linha][coluna] == 1 || matriz_ataque[linha][coluna] == 2) {
        printf("Posicao ja foi atacada.\n");
    }
    else if (matriz[linha][coluna] == 2) {
        printf("Acertou!\n");
        matriz_ataque[linha][coluna] = 2;
        (*ponto2)++;
    }
    else {
        printf("Errou!\n");
        matriz_ataque[linha][coluna] = 1;
    }
    imprimir_matriz(matriz_ataque);
    printf("\n");
    return 0;
}