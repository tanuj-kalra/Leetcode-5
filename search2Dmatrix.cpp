#include<iostream>
#include<vector>
using namespace std;

class Play {
public:
    bool searchMatrix(vector<vector<int> > &mat, int t) {
        int m = mat.size(), n = mat[0].size();
        int l = 0, h = m - 1;
        while(l <= h) {
            int mid = (l+h) / 2;
            if(mat[mid][0] == t)
                return true;
            else if(mat[mid][0] > t) 
                h = mid - 1;
            else
                l = mid + 1;
        }
        if(h < 0) return false;
        m = h, l = 0, h = n - 1;
        while(l <= h) {
            int mid = (l+h) / 2;
            if(mat[m][mid] == t)
                return true;
            else if(mat[m][mid] > t)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return false;
    }
};

int main() {
    vector<vector<int> > mat {{1, 4, 6, 8},
        {9, 13, 15, 20},{30, 40, 50, 60}};

    Play pp;
    if(pp.searchMatrix(mat, 50))
        cout << "Found !\n";

    return 0;
}
