#include<stdio.h>

int majorityElement (int A[], int n) {
    int count, e, i;
    for(i = 0, count = 0; i < n; ++i) {
        if(count == 0)
            e = A[i];
        if(A[i] == e)
            count++;
        else 
            count--;
    }
    for(i = 0, count = 0; i < n; i++)
        if(A[i] == e)
            count ++;
    if(count > (n/2))
        return e;
    else 
        return -1;
}

int main() {
    int a[] = {7,5,7,8,7,7,4,7,0,4,7,7,4};
    int n = sizeof(a)/sizeof(int);

    printf("%d\n", majorityElement(a, n));
}

