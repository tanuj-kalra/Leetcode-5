#include<iostream>
#include<stack>
using namespace std;

template<class T> class Queue {
private:
    stack<T> in;
    stack<T> out;

    void flush () {
        while(!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }

public:
    T front() {
        if(!out.empty())
            return out.top();
        else {
            flush ();
            return out.top();
        }
    }

    void pop() {
        if(!out.empty())
            out.pop();
        else {
            flush ();
            out.pop();
        }
    }

    void push(T a) {
        if(out.empty() && (in.size() > 100))
            flush();
        in.push(a);
    }

    bool empty() {
        return in.empty() && out.empty() ;
    }
};

int main() {
    Queue<int> pp;
    if(pp.empty())
        cout << "empty\n";
    pp.push(3);
    pp.push(5);
    pp.push(7);
    cout << pp.front() << '\n';
    pp.pop();
    pp.push(56);
    cout << pp.front() << '\n';
    pp.pop();
    cout << pp.front() << '\n';
    pp.pop();
    if(pp.empty())
        cout << "empty\n";

    return 0;
}

