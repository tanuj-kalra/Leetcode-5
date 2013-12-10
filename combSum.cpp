#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Play {
public:
    int combSum(vector<int> &c, int t) {
        sort(c.begin(), c.end());
        int count = 0;
        int sum = t;
        int i = c.size() - 1;
        vector<int> index;
        while(i >= -1) {
            while(i >= 0 && c[i] > sum)
                --i;
            if(i >= 0) {
                index.push_back(i);
                sum -= c[i];
                continue;
            } else {
                if(0 == sum) {
                    count++;
                    for(int u = index.size()-1; u >= 0; --u)
                        cout << c[index[u]] << " ";
                    cout << '\n';
                }
                if(index.empty())
                    break;
                i = index.back();
                index.pop_back();
                sum += c[i--];
            }
        }
        return count;
    }

    int combSumII(vector<int> &c, int t) {
        sort(c.begin(), c.end());
        int count = 0;
        int sum = t;
        int popp = -1; // we track value of the popped element
        int i = c.size() - 1;
        vector<int> index;
        while(i >= -1) {
            while(i >= 0 && c[i] > sum)
                --i;
            if(i >= 0) {
                if(c[i] != popp) { // make sure the same value won't be pushed again
                    index.push_back(i);
                    sum -= c[i];
                }
                --i;
                continue;
            } else {
                if(0 == sum) {
                    count++;
                    for(int u = index.size()-1; u >= 0; --u)
                        cout << c[index[u]] << " ";
                    cout << '\n';
                }
                if(index.empty())
                    break;
                i = index.back();
                index.pop_back();
                popp = c[i];
                sum += c[i--];
            }
        }
        return count;
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
    int a[] = {3,5,2};
    int n = sizeof(a) / sizeof(int);
    vector<int> h = pp.arrToVec(a, n);
    int t = 8;

    pp.printV(h);
    cout << "Target: " << t << '\n';
    cout << "Total: " << pp.combSum(h, t) << '\n';

    int b[] = {10,1,2,1,6,7,5};
    n = sizeof(b) /sizeof(int);
    h = pp.arrToVec(b, n);
    t = 8;

    pp.printV(h);
    cout << "Target: " << t << '\n';
    cout << "Total: " << pp.combSumII(h, t) << '\n';

    return 0;
}
