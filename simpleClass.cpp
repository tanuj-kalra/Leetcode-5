#include<iostream>
using namespace std;

class MemoryCell
{
    private:
        int StoredValue;
    public:
        int read() {return StoredValue;}
        int write(int x) {StoredValue = x;}
};

int main()
{
    MemoryCell M;
    M.write(5);
    cout << "Value of content" << M.read() << '\n';
    return 0;
}
