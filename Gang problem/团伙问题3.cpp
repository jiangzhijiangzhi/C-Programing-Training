#include<stdio.h>

int a[2000];
char e[10];
int find(int x){
	if(a[x]!=x)x=find(a[x]);
	return a[x];
}
void group(int x,int y){//��y�ĸ��ڵ���ϵ�x 
	x=find(x);
	y=find(y);
	a[y]=x;
}
int main(){
	int x,y,n,m,i,j,q;
	int k=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=2*n;i++){//��ʼ�� 
		a[i]=i;
	}
	for(i=1;i<=m;i++){//������Ϣ 
		scanf("%s%d%d",e,&x,&y);
		if(e[0]=='F')group(x,y);//�����ѣ��ͺϲ� 
		else if(e[0]=='E'){//�ǵ��ˣ��Ͱ�x����y�ĵ����� 
		group(x,y+n);
		group(y,x+n);
		}
	}
	for(i=1;i<=n;i++){//�Ҹ��ڵ� 
		a[i]=find(i);
	}
	for(i=1;i<=n;i++){//���� 
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