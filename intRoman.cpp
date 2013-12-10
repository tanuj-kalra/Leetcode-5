#include<iostream>
#include<map>
using namespace std;

class Solution{
public:
    string intToRoman (int num) {
        map<int,char> t;
        t[1000] = 'M';
        t[500] = 'D';
        t[100] = 'C';
        t[50] = 'L';
        t[10] = 'X';
        t[5] = 'V';
        t[1] = 'I';
        string rom = "";
        int k = 1000;
        while (k > 0) {
            int q = num / k;
            if(q < 4)
                for(; q > 0; q--)
                    rom += t[k];
            else if (q == 4) {
                rom += t[k];
                rom += t[k*5];
            }
            else if (q == 5) 
                rom += t[k*5];
            else if (q < 9) {
                rom += t[k*5];
                for(; q > 5; q--)
                    rom += t[k];
            }
            else {
                rom += t[k];
                rom += t[k*10];
            }
            num %= k;
            k /= 10;
        }
        return rom;
    }
};

int main() {
    int i;
    cout << "Input an integer : ";
    cin >> i;

    Solution pp;
    string s = pp.intToRoman(i);
    cout << s << '\n';
    return 0;
}

