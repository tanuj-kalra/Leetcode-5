#include<iostream>
#include<string>
using namespace std;

class Play {
public:
    /* brutal force n^2 solution */
    string longestPalindrome(string s) {
        int m = 0;
        int n = s.size() - 1;
        string sub;
        for(int i = 0; i <= n; ++i) {
            int j = i, k = i;
            while(j >= 0 && k <= n) {
                if(s[j] != s[k])
                    break;
                --j, ++k;
            }
            if(m < k - j) {
                m = k - j - 1;
                sub = s.substr(j + 1, m);
            }
            j = i, k = i + 1;
            while(j >= 0 && k <= n) {
                if(s[j] != s[k])
                    break;
                --j, ++k;
            }
            if(m < k - j) {
                m = k - j - 1;
                sub = s.substr(j + 1, m);
            }
        }
        return sub;
    }
};

int main() {
    Play pp;
    string s = "abababac";
    cout << s << endl << pp.longestPalindrome(s) << endl;

    return 0;
}
