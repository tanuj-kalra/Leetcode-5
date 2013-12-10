#include<iostream>
using namespace std;

class Play {
public:
    int lengthNoRepeatSub(string s) {
        int r = 0, low = 0;
        int m[128] = {};
        for(int i = 0; i < s.size(); ++i) {
            if(m[s[i]] == 0)
                m[s[i]] = 1;
            else {
                while(s[low] != s[i])
                    m[s[low++]]--;
                low++;
            }
            r = max(r, i - low + 1);
        }
        return r;
    }
};

int main() {
    string s("abcdcbae");
    Play pp;

    cout << s << " : " << pp.lengthNoRepeatSub(s) << '\n';

    return 0;
}
