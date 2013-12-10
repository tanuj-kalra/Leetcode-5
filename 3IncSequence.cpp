#include<iostream>
#include<vector>
using namespace std;

class Play {
public:
    void threeIncSeq(vector<int> seq) {
        /* find three index i,j,k seq[i] < seq[j] < seq[k] */
        int cl = -1, ch = -1, t = 0;
        int i, n = seq.size();
        for(i = 1; i < n; ++i) {
            if(ch != -1 && seq[i] > seq[ch]) 
                break;
            if(seq[i] > seq[t]) {
                cl = t;
                ch = i;
                t = cl;
            }
            else
                t = i;
        }
        if(i < n && ch != -1)
            cout << seq[cl] << " " << seq[ch] << " " << seq[i] << endl;
    }
};
            
int main() {
    Play pp;
    vector<int> v;
    int t;
    while(cin >> t) {
        v.push_back(t);
    }

    pp.threeIncSeq(v);

    return 0;
}
