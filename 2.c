/*In an IoT-based environmental monitoring system, data collected from multiple
sensors are stored in matrix form. Since most sensor readings are zero at any given
time, the datasets are stored using sparse matrix representation implemented with
arrays to reduce memory usage. Two sparse sensor datasets, collected from
different regions, need to be merged to generate a consolidated dataset for further
analysis. Write a C program to perform the addition of two sparse matrices using
array-based sparse matrix representation.*/ 
#include <stdio.h>
#define MAX 20
void toSparse(int mat[MAX][MAX], int rows, int cols, int sparse[MAX][3]) {
    int k = 1;
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k - 1;
}
void displaySparse(int a[MAX][3]) {
    for (int i = 0; i <= a[0][2]; i++)
        printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
}
void addSparse(int a[MAX][3], int b[MAX][3], int sum[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        printf("\nAddition not possible — dimension mismatch.\n");
        sum[0][2] = 0;
        return;
    }
    int i = 1, j = 1, k = 1;
    sum[0][0] = a[0][0];
    sum[0][1] = a[0][1];
    while (i <= a[0][2] && j <= b[0][2]) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            int val = a[i][2] + b[j][2];
            if (val != 0) {
                sum[k][0] = a[i][0];
                sum[k][1] = a[i][1];
                sum[k][2] = val;
                k++;
            }
            i++;
            j++;
        }
        else if (a[i][0] < b[j][0] ||
                (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            sum[k][0] = a[i][0];
            sum[k][1] = a[i][1];
            sum[k][2] = a[i][2];
            k++;
            i++;
        }
        else {
            sum[k][0] = b[j][0];
            sum[k][1] = b[j][1];
            sum[k][2] = b[j][2];
            k++;
            j++;
        }
    }
    while (i <= a[0][2]) {
        sum[k][0] = a[i][0];
        sum[k][1] = a[i][1];
        sum[k][2] = a[i][2];
        k++;
        i++;
    }
    while (j <= b[0][2]) {
        sum[k][0] = b[j][0];
        sum[k][1] = b[j][1];
        sum[k][2] = b[j][2];
        k++;
        j++;
    }
    sum[0][2] = k - 1;
}

void sparseToNormal(int sparse[MAX][3], int mat[MAX][MAX]) {
    int rows = sparse[0][0];
    int cols = sparse[0][1];
    int terms = sparse[0][2];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            mat[i][j] = 0;
    for (int i = 1; i <= terms; i++)
        mat[sparse[i][0]][sparse[i][1]] = sparse[i][2];
}

int main() {
    int rows, cols;
    int mat1[MAX][MAX], mat2[MAX][MAX];
    int sparse1[MAX][3], sparse2[MAX][3];
    int sumSparse[MAX][3];
    int sumNormal[MAX][MAX];
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("\nEnter Matrix 1:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat1[i][j]);
    printf("\nEnter Matrix 2:\n");
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &mat2[i][j]);
    toSparse(mat1, rows, cols, sparse1);
    toSparse(mat2, rows, cols, sparse2);
    addSparse(sparse1, sparse2, sumSparse);
    sparseToNormal(sumSparse, sumNormal);
    printf("\nSparse Matrix 1:\n");
    displaySparse(sparse1);
    printf("\nSparse Matrix 2:\n");
    displaySparse(sparse2);
    printf("\nFinal Added Sparse Matrix:\n");
    displaySparse(sumSparse);
    printf("\nFinal Sum Matrix (Normal Form):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", sumNormal[i][j]);
        printf("\n");
    }
    return 0;
}
