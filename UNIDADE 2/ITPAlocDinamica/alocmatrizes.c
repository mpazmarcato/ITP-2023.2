#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int nlin, ncol;
  int **mat;
} Matrix;

Matrix* createMatrix(int nlin, int ncol) {
  Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
  if (matrix == NULL) {
    fprintf(stderr, "Erro ao alocar memória para a estrutura Matrix.\n");
    exit(1);
  }

  matrix->nlin = nlin;
  matrix->ncol = ncol;
  matrix->mat = (int**)malloc(nlin * sizeof(int*));
  if (matrix->mat == NULL) {
    fprintf(stderr, "Erro ao alocar memória para a matriz.\n");
    exit(1);
  }

  for (int i = 0; i < nlin; i++) {
    matrix->mat[i] = (int*)malloc(ncol * sizeof(int));
    if (matrix->mat[i] == NULL) {
      fprintf(stderr, "Erro ao alocar memória para a linha da matriz.\n");
      exit(1);
    }
  }

  return matrix;
}

void readMatrix(Matrix* m) {
  for (int i = 0; i < m->nlin; i++) {
    for (int j = 0; j < m->ncol; j++) {
      scanf("%i", &m->mat[i][j]);
    }
  }
}

void printMatrix(Matrix* m) {
  for (int i = 0; i < m->nlin; i++) {
    for (int j = 0; j < m->ncol; j++) {
      printf("%i", m->mat[i][j]);
      if (j < m->ncol - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }
}

void destroyMatrix(Matrix** m) {
  if (*m == NULL) {
    return;
  }

  for (int i = 0; i < (*m)->nlin; i++) {
    free((*m)->mat[i]);
  }
  free((*m)->mat);
  free(*m);
  *m = NULL;
}

int main() {
  int lin, col;
  Matrix* mat;

  scanf("%i %i", &lin, &col);
  mat = createMatrix(lin, col);
  readMatrix(mat);
  printMatrix(mat);
  destroyMatrix(&mat);
  if (mat == NULL) {
    printf("OK\n");
  }
  return 0;
}
