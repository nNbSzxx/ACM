#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a,b;
int ansa[10],ansb[10];

void count_digits(int s,int ans[],int times=1)
{
    int i,d,p;
    if (s <= 0)return ;
    d = s % 10;
    p = s / 10;
    for (i = 1;i <= d;i ++)ans[i] += times;
    while(p > 0) {
        ans[p % 10] += (d + 1) * times;
        p = p / 10;
    }

    for (i = 0;i <= 9;i ++)ans[i] += times * (s / 10);

    times *= 10;
    count_digits((s / 10) - 1, ans, times);
    return ;
}


int main()
{
    int i,j;
	while(scanf("%d%d",&a,&b) != EOF && a + b > 0)	{
	   memset(ansb,0,sizeof(ansb));
	   memset(ansa,0,sizeof(ansa));
	   if (a >= b) {
	      swap(a,b);
	   }
	   a --;
	   if (b > a) {
	      count_digits(b,ansb);
	      count_digits(a,ansa);
	   }
	   for(i = 0; i < 10; i ++) {
	       printf("%d%c", ansb[i] - ansa[i], i==9 ? '\n' : ' ');
	   }
	    
	}
	
	return 0;
}
