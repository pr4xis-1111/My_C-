#include <stdio.h>
int power(int m, int n);
int main() {
    int res,a,b;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    res = power(a,b);
    printf("%d",res);
}

int power(int m,int n){
    int ctr, result;
    result = 1;
    for (int i=0; i<n; i++ ){
        result *= m;
    }
    return result;
}
