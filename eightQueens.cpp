#include<iostream>
using namespace std;

class Play {
public:
    int solveQueens(int n) {
        int num = 0;
        int b[n]; // array is much faster than vector......
        for(int j = 0; j < n; ++j)
            b[j] = -1;
        int i = 0;
        while(i != -1) {
            ++b[i];
            if(b[i] == n) {
                --i;
                continue;
            }
            bool g = true;
            for(int j = 0; j < i; ++j)
                if(b[i] == b[j] || b[i] + j == b[j] + i || b[i] + i == b[j] + j){
                    g = false;
                    break;
                }
            if(g) {
                if(i == n-1) {
                    printBoard(b, n);
                    ++num;
                }
                else 
                    b[++i] = -1;
            }
        }
        return num;
    }
    void printBoard(int b[], int n) {
        cout << '\n';
        for(int i = 0; i < n; ++i) {
            int j = 0;
            for(; j < b[i]; ++j)
                cout << " . ";
            cout << " Q ";
            for(; j < n - 1; ++j)
                cout << " . ";
            cout << '\n';
        }
    }
};

int main() {
    int n = 8;
    Play pp;
    cout << "\nNumbers: "  << pp.solveQueens(n) << '\n';

    return(0);
}

