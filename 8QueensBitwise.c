#include<stdio.h>

int mask;
int n;
long ans;

void check(int col, int ld, int rd) {
    if(col == mask) {
        ++ans;
        return;
    }
    int pos = mask & ~(col | ld | rd);
    while(pos) {
        int p = pos - (pos & pos - 1); // pos & (-pos) works
        check(col | p, (ld | p) << 1, (rd | p) >> 1);
        pos -= p;
    }
}

int main(){
    scanf("%d", &n);
    while(n) {
        mask = (1 << n) - 1;
        ans = 0;
        check(0,0,0);
        printf("n = %d: %ld\n", n , ans);
        scanf("%d", &n);
    }
    return 0;
}

