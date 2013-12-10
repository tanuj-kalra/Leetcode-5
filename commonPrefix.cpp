#include<iostream>
#include<vector>
using namespace std;

class Play {
public:
    string commonPrefix(vector<string> &strs) {
        string ss;
        size_t n = strs.size();
        if(n == 0) return ss;
        size_t m = strs[0].size();
        for(size_t i = 1; i < n; ++i) {
            size_t j;
            for(j = 0; j < m && j < strs[i].size(); ++j) 
                if(strs[0][j] != strs[i][j])
                    break;
            m = j;
            if(m == 0) break;
        }
        ss = strs[0].substr(0,m); // substr may cause leak
        return ss;
    }
};

int main() {
    vector<string> strs;
    strs.push_back("aab");
    strs.push_back("aac");
    strs.push_back("aa");

    Play pp;
    string t = pp.commonPrefix(strs);
    cout << t << '\n';

    return 0;
}
