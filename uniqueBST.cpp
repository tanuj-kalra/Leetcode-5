#include<iostream>
#include<vector>
using namespace std;

class Play {
public:
    int numTrees(int n) {
        /* Catalan numbers C_{2n}^n / (n+1)
         * Recursion: C(n) = C(0)C(n-1) + C(1)C(n-2) + ... + C(n-1)C(0)
         */
        vector<int> v(2,1);
        for(int i = 2; i <= n; ++i){
            int c = 0;
            for(int j = 0; j < i; ++j)
                c += v[j] * v[i-1-j];
            v.push_back(c);
        }
        return v[n];
    }
};

int main() {
    Play pp;
    for(int i = 0; i < 18; ++i)
        cout << pp.numTrees(i) << endl;

    return 0;
}
