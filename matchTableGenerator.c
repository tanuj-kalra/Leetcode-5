#include<stdio.h>
#define TEAMS 2*5

main()
{
    int team[TEAMS];
    int i,j, temp;

    for (i=0; i< TEAMS; ++i)
        team[i]=i+1;
    for (i=0; i< TEAMS-1; ++i)
    {
        for (j=1; j< TEAMS-1; ++j)
            temp=team[j], team[j]=team[j+1], team[j+1]=temp;
        printf("Round %d\n", i+1);
        for (j=0; j< TEAMS/2; ++j)
            printf("%4d --- %d\n", team[j], team[TEAMS-1-j]);
        printf("\n");
    }
}

