// C++ program to implement selection sort for
// array of strings.
#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define MAX_LEN 100

// Sorts an array of strings where length of every
// string should be smaller than MAX_LEN
void selectionSort(char arr[][MAX_LEN], int n)
{
	int i, j, min_idx;

	char minStr[MAX_LEN];
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		int min_idx = i;
		strcpy(minStr, arr[i]);
		for (j = i + 1; j < n; j++)
		{
			// If min is greater than arr[j]
			if (strcmp(minStr, arr[j]) > 0)
			{
				// Make arr[j] as minStr and update min_idx
				strcpy(minStr, arr[j]);
				min_idx = j;
			}
		}
		
		// Swap the found minimum element with the first element
		if (min_idx != i)
		{
			char temp[MAX_LEN];
			strcpy(temp, arr[i]); //swap item[pos] and item[i]
			strcpy(arr[i], arr[min_idx]);
			strcpy(arr[min_idx], temp);
		}
		
		for (int k = 0; k < n; k++){
			if(k == i){
				cout << "[*" << arr[k] << "]  ";
			}
			else
				cout << "[" << arr[k] << "]  ";
			
		}
		cout << endl;
	}
}

int main()
{
	char arr[][MAX_LEN] = {"Susie", "Peppa", "Edmond", "Zoe", "Freddie", "Pedro"};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i;

	cout<<"Given array is\n";
	for (i = 0; i < n; i++)
		cout << "[" << arr[i] << "]  ";
	cout << endl << endl;

	selectionSort(arr, n);

	cout << "\nSorted array is\n";
	for (i = 0; i < n; i++)
		cout << "[" << arr[i] << "]  ";

	return 0;
}

