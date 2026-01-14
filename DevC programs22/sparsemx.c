#include <stdio.h>

int main() {
    int m, n, i, j, k = 0;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int a[m][n];
    printf("Enter matrix elements:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Count non-zero elements
    int size = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != 0)
                size++;
        }
    }

    // Triplet representation
    int sparser[size][3];
    k = 0;
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (a[i][j] != 0) {
                sparser[k][0] = i;   // row
                sparser[k][1] = j;   // col
                sparser[k][2] = a[i][j]; // value
                k++;
            }
        }
    }

    printf("\nSparse Matrix Representation row-major (Row, Col, Val):\n");
    for (i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", sparser[i][0], sparser[i][1], sparser[i][2]);
    }
    printf("\nSparse Matrix Representation col-major (Row Col Val):\n");
    for ( j = 0; j < n; j++) {
        for ( i = 0; i < m; i++) {
            if (a[i][j] != 0) {
                printf("%d %d %d\n", i, j, a[i][j]);
            }
        }
    }

    // Transpose of sparse matrix
    int transpose[size][3];
    for (i = 0; i < size; i++) {
        transpose[i][0] = sparser[i][1];  // col becomes row
        transpose[i][1] = sparser[i][0];  // row becomes col
        transpose[i][2] = sparser[i][2];  // value stays same
    }

    printf("\nTranspose of Sparse Matrix (Row, Col, Val):\n");
    for (i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", transpose[i][0], transpose[i][1], transpose[i][2]);
    }

    return 0;
}

