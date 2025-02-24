#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.
    
    int M=10, N=10; // Dimensões do tabuleiro
    int tabuleiro[M][N];
    
    // Inicializa o tabuleiro com 0 representando água
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            tabuleiro[i][j] = 0;
        }
    }


//Posicione os Navios: Declare e inicialize dois vetores (arrays unidimensionais) para representar os navios. Cada navio ocupará um número fixo de posições no tabuleiro (defina esse tamanho, por exemplo, 3 posições). Um navio será posicionado horizontalmente e o outro verticalmente. Represente as posições ocupadas pelos navios na matriz do tabuleiro com o valor 3. Você deverá escolher as coordenadas iniciais de cada navio e garantir que eles estejam completamente dentro dos limites do tabuleiro e não se sobreponham. 
// Dica: O posicionamento do navio pode ser feito copiando o valor 3 de cada posição do vetor do navio para as posições correspondentes na matriz do tabuleiro, de acordo com a orientação (horizontal ou vertical) do navio.

    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    int coordenadasNavioHorizontal[2] = {2, 3}; // Posição inicial do navio 1
    int coordenadasNavioVertical[2] = {5, 8}; // Posição inicial do navio 2

    // Posiciona um navio horizontalmente
    for (int i = 0; i < 3; i++) {
        // Verifica se o navio está dentro do tabuleiro
        if (coordenadasNavioHorizontal[1]+i-1>N-1 || coordenadasNavioHorizontal[1]+i-1<0 ||
            coordenadasNavioHorizontal[0]-1>M-1 || coordenadasNavioHorizontal[0]-1<0) {
            printf("Navio horizontal fora do tabuleiro\n");
            return 0;
        }
        tabuleiro[coordenadasNavioHorizontal[0]-1][coordenadasNavioHorizontal[1]+i-1] = navioHorizontal[i];
    }

    // Posiciona o navio 2 verticalmente
    for (int i = 0; i < 3; i++) {
        // Verifica se o navio está dentro do tabuleiro
        if (coordenadasNavioVertical[0]+i-1>M-1 || coordenadasNavioVertical[0]+i-1<0 ||
            coordenadasNavioVertical[1]-1>N-1 || coordenadasNavioVertical[1]-1<0) {
            printf("Navio vertical fora do tabuleiro\n");
            return 0;
        }
        // Verifica se o navio não está sobrepondo outro navio
        if (tabuleiro[coordenadasNavioVertical[0]+i-1][coordenadasNavioVertical[1]-1] == 3) {
            printf("Navio vertical sobrepondo outro navio\n");
            return 0;
        }
        else
        {
            tabuleiro[coordenadasNavioVertical[0]+i-1][coordenadasNavioVertical[1]-1] = navioVertical[i];
         }
    }
    
    // Exibe o tabuleiro no console
    printf("\n\n****Exibe 2 navios no tabuleiro****\n\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Declara e inicializa tabuleiros diagonais
    int navioDiagonal1[3] = {3, 3, 3};
    int navioDiagonal2[3] = {3, 3, 3};

    // Define coordenadas dos navios diagonais
    int coordenadasNavioDiagonal1[2] = {3, 3}; // Posição inicial do navio 1
    int coordenadasNavioDiagonal2[2] = {8, 4}; // Posição inicial do navio 2

    // Posiciona um navio diagonalmente
    for (int i = 0; i < 3; i++) {
        // Verifica se o navio está dentro do tabuleiro
        if (coordenadasNavioDiagonal1[1]+i-1>N-1 || coordenadasNavioDiagonal1[1]+i-1<0 ||
            coordenadasNavioDiagonal1[0]+i-1>M-1 || coordenadasNavioDiagonal1[0]+i-1<0) {
            printf("Navio diagonal 1 fora do tabuleiro\n");
            return 0;
        }
        // Verifica se o navio não está sobrepondo outro navio
        if (tabuleiro[coordenadasNavioDiagonal1[0]+i-1][coordenadasNavioDiagonal1[1]+i-1] == 3) {
            printf("Navio diagonal 1 sobrepondo outro navio\n");
            return 0;
        }
        else{
          tabuleiro[coordenadasNavioDiagonal1[0]+i-1][coordenadasNavioDiagonal1[1]+i-1] = navioDiagonal1[i];
        }
    }   

    // Posiciona o navio 2 diagonalmente
    for (int i = 0; i < 3; i++) {
        // Verifica se o navio está dentro do tabuleiro
        if (coordenadasNavioDiagonal2[0]+i-1>M-1 || coordenadasNavioDiagonal2[0]+i-1<0 ||
            coordenadasNavioDiagonal2[1]+i-1>N-1 || coordenadasNavioDiagonal2[1]+i-1<0) {
            printf("Navio diagonal 2 fora do tabuleiro\n");
            return 0;
        }
        // Verifica se o navio não está sobrepondo outro navio
        if (tabuleiro[coordenadasNavioDiagonal2[0]+i-1][coordenadasNavioDiagonal2[1]+i-1] == 3) {
            printf("Navio diagonal 2 sobrepondo outro navio\n");
            return 0;
        }
        else
        {
            tabuleiro[coordenadasNavioDiagonal2[0]+i-1][coordenadasNavioDiagonal2[1]+i-1] = navioDiagonal2[i];
         }
    }

        // Exibe o tabuleiro no console
        printf("\n\n****Exibe 4 navios no tabuleiro****\n\n");
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");
        }
    

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.
   
    // Declara as matrizes de habilidades
    int cone[M][N];
    int cruz[M][N];
    int octaedro[M][N];

    // Inicializa as matrizes de habilidades
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    // Preenche a matriz de habilidade em cone
    for (int i = 0; i < M/2; i++) {
        for (int j = 0; j < N; j++) {
            if (i+j >= M/2 && j-i <= M/2 && i-j <= M/2 && i+j <= 3*M/2) {
                cone[i][j] = 1;
            }
        }
    }
    

    // Preenche a matriz de habilidade em cruz
    for (int i = 0; i < M; i++) {
        cruz[i][N/2] = 1;
        cruz[M/2][i] = 1;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (i+j >= M/2 && j-i <= M/2 && i-j <= M/2 && i+j <= 3*M/2) {
                octaedro[i][j] = 1;
            }
        }
    }
    
    // Exibe as matrizes de habilidades no console
    printf("\n\n****Exibe habilidades especiais no tabuleiro****\n\n");
    printf("Habilidade em cone:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", cone[i][j]);
        }
        printf("\n");
    }

    printf("\nHabilidade em cruz:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", cruz[i][j]);
        }
        printf("\n");
    }

    printf("\nHabilidade em octaedro:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", octaedro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
