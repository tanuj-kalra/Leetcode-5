#include<stdio.h>

void merge(int A[], int m, int B[], int n) {
    int k = m+n-1;
    m--, n--;
    while(m >= 0 && n >= 0) {
        if(A[m] > B[n])
            A[k--] = A[m--];
        else
            A[k--] = B[n--];
    }
    while(n >= 0)
        A[k--] = B[n--];
}

int main() {
    int a[10] = {1,4,8,9,13};
    int b[5] = {3,5,9,10,14};

    merge(a,5,b,5);
    int i;
    for(i=0; i<10; i++)
        printf("%3d", a[i]);
    printf("\n");
    return 0;
}
