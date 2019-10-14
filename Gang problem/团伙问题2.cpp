#include<stdio.h>
#include<string.h>
int a[5000];
char p[10];
int find(int x)
{
    if(a[x]!=x)
       x=find(a[x]);
    return a[x];
}
void unionn(int x,int y)
{
    x=find(x);
    y=find(y);
    a[y]=x;
}
int main()
{
    int n,m,x,y,i,j,z,k=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n*2;i++)
       a[i]=i;
    for(i=1;i<=m;i++)
    {
        scanf("%s%d%d",p,&x,&y);
        if(p[0]=='F')
          unionn(x,y);
        if(p[0]=='E')
        {
            unionn(x,y+n);
            unionn(y,x+n);
        }
    }
    for(i=1;i<=n;i++)
      a[i]=find(i);
    for(i=1;i<n;i++)
      for(j=1;j<=n-i;j++)
        if(a[j]>a[j+1])
        {
            z=a[j];
            a[j]=a[j+1];
            a[j+1]=z;
        }
    for(i=1;i<=n;i++)
      if(a[i]!=a[i-1])
        k++;
    printf("%d",k);
    return 0;
}