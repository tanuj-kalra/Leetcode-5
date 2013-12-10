#include<iostream>
using namespace std;

class Play {
public:
    string palSubseq(string s) {
        int n = s.size();
        int m[1000][1000] = {};
        for(int i = 0; i < n; ++i)
            m[i][i] = 1;
        for(int i = 1; i < n; ++i)
            for(int j = 0; j < n - i; ++j) 
                m[j][i+j] = (s[j] == s[i+j]) ? m[j+1][i+j-1] + 2 :
                    max(m[j][i+j-1], m[j+1][i+j]);
        string ss(m[0][n-1], 0);
        int p = 0, i = 0, j = n-1;
        while(i <= j) {
            if(m[i][j] == m[i+1][j])
                ++i;
            else if(m[i][j] == m[i][j-1])
                --j;
            else {
                ss[p] = ss[m[0][n-1] - 1 - p] = s[i];
                ++i, --j, ++p;
            }
        }
        return ss;
    }
};

int main() {
    string s("adobereader");
    Play pp;
    string pal = pp.palSubseq(s);

    cout << s << '\n' << pal << '\n';

    return 0;
}
