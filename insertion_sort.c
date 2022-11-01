#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* int_array_erstellen(const int size){
    int *array = malloc(sizeof(int) * size);
    srand(time(NULL));
    for (int i = 0; i < size; i++){
        array[i] = rand() % 1000;
    }
    return array;
}

void printarr(const int *array, const int size){
    for(int i = 0; i < size; i++) printf("%d\t", array[i]);
    printf("\n");
}

int array_sum(const int *array, const int size){
    int sum = 0;
    for (int i = 0; i < size; i++)  sum += array[i];
    return sum;
}

int int_comp(const void* p1, const void* p2) {
    int x1 = *((int*)p1); // Wert an Adr p1
    int x2 = *((int*)p2); // Wert an Adr p2
    if (x1 > x2) { return -1; } // Over- und Underflowsicher
    else if (x1 < x2) { return 1; } // Over- und Underflowsicher
    else { return 0; }
}

void swap(void* p1, void* p2, size_t byte_size){
    void *temp = malloc(byte_size);
    memcpy(temp, p1, byte_size);
    memcpy(p1, p2, byte_size);
    memcpy(p2, temp, byte_size);
    free(temp);
}

void insertion_sort(const void* arr, const size_t byte_size, const int arr_size, int compare(const void*, const void*)){
    for (int i = 1; i < arr_size; i++){
        if (compare((char*) arr + (i-1) * byte_size, (char*) arr + i * byte_size) == -1){
            swap((char*) arr + (i-1) * byte_size, (char*) arr + i * byte_size, byte_size);
            if( i > 1) i -= 2;
        }
    }
}


int main(){
    int size = 10;
    int *array = int_array_erstellen(size);
    printarr(array, size);

    insertion_sort(array, sizeof(int), size, *int_comp);

    printarr(array, size);
   // printf("%d\n", array_sum(array, size));
    free(array);
    return 0;
}