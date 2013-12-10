#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Play {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > v(1);
        for(int i = 0; i < S.size(); ++i) {
            int j = v.size();
            while(j-- > 0) {
                v.push_back(v[j]);
                v.back().push_back(S[i]);
            }
        }
        return v;
    }

    vector<vector<int> > subsetsII(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > v(1);
        int c = 1;
        for(int i = 0; i < S.size(); ++i) {
            if(i < S.size() - 1 && S[i] == S[i+1]) {
                c++;
                continue;
            }
            int j = v.size();
            while(j-- > 0) {
                for(int k = 0; k < c; ++k) {
                    v.push_back(v[j]);
                    for(int l = k; l >= 0; --l)
                        v.back().push_back(S[i]);
                }
            }
            c = 1;
        }
        return v;
    }
};

void printVV(vector<vector<int> > v) {
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main() {
    Play pp;
    vector<int> s {3,1,4,2};
    vector<vector<int> >v = pp.subsets(s);
    printVV(v);

    vector<int> t {3,2,3,2};
    vector<vector<int> >u = pp.subsetsII(t);
    printVV(u);

    return 0;
}

