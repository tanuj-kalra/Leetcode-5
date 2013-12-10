#include<iostream>
#include<vector>

using namespace std;

vector<int> plusOne(vector<int> &d) {
    int c = 1;
    for (int i = d.size()-1; i >= 0; --i) {
        d[i] += c;
        c = d[i] / 10;
        d[i] %= 10;
        if (0 == c)
            return d;
    }
    if(c)
        d.insert(d.begin(), 1);
    return d;
}

int main() {
    vector<int> v;
    v.push_back(9);
    v.push_back(9);
    v.push_back(8);
    v.push_back(9);
    v.push_back(9);

    v = plusOne(v);

    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
    cout << '\n';
    return 0;
}
