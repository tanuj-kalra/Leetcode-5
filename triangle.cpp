#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

class Play {
public:
    int minimumTriangle(vector<vector<int> > &t) {
        int n = t.size();
        vector<int> p (n+1, 0);
        while(n-- > 0)
            for(int i = 0; i <= n; ++i) 
                p[i] = t[n][i] + ((p[i] < p[i+1])? p[i] : p[i+1]);
        return p[0];
    }

    vector<vector<int> >  pascalTriangle(int n) {
        vector<vector<int> > t;
        if(0 == n) return t;
        t.resize(n);
        t[0].push_back(1);
        for(int i = 1; i < n; i++) {
            t[i].push_back(1);
            for(int j = 1; j < i; j++)
                t[i].push_back(t[i-1][j-1] + t[i-1][j]);
            t[i].push_back(1);
        }
        return t;
    }

    vector<int> pascalRow(int n) { // uses only k+1 space
        vector<int> r(n+1, 0);
        for(int i = 0; i <= n; i++) {
            r[i] = 1;
            for(int j = i-1; j > 0; j--)
                r[j] += r[j-1];
        }
        return r;
    }

    int uniquePath(int m, int n) { // uniquePath robot on mxn board
        if(m > n) return uniquePath(n, m);
        int r[m];
        int i, j;
        for(i = 0; i < m; i++) {
            r[i] = 1;
            for(j = i-1; j > 0; j--)
                r[j] += r[j-1];
        }
        for(; i < n; i++) 
            for(j = m-1; j > 0; j--)
                r[j] += r[j-1];
        for(i = m-1; i > 0; i--)
            for(j = 0; j < i; j++)
                r[j] += r[j+1];
        return r[0];
    } // should reach the combination number: n+m-2 choose m-1

    void initTriangle(vector<vector<int> > &t, int n) {
        t.clear();
        t.resize(n);
        while(n-- > 0)
            for(int i = 0; i <= n; ++i)
                t[n].push_back(rand() % 20 - 10);
    }

    void printTriangle(vector<vector<int> >&t) {
        int n = t.size();
        for(int j = 0; j < n; j++){
            cout << setw(3*(n-j)) << " ";
            for(int i = 0; i <= j; ++i) 
                cout << setw(5) << t[j][i] << " ";
            cout << '\n';
        }
    }

    void printVec(vector<int> &t) {
        int n = t.size();
        for(int i = 0; i < n; i++)
            cout << setw(5) << t[i] << " ";
        cout << '\n';
    }
};

int main() {
    vector<vector<int> > a;
    int n;
    
    srand(time(0));
    Play pp;
    for(n = 1; n < 10; n++) {
        pp.initTriangle(a, n);
        int sum = pp.minimumTriangle(a);
        cout << "Min Sum: " << sum << '\n';
        pp.printTriangle(a);
    }

    a = pp.pascalTriangle(10);
    pp.printTriangle(a);

    int m = 9;
    vector<int> r = pp.pascalRow(m);
    cout << setw(2) << m << ":";
    pp.printVec(r);

    cout << pp.uniquePath(10, 10) << '\n';

    
    return 0;
}
