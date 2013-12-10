#include<iostream>
using namespace std;

class Play {
public:
    int searchInsert(int A[], int n, int t) {
        int l = 0, r = n - 1, mid;
        while(l <= r) {
            mid = (l + r) /2;
            if(t < A[mid])
                r = mid - 1;
            else if(t > A[mid])
                l = mid + 1;
            else
                return mid;
        }
        return l;
    }
};

int main() {
    int a[] = {1,3,5};
    int n = sizeof(a)/sizeof(int);
    int t = 5;

    Play pp;
    cout << pp.searchInsert(a, n, t) << '\n';

    return 0;
}
