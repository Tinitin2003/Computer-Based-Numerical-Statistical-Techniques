#include <stdio.h>

void gaussJordan(int n, double mat[][2 * n]) {
    int i, j, k;
    double temp;

    // Gaussian Elimination
    for (i = 0; i < n; i++) {
        // Make the diagonal element 1
        if (mat[i][i] != 1) {
            double divisor = mat[i][i];
            for (j = i; j < 2 * n; j++) {
                mat[i][j] /= divisor;
            }
        }

        // Make all other elements in the current column zero
        for (j = 0; j < n; j++) {
            if (i != j) {
                double factor = mat[j][i];
                for (k = i; k < 2 * n; k++) {
                    mat[j][k] -= factor * mat[i][k];
                }
            }
        }
    }

    // Print the solutions
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.3lf\n", i + 1, mat[i][n]);
    }
}

int main() {
    int n, i, j;
    printf("Enter the number of variables: ");
    scanf("%d", &n);

    double mat[n][2 * n];

    printf("Enter the augmented matrix (coefficients + constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%lf", &mat[i][j]);
        }
        scanf("%lf", &mat[i][n]); // Constants column
    }

    gaussJordan(n, mat);

    return 0;
}
