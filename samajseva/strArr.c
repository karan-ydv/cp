#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

void ArrayChallenge(char * strArr[], int arrLength) {
    int* len = (int*) malloc(arrLength * sizeof(int));
    for(int i = 0; i < arrLength; i++) {
        int c = 0;
        while(strArr[i][c] != '\0')
            c++;
        len[i] = c;
    }
    
    qsort(len, arrLength, sizeof(int), compare_ints);
    for(int i = 0; i < arrLength; i++) {
        int c = 0;
        while(strArr[i][c] != '\0')
            c++;
        if(c == len[arrLength - 3]) {
            printf("%s", strArr[i]);
            return;
        }
    }
}

int main() {
    char* A[] = {"a", "abcd", "abcde", "ab"};
    ArrayChallenge(A, 4);
}