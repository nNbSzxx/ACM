#include<stdio.h>
int main(){
    int n,x[50002],d[50002],i,j,flag,min=100000000;
    scanf("%d",&n);
    scanf("%d",&x[2]);
    for(i=3;i<=n-1;i++)
    {
        scanf("%d",&x[i]);
        d[i-1]=x[i]-x[i-1];//d[i]��¼��������ׯ��� 
        if(min>d[i-1])//������С������λ�� 
        {
            min=d[i-1];
            flag=i-1;
        } 
    }
    scanf("%d",&x[n]);
    if(n<4)//��ׯ����С��4���޽� 
        printf("0\n");
    else//����ʽ��� 
        printf("%d\n%d %d %d %d\n",x[n]+min,flag+1,1,n,flag);
    return 0;
} 
