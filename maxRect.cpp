#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Play {
public:
    int maxRect(vector<vector<char> > &mat) {
        if(mat.empty()) return 0;
        int m = mat.size(), n = mat[0].size();
        vector<int> H(n + 1, 0); // histogram, last height = 0 for convenience
        int ret = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == '0') H[j] = 0; // '0' is a char !
                else H[j]++;
            }
            ret = max(ret, maxHist(H));
        }
        return ret;
    }

    int maxHist(vector<int> &H) { // assume the last height is 0
        int ret = 0, n = H.size(), i = 0;
        stack<int> ind;
        while(i < n) {
            if(ind.empty() || H[ind.top()] <= H[i]) ind.push(i++);
            else {
                int t= ind.top();
                ind.pop();
                ret = max(ret, H[t] * (ind.empty() ? i : i - ind.top() - 1));
            }
        }
        return ret;
    }
};

int main() {
    vector<vector<char> > mat;
    string ss;
    while(getline(cin, ss))
        mat.push_back(vector<char>(ss.begin(),ss.end()));
    Play pp;
    cout << "Max Rect = " << pp.maxRect(mat) << endl;

    return 0;
}
