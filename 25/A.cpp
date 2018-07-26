#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
const int MAX = 50010;
using namespace std;

int main()
{
	int t;
	int k,n;
	double sum, qsum;
	double num[MAX];
	scanf("%d",&t);
	while (t --) {
		sum = 0;
		scanf("%d%d",&n,&k);
		qsum = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%lf",&num[i]);
		}
		 if(n <= k ) {  
            printf("0\n");  
            continue;  
        }  
        sort (num+1, num+n+1);
        int l = n - k;
        
        for(int i = 1; i <= l; i++)  {  
            sum += num[i];  
            qsum += num[i] *num[i];  
        } 
        double ans = qsum - sum * sum / l;  
        for(int i = l+1; i <= n; i++) {  
            sum -= num[i - l];  
            sum += num[i];  
            qsum -= num[i - l] * num[i - l];  
            qsum += num[i] * num[i];  
            ans = min(ans, qsum - sum * sum / l);  
        }  
        printf("%.10f\n", ans);  
	}
}
