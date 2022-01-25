#include <stdio.h>

int main(void)
{
    int n, i, count, j, searchFor;

    printf("Input the number of elements to be stored in the Array: ");
    scanf("%d", &n);

    int arr[n], frequency[n];

    printf("Input %d elements in the array: \n", n);

    // taking inputs in the array

    for(i = 0; i < n; i++){
        printf("element- %d: ", i);
        scanf("%d", &arr[i]);

        frequency[i] = 0;
    }


    // counting frequency of each elements in the array

    for(i = 0; i < n; i++){
        count = 1;
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                // To avoid counting same element again, storing -1 at that index
                frequency[j] = -1;
            }
        }
        if (frequency[i] != -1)
            frequency[i] = count;
    }

    // Displays the frequency of each element present in array

    printf("\nThe frequency of all element of an array:\n");
    for(i = 0; i < n; i++){
        if(frequency[i] != -1){
            printf("%d occurs %d times\n", arr[i], frequency[i]);
        }
    }

    return 0;
}

// Explanation: 
// In the above we are counting frequency of each element present in the array.
// It uses two array 'arr' and 'frequency' both of same size i.e. number of elements user enters.
// Array 'arr' will hold all the elements whose frequency is to be calculated.
// Array 'frequency' will hold the frequency of elements present in the array.
// To avoid counting the frequency of same element again, it is storing -1 at all the index of a number after its frequency is already calculated.

