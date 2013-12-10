#include<stdio.h>

void revij(char*, int, int);

void revword(char *s) {
    int i, j;
    for(j=0; s[j] != '\0'; j++);
    int end = j - 1;
    revij(s, 0, end);
    j = -1; 
    while(1) {
        i = ++j;
        for (; s[j] != ' '; j++)
           if (j == end) {
              revij(s, i, j);
              return;
           }
        revij(s, i, j-1);
    }
} 
            

void revij(char *s, int i, int j) {
    while(i<j) {
        s[i] ^= s[j];
        s[j] ^= s[i];
        s[i] ^= s[j];
        i++, j--;
    }
}

main() {
    char a[] = "This is a Sentance to   pp qq qqq        be Reversed!";
    revword(a);
    printf("%s\n", a);
}
