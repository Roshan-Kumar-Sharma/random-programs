#include <stdio.h>

int main() {

  int n, index, i, numberToSearch;
  
  printf("Enter the value of N: ");
  scanf("%d", &n);
  
  int arr[n];
  
  i = 0;
  
  for(i=0; i < n; i++){
    printf("\nEnter value for index[%d]: ", i);
  	scanf("%d", &arr[i]);
  }
  
  printf("\n\nThe entered elements in the array: ");
  for(i=0; i<n; i++){
    printf("%d ", arr[i]);
  }
  
  printf("\n\nEnter the number which is to searched in array : ");
  scanf("%d", &numberToSearch);
  
  index = -1; // initializing with -1 
  	
  // searching for the number in the array
  for(i=0; i<n; i++){
  	if(arr[i] == numberToSearch){
  		index = i; // storing the index if number is present 
  		break;
  	}
  }
  	
  if(index == -1){
  	printf("\n\n%d is not present in the array\n", numberToSearch);
  }
  else{
  	printf("\n\n%d is present in the array at index %d\n", numberToSearch, index);
  }

  return 0;
}
