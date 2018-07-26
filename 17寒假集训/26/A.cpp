#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10005;
const double PRE = 1e-8;

int main()
{
	int n,k;
	double temp;
	double num[MAX];
	double sum;
	while (scanf("%d%d",&n,&k), n || k) {
		sum = 0;
		for (int i = 1; i <= n; i ++) {	
			scanf("%lf",&num[i]);
			sum += num[i];
		}
			
		double mid;
		double i = 0.0;
		double j = sum / k ;
		while ( j - i > PRE) {
			mid = ( i + j ) / 2;
          	int cnt = 0;
          	int flag = 0;
			for (int i1 = 1; i1 <= n; i1 ++) {
          		cnt += (int)(num[i1] / mid);
          		if (cnt >= k) {
          			flag = 1;
          			break;
				}
			}
			//printf("%d %d %d %d\n",i,j,mid,cnt);
			if (flag) {
				i = mid;
			} else	 {
				j = mid;
			}
		}	
		printf("%.2lf\n", i);
	}
	return 0;
}
