#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int judge(int m)
{
	int a[10] = {0};
	while (m ) {
		int temp = m % 10;
		m /= 10;
		if (a[temp]) {
			return 0;
		} else {
			a[temp] = 1;
		}
	}
	return 1;
}

int main()
{
    int i;
	int sum[100010]={0};
	int isTrue[100010]={1,1,1,1,1,1,1,1,1,1,};
	for (i = 1;i <= 9; i ++) {
		sum[i] = i;
	}
	for (i = 10; i <= 100000; i ++) {
		sum [i] = sum[i - 1];
		if (isTrue[i / 10]) {
			if (judge(i)){
				isTrue[i] = 1;
				sum[i] ++;
			}
		}
	}
	int t;
	cin >> t;
	while (t --) {
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",sum[b]-sum[a-1]);
	}
	return 0;
}
