#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
    int a;
    int b;
    bool cf;
    Interval() : a(0), b(0), cf(false) {}
    Interval(int start, int end) : a(start), b(end), cf(false) {}
};

bool compare(const Interval &s, const Interval &t) {
    return s.a < t.a;
}

class Play {
public:
    void setflag(vector<Interval> &list) {
        /* same idea as merge intervals, when intervals merge, they conflict */
        sort(list.begin(), list.end(), compare);
        int i = 0, n = list.size();
        while(i < n) {
            int m = list[i].b;
            int j = i + 1;
            while(j < n && list[j].a <= m) {
                m = max(m, list[j].b);
                list[j].cf = true;
                ++j;
            }
            if(j != i + 1)
                list[i].cf = true;
            i = j;
        }
    }

    void printEvents(vector<Interval> &list) {
        int n = list.size();
        for(int i = 0; i < n; ++i) {
            cout << list[i].a << " " << list[i].b 
                << (list[i].cf ? " Yes" : " ") << endl;
        }
    }
};

int main() {
    Play pp;
    vector<Interval> l;
    int s, t;
    while(cin >> s) {
        cin >> t;
        Interval ev(s,t);
        l.push_back(ev);
    }

    pp.setflag(l);
    pp.printEvents(l);
    
    return 0;
}


