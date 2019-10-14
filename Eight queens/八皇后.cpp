#include<stdio.h>
#include<math.h>
#include<malloc.h>
int y=0; 
int place(int *x,int k){//判断皇后是否能放在k行x[k]列 
	int i;
	for(i=1;i<k;i++){//对k-1行进行考察，如果k-1行某行的皇后和k行的在同一列或者同一斜线，返回0 
		if((x[i]==x[k])||(fabs(x[i]-x[k])==fabs(i-k)))return 0;
	}
	return 1;
}
void nQueens(int *x,int n){
	int k=1;//k是当前行 
	x[k]=0;
	while(k>0){
		x[k]++;//移到下一列 
		while(x[k]<=n&&!place(x,k))x[k]++;//找出能摆放的列 
		if(x[k]<=n){
			if(k==n){//进行输出 
				y++;
				printf("第%d种解法\n",y);
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						if(j==x[i])printf("Q");
						else printf("*");
					}
					printf("\n");
				}
				printf("\n");
			}
			else{
				k++;
				x[k]=0;
			}
		}//回溯到上一行 
		else k--;
	}
	y=0;
}


int main(){
	int n,*x;//数组首地址 
	while(scanf("%d",&n)!=EOF){
		x=(int *)malloc(sizeof(int)*(n+1));
		nQueens(x,n);
	}
	return 0;
}