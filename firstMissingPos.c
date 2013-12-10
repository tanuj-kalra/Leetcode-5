#include<stdio.h>

int firstMissingPos(int A[], int n) {
    int i = 0;
    for(; i < n; i++) { // mark appeared integer A[i] at A[i]-th position
        int t = A[i];
        while(t > 0 && t <= n) { // tracing cycles avoid loss of info
            int temp = A[t-1];
            if(temp == t) 
                break;
            A[t-1] = t;
            t = temp;
        }
    }
    for(i = 0; i < n; i++)
        if(A[i] != (i+1))
            return (i+1); // first unmarked, first missing
    return n + 1;
}

int main() {
    int b[] = {1,4,2,0,3,4,2,4,2};
    int x = sizeof(b)/sizeof(int);
    printf("%d\n", firstMissingPos(b, x));

    int a[] = {5,7,9,-9,-4,2,3,10,1,17,9,-3,87,98,55};
    int y = sizeof(a)/sizeof(int);
    printf("%d\n", firstMissingPos(a, y));
    return 0;
}
