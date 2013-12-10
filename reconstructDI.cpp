#include<iostream>
#include<string>
using namespace std;

class Play {
public:
    void reconstruct(string &s) { 
        /* reconstruct minimal lexical seq with DIDI */
        int n = s.size();
        int m = 1; // minimal current availabe number
        int i = 0;
        while(i < n) { 
            if(s[i] == 'I') {
                cout << m++ << " "; // output
                i++;
            }
            else {
                int j;
                for(j = i; j < n && s[j] != 'I'; ++j)
                    ;
                int t = m + j - i + 1;
                for(; i <= j; ++i)
                    cout << m + j - i << " "; // output
                m = t;
            }
        }
        if(s[n-1] == 'I') 
            cout << m; // output
        cout << endl;
    }
};

int main() {
    Play pp;
    string s;
    cin >> s;

    pp.reconstruct(s);
    return 0;
}


