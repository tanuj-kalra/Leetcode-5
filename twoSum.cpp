#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Play {
public:
    vector<int> twoSum(vector<int> &n, int t) {
        vector<int> v;
        int i,j;
        for(i = 0; i < n.size(); i++)
            for(j = i+1; j < n.size(); j ++)
                if(n[i] + n[j] == t)
                    v.push_back(i+1), v.push_back(j+1);
        return v;
    }

    void twoSumII(vector<int> m, int t) {
        sort(m.begin(), m.end());
        int p = 0, q = m.size() -1;
        while(p < q) { 
            int s = m[p] + m[q];
            if(s == t) {
                cout << m[p] << " " << m[q] << '\n';
                p++;
                q--;
            } else {
                if(s < t) p++;
                else q--;
            }
        }
    }

    void arrToVec(vector<int> &v, int a[], int n) {
        v.resize(n);
        while(n-- > 0)
            v[n] = a[n];
    }
            

    void printV(vector<int> &n) {
        for(int i = 0; i < n.size(); ++i)
            cout << n[i] << " ";
        cout << '\n';
    }
};

int main() {
    int a[] = {3,4,-9,7,8,-3,4,5,2,1,-1};
    int n = sizeof(a)/sizeof(int);
    vector<int> v;

    int t = 8;

    Play pp;
    pp.arrToVec(v,a,n);
    pp.printV(v);
    cout << "Target: " << t << " Pos: ";
    vector<int> s = pp.twoSum(v, t);
    pp.printV(s);
    pp.twoSumII(v,t);

    return 0;
}

