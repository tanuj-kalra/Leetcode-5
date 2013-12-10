#include<iostream>
using namespace std;

class Solution {
    public:
    double find_medium(int A[], int m, int B[], int n) {
        int flag = (m + n) % 2;
        int k = (m + n) /2;
        if(flag)
            return one_side_k(A,m,B,n,k) | one_side_k(B,n,A,m,k);
        else
            return ((double)(one_side_k(A,m,B,n,k-1) | one_side_k(B,n,A,m,k-1))
                + (one_side_k(A,m,B,n,k) | one_side_k(B,n,A,m,k))) /2;
    }

    int one_side_k(int A[], int m, int B[], int n, int k){
        if(0 == n) return A[k];
        int l,r, mid, cr;
        l = 0, r = m - 1;
        while(l <= r) {
            mid = (l+r) /2;
            cr = k-mid - 1;
            if(cr < -1) 
                r = mid - 1;
            else if(cr + 1 > n) 
                l = mid + 1;
            else if(cr == -1) {
                if(A[mid] <= B[0])
                    return A[mid];
                r = mid - 1;
            }
            else if(cr + 1 == n) {
                if(A[mid] >= B[n-1])
                    return A[mid];
                l = mid + 1;
            }
            else if(A[mid] > B[cr+1])
                r = mid - 1;
            else if(A[mid] < B[cr])
                l = mid + 1;
            else 
                return A[mid];
        }
        return 0;
    }
};

int main() {
    int a[] = {1,2,3,4,5};
    int b[] = {6,7,8,9,10};
    Solution pp;
    double kk = pp.find_medium(a, 5, b,5 );
    cout << kk << '\n';
}
