#include<stdio.h>

void swap (int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void siftUp(int a[], int k) { //siftUp a[k] in a[0......], MAX HEAP !
    while(k > 0) {
        int j = (k-1)/2;
        if(a[k] > a[j])
            swap(a + k, a + j);
        k = j;
    }
}

void siftDown(int a[], int n, int k) { //siftDown a[k] in a[......n]
    int j;
    while((j = 2 * k + 1) < n) {
        j = (a[j] > a[j+1]) ? j : j+1;
        if(a[j] > a[k])
            swap(a + k, a + j);
        k = j;
    }
    if (j == n)
        if(a[n] > a[k])
            swap(a + k, a + n);
}
 
void heapify(int a[], int n) {
    int i = n/2;
    for(;i >= 0; i--)
        siftDown(a, n, i);
}

void heapSort(int a[], int n) {
    heapify(a, n);
    while(n > 0) {
        swap(a, a + n);
        siftDown(a, --n, 0);
    }
}

void printArr(int a[], int n) {
    int i = 0;
    while(i <= n)
        printf("%3d", a[i++]);
    printf("\n");
}
        

int main() {
    int a[] = {3,5,19,8,4,1,2,7,6,0,3,4,10,20,19,30,14,13,11,9,7}; // n = 20
    int n = 15;

    printArr(a,n);
    heapSort(a, n);
    printArr(a,n);

    return 0;
}


