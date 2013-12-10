#include<iostream>
using namespace std;

class Play {
public:
    int trap(int A[], int n) {
        if(n == 0) return 0;
        int i, mi = 0, m = 0;
        for(i = 0; i < n; ++i) {
            if(A[i] > m)
                mi = i;
        }
        int sum = 0, lm;
        for(lm = A[0], i = 1; i < mi; ++i) {
            if(A[i] < lm)
                sum += (lm - A[i]);
            else 
                lm = A[i];
        }
        for(lm = A[n-1], i = n-2; i > mi; --i) {
            if(A[i] < lm)
                sum += (lm - A[i]);
            else 
                lm = A[i];
        }
        return sum;
    }

    int trapII(int A[], int n) {
        if(n == 0) return 0;
        int i = 0, j = n-1, lm = A[0], rm = A[n-1], sum = 0;
        while(i < j) {
            if(lm < rm) {
                if(A[++i] < lm)
                    sum += (lm - A[i]);
                else
                    lm = A[i];
            } else {
                if(A[--j] < rm)
                    sum += (rm - A[j]);
                else
                    rm = A[j];
            }
        }
        return sum;
    }
        
};

int main() {
    int a[] = {4,2,0,3,2,5};
    int n = sizeof(a)/sizeof(int);

    Play pp;
    cout << pp.trap(a, n) << '\n';
    cout << pp.trapII(a,n) << '\n';

    return 0;
}

