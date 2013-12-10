#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Play {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > v;
        sort(num.begin(), num.end());
        for(int i = num.size() - 1; i >= 2; --i) {
            if(i < num.size() - 1 && num[i] == num[i+1])
                continue;
            int sum = -num[i];
            int k = 0, l = i-1;
            while(k < l) {
                if(num[k] + num[l] == sum) {
                    vector<int> t(3);
                    t[0] = num[k], t[1] = num[l], t[2] = num[i];
                    v.push_back(t);
                    ++k, --l;
                    while(k < i && num[k] == num[k-1])
                        ++k;
                    while(l >= 0 && num[l] == num[l+1])
                        --l;
                } else if(num[k] + num[l] < sum) {
                    ++k;
                } else {
                    --l;
                }
            }
        }
        return v;
    }

    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int m = num[0] + num[1] + num[2];
        for(int i = 0; i < num.size() - 1; ++i) {
            int j = i + 1, k = num.size() - 1;
            while(j < k) {
                int t = num[i] + num[j] + num[k];
                if(abs(t-target) < abs(m-target))
                    m = t;
                if(t < target)
                    ++j;
                else 
                    --k;
            }
        }
        return m;
    }
};

void printV(vector<int> &v) {
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

void printVV(vector<vector<int> > &v){
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

int main() {
    Play pp;
    vector<int> num {-1,0,1,2,-1,-4};
    printV(num);

    vector<vector<int> > v = pp.threeSum(num);
    printVV(v);

    vector<int> uu {-3, -2, -5, 3, -4};
    int t = -1;
    int m = pp.threeSumClosest(uu, t);
    printV(uu);
    cout << "Target: " << t << " sum: " << m << endl;

    return 0;
}
