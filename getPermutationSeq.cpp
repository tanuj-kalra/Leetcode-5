#include<iostream>
#include<string>
using namespace std;

int factorial(int n) {
    int m = 1;
    for(int i = 2; i <= n; ++i)
        m *= i;
    return m;
}

class Play {
public:
    string getPermutation(int n, int k) {
        string s(n, '1');
        --k, --n;
        int m = factorial(n), q;
        int i, j;
        for(i = 0; i < n; ++i) {
            q = k/m;
            s[i] += q;
            k -= q*m;
            m /= (n-i);
        }
        for(i = n-1; i >= 0; --i)
            for(j = i+1; j <= n; ++j)
                s[j] += (s[j] >= s[i]) ? 1 : 0;
        return s;
    }
};

int main() {
    Play pp;
    cout << pp.getPermutation(3,6) << '\n';
    cout << pp.getPermutation(5,119) << '\n';
    cout << pp.getPermutation(2,2) << '\n';
    cout << pp.getPermutation(4,24) << '\n';
    cout << pp.getPermutation(9,120) << '\n';

    return 0;
}
