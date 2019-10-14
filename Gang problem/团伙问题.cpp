#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m;
int a[1001][1001],father[1001];//a[i][j]存储第i个人的第j个敌人
int find(int);
void merge(int,int);
int find(int);
void work();
int main()
{
	work();
	return 0;
} 
void work()
{
	memset(a,0,sizeof(a));
	cin>>n>>m;
	for(int i=1;i<=n;i++) father[i]=i;//初始化为自己	
	int p,x,y;
	for(int i=1;i<=m;i++)
	{
		cin>>p>>x>>y;
		if(p==0) merge(x,y);//如果x，y是亲戚，则合并 
		if(p==1)//如果x，y是敌人，则把x并入y的所以敌人中，y并入x的敌人中 
		{
			for(int j=1;j<=a[x][0];j++) merge(y,a[x][j]);			
			for(int j=1;j<=a[y][0];j++) merge(x,a[y][j]);
			a[y][0]++;a[y][a[y][0]]=x;//a[x][0]记录的x的敌人数 
			a[x][0]++;a[x][a[x][0]]=y;
		}
	}	
	int tot=0;//如果自己就是树的根表明是一个集合 
	for(int i=1;i<=n;i++) if(father[i]==i) tot++;
	cout<<tot<<endl;
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)father[x]=y;
}
int find(int x)
{
	if(father[x]==x) return x;
	father[x]=find(father[x]);
	return father[x];
}