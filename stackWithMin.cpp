#include<iostream>
using namespace std;

class StackWithMin {
private:
    int data[1024];
    int min[1024];
    int si;
    int mi;

public:
    StackWithMin() { si = -1; mi = 0;}
    
    void push(int val) {
        if(si == -1){
            mi = 0;
            min[mi] = val;
        }  
        else if( val <= min[mi] )
            min[++mi] = val;
        data[++si] = val;
    }
    
    int getMin () { 
        if(mi<0) return -1;
        return min[mi]; 
    }

    int pop (){
        if (si < 0) return -1;
        if(data[si] == min[mi]) 
                --mi;
        return data[si--];
    }
};

template<class T> class StackWithM { // stack with Min without auxilury stack
private:
    T data[1024];
    T m;
    int si;

public:
    StackWithM() { si = -1; m = 0;}

    void push(int val) {
        if(si == -1) {
            m = val;
            data[++si] = val;
        }
        else if( val < m ) {
            data[++si] = val * 2 - m;
            m = val;
        }
        else
            data[++si] = val;
    }

    T getMin() {
        return m;
    }

    T pop() {
        if(si < 0) return -1;
        if(data[si] < m) {
            T t = m;
            m = m * 2 - data[si--];
            return t;
        } else
            return data[si--];
    }

    int size() {
        return si + 1;
    }
};
        

int main() {
    StackWithMin test;
    test.push(8);
    test.push(9);
    test.push(6);
    test.push(3);
    test.push(4);
    test.push(2);
    test.push(3);
    int i;
    for(i=8;i>0; --i) {
        cout << "min = " << test.getMin();
        cout << "  pop = " << test.pop() << '\n';
    }
    cout << '\n';

    StackWithM<int> t;
    t.push(8);
    t.push(9);
    t.push(6);
    t.push(3);
    t.push(2);
    t.push(4);
    t.push(3);
    t.push(2);
    t.push(3);
    t.push(2);
    t.push(3);
    for(i = t.size(); i > 0; --i) {
        cout << "min = " << t.getMin();
        cout << "  pop = " << t.pop() << '\n';
    }

    return 0;
}
    
