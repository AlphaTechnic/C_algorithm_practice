# include <stdio.h>
# include <stdlib.h>

int** transpose(int** matrix, int m, int n);
void printMatrix(int** matrix, int m, int n);

int main(void) {
    int rows, cols;
    int i, r, c;
    int** matrix;
    int** transposed_matrix;

    printf("Number of Rows : ");
    scanf("%d", &rows);
    printf("Number of Cols : ");
    scanf("%d", &cols);

    // matrix가 저장될 공간의 메모리를 할당받는다.
    matrix = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    // matrix의 원소를 seed=20121277로 1~100까지의 랜덤 숫자로 생성한다. 
    srand(20121277);
    for (r = 0; r < rows; r++) {
        for (c = 0; c < cols; c++) {
            *(*(matrix + r) + c) = rand() % 100 + 1;
        }
    }

    printf("seed번호 20121277로 생성된 Matrix\n");
    printMatrix(matrix, rows, cols);

    transposed_matrix = transpose(matrix, rows, cols);

    printf("Transpose된 Matrix\n");
    // matrix의 원소들을 print할 때 대입되었던 rows, cols의 위치를 
    // transposed_matrix의 인자로 들어갈때는 그 위치를 뒤바꾸어서 대입한다.
    printMatrix(transposed_matrix, cols, rows);

    // heap메모리에 저장된 matrix 할당 해제 
    for (i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    // heap메모리에 저장된 transposed_matrix 할당 해제 
    for (i = 0; i < cols; i++) {
        free(transposed_matrix[i]);
    }
    free(transposed_matrix);
    return 0;
}

int** transpose(int** matrix, int m, int n) {
    int r, c;
    int transposed_rows, transposed_cols;
    int** transposed;

    // matrix의 row인 m을 transposed의 cols로, 
    // matrix의 column인 n을 transposed의 rows로 할당
    transposed_rows = n;
    transposed_cols = m;

    // heap메모리에 transposed를 위한 공간 할당 
    transposed = (int**)malloc(sizeof(int*) * transposed_rows);
    for (r = 0; r < transposed_rows; r++) {
        transposed[r] = (int*)malloc(sizeof(int) * transposed_cols);
    }

    for (r = 0; r < transposed_rows; r++) {
        for (c = 0; c < transposed_cols; c++) {
            transposed[r][c] = matrix[c][r];
        }
    }
    return transposed;
}

void printMatrix(int** matrix, int m, int n) {
    int r, c;
    for (r = 0; r < m; r++) {
        for (c = 0; c < n; c++) {
            printf("%3d ", *(*(matrix + r) + c));
        }
        printf("\n");
    }
}
