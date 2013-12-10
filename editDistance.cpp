#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Play {
public:
    int editDistance(string s1, string s2) {
        /* allow: Insert, Delete, Replace */
        int m = s1.size() + 1;
        int n = s2.size() + 1;
        vector<vector<int> > L(m, vector<int>(n,0));
        for(int i = 0; i < m; ++i) 
            L[i][0] = i;
        for(int j = 0; j < n; ++j)
            L[0][j] = j;
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j) {
                if(s1[i-1] == s2[j-1])
                    L[i][j] = L[i-1][j-1];
                else 
                    L[i][j] = 1 + min(L[i-1][j-1], min(L[i][j-1], L[i-1][j]));
            }
        return L[m-1][n-1];
    }
};

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    Play pp;

    cout << pp.editDistance(s1,s2) << endl;
    return 0;
}
