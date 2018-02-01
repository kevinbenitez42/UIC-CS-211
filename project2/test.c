#include <stdlib.h>
#include <stdio.h>

int main()
{
  int xsize = 4;
  int ysize = 5;
  int **arr = (int**)malloc(xsize * sizeof(int*));
  for(int i = 0; i < xsize; i++){
    arr[i] = (int*)malloc(ysize * sizeof(int));
  }
  int count = 0;
  for(int i = 0; i < xsize; i++){
    for(int j = 0; j< ysize; j++){
      count++; arr[i][j] = count;
}
}
  for(int i = 0; i < xsize; i++)
    for(int j = 0; j< ysize; j++)
      printf("%s %d\n","val: ", arr[i][j]);
}
