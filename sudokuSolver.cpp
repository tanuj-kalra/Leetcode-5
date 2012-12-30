#include<iostream>
using namespace std;

class Play {
public:
    bool solver(char board[9][9]) {
        /* 1. There's a simpler recursive approach.
         * 2. nextpos & prevpos could be implemented as a
         *    doubly linked list to accerlate search.
         * 3. Test data are available at sudoku.data
         */
        char run[9][9];
        initrun(run, board);
        if(!verify(run))
            return false;
        int i = 0, j = -1;
        nextpos(i,j,board);
        while(1) {
            if(nextnum(i, j, run)) {
                if(!nextpos(i, j, board)) {
                    cout << " Solved ! \n\n";
                    print(run);
                    return true;
                }
                run[i][j] = 0;
            } else {
                run[i][j] = 0;
                if(!prevpos(i, j, board))
                    return false;
            }
        }
    }

    void initrun(char run[9][9], char board[9][9]) {
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j) {
                if(board[i][j] == '.')
                    run[i][j] = 0;
                else
                    run[i][j] = board[i][j] - '0';
            }
    }

    bool verify(char run[9][9]) {
        int num[9];
        for(int i = 0; i < 9; ++i) {
            setZero(num);
            for(int j = 0; j < 9; ++j)
                if(!check(run[i][j], num))
                    return false;
        }
        for(int j = 0; j < 9; ++j) {
            setZero(num);
            for(int i = 0; i < 9; ++i)
                if(!check(run[i][j], num))
                    return false;
        }
        for(int i = 0; i < 9; i += 3)
            for(int j = 0; j < 9; j += 3) {
                setZero(num);
                for(int l = 0; l < 3; ++l)
                    for(int k = 0; k < 3; ++k)
                        if(!check(run[i+l][j+k], num))
                            return false;
            }
        return true;
    }

    bool check(char c, int A[9]) {
        if(c == 0)
            return true;
        if(A[c-1] == 1)
            return false;
        else
            A[c-1] = 1;
        return true;
    }

    void setZero(int A[9]) {
        for(int i = 0; i < 9; ++i)
            A[i] = 0;
    }

    bool nextpos(int &i, int &j, char board[9][9]) {
        ++j;
        while(i < 9) {
            while(j < 9) {
                if(board[i][j] == '.')
                    return true;
                ++j;
            }
            ++i;
            j = 0;
        }
        return false;
    }

    bool prevpos(int &i, int &j, char board[9][9]) {
        --j;
        while(i >= 0) {
            while(j >= 0) {
                if(board[i][j] == '.')
                    return true;
                --j;
            }
            --i;
            j = 8;
        }
        return false;
    }

    bool nextnum(int &i, int &j, char run[9][9]) {
        int A[9];
        int k;
        for(k = 0; k < 9; ++k)
            A[k] = k + 1;
        int t;
        for(k = 0; k < 9; ++k) {
            if(t = run[i][k])
                A[t - 1] = 0;
            if(t = run[k][j])
                A[t - 1] = 0;
        }
        int p = (i/3) * 3, q = (j/3) * 3;
        for(k = 0; k < 3; ++k) {
            for(int l = 0; l < 3; ++l)
                if(t = run[p+k][q+l])
                    A[t - 1] = 0;
        }
        k = run[i][j];
        while(k < 9 && A[k] == 0)
            ++k;
        if(k < 9) {
            run[i][j] = k + 1;
            return true;
        } else
            return false;
    }

    void print(char run[9][9]) {
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) 
                if(run[i][j])
                    cout << (int)run[i][j] << " ";
            cout << '\n';
        }
    }

    void readboard(char board[9][9]) {
        char c;
        for(int i = 0; i < 9; ++i) 
            for(int j = 0; j < 9; ++j){
                cin >> c;
                board[i][j] = c;
            }
    }
};
      
int main() {
    Play pp;
    char board[9][9];
//    pp.readboard(board);
//    for(int j = 0; j < 10000; ++j)
//        pp.solver(board);
    int i;
    while(cin >> i) {
        pp.readboard(board);
        cout << '\n' << i << " : ";
        if(!pp.solver(board))
            cout << "Unsolvable" << endl;
    }
    return 0;
}

