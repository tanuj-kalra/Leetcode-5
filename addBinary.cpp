#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string add_binary (string &a, string &b) {
        int len1 = a.size();
        int len2 = b.size();
        string s;
        s.resize((len1 > len2) ? len1 : len2);
        char carry = '0';
        char va, vb;
        for(--len1, --len2; len1 >= 0 || len2 >=0; --len1, --len2) {
            va = (len1 >= 0) ? a[len1] : '0';
            vb = (len2 >= 0) ? b[len2] : '0';
            s[(len1 > len2) ? len1 : len2] = va ^ vb ^ carry;
            carry = va & vb | va & carry | vb & carry;
        }
        if('1' == carry)
            s.insert(s.begin(), '1');
        return s;
    }
};

int main() {
    Solution pp;
    string a = "1010";
    string b = "110";
    cout << "Sum of " << a << " and " << b
         << " is " << pp.add_binary(a,b) << '\n';
}

