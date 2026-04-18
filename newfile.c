#include <stdio.h>
#include <string.h> 

int main(){
char str[50];
fgets(str, 50, stdin);
int len;
len = strlen(str);
int start = 0, end = len -1;
while (start < end) {
char temp = str[start];
str[start] = str[end];
str[end] = temp;
start++;
end--;
}
int counter = 0;
while (counter < len){
if (str[counter] == '\t' || str[counter] == ' ')
str[counter] = '~';
counter++;
}
printf("%s\n",str);
}

