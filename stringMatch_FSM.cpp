#include<iostream>
#include<string>
#include<vector>
using namespace std;

class StringMatcher {
private:
    vector<vector<int> > stats;
    int ex;
    int saver;

public:
    StringMatcher(string &p) {
        rebuildstats(p);
    }

    void rebuildstats(string &p) {
        stats.clear();
        ex = p.size();
        saver = ex; // save some space
        int star = -1;
        for(int i = 0; i < ex; ++i){
            if(p[i] == '*') { // every * is a jumper
                if(i > 0) 
                    for(int j = 0; j < 26; ++j)
                        if(stats[i-1][j] == i)
                            stats[i-1][j] = i+1;
                stats.push_back(vector<int>(1,0)); //dummy
                /* full length vect have to be added if no saver counting */
                star = i;
                --saver;
                continue;
            }
            stats.push_back(vector<int>(26, star + 1));
            for(char c = 'a'; c <= 'z'; ++c) {
                for(int j = star + 1; j <= i; j++) {
                    bool match = true;
                    int k = star + 1, l = j;
                    while(l < i) {
                        if(p[k++] != p[l++]) {
                            match = false;
                            break;
                        }
                    }
                    match = (match && p[k] == c);
                    if(match) {
                        stats[i][c - 'a'] = k + 1;
                        break;
                    }
                }
            }
        }
    }

    bool isMatch(string &s) {
        if(!saver)
            return true;
        int r = 0;
        for(int i = 0; i < s.size(); ++i) {
            r = stats[r][s[i] - 'a'];
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
                



