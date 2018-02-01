#include <stdio.h>
#include <stdlib.h>
void arrayCopy(int fromArray[], int toArray[], int size);
void myFavorateSort(int arr[], int size);
void printArray(int arr[], int size);
void swapElements(int array[], int index1, int index2);
int findSmallestInteger(int arr[],int size);
int linSearch(int arr[], int size, int target, int* numComparisons);
int binSearch(int arr[], int size, int target, int* numComparisons);
int* increaseArraySize(int arr[], int *size);

int main(){
  int val = 0;
  int count = 0;
  int size = 100;
  int target = 0;
  int numComparisons = 0;
  int index = 0;

  int * arr = (int*)malloc(size * sizeof(int));

  printf("%s\n","type in an integer or set of integers(to terminate, press -999):");
  while(val != -999)
  {
    if(count >= size){
      arr = increaseArraySize(arr, &size);
    }

    scanf("%d",&val);
    if(val == -999){printf("%s\n\n","end of file" ); break;}
    arr[count] = val;
    count++;
  }
  int* arr_copy = (int*)malloc(size * sizeof(int));
  arrayCopy(arr, arr_copy, size);
  myFavorateSort(arr_copy, size);

  val = 0;
  printf("%s\n","input values to search(to terminate, press -999):");

  while(target != -999){
    numComparisons = 0;
    scanf("%d",&target);
    if(target == -999){printf("%s\n", "end of input" );  printf("\n");break;}
    index = linSearch(arr,size,target,&numComparisons);
    printf("%s\n","linear sort on unsorted array:" );
    if(index == -1)
    {

      printf("%s\n","value could not be found");
      printf("%s", "Number of Comparisons: ");
      printf("%d\n", numComparisons);
    }
    else{
      printf("%s","value found at index " );
      printf("%d\n", index);
      printf("%s", "Number of Comparisons: ");
      printf("%d\n", numComparisons);
    }
    printf("\n" );
    numComparisons = 0;
    index = binSearch(arr_copy,size,target,&numComparisons);
    printf("%s\n","binary search on sorted array:" );
    if(index == -1)
    {
      printf("%s\n","value could not be found");
      printf("%s", "Number of Comparisons: ");
      printf("%d\n", numComparisons);
    }
    else{
      printf("%s","value found at index " );
      printf("%d\n", index);
      printf("%s", "Number of Comparisons: ");
      printf("%d\n", numComparisons);
    }

    printf("\n" );
  }
}
// copys array
void arrayCopy(int fromArray[], int toArray[], int size)
{
  for(int i = 0; i < size; i++){
    toArray[i] = fromArray[i];
  }
}

//Selection Sort
void myFavorateSort(int arr[], int size)
{
  for(int i = 0; i < size; i++)
  {
    for (int j = 0; j < i ; j++)
    {
      if(arr[i] < arr[j])
      swapElements(arr, i, j);
    }
  }
}
//Linear search
int linSearch(int arr[], int size, int target, int* numComparisons)
{
  for(int i = 0; i < size; i++)
  {
    *numComparisons = *numComparisons + 1;
    if(arr[i] == target)
    {
      return i;
    }
  }
  return -1;
}
//binary search
int binSearch(int arr[], int size, int target, int* numComparisons)
{
  int start = 0;
  int end = size;
  while(start <= end){
    *numComparisons = *numComparisons + 1;
    int mid = (start + end)/2;

    if(target == arr[mid])
    {
      return mid;
    }
    else if(target < arr[mid])
    {
      end = mid - 1;
    }
    else{
      start = mid + 1;
    }
  }
  return -1;
}

int* increaseArraySize(int darr[], int* size){
  int *temp;
  temp = (int *) malloc ( *size * 2 * sizeof(int) );
  int i;
  for ( i = 0 ; i < *size ; i++)
  temp[i] = darr[i];
  free (darr);
  darr = temp;
  *size = *size * 2;
  return darr;
}

void printArray(int arr[], int size)
{
  int count = 0;
  for(int i = 0; i < size ; i++)
  {
    printf("%d\n",arr[i]);
  }
}

void swapElements(int arr[], int index1, int index2)
{
  int temp = arr[index1];
  arr[index1] = arr[index2];
  arr[index2] = temp;
}

int findSmallestInteger(int arr[],int size)
{
  int smallest = arr[0];
  for(int i = 0; i < size; i++)
  {
    if (arr[i] < smallest)
    {
      smallest = arr[i];
    }
  }
  return smallest;
}
