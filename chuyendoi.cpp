#include <stdio.h>
#include <stdlib.h>

// A function to print the adjacency matrix of a graph
void printMatrix(int** matrix, int n);

// A function to print the number of vertices and edges of a graph
void printVerticesAndEdges(int** matrix, int n);

// A function to print the specific edges of a graph
void printEdges(int** matrix, int n);

// A function to read the adjacency matrix of a graph from the user input
int** readMatrix(int* n);

// Driver program to test the above functions
int main();

void printMatrix(int** matrix, int n) {
  printf("The adjacency matrix of the graph is:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void printVerticesAndEdges(int** matrix, int n) {
  int edges = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (matrix[i][j] == 1) {
        edges++;
      }
    }
  }
  printf("The number of vertices of the graph is: %d\n", n);
  printf("The number of edges of the graph is: %d\n", edges);
}

void printEdges(int** matrix, int n) {
  printf("The specific edges of the graph are:\n");
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (matrix[i][j] == 1) {
        printf("%d - %d\n", i, j);
      }
    }
  }
}

int** readMatrix(int* n) {
  printf("Enter the number of vertices of the graph:\n");
  scanf("%d", n);
  int** matrix = (int**)malloc(*n * sizeof(int*));
  for (int i = 0; i < *n; i++) {
    matrix[i] = (int*)malloc(*n * sizeof(int));
  }
  printf("Enter the adjacency matrix of the graph:\n");
  for (int i = 0; i < *n; i++) {
    for (int j = 0; j < *n; j++) {
      scanf("%d", &matrix[i][j]);
    }
  }
  return matrix;
}

int main() {
  int n;
  int** matrix = readMatrix(&n);
  printMatrix(matrix, n);
  printVerticesAndEdges(matrix, n);
  printEdges(matrix, n);
  for (int i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);
  return 0;
}
