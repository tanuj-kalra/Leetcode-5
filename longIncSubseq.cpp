#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

class Solution {
    private:
        vector<int> s;
        vector<int> pre;

        int push(int k) {
            if(s.empty()){
                s.push_back(k);
                return -1;
            }
            if(k >= s.back()){
                s.push_back(k);
                return s[s.size()-2];
            }
            int l = 0, r = s.size()-1, mid;
            while(l < r)
                (s[mid = (l+r)/2] > k) ? r = mid : l = mid+1;
            s[r] = k;
            return (r-1 >= 0) ? s[r-1] : -1;
        }

    public:
        int max_inc_seq (int a[], int n) {
            int i;
            for(i = 0; i < n; ++i)
                pre.push_back(push(a[i]));
            cout << "longest increasing: " << s.size() << '\n';
            int pt = s.back();
            i = n - 1;
            while(pt != -1) {
                cout << pt << " ";
                for(; a[i] != pt ; i-- );
                pt = pre[i--];
            }
            cout << '\n';
            s.clear();
            pre.clear();
            return 0;
        }
};

int main() {
    Solution pp;
    int a[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int i;
    for(i=0; i < 16; i++)
        cout << a[i] << " ";
    cout <<'\n';
    pp.max_inc_seq(a, 16);

    srand(time(0));
    int b[15];
    int j;
    for(i = 0; i < 15; i++) {
        for(j = 0; j < 15; j++) {
            b[j] = rand()%16;
            cout << b[j] << " ";
        }
        cout << '\n';
        pp.max_inc_seq(b, 15);
    }
    return 0;
}
