#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;

bool balance_bracket( string &s) {
    string token = "{[()]}";
    int num = token.size();
    map<char, char> match;
    int i, j;
    for(i=0, j = num - 1; i < j; ++i, --j)
        match[token[i]]=token[j];
 
    int len = s.size();
    stack<char> pool;
    int pos;
    char temp;
 
    for (i=0; i < len; ++i)
    {
        temp = s[i];
        pos = token.find(temp);
        if(pos == -1) continue;
        if(pool.empty() || pos < num/2) {
            pool.push(temp);
            continue;
        }
        if(match[pool.top()] == temp) {
            pool.pop();
            continue;
        }
        return false;
    }
    if (!pool.empty()) return false;
    return true;
}

int main() {
    string str;
    cout <<"Enter an expression: \n" ;
    getline (cin, str);
    if(balance_bracket(str))
        cout << "True\n";
    else
        cout << "False\n";
}

