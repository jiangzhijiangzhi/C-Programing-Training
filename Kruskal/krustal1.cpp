#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define MAX_TREE_SIZE 100
#define MAXV 100
using namespace std;
int fa[1001],m,n;
struct node{
	int u,v,w;
	int weight;
	friend bool operator<(node n1,node n2){
		return n1.w> n2.w;
	}
}edge[1001];
typedef struct PTNode{
	int data;
	int parent;
}PTNode;
typedef struct{
	PTNode nodes[MAX_TREE_SIZE];
	int r,n;
}PTree;
typedef PTree MFSet;
priority_queue<node> q;
int find_father(int u){//ÕÒ¸¸½Úµã 
	if(fa[u]==u)return fa[u];
	return fa[u]=find_father(fa[u]);
	//return (fa[u]==u)?u:find_father(fa[u]);
}

void Kruskal(){
	for(int i = 1; i <= n; i++)
        fa[i] = i;
    while(!q.empty()){
    	node e=q.top();
    	q.pop();
    	int uu = find_father(e.u);
        int vv = find_father(e.v);
        if(uu != vv)
        {
            fa[uu] = vv;//¹é²¢ 
            printf("%d %d %d\n",e.u,e.v,e.w);
        }
    }
}
int main(){
	FILE *fp;
	fp=fopen("kruskal.txt","r");
		while(fscanf(fp,"%d%d",&n,&m)!=EOF){
			for(int i=0;i<m;i++){
            fscanf(fp,"%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
            q.push(edge[i]);
        	}
        	Kruskal();
		}
		return 0;
}