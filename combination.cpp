#include<iostream>
#include<vector>

using namespace std;

class Play {
public:
    vector<vector<int> > comb(int n, int k) {
        vector<vector<int> > r;
        vector<int> s;
        for(int i = 0; i < k; )
            s.push_back(++i);
        r.push_back(s);
        while(next(s,n,k-1)) 
            r.push_back(s);
        return r;
    }

    bool next(vector<int> &s, int n, int d) {
        int i = d;
        while(i >= 0 && s[i] == n--)
            --i;
        if(i < 0) return false;
        else {
            s[i]++;
            while(i < d) {
                s[i+1] = s[i] + 1;
                ++i;
            }
        }
        return true;
    }
};

void printVV(vector<vector<int> > &v) {
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << '\n';
    }
}

int main() {
    Play pp;
    vector<vector<int> > v = pp.comb(5,3);
    printVV(v);

    return 0;
}
