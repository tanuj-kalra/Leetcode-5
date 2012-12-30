#include<iostream>
#include<string>
#include<vector>
using namespace std;

/* FSM implementation of string search WITHOUT wildcard matching.
 * A program that match "*" is in another file.
 * However "?" that match one character seems hard. The state 
 * transition isn't determined in this case.
 */
class StringMatcher {
private:
    vector<vector<int> > stats;
    int ex;

public:
    StringMatcher(string &p) {
        rebuildstats(p);
    }

    void rebuildstats(string &p) {
        cout << "Building...";
        stats.clear();
        ex = p.size();
        for(int i = 0; i < ex; ++i){
            stats.push_back(vector<int>(128, 0));
            for(int c = 0; c < 128; ++c) { // careful not to use: char c
                for(int j = 0; j <= i; ++j) {
                    bool match = true;
                    int k = 0, l = j;
                    while(l < i && (match &= (p[k++] == p[l++])))
                        ;
                    match &= (p[k] == c);
                    if(match) {
                        stats[i][c] = k + 1;
                        break;
                    }
                }
            }
        }
        cout << "Complete" << endl;
    }

    bool isMatch(string &s) {
        int r = 0;
        for(int i = 0; i < s.size(); ++i) {
            r = stats[r][s[i]];
            if(r == ex)
                return true;
        }
        return false;
    }
};

int main() {
    string p;
    cin >> p;
    StringMatcher matcher(p);
    string s;
    while(cin >> s) {
        if(matcher.isMatch(s))
            cout << "Match ! \n";
        else
            cout << "NOT Match !\n";
    }

    return 0;
}
                



