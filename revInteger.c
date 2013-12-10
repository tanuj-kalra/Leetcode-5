#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int rev( int x){
    int f = 1;
    if (x < 0){
        f = -1;
        x = 0 - x;
    }
    int r = 0;
    while (x > 0) {
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return r * f;
}

int main() {
    srand(time(0));
    int i;
    for(i=0; i < 100; i++){
        int x = (rand() % 1000000) - 500000;
        printf("%20d -> %20d\n", x, rev(x));
    }
    return 0;
}

