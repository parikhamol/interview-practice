// Implement a method do string compression.

#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;


int main() {
  int mat[3][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
  };
  int size = sizeof(mat[0])/sizeof(*mat[0]);
  for(int layer = 0; layer < size/2; layer++){
    int first = layer;
    int last = size - 1 - layer;
    for ( int i = first; i < last; i++) {
      int offset = i - first;
      int temp = mat[first][i];
      mat[first][i] = mat[last-offset][first];
      mat[last-offset][first] = mat[last][last-offset];
      mat[last][last-offset] = mat[i][last];
      mat[i][last] =temp;
    }
  }
  for (int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      cout<<mat[i][j];
    }
    cout<<endl;
  }
  return 0;
}


