/*
 *File:  mst.cpp
 *Date : 2014-09-24 17:05:49
 */

#include<stdio.h>
#include<string.h>
#include<math.h>

int path[102][102];
int flag[102];
int closedge[102];
int max;
int cnt;

int CreatMST(int n)
{
    int i, j, x, k;
    flag[0] = 1;
    for(i=1; i<n; ++i)
    closedge[i] = path[0][i];
    for(i=1; i<n; ++i)
    {
        k = max, x = 1;
        for(j=1; j<n; ++j)
        if(!flag[j] && closedge[j] < k)
            x = j, k = closedge[j];
        flag[x] = 1;
        cnt += k;
        for(j=1; j<n; ++j)
        if(!flag[j] && closedge[j] > path[x][j])
        closedge[j] = path[x][j];
    }
    return cnt;
}

int main()
{
    int i, j, k, t, x, y, n, m;
    while(scanf("%d", &n) != EOF && n)
    {
        max = 0;
        cnt = 0;
        memset(flag, 0, sizeof(flag));
        memset(closedge, 0, sizeof(closedge));
        memset(path, 0, sizeof(int)*102*102);
        for(i=0; i<(n*(n-1))/2; ++i)
        // 计算N*(N+1)条路径的权重 
        {
            scanf("%d%d%d", &x, &y, &m);
            path[x-1][y-1] = path[y-1][x-1] = m;
            if(max < m) max = m; 
        }
        max++;
        for(i=0; i<n; ++i)
        path[i][i] = max;
        
        printf("%d\n", CreatMST(n));
    }
    return 0;
}

