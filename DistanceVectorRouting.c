#include <stdio.h>
void main()
{
    int i, n, r[20], s, de, ns, rns[20], j, m[20][20], d[20];
    int dis[20], min = 0, index;
    for (i = 1; i <= 20; i++)
        dis[i] = 0;
    printf("Enter number of routers: ");
    scanf("%d", &n);
    printf("Enter the names of the routers: ");
    for (i = 1; i <= n; i++)
        scanf("%d", &r[i]);
    printf("Enter the source router: ");
    scanf("%d", &s);
    printf("Enter the destination router: ");
    scanf("%d", &de);
    printf("Enter number of neighbors for the source: ");
    scanf("%d", &ns);
    printf("Enter the names of the neighbors of the source: ");
    for (i = 1; i <= ns; i++)
        scanf("%d", &rns[i]);
    printf("Enter the cost matrix: ");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &m[i][j]);
            if (m[i][j] == 0)
                m[i][j] = 99;
        }
    printf("The delays from neighbors are");
    for (i = 1; i <= ns; i++)
    {
        dis[i] = m[s][rns[i]] + m[rns[i]][de];
        printf("%d\t", dis[i]);
    }
    min = dis[1];
    index = 1;
    for (i = 2; i <= ns; i++)
    {
        if (min > dis[i])
        {
            min = dis[i];
            index = i;
        }
        printf("\nMinimum distance from router %d to %d is through router %d that is %d\n", s, de, rns[index], min);
    }
}

/*
4
1 2 3 4
3
1
2
2 4
0 1 1 0
1 0 3 2
0 3 0 2
1 2 2 0
*/