#include<stdio.h>

int a[2000];
char e[10];
int find(int x){
	if(a[x]!=x)x=find(a[x]);
	return a[x];
}
void group(int x,int y){//把y的根节点组合到x 
	x=find(x);
	y=find(y);
	a[y]=x;
}
int main(){
	int x,y,n,m,i,j,q;
	int k=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=2*n;i++){//初始化 
		a[i]=i;
	}
	for(i=1;i<=m;i++){//输入信息 
		scanf("%s%d%d",e,&x,&y);
		if(e[0]=='F')group(x,y);//是朋友，就合并 
		else if(e[0]=='E'){//是敌人，就把x并入y的敌人中 
		group(x,y+n);
		group(y,x+n);
		}
	}
	for(i=1;i<=n;i++){//找根节点 
		a[i]=find(i);
	}
	for(i=1;i<=n;i++){//排序 
		for(j=1;j<=n-1;j++){
			if(a[j]>a[j+1]){
				q=a[j];
				a[j]=a[j+1];
				a[j+1]=q;
			}
		}
	}
	for(i=1;i<=n;i++){
		if(a[i]!=a[i-1])k++;
	}
	printf("%d\n",k);
	return 0;
}