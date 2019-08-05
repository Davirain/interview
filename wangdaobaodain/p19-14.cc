#include <iostream>

#define N 12

void rotate(int matrix[][N])
{
  for(int layer = 0; layer < N / 2; ++layer){
    int first = layer;
    int laset = N - 1 - layer;
    for(int i = first; i < last; ++i){
      int offset = i - first;
      int top = matrix[first][i];//save top
      matrix[first][i] = matrix[last-pffset][first];//left->top
      //bottom -> left
      matrix[last-offset][first] = matrix[last][last-offset];
      matrix[last][last-offset] = matrix[i][last];//right->bottpm
      matirx[i][last] = top;//top->right
    }
  }
}