#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

template<class T> class Stack {
private:
    T* A;
    int p;

public:
    Stack() {
        A = new T[1000];
        p = -1;
    }

    ~Stack() {
        delete [] A;
    }

    T top() {
        if(p > -1)
            return A[p];
        else 
            return A[0];
    }

    void pop() {
        if(p > -1)
            p--;
    }

    void push(T a) {
        if(p < 999)
            A[++p] = a;
    }

    bool empty() {
        if( p == -1)
            return true;
        else 
            return false;
    }

    int size() {
        return p+1;
    }

    void print() {
        for(int i = 0; i <= p; i++)
            cout << A[i] << " ";
        cout << '\n';
    }
};

template<class T> class Solution {
public:
    void insertSort(Stack<T> & s){
        Stack<T> B;
        int n = s.size();

        while(n-- > 0) {
            T temp = s.top();
            s.pop();
            int j = 0;
            while(!B.empty()) {
                if(temp < B.top())
                    break;
                s.push(B.top());
                B.pop();
                j++;
            }
            B.push(temp);
            while(j-- > 0) {
                B.push(s.top());
                s.pop();
            }
        }
        while(!B.empty()) {
            s.push(B.top());
            B.pop();
        }
    }
};

int main() {
    Stack<int> ss;
    Solution<int> pp;

    srand(time(0));
    for(int i = 0; i < 50; i++) 
        ss.push(rand() % 100);
    ss.print();

    pp.insertSort(ss);
    ss.print();

    return 0;
}




