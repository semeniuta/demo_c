#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_arr(int* arr, int sz) {
    for (int i = 0; i < sz; i++) {
        printf("%d\n", arr[i]);
    }
}

int main() {

    // Create the initial array, filled with 1's

    int sz = 5;

    int* arr = (int*) malloc(sz * sizeof(int));
    
    for (int i = 0; i < sz; i++) {
        arr[i] = 1;
    }

    // Double the size of the array and fill the rest with 0's

    int new_sz = sz * 2;

    arr = realloc(arr, new_sz);

    printf("Grown array:\n");
    print_arr(arr, new_sz);
    printf("---\n");

    memset(arr + sz, 0, sz * sizeof(int));
    printf("Grown array after filling the rest with 0's:\n");
    print_arr(arr, new_sz);

    return 0;
}