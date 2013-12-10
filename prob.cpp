#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int prob() {
    return rand() % 2;
}

int probp(double p) {
    while(prob() != 1) 
        p = (2 * p > 1 ? 2 * p - 1 : 2 * p);
    return 2 * p > 1 ? 1 : 0;
}

double test(double p) {
    int N = 5000;
    int count = 0;
    for(int i = 0; i < N; i++)
        count += probp(p);
    return count * 1.0 / N;
}

int main() {
    srand(time(NULL));
    double p;
    cin >> p;
    cout << "Test result: " << test(p) << endl;
    return 0;
}
