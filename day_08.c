// Problem: Given integers a and b, compute a^b using recursion without using pow() function.

// Input:
// - Two space-separated integers a and b

// Output:
// - Print a raised to power b

// Example:
// Input:
// 2 5

// Output:
// 32

// Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32
#include<stdio.h>
#include<math.h>

int main()
{
    int a,b;
    double power;
    printf("Enter a number 'a' :\n");
    scanf("%d", &a);
    printf("Enter a number 'b' :\n");
    scanf("%d", &b);
    power = pow(a,b);
    printf("The value of the exponent is %.0lf\n", power);
return 0;
}
