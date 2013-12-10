#include<stdio.h>

int getBitsOne(int c)
{
    c = ((c & 0xaaaaaaaa)>>1) + (c & 0x55555555);
    c = ((c & 0xcccccccc)>>2) + (c & 0x33333333);
    c = ((c & 0xf0f0f0f0)>>4) + (c & 0x0f0f0f0f);
    c = ((c & 0xff00ff00)>>8) + (c & 0x00ff00ff);
    c = ((c & 0xffff0000)>>16) + (c & 0x0000ffff);
    return c;
}

main()
{
    int i;
    for(i=1; i<30; ++i)
        printf("%d has %d bits of one\n", i, getBitsOne(i));
}
