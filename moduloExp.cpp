#include<iostream>
using namespace std;

class Solution {
public:
    long moduloExp (int a, int b, long m){
        long p = a % m;
        long r = 1;
        while(b>0){
            if(b & 1)
                r = (r * p) % m;
            b >>= 1;
            p = (p * p) % m;
        }
        return r;
    }
};

int main() {
    int a, b, m = 1;
    Solution pp;

    a = 30;
    b = 239; 
    for(m = 2; m < 1000000; m++) 
        if(0 == (pp.moduloExp(a,b,m) + pp.moduloExp(b,a,m)) % m)
            cout << m << '\n';

//    cout << "Input: base, power, modulo:\n";
//    while(1) {
//        cin >> a >> b >> m;
//        if(m == 0) break;
//        cout << pp.moduloExp(a,b,m) << '\n';
//    }

    return 0;
}
