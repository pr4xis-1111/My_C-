#include <stdio.h>
#include <string.h>


void swap(void *a, void *b, size_t size);

void shiftsort(int arr[], int size_arr);


int main(void){
    int sequence[7] = {0, 4, 3, 2, 0, 0, 1};
    shiftsort(sequence,7);
    for (int i = 0; i < 7; i++) printf("%d", *(sequence + i));
    printf("\n");
    return 0;
}

/* Expected output - { 4 , 3 , 2, 1, 0, 0 ,0 } */

void shiftsort  (int arr[],int size_arr){
    int *arrptr = arr;
    int *boundptr = arr;
    while (1) {
        if (*arrptr == 0 && *boundptr != 0){
            boundptr = arrptr;
        }
        else if (*arrptr && arrptr > boundptr){
            swap(boundptr,arrptr, sizeof(int));
            *arrptr = 0;
            boundptr++;
        }
        arrptr++;
        if (arrptr == (arr + (size_arr))) break;
    }
}

/* Swap function is technically a copy function - disregard wording */ 

void swap(void *a, void *b, size_t size) {
    for (size_t i = 0; i < size; i++){
        *((char *)a) = *((char *)b);
        a = ((char *)a)+1;
        b = ((char *)b)+1;
    }
}

