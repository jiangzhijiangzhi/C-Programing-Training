#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXQSIZE 200

typedef int QElemType;
typedef struct{
	QElemType *base;
	int front;
	int rear;
}SqQueue;
void initQueue(SqQueue *Q){//空队列 
	Q->base=(QElemType *)malloc(MAXQSIZE*sizeof(QElemType));
	if(!Q->base)exit(1);
	Q->front=Q->rear=0;
}
int QueueLength(SqQueue *Q){//求队列长度 
	int e;
	e=(Q->rear-Q->front+MAXQSIZE)%MAXQSIZE;
	return e;
}
void EnQueue(SqQueue *Q,QElemType e){//插入的元素e 
	if((Q->rear+1)%MAXQSIZE==Q->front)exit(1);
	Q->base[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXQSIZE;
}
void DeQueue(SqQueue *Q){//删除元素e 
	if(Q->front==Q->rear)exit(1);
	Q->front=(Q->front+1)%MAXQSIZE;
}
QElemType GetHead(SqQueue *Q){
	return Q->base[Q->front];
}
int main(){
	int N,n,c;
	QElemType t,x;
	SqQueue f,*Q;
	printf("输入三角形规模：\n");
	while(scanf("%d",&N)!=EOF){
		Q=&f;
		initQueue(Q);
		EnQueue(Q,1);
		for(n=2;n<=N;n++){
		EnQueue(Q,1);
		for(c=1;c<=n-2;c++){
			t=GetHead(Q); 
			DeQueue(Q);
			printf("%d  ",t);
			x=GetHead(Q);
			t=t+x;
			EnQueue(Q,t);
		}
		EnQueue(Q,1);
		printf("%d  ",GetHead(Q));
		DeQueue(Q);
		printf("\n");
	}
		while(Q->front!=Q->rear){
			printf("%d  ",GetHead(Q));
			DeQueue(Q);
		}
		printf("\n");
	}
	return 0;
}
