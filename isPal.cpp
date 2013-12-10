#include<iostream>
#include<string>

using namespace std;

class Play {
    public:
        bool isAlphaNum(char c) {
            return 'a' <= c && c <= 'z' ||
                'A' <= c && c <= 'Z' || '0' <= c && c <= '9';
        }

        char toLow(char c) {
            if('A' <= c && c <= 'Z') return c - 'A' + 'a';
            else return c;
        }

        bool isPalindrome(string s) {
            int i = 0, j = s.size() - 1;
            while(i < j) {
                if(isAlphaNum(s[i])) {
                    if(isAlphaNum(s[j])) {
                        if(toLow(s[i]) != toLow(s[j])) return false;
                        i++, j--;
                    }
                    else j--;
                }
                else i++;
            }
            return true;
        }
};

int main() {
    Play pp;
    string s;
    while(cin >> s) {
        if(pp.isPalindrome(s))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
