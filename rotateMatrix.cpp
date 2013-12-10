#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; ++i)
            for(int j = i; j < n-1-i; ++j){
                int t = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = t;
            }
    }

    void print(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j)
                cout << setw(4) << matrix[i][j];
            cout << '\n';
        }
    }
};

int main() {
    vector<vector<int> > m;
    int n = 20;
    m.resize(n);
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            m[i].push_back(i * n + j);
    Solution pp;
    pp.print(m);
    cout << '\n';
    pp.rotate(m);
    pp.print(m);
    return 0;
}







