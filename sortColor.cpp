#include<iostream>
using namespace std;

class Play {
public:
    void sortColors(int A[], int n) { // like selection with repeated pivet element
        int p = -1, q = 0;
        for(int i = 0; i < n; ++i) {
            if(A[i] < 1) {
                swap(A[i], A[++p]);
                if(q != 0)
                    swap(A[i], A[q + p]);
            }
            else if(A[i] == 1) {
                swap(A[i], A[++q+p]);
            }
        }
    }
};

void printA(int A[], int n) {
    for(int i = 0; i < n; ++i)
        cout << A[i] << " ";
    cout << '\n';
}

int main() {
    int a[] = {1,2,0,0,1,2,2,1,2,0,2,1};
    int n = sizeof(a)/sizeof(int);
    printA(a, n);

    Play pp;
    pp.sortColors(a,n);
    printA(a,n);

    return 0;
}
