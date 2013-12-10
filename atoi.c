#include<stdio.h>
#include<limits.h>

int atoi(char s[])
{
    int i, n;

    n = 0;
    for ( i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + ( s[i] - '0' );
    return n;
}

int atoiII(char *str) {
    int i = 0;
    int sign = 0;
    long long r = 0;
    while(str[i] == ' ')
        ++i;
    char c = str[i];
    if(c == '-') {
        sign = 1;
        ++i;
    } else if(c == '+') {
        ++i;
    }
    while( c = str[i++]) {
        if(c < '0' || c > '9')
            break;
        r = 10 * r + c - '0';
    }
    if(sign)
        r = -r;
    if(r > INT_MAX)
        return INT_MAX;
    else if(r < INT_MIN)
        return INT_MIN;
    else
        return (int)r;
}

main()
{
    char *c = "23456789aabb0";

    printf("%s converted to %d\n", c, atoi(c));
    
    char *st;
    scanf("%s", st);
    printf("%d\n", atoiII(st));
    
}
