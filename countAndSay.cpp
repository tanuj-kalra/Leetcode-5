#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        stack<char> buf;
        char lab;
        int i,j,ct;
        for(i=1; i<n ; i++) {
            j = s.size() - 1;
            while(j >= 0) {
                lab = s[j];
                buf.push(lab);
                for(ct=0 ; lab==s[j]; j--, ct++)
                    if(j < 0)
                        break;
                do {
                    buf.push(ct % 10 + '0');
                } while((ct /= 10) > 0);
            }
            s.clear();
            while(!buf.empty()) {
                s += buf.top();
                buf.pop();
            }
        }
        return s;
    }
};

int main() {
    Solution pp;
    int i;
    for(i=1; i<31; i++)
        cout << pp.countAndSay(i) <<'\n';
    return 0;
}

