#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Play {
public:
    int maxProfit(vector<int> &p) { // buy and sell only time
        if(p.empty()) return 0;
        int m = 0, lm = p[0];
        for(int i = 1; i < p.size(); ++i) {
            if(p[i] > p[i-1]) m = max(m, p[i] - lm);
            else lm = min(lm, p[i]);
        }
        return m;
    }

    int maxProfitII(vector<int> &p) {
        int m = 0;
        for(int i = 1; i < p.size(); ++i)
            if(p[i] > p[i-1]) m += (p[i]-p[i-1]);
        return m;
    }

    int maxProfitIII(vector<int> &p) {
        int n = p.size();
        if(n == 0) return 0;

        vector<int> inc(n,0), dec(n,0);
        for(int i = 1, lm = p[0]; i < n; ++i) {
            inc[i] = max(inc[i-1], p[i] - lm);
            lm = min(p[i], lm);
        }
        for(int i = n-2, lm = p[n-1]; i >= 0; --i) {
            dec[i] = max(dec[i+1], lm - p[i]);
            lm = max(p[i], lm);
        }
        int profit = 0;
        for(int i = 0; i < n; ++i) 
            profit = max(profit, inc[i] + dec[i]);
        return profit;
    }

    int maxPIII(vector<int> &p) {
        /* observation: 
         * maxIII = maxI + max local drop OR maxI + another maxI
         */
        int lmin = INT_MAX, lmax, ldrop, rise = 0, total = 0;
        for(int i = 0; i < p.size(); ++i) {
            if(p[i] < lmin) {
                lmin = p[i];
                lmax = p[i];
                ldrop = rise;
                /* reset ldrop as max of local drop and previous rise */
                continue;
            }
            lmax = max(lmax, p[i]);
            ldrop = max(ldrop, lmax - p[i]);
            rise = max(rise, p[i] - lmin);
            /* rise give the solution to buy sell stock I */
            total = max(total, p[i] - lmin + ldrop);
        }
        return total;
    }

    void arrToVec(vector<int> &v, int a[], int n) {
        v.resize(n);
        while(n-- > 0)
            v[n] = a[n];
    }
            

    void printV(vector<int> &n) {
        for(int i = 0; i < n.size(); ++i)
            cout << n[i] << " ";
        cout << '\n';
    }

};

int main() {
    Play pp;
    int a[] = {3,2,6,5,0,3};
    int n = sizeof(a)/sizeof(int);
    vector<int> v;
    pp.arrToVec(v, a, n);
    pp.printV(v);

    cout << pp.maxProfit(v) << '\n';

    int b[] = {6,1,3,2,4,7};
    int m = sizeof(b)/sizeof(int);
    vector<int> u;
    pp.arrToVec(u, b, m);
    pp.printV(u);

    cout << pp.maxProfitII(u) << '\n';

    int c[] = {1,2,4,2,5,7,2,4,9,0,9}; 
    int o = sizeof(c)/sizeof(int);
    vector<int> w;
    pp.arrToVec(w, c, o);
    pp.printV(w);
    cout << pp.maxProfitIII(w) << '\n';
    cout << pp.maxPIII(w) << '\n';

    return 0;
}

