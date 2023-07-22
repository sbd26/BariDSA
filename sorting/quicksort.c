#include <stdio.h>

void
swap(int * a, int * b)
{
  int _t = *a;
  *a = *b;
  *b = _t;
}

void
display(int * arr, int arr_sz)
{
  for (int i = 0; i < arr_sz; i++)
  {
    printf("[%d] -> [%d]\n",i, arr[i]);
  }
}

int
quick_sort_partition(int * arr, int low, int hi)
{
  int pivot = arr[low]; // so we are making top right to pivot
  int i = low; // we will increment i until we found the greateer than pivot that means increment i while pivot < arr[i]
  int j = hi; // same as for j 
  
  while(i < j) // loop until i < j
  {
    while(pivot >= arr[i])
    {
      ++i;
    }
    while(pivot < arr[j])
    {
      --j;
    }
    if (i < j) swap(&arr[i], &arr[j]);
  }
  swap(&arr[j], &arr[low]);
  return j;
}


void
quick_sort(int * arr, int low, int hi)
{
  if (low < hi)
  {
    int mid = quick_sort_partition(arr, low, hi);
    quick_sort(arr, low, mid - 1);
    quick_sort(arr, mid + 1, hi);
  }
}



int
main(int argc, char * argv[])
{
  int arr[5] = {5,4,3,2,12};
  display(arr, 5);
  quick_sort(arr, 0, 4);
  printf("\n");
  display(arr, 5);
  return 0;
}
