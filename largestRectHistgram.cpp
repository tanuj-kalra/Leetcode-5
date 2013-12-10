#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Play {
public:
    int largestRectArea(vector<int> &h) {
        stack<int> p;
        int i = 0, m = 0;
        h.push_back(0);
        while(i < h.size()) {
            if(p.empty() || h[p.top()] <= h[i])
                p.push(i++);
            else {
                int t = p.top();
                p.pop();
                m = max(m, h[t] * (p.empty() ? i : i - p.top() - 1 ));
            }
        }
        return m;
    }

    void printV(vector<int> &h) {
        for(int i = 0; i < h.size(); ++i)
            cout << h[i] << " ";
        cout << '\n';
    }

    vector<int> arrToVec(int *a, int n) {
        vector<int> h;
        for(int i = 0; i < n; ++i)
            h.push_back(a[i]);
        return h;
    }
};

int main() {
    Play pp;
    int a[] = {2,1,4,5,1,3,3};
    int n = sizeof(a) / sizeof(int);
    vector<int> h = pp.arrToVec(a, n);

    pp.printV(h);
    cout << pp.largestRectArea(h) << '\n';

    return 0;
}
