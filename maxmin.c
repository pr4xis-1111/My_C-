#include <stdio.h>
int main() {
    int c,min,max;
    int ctr = 0;
    while (1){
        printf("Enter value: ");
        scanf("%d",&c);
        if (c == 0) break;
        if (ctr == 0){
            min = max = c;
            ctr++ ;
            continue;
        }
        if (c > max) max = c;
        if (c < min) min = c;
    }
    printf("Max: %d \nMin: %d",max,min);
}
