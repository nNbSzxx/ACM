#include<stdio.h>
int main(){
    int n,x[50002],d[50002],i,j,flag,min=100000000;
    scanf("%d",&n);
    scanf("%d",&x[2]);
    for(i=3;i<=n-1;i++)
    {
        scanf("%d",&x[i]);
        d[i-1]=x[i]-x[i-1];//d[i]记录相邻两村庄间距 
        if(min>d[i-1])//更新最小间距和其位置 
        {
            min=d[i-1];
            flag=i-1;
        } 
    }
    scanf("%d",&x[n]);
    if(n<4)//村庄个数小于4则无解 
        printf("0\n");
    else//按格式输出 
        printf("%d\n%d %d %d %d\n",x[n]+min,flag+1,1,n,flag);
    return 0;
} 
