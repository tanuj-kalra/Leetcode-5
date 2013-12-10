#include<iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()) return 0;
        int i = s.size();
        if ('0' == s[0])
            return 0;
        int p = 1, n = 0;
        for(int j = 1; j < i; ++j) {
            if('0' == s[j]) {
                if('0' == s[j-1] || s[j-1] > '2')
                    return 0;
                else {
                    n = p; 
                    p = 0;
                }
            } else if ((s[j-1] == '1') ||
                    (s[j-1] == '2' && s[j] < '7')) {
                int t = p;
                p += n;
                n = t;
            } else {
                p += n;
                n = 0;
            }
        }
        return p + n;
    }
};

int main() {
    string s;
    Solution pp;

    while(1) {
        cout << "Input string of numbers. Press Ctrl + C to exit\n";
        cin >> s;
        cout << pp.numDecodings(s) << '\n';
    }

    return 0;
}
