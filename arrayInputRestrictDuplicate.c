#include <stdio.h>

int main() {

  int n, isPresent, i, j;
  
  printf("Enter the value of N: ");
  scanf("%d", &n);
  
  int arr[n];
  
  i = 0;
  
  while(i < n)
  {
    printf("\nEnter value for index[%d]: ", i);
  	scanf("%d", &arr[i]);
  	
  	isPresent = 0;
  	
  	for(j=0; j<i; j++){
  		if(arr[j] == arr[i]){
  			isPresent = 1;
  			break;
  		}
  	}
  	
  	if(isPresent){
  		printf("Number already exists in array. So not inserted.\n");
  		continue;
  	}
  	i++;
  }

  printf("\nThe unique elements in the array: ");
  for(i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
  
  return 0;
}

