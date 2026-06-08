#include <stdio.h>
#include <string.h>

int main() {
    char s[50];
    fgets(s,50,stdin);
    int x = strlen(s);
    int numword = 0, inword = 0;
    for (int i= 0; i < x-1; i++){
        if (((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) && inword == 0) {
            inword++;
            numword++;
        }
        if ((s[i] == ' ' || s[i] == '\t') && inword == 1){
            inword = 0;
        }
    }
    printf("Number of words: %d\n",numword);
}
