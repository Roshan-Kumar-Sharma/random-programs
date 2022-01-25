#include <stdio.h>

void swap(int *num1, int *num2){
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;

    return;
}

int main(void)
{
    int n1, n2;

    printf("Input 1st number: ");
    scanf("%d", &n1);

    printf("Input 2nd number: ");
    scanf("%d", &n2);

    swap(&n1, &n2);

    printf("\nBefore swapping: n1 = %d, n2 = %d\n", n2, n1);
    printf("After swapping: n1 = %d, n2 = %d\n", n1, n2);

    return 0;
}

// Explanation:
// In the above we are swapping the elements by reference.
// It is calling a function 'swap()' with parameters 'num1' and 'num2' which is holding the address of 'n1' and 'n2'.
// The values of 'n1' and 'n2' are swapped using a variable 'temp'.