#include <stdio.h>
#include <string.h>


void swap(void *a, void *b, size_t size);

void pivot(int arr[], int size_arr, int piv);


int main(void){
    int sequence[7] = {9, 3, 6, 2, 7, 8, 4};
    pivot(sequence,7,6);
    for (int i = 0; i < 7; i++) printf("%d", *(sequence + i));
    printf("\n");
    return 0;
}

void pivot(int arr[],int size_arr,int piv){
    int bool = 1;
    int *pivptr;
    int *arrptr = arr;
    for (int i = 0; i< size_arr; i++){
        if (arr[i] == piv) pivptr = (arr + i);
    }
    while (bool){
        for (int i =0; i < size_arr; i++){
            if (*arrptr < piv && arrptr > pivptr){
                swap(arrptr, pivptr, sizeof(int));
                pivptr = arrptr;
                arrptr = arr;
                break;
            }
            if (*arrptr > piv && arrptr < pivptr){
                swap(arrptr, pivptr, sizeof(int));
                pivptr = arrptr;
                break;
            }
            if (arrptr == (arr + (size_arr-1))) {
                bool = 0;
                break;
            }
            arrptr++;
        }
    }
}

void swap(void *a, void *b, size_t size) {
    char x;
    for (size_t i = 0; i < size; i++){
        x = *((char *)a);
        *((char *)a) = *((char *)b);
        *((char *)b) = x;
        a = ((char *)a)+1;
        b = ((char *)b)+1;
    }
}

