#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;
struct node{
    int u,w,v;
    friend bool operator< (node n1,node n2){
		return n1.w> n2.w;
	}
}edge[10001];
int father[1001],n,m;
priority_queue<node> q;
void init()
{
    for(int i = 1; i <= n; i++)
        father[i] = i;	
}

int findfa(int r)
{
    return (father[r]==r)?r:findfa(father[r]);
}

void kruskal()
{
    init();
    while(!q.empty()){
    	node e=q.top();
    	q.pop();
    	int uu = findfa(e.u);
        int vv = findfa(e.v);
        if(uu != vv)
        {
            father[uu] = vv;//¹é²¢ 
            printf("%d %d %d\n",e.u,e.v,e.w);
        }
    }
}
int main(){
	FILE *fp;
	fp=fopen("kruskal.txt","r");
	if (fp == NULL)
    {
        printf("Cannot open the file!\n");
        exit(0);
    }
	while(fscanf(fp,"%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<m;i++)
        {
            fscanf(fp,"%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
            q.push(edge[i]);
        }
        kruskal();
    }
    return 0;
}