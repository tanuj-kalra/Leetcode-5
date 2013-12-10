#include<iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0, j = n;
        while(i < j) {
            if(A[i] == elem) 
                A[i] = A[--j];
            else 
                i++;
        }
        return j;
    }
};

int main() {
    int a[] = {3,4,5,3,6,8,9,2,5,4};
    int n = sizeof(a)/sizeof(int);
    int i;
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';

    Solution pp;

    int l = pp.removeElement(a, n, 3);
    cout << "New length " << l << '\n';
    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << '\n';

    return 0;
}
