#include<iostream>
using namespace std;

class Solution {
    public:
    int fib(int n) {
        int s1 = 1;
        int s2 = 1;
        int temp;
        if(n < 2)
            return 1;
        int i;
        for(i=1; i < n; ++i) {
            temp = s1;
            s1 = s2;
            s2 += temp;
        }
        return s2;
    }
};

int main(){
    Solution pp;
    int i;
    for ( i=0; i < 32; ++i)
        cout << pp.fib(i) << '\n';
}
