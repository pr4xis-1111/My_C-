#include <stdio.h>
#include <string.h>


void swap(void *a, void *b, size_t size);

void word_reverse(char arr[], int size);

void reverse_str(char *startptr, char *endptr);


int main(void){
    char sequence[50] = "I love Linux ";
    int size = strlen(sequence);
    word_reverse(sequence, size);
    printf("%s\n", sequence);
    return 0;
}


void word_reverse(char arr[], int size){
    reverse_str(arr, (arr+(size-1)));
    char *space_ptr = arr;
    char *space_boundptr = arr;
    while (1){
            if (*space_ptr == ' '){
                reverse_str(space_boundptr, space_ptr-1);
                space_boundptr = space_ptr;
            }
            space_ptr++;
            if (space_ptr == (arr+size)) {
                reverse_str(space_boundptr, (space_ptr-1));
                break;
            }
    }
}


void reverse_str(char *startptr, char *endptr){
    while (startptr < endptr) {
        char temp = *startptr;
        *startptr = *endptr;
        *endptr = temp;
        startptr++;
        endptr--;
    }
}
