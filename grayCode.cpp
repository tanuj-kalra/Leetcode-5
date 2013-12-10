#include<iostream>
#include<vector>
using namespace std;

class Play {
public:
    vector<int> grayCode(int n) {
        vector<int> r;
        r.push_back(0);
        for(int i = 0; i < n; ++i)
            for(int j = r.size() - 1; j >= 0; --j)
                r.push_back(r[j] | 1 << i);
        return r;
    }
};

void printV(vector<int> &v) {
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << '\n';
}

int main() {
    int n = 5;
    Play pp;
    vector<int> v = pp.grayCode(n);
    printV(v);

    return 0;
}
