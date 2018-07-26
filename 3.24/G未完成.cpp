#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int main() 
{
	int dp[MAX][1005];
	int c[5],tot;
	for (int i = 1; i <= 4; i ++) {
		scanf("%d",&c[i]);
	}
	sort(c+1,c+4+1);
	scanf("%d",&tot);
	for (int t = 1; t <= tot; t ++) {
		dp[0][0] = 1;
		
	    for (int i = 1; i <= 4 ; ++ i)
	    {
	        for (int j = c[i]; j <= ; j ++) 
	        {
	            for(int k = 1; k <= 100; k ++)
	            {
	                dp[j][k] += dp[j-w[i]][k-1];
	            }
	        }
	    }
	}
	
	
	return 0;
} 
