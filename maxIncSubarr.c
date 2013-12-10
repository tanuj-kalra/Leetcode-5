#include<stdio.h>
#include<stdlib.h>

typedef struct Node Node;
struct Node {
    int index;
    Node * next;
};

typedef struct Vertex Vertex;
struct Vertex {
    int val;
    int len;
    int pre;
    Node * ad;
};

void max_inc_seq (int * a, int len)
{
    Vertex * p;
    p = (Vertex *) malloc (sizeof(Vertex) * len);
    if (!p) 
        exit(1);
    
    int i,j;
    for (i=0; i < len; ++i)
    {
        p[i].val = a[i];
        p[i].len = 1;
        p[i].pre = -1;
        p[i].ad = NULL;
    }

    Node *temp;
    for (i=0; i < len; ++i)
        for(j=0; j < i; ++j)
            if(p[i].val >= p[j].val)
            {
                temp = (Node *) malloc (sizeof(Node));
                if (!temp)
                    exit(2);
                temp->index = j;
                temp->next = p[i].ad;
                p[i].ad = temp;
            } 
    
    int max_node = 0;
    for (i=0; i < len; ++i)
    {
        temp = p[i].ad;
        while (temp)
        {
            if(p[i].len < p[temp->index].len + 1)
            {
                p[i].len = p[temp->index].len + 1;
                p[i].pre = temp->index;
            }
            temp = temp->next;
        }
        if(p[max_node].len < p[i].len)
            max_node = i;
    }

    Vertex *t;
    t = p + max_node;
    printf("%3d",t->val);
    while ( t->pre >= 0)
    {
        t = p + t->pre;
        printf("%3d", t->val);
    }
    
    Node *freet;
    for (i=0; i < len; ++i)
    {
        freet = p[i].ad;
        while (freet)
        {
            temp = freet->next;
            free(freet);
            freet = temp;
        }
    }
    free (p);
}


main()
{
    int a[] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};   
    int len = 16;
    int i;
    for (i=0; i < len; ++i)
        printf("%3d", a[i]);
    printf("\n Longest subarray is \n");
    max_inc_seq (a, len);
    printf("\n");
}
