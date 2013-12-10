#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Play {
public:
    int kmp(string t, string p) {
        if(p.empty())
            return 0;
        int m = p.size();
        vector<int> table(m,-1);
        for(int i = 1; i < m; ++i) {
            int k = table[m - 1];
            while(p[k + 1] != p[i]) {
                if(k == -1) break;
                k = table[k];
            }
            if(p[k + 1] == p[i])
                table[i] = k + 1;
        }

        int q = -1;
        int n = t.size();
        for(int i = 0; i < n; ++i) {
            while(p[q + 1] != t[i]) {
                if(q == -1) break;
                q = table[q];
            }
            if(p[q + 1] == t[i])
                q++;
            if(q == m - 1)
                return i - q;
        }
        return -1;
    }
};

int main() {
    Play pp;
    string t, p;
    while(cin >> p) {
        cin >> t;
        cout << "Index: " << pp.kmp(t,p) << endl;
    }

    return 0;
}
