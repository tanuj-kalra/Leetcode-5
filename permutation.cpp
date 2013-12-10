#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>
using namespace std;

class Play{
public:
    vector<vector<int> > permute(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> > r;
        r.push_back(num);
        while(nextPermute(num))
            r.push_back(num);
        return r;
    }

    bool nextPermute(vector<int> &num) {
        int i,j,n;
        i = j = num.size() - 1;
        while(i > 0 && num[i] <= num[i-1]) 
            --i;
        n = i - 1;
        if(n < 0) return false;
        else{
            while(i < j)
                swap(num[i++], num[j--]);
            i = n + 1;
            while(num[i] <= num[n])
                ++i;
            swap(num[i], num[n]);
            return true;
        }
    }

    vector<vector<int> > permuteR(vector<int> &num) { // recursive
        vector<vector<int> > r;
        helper(r, num, 0);
        return r;
    }

    int helper(vector<vector<int> > &r, vector<int> &num, int l) {
        int i, mi = l;
        for(i = l; i < num.size(); ++i)
            mi = num[mi] < num[i] ? mi : i;
        swap(num[mi], num[l]);
        if(l == num.size() - 1)
            r.push_back(num);
        else 
            while((i = helper(r, num, l + 1)) != -1)
                swap(num[i], num[l]);
        if(l != 0) {
            int m = INT_MAX;
            mi = -1;
            for(i = l; i < num.size(); ++i)
                if(num[i] > num[l-1] && num[i] < m) {
                    m = num[i];
                    mi = i;
                }
            return mi;
        }
        return 0;
    }
};

void printVV(vector<vector<int> > &v) {
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < v[i].size(); ++j)
            cout << v[i][j] << " ";
        cout << '\n';
    }
}

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
//    v.push_back(5);
    printV(v);

    Play pp;
    vector<vector<int> > r;
    r = pp.permute(v);
    printVV(r);

    cout << "Next ALGORITHM\n";
    printV(v);
    r = pp.permuteR(v);
    printVV(r);
    return 0;
}
