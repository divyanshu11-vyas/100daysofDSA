// Problem: Given an array of integers, count the frequency of each distinct element and print the result.

// Input:
// - First line: integer n (size of array)
// - Second line: n integers

// Output:
// - Print each element followed by its frequency in the format element:count

// Example:
// Input:
// 5
// 1 2 2 3 1

// Output:
// 1:2 2:2 3:1
#include <stdio.h>

int main() {
    int n;
    printf("Enter n :\n");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter array elements :\n");
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; i++) {
        int count = 1;
        int alreadyCounted = 0;
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                alreadyCounted = 1;
                break;
            }
        }

        if(alreadyCounted)
            continue;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }

        printf("%d:%d ", arr[i], count);
    }

    return 0;
}
