#include<stdio.h>

int max(int x, int y)
{
    return (x>y) ? x : y;
}

int max_subarray(int *a, int len)
{
    int max_sofar = 0;
    int max_endhere = 0;
    int start = 0;
    int end = 0;
    int i = 0;
    int temp;
    for(; i < len; ++i)
    {
        temp = max_endhere+a[i];
        if( temp > 0 )
            max_endhere = temp;
        else {
            max_endhere = 0;
            start = i+1;
        }
        if( max_endhere > max_sofar) {
            max_sofar = max_endhere;
            end = i;
        }
    }
    printf("\nFrom %d to %d, SUM = %d\n", start, end, max_sofar);
    return max_sofar;
}

main()
{
    int a[] = {-3, 5, 10, -5, 8, 9, -4, 6, -7, 2};
    int l = 10;

    int i;
    for(i=0; i< l; ++i)
        printf("%4d", a[i]);
    max_subarray(a,l);
}

