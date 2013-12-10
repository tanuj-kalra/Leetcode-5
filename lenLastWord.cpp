#include<iostream>

class Play {
public: 
    int length(const char * s) {
        int r = 0;
        while(*s) {
            if(*(s++) != ' ')
                ++r;
            else if(*s && *s != ' ')
                r = 0;
        }
        return r;
    }
};

int main() {
    Play pp;
    std::cout << pp.length("Hello World") << '\n';
    std::cout << pp.length("Day   ") << '\n';

    return 0;
}
