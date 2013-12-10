#include<iostream>
#include<vector>
using namespace std;

class Play {
public:
    bool isMatch(const char *s, const char *p) {
        /* bad m*n dp solution, TOO SLOW TO PASS OJ */
        int i = 0, j = 0;
        for(; s[j] != 0; ++j)
            ;
        for(; p[i] != 0; ++i)
            ;
        vector<vector<bool> >v(i+1, vector<bool>(j+1, 0));
        v[0][0] = 1;
        for(i = 0; p[i] != 0; ++i) {
            if(v[i][0] && p[i] == '*')
                v[i+1][0] = 1;
            bool f = false;
            for(j = 0; s[j] != 0; ++j) {
                switch(p[i]) {
                    case '*':
                        v[i+1][j+1] = v[i][j] || v[i][j+1] || f;
                        f = true;
                        break;
                    case '?':
                        v[i+1][j+1] = v[i][j];
                        break;
                    default:
                        v[i+1][j+1] = v[i][j] && p[i] == s[j];
                }
            }
        }
        return v[i][j];
    }
};

int main() {
    Play pp;
    string s,p;
    cin >> s >> p;
    const char *sc = s.c_str();
    const char *pc = p.c_str();

    if(pp.isMatch(sc, pc))
        cout << "Match ! \n";

    return 0;
}
