#include<iostream>
using namespace std;

bool gt (int a, int b) { return a > b; }
bool lt(int a, int b) { return a < b; }
bool eq(int a, int b) { return a == b; }
bool ge(int a, int b) { return a >= b; }
bool le(int a, int b) { return a <= b; }

int search(int A[], int N, int key, bool (*f) (int, int)) {
    int dir = f(A[0], A[N-1]) ? -1 : 1; // direction of the search
    int cur = (dir == 1) ? 0 : N - 1;
    while(!f(A[cur], key)) {
        cur += dir;
        if(cur < 0 || cur > N - 1) return -1; // not found
    }
    return A[cur];
}

int main() {
    int A[] = {1,2,3,3,5,6};
    int n = sizeof(A)/sizeof(int);
    
    int key = 4;
    cout << "greater: " << search(A,n,key,gt) << endl;
    cout << "less: " << search(A,n,key,lt) << endl;
    cout << "equal: " << search(A,n,key,eq) << endl;
    cout << "greater_equal: " << search(A,n,key,ge) << endl;
    cout << "less_equal: " << search(A,n,key,le) << endl;

    return 0;
}
