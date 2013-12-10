#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

class Solution {
public:
    void setMatrixZero (vector<vector<int> > &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i, j;
        srand(time(0));
        int marker;
        bool nfound = true;
        while(nfound) {
            marker = rand();
            nfound = false;
            for(i=0; i<n; i++)
                for(j=0; j<m; j++)
                    if(mat[i][j] == marker)
                        nfound = true;
        }
        cout << "Marker: " << marker << '\n';
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) 
                if(mat[i][j] == 0)
                    break;
            if (j<m)
                for(j=0; j<m; j++) {
                    if(mat[i][j] == 0)
                        mat[i][j] = marker;
                    else
                        mat[i][j] = 0;
                }
        }
        for(j=0; j<m; j++) {
            for(i=0; i<n; i++)
                if(mat[i][j] == marker)
                    break;
            if(i < n) 
                for(i=0; i<n; i++)
                    mat[i][j] = 0;
        }
    }

    void setMatZero (vector<vector<int> > &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i, j;
        bool fc = false, fr = false;
        for(i = 0; i < n; i++)
            if(mat[i][0] == 0) {
                fr = true;
                break;
            }
        for(j = 0; j < m; j++)
            if(mat[0][j] == 0) {
                fc = true;
                break;
            }
        for(i = 1; i < n; i++)
            for(j = 0; j < m; j++)
                if(mat[i][j] == 0) {
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                }
        for(i = 1; i < n; i++)
            for(j = 1; j < m; j++)
                if(mat[i][0] == 0 || mat[0][j] == 0)
                    mat[i][j] = 0;
        if(fr)
            for(i = 0; i < n; i++) 
                mat[i][0] = 0;
        if(fc)
            for(j = 0; j < m; j++)
                mat[0][j] = 0;
    }

    void printMat (vector<vector<int> > &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i, j;
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++)
                cout << setw(4) << mat[i][j];
            cout << '\n';
        }
        cout << '\n';
    }
};

int main() {
    vector<vector<int> > mat;
    int n = 30;
    int m = 20;
    mat.resize(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            mat[i].push_back(n * i + j);
    Solution pp;

    mat[0][0] = 1;
    mat[20][2] = 0;
    mat[5][4] = 0;
    mat[9][15] = 0;
    pp.printMat(mat);
    pp.setMatrixZero(mat);
    pp.printMat(mat);

    return 0;
}

