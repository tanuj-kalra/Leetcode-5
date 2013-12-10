#include<iostream>
#include<set>
#include<map>
#include<queue>
using namespace std;

/* following solution by peking2
 * compile with: g++ -std=gnu++11
 */ 
class Play {
private:
    set<string> dict = {"fox", "fog", "dog"};

public:
    int editDistance(string word1, string word2) {
        queue<string> q;
        q.push(word1);
        map<string, int> hash;

        while(!q.empty()) {
            string t = q.front();
            q.pop();
            int step = hash[t];
            for(int i = 0; i < t.size(); ++i) {
                char c = t[i];
                for(int j = 'a'; j <= 'z'; ++j) {
                    t[i] = j;
                    if(t == word2)
                        return step + 1;
                    else if(dict.find(t) != dict.end() && hash[t] == 0) {
                        hash[t] = step + 1;
                        q.push(t);
                    }
                }
                t[i] = c;
            }
        }
        
        return -1;
    }
};

int main() {
    Play pp;
    string s1("fox");
    string s2("dog");
    cout << pp.editDistance(s1,s2) << endl;

    return 0;
}

