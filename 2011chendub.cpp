/*
 *File:  2011chendub.cpp
 *Date : 2014-11-08 12:48:58
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f
#define loop(i,l,r) for(int (i)=(l);(i)<=(r);(i)++)
#define iloop(i,l,r) for(int (i)=(r);(i)>=(l);(i)--)

using namespace std;
int n,m;
char g[4][55][55];
char a[55][55];
char str[110][30];
char ans[4][110*30];
char tmp[110*30];
char * cmp(char *a,char *b)
{
    int la,lb;
    la = lb =0;
    while(la<strlen(a)&&lb<strlen(b))
    {
    while(a[la]==' ') la++;
    while(b[lb]==' ') lb++;
    while(a[la]!=' '&&b[lb]!=' ')
    {
        if(a[la]>b[lb]) return b;
        else if(a[la]<b[lb])return a;
        else {
            la++;
            lb++;
        }
    }
    if(a[la]==' '&&b[lb]!=' ') return a;
    else if(a[la]!=' '&&b[lb]==' ') return b;
    }

}

int main()
{
    int T;
    scanf("%d",&T);
    for(int cas =1;cas<=T;cas++)
    {
        printf("Case #%d: ",cas);
        clr(tmp);
        scanf("%d",&n);
        for(int i= 1;i<=n;i++)
        {
            scanf("%s",&a[i][1]);
        }
        for(int i =1;i<=n;i++)
        {
            scanf("%s",&g[0][i][1]);
            
        }
        for(int k =1;k<=3;k++)
            for(int j =1;j<=n;j++)
                for(int t =1;t<=n;t++)
                    g[k][t][n-j+1] = g[k-1][j][t];
        scanf("%d",&m);
        for(int i =1;i<=m;i++)
        {
            scanf("%s",str[i]);
        }
        int l,r;
        for(int res=0;res<4;res++)
        {
            l=r= 0;
            for(int i=0;i<4;i++)
            {
                for(int j=1;j<=n;j++)
                    for(int k=1;k<=n;k++)
                    {
                        if(g[(i+res)%4][j][k]=='*')
                        {
                            if(a[j][k]!='.')
                            ans[res][r++] = a[j][k];
                            else ans[res][r++] = ' ';
                        }
                    }
            }
            while(ans[res][r-1]==' ') r--;
            ans[res][r] ='\0';
            while(ans[res][l]==' ') l++;
            //printf("%s\n",&ans[res][l]);
            int flag = 0;
            char t[30];
            int tl = l;
           while(tl<r&&sscanf(&ans[res][tl],"%s",t))
           {
              // printf("%c %d %s\n",ans[res][tl],res,t);
               int i;
               tl+=strlen(t);
               while(ans[res][tl]!=' '&&tl<=r) tl++;
               for(i =1;i<=m;i++)
                   if(strcmp(t,str[i])==0)
                       break;
               if(i==m+1) {flag =1;break;}
           }
           //printf("%d %d\n",res,flag);
           if(flag==0){
                if(strlen(tmp)==0) strcpy(tmp,&ans[res][l]);
                else strcpy(tmp,cmp(tmp,&ans[res][l]));
           } 

        }
        if(strlen(tmp)==0) puts("FAIL TO DECRYPT");
        else {
            int i = 0;
            while(i<strlen(tmp)){
            while(tmp[i]!=' '&&tmp[i]!='\0') {putchar(tmp[i]);i++;}
            if(i<strlen(tmp)) putchar(' ');
            else break;
            while(tmp[i]==' '&&i<strlen(tmp)) i++;
            }
            putchar('\n');
        }

        
    }
    return 0;
}

