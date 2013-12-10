#include<iostream>
#include<vector>
using namespace std;

class Play {
public:
    void nextPermutation(vector<int> &v) {
        int i,j,n;
        i = j = v.size() - 1;
        while(i > 0 && v[i] <= v[i-1])
            --i;
        n = i - 1;
        while(i < j)
            swap(v[i++], v[j--]);
        if(n >= 0) {
            i = n + 1;
            while(v[i] <= v[n])
                ++i;
            swap(v[n], v[i]);
        }
    }
};

void printV(vector<int> &v) {
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << '\n';
}

int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    printV(v);

    Play pp;
    for(int i = 0; i < 20; ++i) {
        pp.nextPermutation(v);
        printV(v);
    }

    return 0;
}

