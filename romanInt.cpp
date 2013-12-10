#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int romanInt (string s){
        map<char, int> tab;
        tab['\0']=0;
        tab['I']=1;
        tab['V']=5;
        tab['X']=10;
        tab['L']=50;
        tab['C']=100;
        tab['D']=500;
        tab['M']=1000;

        int v = 0;
        int i = 0;
        for(;i < s.size(); ++i)
            v += (tab[s[i]] >= tab[s[i+1]]) ? tab[s[i]] : 0 - tab[s[i]];
        return v;
    }
};

int main() {
    string a = "CDXLVI";
    Solution pp;
    cout << a << "=" << pp.romanInt(a) << '\n';
    return 0;
}
