#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 30000
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
char maze[20][20];

typedef struct{
  int r;
  int c;
}PosType;
PosType start,end;
typedef struct{
	PosType seat;
	int di;
}SElemType;

typedef struct{
        SElemType *base;
        SElemType *top;
        int stacksize;
}SqStack;

SElemType e;

Status InitStack(SqStack &S){
       S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
       if(!S.base) exit(OVERFLOW);
       S.top=S.base;
       S.stacksize=STACK_INIT_SIZE;
       return OK;
       }

Status StackEmpty(SqStack S)
{
       if(S.base==S.top)
         return TRUE;
         else return FALSE; 
}

Status Push(SqStack &S,SElemType e){
       *S.top++=e;
       return OK;
}

Status Pop(SqStack &S,SElemType &e){
       if(S.top==S.base) return ERROR;
       e=*--S.top;
       return OK;
}

Status Pass(PosType pos){//检测是否通 
	if(maze[pos.r][pos.c]=='0')return TRUE;
	else return FALSE;
}

void FootPrint(PosType pos){//走过的地方标记为* 
	maze[pos.r][pos.c]='*';
}

void MarkPrint(PosType pos){//走不通的地方标记为@ 
	maze[pos.r][pos.c]='@';
}

PosType NextPos(PosType pos,int di){//东南西北四个方向 
    PosType next=pos;
    if(di==1)next.c++;
    else if(di==2)next.r++;
    else if(di==3)next.c--;
    else if(di==4)next.r--;
    return next;
}

Status MazePath(SqStack &S,PosType start, PosType end){
	InitStack(S);
	PosType curpos=start;
	do{
		if(Pass(curpos)){//如果能通过，就标记为*，从东开始走 
			FootPrint(curpos);
			e.seat=curpos;
			e.di=1;       
			Push(S,e);
			if(curpos.r==end.r&&curpos.c==end.c)return TRUE;//如果到达出口 
			curpos=NextPos(curpos,1);
		}else{
			if(!StackEmpty(S)){
				Pop(S,e);
				while(e.di==4&&!StackEmpty(S)){//四个方向都走不通的话就标记为@ 
					MarkPrint(e.seat);
					Pop(S,e);
				}
				if(e.di<4){
					e.di++;
					Push(S,e);
					curpos=NextPos(e.seat,e.di);
				}
			}
		}
	}
	while(!StackEmpty(S));
	return FALSE;
}
Status print_maze(int x,int y){	//打印迷宫 
	for(int i=0;i<=x+1;i++){
			for(int j=0;j<=y+1;j++){
				printf("%c ",maze[i][j]);
			}
			printf("\n");
		}
		printf("\n");
}
int main(){
    PosType pos;
    SqStack S;
	FILE *fp=fopen("in.txt","r");
	int x,y,i,j,c;
	fscanf(fp,"%d%d",&x,&y);//读取行数和列数 
	fscanf(fp,"%d%d%d%d",&start.r,&start.c,&end.r,&end.c);//读取迷宫的起始和结束位置 
	for(i=1;i<=x;i++){
		for(j=1;j<=y;j++){
			fscanf(fp,"%d",&c);//读取迷宫 
			maze[i][j]=c+48;//整型转化为字符型 
		}
	}
	for(i=0;i<=y+1;i++)maze[0][i]='1'; 
	for(i=0;i<=y+1;i++)maze[9][i]='1';
	for(i=0;i<=y+1;i++)maze[i][0]='1';
	for(i=0;i<=y+1;i++)maze[i][9]='1';//给迷宫加围墙
	print_maze(x,y);//打印迷宫 
	
	InitStack(S);
	MazePath(S,start,end);//走迷宫 
	for(i=0;i<x+2;i++){
		for(j=0;j<y+2;j++){
			if(maze[i][j]=='1')maze[i][j]='#';//将围墙和不能走的地方替换成# 
			if(maze[i][j]=='0')maze[i][j]=' ';//将每走过的地方替换成空 
		}
	}
	
	print_maze(x,y);//打印走后的迷宫 
	fclose(fp);
	return 0;
}
