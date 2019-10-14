#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

char Precede(char t1,char t2){//优先级判断 
	int i,j;
	char pre[][7]={
		{'>','>','<','<','<','>','>'},
		{'>','>','<','<','<','>','>'},
		{'>','>','>','>','<','>','>'},
		{'>','>','>','>','<','>','>'},
		{'<','<','<','<','<','=',' '},
		{'>','>','>','>',' ','>','>'},
		{'<','<','<','<','<',' ','='}};  
	switch(t1){
		case '+':i=0;break;
		case '-':i=1;break;
		case '*':i=2;break;
		case '/':i=3;break;
		case '(':i=4;break;
		case ')':i=5;break;
		case '#':i=6;break;	                    
	}
	switch(t2){
		case '+':j=0;break;   
		case '-':j=1;break;
		case '*':j=2;break;
		case '/':j=3;break;
		case '(':j=4;break;
		case ')':j=5;break;
		case '#':j=6;break;        		
	}
	return pre[i][j]; 
 }
double Operate(double a,char theta,double b){//运算 
	double c;
	switch(theta){
		case '+':c=a+b;break;
		case '-':c=a-b;break;
		case '*':c=a*b;break;
		case '/':c=a/b;break;
	}
	return c;
}
void Cal(){
	char c;
	stack<char>op;
	stack<double>nums;
	op.push('#');
    bool flag = true;
    double num=0;
    c=getchar();
	while(c!='#'||op.top()!='#'){
		if(c<='9'&&c>='0'){
			double n;
			n=(double)(c-'0');
			num=num*10+n;
			nums.push(num);
			c=getchar();
		}else{
			num=0;
			char cmp = Precede(op.top(), c);
			
            if(cmp=='<'){
                op.push(c);
                c = getchar();
		}else if(cmp=='='){
				op.pop();
                c=getchar();
		}else if(cmp=='>'){
				double num1, num2;
				double tempans;
                char tempop;
                num2 = nums.top(); nums.pop();
			    num1 = nums.top(); nums.pop();
                tempop = op.top(); op.pop();
                tempans = Operate(num1, tempop, num2);
                nums.push(tempans);
			}
		}
	}
    printf("%lf\n",nums.top());
}	                                                       	
int main(){ 	                                                      	
	Cal();
	return 0;
}