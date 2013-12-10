#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

class Play {
public:
    vector<string> letterCombo(string digi) {
        map<char, string> table;
        table['2'] = "abc";
        table['3'] = "def";
        table['4'] = "ghi";
        table['5'] = "jkl";
        table['6'] = "mno";
        table['7'] = "pqrs";
        table['8'] = "tuv";
        table['9'] = "wxyz";
        int n = digi.size();
        vector<string> v;
        v.push_back(" ");
        for(int i = 0; i < n; ++i) {
            char c = digi[i];
            int ss = table[c].size();
            int m = v.size();
            for(int j = 1; j < ss; ++j)
                for(int k = 0; k < m; ++k)
                    v.push_back(v[k] + table[c][j]);
            c = table[c][0];
            for(int k = 0; k < m; ++k)
                v[k] += c;
        }
        return v;
    }
};

int main() {
    Play pp;
    string digi;
    vector<string> v;

    while(cin >> digi) {
        v = pp.letterCombo(digi);
        int n = v.size();
        for(int i = 0; i < n; ++i)
            cout << v[i] << '\n';
    }

    return 0;
}


