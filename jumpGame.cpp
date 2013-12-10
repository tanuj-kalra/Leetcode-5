#include<iostream>
using namespace std;

class Play {
public:
    bool canJump(int A[], int n) {
        int m = A[0];
        int i = 0;
        while(i <= m ) {
            m = max(m, i + A[i]);
            if(m >= n-1) return true;
            ++i;
        }
        return false;
    }

    int jump(int A[], int n) {
        int p = 0, q = 0, i = 0;
        while(q < n-1) {
            int m = q;
            for(; p <= q; ++p)
                m = max(m, p + A[p]);
            if(m == q) return -1; // in case cannot reach end
            q = m;
            ++i;
        }
        return i;
    }

};

int main() {
    int a[] = {3,3,1,0,0,4};
    int n = sizeof(a) / sizeof(int);

    Play pp;
    if(pp.canJump(a, n))
        cout << "Can Jump\n";

    cout << "JUMP in " << pp.jump(a, n) << " steps !\n";

    return 0;
}
