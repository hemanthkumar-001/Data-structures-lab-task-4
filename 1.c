/*In a web crawler and search engine system, web pages are represented as nodes in
a graph, and page-to-page hyperlinks are represented as edges. Since each web
page typically links to only a few other pages, the adjacency matrix representing
these links contains a large number of zero entries. To optimize memory usage, the
page-to-page links are stored using a sparse matrix representation implemented with
arrays (3-tuple form). Given the sparse matrix representation of page-to-page links,
compute the transpose of the sparse matrix using arrays.*/
#include <stdio.h>

int main()
{
    int matrix[10][10], sparse[50][3], transpose[50][3];
    int rows, cols, i, j, k = 1;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    printf("Enter the matrix:\n");
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    sparse[0][2] = k - 1;
    printf("\nSparse Matrix (Triplet Form):\n");
    printf("Row Col Val\n");
    for (i = 0; i <= sparse[0][2]; i++)
        printf("%d   %d   %d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    transpose[0][0] = sparse[0][1];
    transpose[0][1] = sparse[0][0];
    transpose[0][2] = sparse[0][2];
    k = 1;
    for (i = 0; i < sparse[0][1]; i++)
    {
        for (j = 1; j <= sparse[0][2]; j++)
        {
            if (sparse[j][1] == i)
            {
                transpose[k][0] = sparse[j][1];
                transpose[k][1] = sparse[j][0];
                transpose[k][2] = sparse[j][2];
                k++;
            }
        }
    }
    printf("\nTranspose of Sparse Matrix:\n");
    printf("Row Col Val\n");
    for (i = 0; i <= transpose[0][2]; i++)
        printf("%d   %d   %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    return 0;
}
