#include<stdio.h>
#include<math.h>
#include<malloc.h>
int y=0; 
int place(int *x,int k){//�жϻʺ��Ƿ��ܷ���k��x[k]�� 
	int i;
	for(i=1;i<k;i++){//��k-1�н��п��죬���k-1��ĳ�еĻʺ��k�е���ͬһ�л���ͬһб�ߣ�����0 
		if((x[i]==x[k])||(fabs(x[i]-x[k])==fabs(i-k)))return 0;
	}
	return 1;
}
void nQueens(int *x,int n){
	int k=1;//k�ǵ�ǰ�� 
	x[k]=0;
	while(k>0){
		x[k]++;//�Ƶ���һ�� 
		while(x[k]<=n&&!place(x,k))x[k]++;//�ҳ��ܰڷŵ��� 
		if(x[k]<=n){
			if(k==n){//������� 
				y++;
				printf("��%d�ֽⷨ\n",y);
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
		}//���ݵ���һ�� 
		else k--;
	}
	y=0;
}


int main(){
	int n,*x;//�����׵�ַ 
	while(scanf("%d",&n)!=EOF){
		x=(int *)malloc(sizeof(int)*(n+1));
		nQueens(x,n);
	}
	return 0;
}