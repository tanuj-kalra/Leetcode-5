#include<stdio.h>

int min(int a, int b) {
    return a < b? a : b;
}

int findKth(int A[], int m, int B[], int n, int k) {
    while(m && n && k > 1) {
        m = min(m,k), n = min(n,k);
        int i,j;
        if(m > n) j = min(k/2,n), i = k - j;
        else i = min(k/2,m), j = k - i;
        if(A[i-1] > B[j-1]) B = B + j, n = n - j, k = k - j;
        else A = A + i, m = m - i, k = k - i;
    }
    if(m == 0) return B[k-1]; // A is empty, kth is B[k-1] !
    else if(n == 0) return A[k-1];
    else // k == 1
        return A[0] < B[0] ? A[0] : B[0];
}

int main() {
    int a[] = {1,6,9,10};
    int b[] = {2,5,7,8};
    int m = sizeof(a)/sizeof(int);
    int n = sizeof(b)/sizeof(int);

    int k = 3;
    int result = findKth(a,m,b,n,k);
    printf("%d\n", result);

    return 0;
}
