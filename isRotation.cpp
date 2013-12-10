#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isRotation(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        s1 += s1;
        if(s1.find(s2) == string::npos) return false;
        return true;
    }
};

int main() {
    string s1 = "ppmmaa";
    string s2 = "mmppaa";

    Solution pp;
    if (pp.isRotation(s1, s2))
        cout << "Is rotation\n";
    return 0;
}
