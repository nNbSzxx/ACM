#include <cstdio>
#include <iostream>
#define ma 65536 
using namespace std;
bool b[ma];
int a[ma];
bool f[1000001];
int main()
{
	//freopen("A.in","r",stdin); 
    //freopen("A.out","w",stdout);
	int l,r,j=0;
    for(int i=2;i<=ma;i++)
    {
        if(!b[i])
            a[++j]=i;
        for(int k=1;k<=j && a[k]*i<=ma;k++)
        {
            b[a[k]*i]=true;
            if(i%a[k]==0)
                break;
        }
    }
    int n=j;
    while(~scanf("%d%d",&l,&r))
    {
        for(int i=0;i<=r-l;i++)
            f[i]=true;
        for(int i=1;i<=n;i++)
            for(int j=max(2,(l-1)/a[i]+1);j<=r/a[i];j++)
                f[a[i]*j-l]=false;
        int last=-1;
        int min1=-1,min2,max1=-1,max2;
        if(l==1)
            f[0]=false;
        for(int i=0;i<=r-l;i++)
        if(f[i])
        if(last==-1)
            last=i;
        else
        {
            if(min1==-1)
            {
                min1=last;
                min2=i;
            }
            if(i-last<min2-min1)
            {
                min1=last;
                min2=i;
            }
            if(max1==-1)
            {
                max1=last;
                max2=i;
            }
            if(i-last>max2-max1)
            {
                max1=last;
                max2=i;
            }
            last=i;
        }
        if(max1==-1)
   	         printf("There are no adjacent primes.\n");
        else
            printf("%d,%d are closest, %d,%d are most distant.\n",min1+l,min2+l,max1+l,max2+l);
    }
    return 0;
}
