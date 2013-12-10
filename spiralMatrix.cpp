#include<iostream>
#include<vector>
using namespace std;

class Play {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> v;
        int lr = 0, mr = matrix.size() - 1, 
            lc = 0, mc = matrix[0].size() - 1, 
            i = 0, j = 0;
        int c = 1;
        while(lc <= mc && lr <= mr) {
            v.push_back(matrix[i][j]);
            switch(c) {
            case 1:
                if(j < mc)
                    ++j;
                else {
                    ++i;
                    ++lr;
                    c = 2;
                }
                break;
            case 2:
                if(i < mr)
                    ++i;
                else {
                    --mc;
                    --j;
                     c = 3;
                }
                break;
            case 3:
                if(j > lc)
                    --j;
                else {
                    --mr;
                    --i;
                     c = 4;
                }
                break;
            case 4:
                if(i > lr)
                    --i;
                else {
                    ++lc;
                    ++j;
                     c = 1;
                }
                break;
            };
        }
        return v;
    }

    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > mat(n, vector<int>(n,0));
        if(n == 0)
            return mat;
        int i = 0, j = 0, k = 1;
        while(k <= n * n) {
            mat[i][j] = k++;
            if(j < n - 1 - i && j >= i - 1)
                ++j;
            else if(j < i - 1 && j <= n - 1 - i)
                --i;
            else if(j >= n - 1 - i && j > i)
                ++i;
            else 
                --j;
        }
        return mat;
    }
};

void printV(vector<int> & v) {
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    Play pp;
    vector<vector<int> > mat(3, vector<int>(3, 0));
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            mat[i][j] = i * 3 + j;
    vector<int> v = pp.spiralOrder(mat);
    printV(v);
    mat = pp.generateMatrix(5);
    v = pp.spiralOrder(mat);
    printV(v);

    return 0;
}
