#include<iostream>
#include<vector>
using namespace std;

int maxProfitK(vector<int> &p, int k) {
    vector<int> f(k + 1, 0), g(k + 1, 0);
    for(int i = 1; i < p.size(); i++) {
        int d = p[i] - p[i-1];
        for(int m = min(i, k); m > 0; m--) {
            f[m] = max(g[m-1], f[m]) + d;
            g[m] = max(g[m], f[m]);
        }
    }
    int profit = 0;
    for(int i = 1; i <= k; i++)
        profit = max(profit, g[i]);
    return profit;
}

int main() {
    vector<int> price{1,2,4,2,5,7,2,4,9,0,9};
    cout << maxProfitK(price, 2) << endl;

    return 0;
}
