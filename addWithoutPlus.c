#include<stdio.h>

int add(int a, int b) {
    if (0 == b) return a;
    return add(a^b, (a & b) << 1);
}

main() {
    int a, b;
    printf("Input: \n");
    scanf("%d%d",&a, &b);
    printf("%d\n", add(a,b));
}
