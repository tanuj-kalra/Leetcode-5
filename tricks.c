/* Collection of bitwise tricks 
 * 1. Count the number of 1s in a binary number
 * 2. Decide whether an integer is a power of 2.
 */

#include<stdio.h>

int getBitsOne(int c) {
    c = ((c & 0xaaaaaaaa) >> 1) + (c & 0x55555555);
    c = ((c & 0xcccccccc) >> 2) + (c & 0x33333333);
    c = ((c & 0xf0f0f0f0) >> 4) + (c & 0x0f0f0f0f);
    c = ((c & 0xff00ff00) >> 8) + (c & 0x00ff00ff);
    c = ((c & 0xffff0000) >> 16) + (c & 0x0000ffff);
    return c;
}

int isPowerOfTwo(int x) {
    return (x != 0) && !(x & (x-1));
}

int main() {
    int c = 5;
    printf("%d, %d\n", c, getBitsOne(c));

    int d = 16;
    printf("%d, %d\n", d, isPowerOfTwo(d));

    return 0;
}
