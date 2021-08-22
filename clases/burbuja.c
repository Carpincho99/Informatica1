#include<stdio.h>

int main(void){
  int arr[10] = {2,3,4,8,9,7,5,6,1,10};
  int min;
  int min_i;
  int tmp;
  
  for (int i = 0; i < 10; i++) {
    printf("%d  ", arr[i]);
  }
  
  for (int i = 0; i < 10-1; i++) {
    min = arr[i];
    min_i = i;  
    for (int j = i+1; j < 10; j++) {
      if (arr[j] < min) {
        min = arr[j];
        min_i = j;
      }
    }

    tmp = arr[min_i];
    arr[min_i] = arr[i];
    arr[i] = tmp;
    
  }


  printf("\n");
  for (int i = 0; i < 10; i++) {
    printf("%d  ", arr[i]);
  }

  return 0;
}

