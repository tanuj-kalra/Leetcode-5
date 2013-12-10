#include<stdio.h>

int removeDuplicates(int A[], int n) {
    int i = -1, j = 0;
    while(j < n) {
        A[++i] = A[j];
        while(A[i] == A[j] && ++j < n)
            ;
    }
    return i + 1;
}

int removeDup2(int A[], int n) {
    int i = -1, j = 0;
    while(j < n) {
        A[++i] = A[j];
        if(++j < n && A[i] == A[j])
            A[++i] = A[j];
        while(A[i] == A[j] && ++j < n)
            ;
    }
    return i + 1;
}



int printArr(int A[], int n) {
    int i;
    for(i = 0; i < n; i++)
        printf("%3d", A[i]);
    printf("\n");
}

int main() {
    int a[] = {2,2,3,3,4,4,4,5,6,7,7};
    int n = sizeof(a)/sizeof(int);
    printArr(a, n);

    int l = removeDuplicates(a, n);
    printf("Length = %d\n",l);
    printArr(a,l);

    int b[] = {2,2,3,4,4,4,5,6,6,6,7,7,8,9,9};
    n = sizeof(b)/sizeof(int);
    printArr(b, n);

    l = removeDup2(b, n);
    printf("Length = %d\n",l);
    printArr(b,l);


    return 0;
}
