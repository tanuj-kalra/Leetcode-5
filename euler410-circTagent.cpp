#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

vector<int> sieve(int n) {
    vector<int> vis(n + 1,0);
    vector<int> primes;
    int m = sqrt(n) + 1;
    for(int i = 2; i <= m; i++) if(!vis[i]) {
        primes.push_back(i);
        for(int j = i*i; j <= n; j+= i) vis[j] = 1;
    }
    return primes;
}

vector<int> factor(int n) {
    vector<int> counts(n+1, 1); 
    for(int i = 2; i <= n; i++) if(counts[i] == 1)
        for(int j = i; j <= n; j += i) counts[j] <<= 1;
    return counts;
}

long long circTagent(long long R, long long X) {
    int cap = min(R,X);
    vector<int> counts = factor(cap);

    long long sum = 0;
    for(int i = 1; i <= cap; i++) {
        long long s = R/i, t = X/i;
        sum += counts[i] * ((i & 1) ? s * t: 
                (s/2 + (s & 1)) * (t/2 + (t & 1)) + (s/2) * (t/2));
    }
    return sum * 2;
}

int main() {
    int R,X;
//    cin >> R >> X;
//    cout << circTagent(R,X) << endl;
    cout << circTagent(1,5) << endl;
    cout << circTagent(2,10) << endl;
    cout << circTagent(10,100) << endl;
    cout << circTagent(100000000, 1000000000) * 2 << endl;

    return 0;
}
