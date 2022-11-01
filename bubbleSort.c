#include <stdio.h>

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(char *arr, int size, int type){ 
    while (1) {
        int swaps = 0;
        printArray(arr, size);
        for (int i = 1; i < size; i++) {
            if ( arr[(i-1) * type] > arr[i * type]) {
                // swaping i and i-1 with XOR
                arr[(i-1) * type] ^= arr[i * type];
                arr[i * type] ^= arr[(i-1) * type];
                arr[(i-1) * type] ^= arr[i * type];
                swaps++;
            }
        }
        if (swaps == 0) break;
    }
}

int main()
{
    int array[] = {1,3,5,2,9,1,0};
    int array_size = sizeof(array)/sizeof(int);

    bubbleSort(array, array_size, sizeof(int));

    printArray(array, array_size);

    return 0;
}
