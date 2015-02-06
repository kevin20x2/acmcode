/*
 *File:  chat.cpp
 *Date : 2014-10-22 13:58:16
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
struct node{
    int u;
    struct node *next;
    struct node * be;
    node(int x) {
        u = x; 
        next = NULL;
        be = NULL;
    }
};
node * head;
node * maxn;
node * tail;
node * top;
int T;
char str[20];
int n;
int chat[5010];
void prior(node * p)
{
    if(head == p) return ;
    else {
        p->be->next = p->next;
        if(tail!=p)
            p->next->be = p->be;
        else tail = p->be;
        p->be = NULL;
        p->next = head;
        head->be = p;
        head = p;
    }
}
void del_node(node *p)
{
    if(tail!=p&&head!=p){
        p->be->next = p->next;
        p->next->be = p->be;
    }
    else if(head == p)
    {
        head = p->next;
        if(p->next !=NULL)
        p->next->be = NULL;
    }
    else if(tail == p)
    {
        tail = p->be;
        if(p->be!=NULL)
        p->be->next = NULL;
    }
    
    free(p);
    
}
node * find_node(int u)
{
    node * t = head;
    while(t!=NULL)
    {
        if(t->u ==u) return t;
        t = t->next;
    }
    return NULL;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        head = NULL;
        maxn =NULL;
        tail = NULL;
        top = NULL;
        clr(chat);
        scanf("%d",&n);
        int x;
        for(int i =1;i<=n;i++)
        {
            scanf("%s",str);
            printf("Operation #%d: ",i);
            if(strcmp(str,"Prior")==0)
            {
               if(head == NULL) 
                   puts("empty.");
               else{
                   prior(maxn);
                   puts("success.");
               } 
            }
            else if(strcmp(str,"Add")==0)
            {
                scanf("%d",&x);
                node * tmp = find_node(x);
                if(tmp !=NULL)
                {
                    puts("same priority.");
                }
                else {
                    node * t = new node(x);
                    if(head !=NULL)
                    {
                        tail ->next = t;
                        t->be = tail;
                        tail = t;
                    }
                    else {
                        head = t;
                        tail = t;
                        maxn = t;
                    }
                    if(maxn==NULL||maxn->u<x)
                    {
                        maxn = t;
                    }
                    puts("success.");
                }
            }
            else if(strcmp(str,"Chat")==0)
            {
                scanf("%d",&x);
                if(head == NULL)
                    puts("empty.");
                else{ 
                    if(top!=NULL)
                    {
                        chat[top->u] +=x;
                        puts("success.");
                    }
                    else {
                        chat[head->u] +=x;
                        puts("success.");
                    }
                }
            }
            else if(strcmp(str,"Close")==0)
            {
                scanf("%d",&x);
                node * t = find_node(x);
                if(t ==NULL)
                {
                    puts("invalid priority.");
                }
                else {
                    printf("close %d with %d.\n",x,chat[x]);
                    del_node(t);
                    chat[x]  = 0;
                }
            }
            else if(strcmp(str,"Rotate")==0)
            {
                scanf("%d",&x);
                int i = 1;
                node * t = head;
                while(i<x&&t!=NULL)
                {
                    t=t->next;
                    i++;
                }
                if(t==NULL)
                    puts("out of range.");
                else { 
                    prior(t);
                    puts("success.");
                }
            }
            else if(strcmp(str,"Choose")==0)
            {
                scanf("%d",&x);
                node *t = find_node(x);
                if(t == NULL)
                {
                    puts("invalid priority.");
                }
                else {
                    prior(t);
                    puts("success.");
                }
            }
            else if(strcmp(str,"Top")==0)
            {
                scanf("%d",&x);
                node *t = find_node(x);
                if(t==NULL)
                {
                    puts("invalid priority.");
                }
                else {
                    top = t;
                    puts("success.");
                }
            }
            else if(strcmp(str,"Untop")==0)
            {
                if(top!=NULL)
                {
                    top =NULL;
                    puts("success.");
                }
                else {
                    puts("no such person.");
                }
            }
        }
        if(top!=NULL)
        {
            if(chat[top->u]!=0)
                printf("Bye %d: %d\n",top->u,chat[top->u]);
            del_node(top);
            top =NULL;
        }
        while(head!=NULL)
        {
            if(chat[head->u]!=0)
                printf("Bye %d: %d\n",head->u,chat[head->u]);
            del_node(head);
        }

    }
    return 0;
}

