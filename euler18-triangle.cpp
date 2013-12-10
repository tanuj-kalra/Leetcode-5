#include<iostream>
#include<vector>
using namespace std;

int minTriangle(vector<vector<int> > &t) {
    int n = t.size();
    vector<int> p(n+1, 0);
    while(n-- > 0)
        for(int i = 0; i <= n; i++)
            p[i] = t[n][i] + ((p[i] < p[i+1])? p[i] : p[i+1]);
    return p[0];
}

int maxTriangle(vector<vector<int> > &t) {
    int n = t.size();
    vector<int> p(n+1, 0);
    while(n-- > 0)
        for(int i = 0; i <= n; i++)
            p[i] = t[n][i] + ((p[i] > p[i+1])? p[i] : p[i+1]);
    return p[0];
}

int main() {
    int TRIANGLE;
    cin >> TRIANGLE;
    vector<vector<int> > t(TRIANGLE);
    int c;
    for(int i = 0; i < TRIANGLE; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> c;
            t[i].push_back(c);
        }
    }

    cout << maxTriangle(t) << endl;
    cout << minTriangle(t) << endl;
}

