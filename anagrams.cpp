#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Play {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> cc;
        map<string, vector<string> > dict;
        vector<string>::iterator st;
        for(st = strs.begin(); st != strs.end(); st++) {
            string key = *st;
            sort(key.begin(), key.end());
            dict[key].push_back(*st);
        }
        map<string, vector<string> >::iterator it;
        for(it = dict.begin(); it != dict.end(); it++) {
            if(it->second.size() > 1)
                for(st = it->second.begin(); st != it->second.end(); st++)
                    cc.push_back(*st);
        }
        return cc;
    }
};

template <typename T>
void printV(vector<T> v) {
    int n = v.size();
    for(int i = 0; i < n; ++i)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    Play pp;
    vector<string> words;
    vector<string> ana;

    string st;
    while(cin >> st) {
        words.push_back(st);
    }
    ana = pp.anagrams(words);
    printV(ana);

    return 0;
}
