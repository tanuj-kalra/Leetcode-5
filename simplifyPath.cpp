#include<iostream>
#include<list>
#include<string>
using namespace std;

class Play {
public:
    string simplifyPath(string path) {
        list<string> l;
        int i = -1;
        while(++i < path.size()) {
            if(path[i] == '/')
                continue;
            string t;
            t.clear();
            while(i < path.size() && path[i] != '/')
                t += path[i++];
            if(t == "..") {
                if(!l.empty())
                    l.pop_back();
            } else if(t != ".")
                l.push_back(t);
        }
        list<string>::iterator it;
        string st;
        for(it = l.begin(); it != l.end(); it++)
            st = st + '/' + *it;
        if(st.empty())
            st += '/';
        return st;
    }
};

int main() {
    Play pp;
    string s;
    while(cin >> s)
        cout << pp.simplifyPath(s) << endl;

    return 0;
}
