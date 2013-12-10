#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Play {
public:
    void fourSum(vector<int> &num, int target) {
        typedef multimap<int, pair<int,int> >::iterator It;
        typedef pair<int, int> Index;
        sort(num.begin(), num.end());
        multimap <int, Index> mult;
        for(int l = 1; l < num.size(); ++l) {
            for(int k = 0; k < l; ++k) {
                int sum = num[k] + num[l];
                pair<It, It> ran = mult.equal_range(target - sum);
                for(It it = ran.first; it != ran.second; it++) {
                    int i = it->second.first, j = it->second.second;
                    if(j >= k || i != 0 && num[i] == num[i-1] ||
                               j != i+1 && num[j] == num[j-1] ||
                               k != j+1 && num[k] == num[k-1] ||
                               l != k+1 && num[l] == num[l-1])
                        continue;
                    cout << num[i] << " " << num[j] << " "
                        << num[k] << " " << num[l] << endl; // output
                }
                Index p(k,l);
                mult.insert(pair<int, Index>(sum, p));
            }
        }
    }
};

void printV(vector<int> &v) {
    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    vector<int> v {-3,-2,-1,0,0,1,2,3};
    int t = 0;
    Play pp;
    
    printV(v);
    pp.fourSum(v,t);

    return 0;
}
