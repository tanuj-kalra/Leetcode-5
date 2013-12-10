#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Interval {
    int a;
    int b;
    Interval() : a(0), b(0) {}
    Interval(int s, int t) : a(s), b(t) {}
};

bool isLower(const Interval &v1, const Interval &v2) {
    return v1.a < v2.a;
}

class Play {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> cc;
        sort(intervals.begin(), intervals.end(), isLower);
        int n = intervals.size();
        int i = 0;
        while(i < n) {
            cc.push_back(intervals[i++]);
            while(i < n && intervals[i].a <= cc.back().b)
                cc.back().b = max(cc.back().b, intervals[i++].b);
        }
        return cc;
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInt) {
        /* Assume the original list is already sorted
         * with no overlap. Property maintained after
         * insert. 
         * How about a different structure than vector. 
         * Do an in place insert. ("map" is an option)
         * */
        vector<Interval> v;
        int i = 0;
        int n = intervals.size();
        while(i < n && newInt.a > intervals[i].b)
            v.push_back(intervals[i++]);
        while(i < n && newInt.b >= intervals[i].a) {
            newInt.b = max(newInt.b, intervals[i].b);
            newInt.a = min(newInt.a, intervals[i].a);
            ++i;
        }
        v.push_back(newInt);
        while(i < n)
            v.push_back(intervals[i++]);
        return v;
    }
};

// Compile with option: g++ -std=gnu++11
int main() {
    vector<Interval> in;
    Interval v;
    v.a = 2, v.b = 3;
    in.push_back(v);
    v.a = 4, v.b = 6;
    in.push_back(v);
    v.a = 5, v.b = 8;
    in.push_back(v);
    v.a = 9, v.b = 10;
    in.push_back(v);

    vector<Interval> out;
    Play pp;
    out = pp.merge(in);

    for(Interval &c : out) {
        cout << c.a << " " << c.b << '\n';
    }

    v.a = 4, v.b = 9;
    in = pp.insert(out, v);
    for(Interval &c : in) {
        cout << c.a << " " << c.b << '\n';
    }

    return 0;
}
