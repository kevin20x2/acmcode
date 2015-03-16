/*
 *File:  ceshi.cpp
 *Date : 2015-03-05 16:42:40
 */
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<ctime>
#include<algorithm>
typedef  long long LL;

#define clr(x) memset((x),0,sizeof(x))
#define inf 0x3f3f3f3f

using namespace std;

int main()
{
    int pc = 0x1000;
    int address = 0x0001;
    int npc = ((pc-1)&0xf000)|(address+1);
    int npc2 = ((pc)&0xf000)|(address);
    double t = time(NULL);
    cout<< npc<<' '<<npc2;
    cout<< t<<endl;

    t = (double)clock()/CLOCKS_PER_SEC;
    cout<< t<<endl;

    return 0;
}

