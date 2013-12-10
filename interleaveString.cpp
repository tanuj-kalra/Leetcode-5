#include<iostream>
#include<string>
using std::string;

class Play {
public:
    string s1, s2, s3;

    bool isInterleave(string st1, string st2, string st3) {
        s1 = st1, s2 = st2, s3= st3;
        int i1 = s1.size();
        int i2 = s2.size();
        int i3 = s3.size();
        if(i3 != i1 + i2)
            return false;
        return helper(i1,i2,i3);
    }

    bool helper(int i1, int i2, int i3) {
        if(i3 == 0)
            return true;
        --i3;
        if(i1 && s1[i1-1] == s3[i3] && helper(i1-1, i2, i3))
            return true;
        if(i2 && s2[i2-1] == s3[i3] && helper(i1, i2-1, i3))
            return true;
        return false;
    }
};

int main() {
    string s1, s2, s3;
    Play pp;
    do {
        std::cin >> s1 >> s2 >> s3;
        if(pp.isInterleave(s1,s2,s3))
            std::cout << "Is interleave !\n";
    } while(s1 != "kkk");

    return 0;
}

