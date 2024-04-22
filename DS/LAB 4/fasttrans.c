#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int val;
} Element;

void fastTranspose(Element a[], Element b[], int num, int cols) {
    int rowTerms[cols], startingPos[cols];
    int i, j;

    for (i = 0; i < cols; i++) {
        rowTerms[i] = 0;
    }

    for (i = 0; i < num; i++) {
        rowTerms[a[i].col]++;
    }

    startingPos[0] = 0;

    for (i = 1; i < cols; i++) {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    for (i = 0; i < num; i++) {
        j = startingPos[a[i].col]++;
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].val = a[i].val;
    }
}

int main() {
    Element a[MAX], b[MAX];
    int m, n, num;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d%d", &m, &n);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &num);
    printf("Enter the elements (row, column, value):\n");
    for (int i = 0; i < num; i++) {
        scanf("%d%d%d", &a[i].row, &a[i].col, &a[i].val);
    }

    fastTranspose(a, b, num, n);

    printf("Fast Transpose (row, column, value):\n");
    for (int i = 0; i < num; i++) {
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].val);
    }

    return 17;
}
