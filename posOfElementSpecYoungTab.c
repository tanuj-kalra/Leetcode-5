#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 1000000 
#define RANDSTEP 50


void quicksort(int v[], int left, int right)
{
    int i, last;
    void swap(int [], int i, int j);

    if (left >=right)
        return;
    swap(v, left, (left+right)/2);
    last=left;
    for (i=left+1; i<= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);
    quicksort(v, left, last-1);
    quicksort(v, last+1, right);
}

void swap(int v[], int i, int j)
{
    int temp;

    temp=v[i], v[i]=v[j], v[j]=temp;
}


long searchx(long v[], long t, long m, long n)
{
    long i, j, pos ,c;

    c = v[m]+v[n];

    pos = n;
    for(i=m-1,j=n+1; i>=0; --i)
    {
        for(; j < t; ++j)
            if(v[i]+v[j] >= c)
                break;
        pos += j;
    }
    for(i=m+1,j=n-1; i<t; ++i)
    {
        for(; j >=0 ; --j)
            if(v[i]+v[j] < c)
                break;
        pos += (j+1);
    }
    return pos;
}
        
int binsearch(int v[], int left, int right, int value)
{
    if(left >= right)
    {
        if(v[left] == value)
        {   
            int i;
            for(i= left;i > 0 && v[i] == value; --i) 
                ;
            return i;
        }
        else
            return -1;
    }
    
    int p = (left+right)/2;

    if ( v[p] < value )
         return binsearch(v, p+1, right, value);
    else
         return binsearch(v, left, p, value);

}

main()
{
    long x[ SIZE ];
  //  int xpx[ SIZE ] [SIZE ];
  //  int xplusx[SIZE*SIZE];
    long i, j, k;


    //Initialize x[]
    srand(time(NULL));
    x[0]=5;
    for(i=1 ; i<SIZE ; ++i)
        x[i]=x[i-1]+(long)(RANDSTEP * (rand()/(RAND_MAX + 1.0)));
//    for(k=0; k<SIZE; ++k)
  //      printf("%6d%c",x[k],(k%8==7)? '\n': ' ');
    printf("\n");

/*    //ADD together to generate the sum table
    //As well intialize xplusx[]
    for(i=0 ; i<SIZE ; ++i)
        for(j=0 ; j<SIZE ; ++j)
        {
            xpx[i][j] = x[i] + x[j];
            xplusx[j + i*SIZE] = xpx[i][j];
        }

    //quicksort xplusx
    quicksort(xplusx, 0, SIZE*SIZE-1);
//    for(k=0; k < SIZE*SIZE; ++k)
  //      printf("%6d%c",xplusx[k],((k%8)==7) ? '\n': ' ');
    printf("\n");
    
*/
    long m=SIZE/2, n=SIZE/2;
//    int key = xpx[m][n];

    long ms = searchx(x, SIZE, m, n);
    printf("Key=%ld and MS=%ld\n",x[m]+x[n],ms);
//    int bs = binsearch(xplusx, 0, SIZE*SIZE-1, key) + 1;

//    printf("Key=%d Compare results: MS=%d  BS=%d\n", key,ms, bs);
  

}
