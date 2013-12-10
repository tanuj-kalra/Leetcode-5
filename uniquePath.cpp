#include<iostream>
#include<vector>
using namespace std;

class Play {
public:
    int uniquePathII(vector<vector<int> > &mat) { // dp on each row
        int m = mat.size();
        int n = mat[0].size();
        vector<int> r(n+1, 0);
        int i = n-1;
        m--;
        while(i >= 0 && mat[m][i] == 0)
            r[i--] = 1;
        while(m-- > 0) {
            for(i = n-1; i >=0; i--)
                r[i] = (mat[m][i] == 1) ? 0 : r[i] + r[i+1];
        }
        return r[0];
    }
    
    int minPathSum(vector<vector<int> > &g) { // almost same as robot II
        int m = g.size();
        int n = g[0].size();
        vector<int> s(n--, 0);
        m--;
        s[n] = g[m][n];
        int i;
        for(i = n - 1; i >= 0; --i)
            s[i] = g[m][i] + s[i+1];
        while(m-->0) {
            s[n] += g[m][n];
            for(i = n - 1; i >= 0; --i)
                s[i] = g[m][i] + min(s[i], s[i+1]);
        }
        return s[0];
    }

    vector<vector<int> > format(int a[], int m, int k) {
        int n = k / m;
        vector<vector<int> > v;
        v.resize(m);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                v[i].push_back(a[i*n + j]);
        return v;
    }

    void print(vector<vector<int> > &v) {
        int m = v.size();
        int n = v[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++)
                cout << v[i][j] << " ";
            cout << '\n';
        }
    }
};

int main() {
    Play pp;
    int pre[] = {0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,1,0};
    int k = sizeof(pre)/ sizeof(int);
    int m = 4;
    vector<vector<int> > a = pp.format(pre, m, k);

    pp.print(a);
    cout << pp.uniquePathII(a) << '\n';


    int pb[] = {1,2,3,8,4,3,2,1,5,3,2,3,1,4,5,3,6};
    k = sizeof(pb)/sizeof(int);
    m = 4;
    a = pp.format(pb, m, k);

    pp.print(a);
    cout << pp.minPathSum(a) << '\n';

    return 0;
}
