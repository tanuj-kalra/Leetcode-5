/* compile with: g++ -gnu++11 100bulbsim.cpp */

#include<iostream>
#include<random>

#define BULB 100 
#define LAMBDA 1.0
#define TESTS 10000

using namespace std;

int main() {
    random_device gen;
    exponential_distribution<double> dist(LAMBDA);
    int k;
    cin >> k;
    double bulbs[k];
    int pass = 0;
    for(int t = 0; t < TESTS; t++) {
        for(int i = 0; i < k; i++) {
            bulbs[i] = dist(gen);
        }
        int i = 0, j = k - 1;
        while(i < j) {
            if(bulbs[i] < 1) {
                bulbs[i] += bulbs[j];
                j--;
            }
            else
                i++;
        }
        if(i >= BULB)
            pass++;
    }
    cout << "Probability = " << (1.0 * pass)/TESTS << endl;
    return 0;
}

