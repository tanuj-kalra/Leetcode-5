#include<stdio.h>

unsigned helper(unsigned a, unsigned *b, unsigned *r) {
    if(a < *b) {
        *r = a;
        return 0;
    }
    int q = helper(a >> 1, b, r);
    *r = (*r << 1) + (a & 1);
    q = q << 1;
    if(*r >= *b) {
        *r -= *b;
        return q + 1;
    } else {
        return q;
    }
}

int divide(int dividend, int divisor) {
    int sign = 1;
    unsigned a, b;
    if(dividend < 0) {
        a = ~(dividend - 1);
        sign ^= 1;
    } else {
        a = dividend;
    }
    if(divisor < 0) {
        b = ~(divisor -1);
        sign ^= 1;

    } else {
        b = divisor;
    }
    unsigned r;
    r = helper(a, &b, &r);
    if(sign)
        return r;
    else
        return -(int)r;
}

int main() {
    int a ,b;
    scanf("%d%d", &a, &b);
    printf("%d / %d = %d\n", a, b, divide(a,b));

    return 0;
}
