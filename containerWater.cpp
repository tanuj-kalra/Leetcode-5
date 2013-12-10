#include<iostream>
#include<vector>
using namespace std;

class Play {
public:
    int maxArea(vector<int> h) {
        int i = 0, j = h.size() - 1, lm = h[0], rm = h[j];
        int m = j * min(lm, rm);
        while(i < j) {
            if(lm < rm) {
                if(h[++i] > lm) {
                    lm = h[i];
                    m = max(m, (j - i) * min(lm, rm));
                }
            } else {
                if(h[--j] > rm) {
                    rm = h[j];
                    m = max(m, (j - i) * min(lm, rm));
                }
            }
        }
        return m;
    }
};

int main() {
    vector<int> v;
    v.push_back(5);
    v.push_back(2);
    v.push_back(12);
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);
    v.push_back(4);
    v.push_back(11);
    v.push_back(9);
    v.push_back(4);

    Play pp;
    int m = pp.maxArea(v);
    cout << "MAX AREA = " << m << '\n';

    return 0;
}
