#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>

int sqrtN(int x) {
    /* Newton method: x = 2 * y_0 (y - y_0) + y_0^2 */
    double y = (x >> 10) + 1024;
    int i;
    for(i = 0; i < 15; ++i)
        y = x / y / 2 + y / 2;
    return (int)y;
}

int sqrtII(int x) {
    /* Binary search, a little bit faster than newton */
    long long low = 0, high = x;
    while(low <= high) {
        long long mid = (low + high) / 2;
        long long p = mid * mid;
        if(p <= x && x < p + 2 * mid + 1)
            return mid;
        else if(p > x) 
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    srand(time(0));

    int i;
    for(i = 0; i < 10000; ++i) {
        int d = i;
        if(sqrtN(d) != sqrtII(d))
            printf("Different ! %d: %d: %d\n",d,sqrtN(d), sqrtII(d));
    }

    return 0;
}

