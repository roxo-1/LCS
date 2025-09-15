//Carolina Lee - 10440304

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int LCS(char *X, char *Y){
    int m = strlen(X);
    int n = strlen(Y);

    // Aloca a tabela de programação dinâmica
    int **L = (int **)malloc((m + 1) * sizeof(int *));
    for (int i = 0; i <= m; i++) {
        L[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    // Preenche a tabela L para encontrar os comprimentos das LCS
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            } else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }

    // O comprimento da LCS está na última célula da tabela
    int lcs_length = L[m][n];
    char *lcs = (char *)malloc((lcs_length + 1) * sizeof(char));
    lcs[lcs_length] = '\0'; // Adiciona o terminador

    // Constrói a string da LCS a partir da tabela
    int i = m, j = n;
    int index = lcs_length;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        } else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Imprime o resultado
    printf("Comprimento da LCS: %d\n", lcs_length);
    if (lcs_length > 0) {
        printf("LCS: %s\n", lcs);
    } else {
        printf("LCS: (nenhuma subsequência comum)\n");
    }

    // Libera a memória alocada
    for (int k = 0; k <= m; k++) {
        free(L[k]);
    }
    free(L);
    free(lcs);
}
int main(){
    FILE *file1, *file2;
    char X[1001], Y[1001];

    // Abre o primeiro arquivo para leitura
    file1 = fopen("string1.txt", "r");
    if (file1 == NULL) {
        perror("Erro ao abrir o arquivo string1");
        return 1;
    }

    // Lê o conteúdo do primeiro arquivo
    if (fscanf(file1, "%1000s", X) != 1) {
        printf("Erro ao ler o arquivo string1 ou ele está vazio.\n");
        fclose(file1);
        return 1;
    }
    fclose(file1);

    // Abre o segundo arquivo para leitura
    file2 = fopen("string2.txt", "r");
    if (file2 == NULL) {
        perror("Erro ao abrir o arquivo string2");
        return 1;
    }

    // Lê o conteúdo do segundo arquivo
    if (fscanf(file2, "%1000s", Y) != 1) {
        printf("Erro ao ler o arquivo string2 ou ele está vazio.\n");
        fclose(file2);
        return 1;
    }
    fclose(file2);

    // Chama a função LCS
    LCS(X, Y);

    return 0;
}