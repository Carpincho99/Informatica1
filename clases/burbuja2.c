#include<stdio.h>

int main(void){
  int arr[10] = {2,3,4,8,9,7,5,6,1,10};
  int tmp;
  
  for (int i = 0; i < 10; i++) {
    printf("%d  ", arr[i]);
  }

  for (int i = 0; i < 10-1; i++) {
    for (int j = 0; j < 10-1-i; j++) {
      if (arr[j] > arr[j+1]) {
        tmp =  arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;

      }
    }
  }
    


  printf("\n");
  for (int i = 0; i < 10; i++) {
    printf("%d  ", arr[i]);
  }

  return 0;
}

