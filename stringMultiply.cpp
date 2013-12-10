#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Play {
public:
    string stringMultiply(string s1, string s2) {
        if(s1[0] == '0' || s2[0] == '0') return "0";
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int m = s1.size() - 1, n = s2.size() - 1;
        int k = s1.size() + s2.size();
        string product(k, 0);
        for(int cc = 0; cc < k; cc++) {
            for(int i = max(0, cc - n), j = cc - i; i <= m && j >= 0 ; i++, j--) {
                int carry = (s1[i] - '0') * (s2[j] - '0');
                for(int adder = cc; carry != 0; adder++) {
                    int temp = carry + product[adder];
                    product[adder] = temp % 10;
                    carry = temp / 10;
                }
            }
            product[cc] += '0';
        }
        if(product[k-1] == '0') 
            product.erase(product.end() - 1);
        reverse(product.begin(), product.end());
        return product;
    }

    string stringMultiplyII(string &s1, string &s2) { // From web
        int m = s1.size(), n = s2.size();
        vector<int> product(m+n, 0);

        for(int i = 0; i < m; i++) {
            int d1 = s1[m - i - 1] - '0';
            int carry = 0;
            for(int j = 0; j < n; j++) {
                int d2 = s2[n - j - 1] - '0';
                carry = carry + product[i+j] + d1 * d2;
                product[i+j] = carry % 10;
                carry = carry / 10;
            }
            product[i + n] = carry;
        }
        int i = m + n - 1;
        while(product[i] == 0) i--;
        string result = "";
        while(i >= 0)
            result += char(product[i--] + '0');
        return result;
    }
};

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    
    Play pp;
    cout << pp.stringMultiply(s1,s2) << endl;
    cout << pp.stringMultiplyII(s1,s2) << endl;

    return 0;
}
