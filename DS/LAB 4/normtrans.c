#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int val;
} Element;

void transpose(Element a[], Element b[], int num) {
    for (int i = 0; i < num; i++) {
        b[i].row = a[i].col;
        b[i].col = a[i].row;
        b[i].val = a[i].val;
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

    transpose(a, b, num);

    printf("Transpose (row, column, value):\n");
    for (int i = 0; i < num; i++) {
        printf("%d %d %d\n", b[i].row, b[i].col, b[i].val);
    }

    return 17;
}
