#include<iostream>
using namespace std;

class Play {
public:
    int searchRotateArr(int A[], int n, int t) { // assume no repeat
        int l = 0, r = n - 1, mid;
        while(l <= r) {
            mid = (l+r) /2;
            if(A[mid] == t)
                return mid;
            if((A[l] < A[r] && A[mid] < t) ||
                    (A[l] > A[r] && ((t > A[mid] && A[mid] > A[l]) ||
                                     (t < A[l] && (t > A[mid] ||
                                                        A[mid] >= A[l])))))
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

    /* Worst case when all elements are the same [2,2,2,2,2,2,2] */
    int searchRotArrII(int A[], int n, int t) { 
        int l = 0, r = n - 1, mid;
        while(l <= r) {
            if(l < r && A[l] == A[r]) {
                --r;
                continue;
            }
            mid = (l+r) /2;
            if(A[mid] == t)
                return mid;
            if(A[l] < A[r]) {
                if(A[mid] < t) l = mid + 1;
                else r = mid - 1;
            } else {
                if(A[mid] >= A[l]) {
                    if(t > A[mid] || t < A[l]) l = mid + 1;
                    else r = mid - 1;
                } else {
                    if(t > A[mid] && t < A[l]) l = mid + 1;
                    else r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    int a[] = {3,6,7,9,0,1};
    int n = sizeof(a)/sizeof(int);
    int t = 1;

    Play pp;
    cout << pp.searchRotateArr(a,n,t) << '\n';

    int b[] = {3,1,1};
    n = sizeof(b)/sizeof(int);
    t = 3;
    cout << pp.searchRotArrII(b,n,t)<< '\n';


    return 0;
}
