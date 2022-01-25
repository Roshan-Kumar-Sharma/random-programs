#include <stdio.h>

int calculateSum(int n)
{
    // base condition to stop recursion

    if(n <= 1)
        return 1;

    return n + calculateSum(n - 1);
}

int main(void)
{
    int n, sum;

    printf("Input the last number of the range starting from 1 : ");
    scanf("%d", &n);

    // calling function with n and storing sum from 1 to n in sum

    sum = calculateSum(n);

    printf("\nThe sum of numbers from 1 to %d : %d\n", n, sum);

    return 0;
}

// Explanation:
// In the above program we are calculating the sum of numbers from 1 to n i.e. 1+2+3+....+n
// It is calling a function 'calculateSum()' with parameters 'n' upto which we have to calculate the sum.
