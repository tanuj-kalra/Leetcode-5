#include<iostream>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if(n < 0)
            x = 1/x;
        double r = 1;
        double p = x;
        while(n) {
            if(n & 1)
                r *= p;
            p *= p;
            n /= 2; // Could do a right shift here for positiv powers
        }
        return r;
    }
};

int main() {
    Solution pp;
    cout << pp.pow(1.00012, 1024) << '\n';
    cout << pp.pow(-1, -2147483648) << '\n'; // Be careful of the INT_MIN trap !
    cout << pp.pow(-1.00001, 447125) << '\n';
    return 0;
}

