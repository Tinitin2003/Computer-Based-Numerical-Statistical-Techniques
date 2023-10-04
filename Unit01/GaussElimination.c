#include <stdio.h>

void gaussElimination(int n, double mat[][n + 1]) {
    int i, j, k;
    double temp;

    // Forward Elimination
    for (i = 0; i < n - 1; i++) {
        // Partial Pivoting: Find the row with the maximum element in the current column
        int maxRow = i;
        for (j = i + 1; j < n; j++) {
            if (mat[j][i] > mat[maxRow][i]) {
                maxRow = j;
            }
        }

        // Swap the current row with the row having the maximum element
        if (maxRow != i) {
            for (j = i; j <= n; j++) {
                temp = mat[i][j];
                mat[i][j] = mat[maxRow][j];
                mat[maxRow][j] = temp;
            }
        }

        // Make all elements below the current pivot zero
        for (j = i + 1; j < n; j++) {
            double factor = mat[j][i] / mat[i][i];
            for (k = i; k <= n; k++) {
                mat[j][k] -= factor * mat[i][k];
            }
        }
    }

    // Back Substitution
    double solutions[n];
    for (i = n - 1; i >= 0; i--) {
        solutions[i] = mat[i][n];
        for (j = i + 1; j < n; j++) {
            solutions[i] -= mat[i][j] * solutions[j];
        }
        solutions[i] /= mat[i][i];
    }

    // Print the solutions
    printf("Solution:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.3lf\n", i + 1, solutions[i]);
    }
}

int main() {
    int n, i, j;
    printf("Enter the number of variables: ");
    scanf("%d", &n);

    double mat[n][n + 1];

    printf("Enter the augmented matrix (coefficients + constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }

    gaussElimination(n, mat);

    return 0;
}
