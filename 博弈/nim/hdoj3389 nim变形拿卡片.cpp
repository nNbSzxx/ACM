/*	
	很容易得到只有3个盒子是完全无法移动的：1，2，4 
 	如果一个盒子需要移动奇数次到达1，2，4，那么是一个需要考虑的盒子
	而如果是偶数次的话则不需要考虑
	（面对必败态，移动偶数次的盒子对手只需要再移动一次还是必败态） 
	有没有可能既存在偶数次又存在奇数次呢？
	首先考虑有无可能从一个盒子到另一个盒子有无可能存在不同的两条路径，
	这两条路径中间经过的盒子数的奇偶不同？
	显然不可能，因为从规则可推出路径上的盒子序号必然是奇偶相间的
	那么一个盒子到1，3，4的路径里，路径长度的奇偶会不同吗
	如果存在，显然不可能是到1和3的。
	1，4？它们对3取模都余1，根据规则，路径上经过的盒子必然是对3余1和余2相间的，
	所以不可能
	3，4？到3的路径上的盒子必然是都是余0的，而到4的则是余1余2相间的，
	故一个盒子只可能到达其中一个盒子
	综上，只要找到一条到达1，3，4的路径，得到路径长度的奇偶，
	就可以判断需不需要考虑该盒。
	需要考虑的盒子构成nim博弈。 
*/ 
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int tab[10010];
	tab[1] = 0;
	tab[2] = -1;
	tab[3] = 0;
	tab[4] = 0;
	for (int i = 5; i <= 10000; i ++) {
		for (int j = 1; j < i; j ++) {
			if ((i + j) % 3 == 0 && (i + j) % 2 == 1) {
				tab[i] = ~tab[j];
				break;
			}
			
		}
	}

	int t, tc = 1;
	scanf("%d",&t);
	while (t -- ) {
		int n;
		int ans = 0, a;
		scanf("%d",&n);
		printf("Case %d: ",tc ++);
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&a);
			if (tab[i]) {
				ans ^= a;
			}
		}
		if (ans) {
			puts("Alice");
		} else {
			puts("Bob");
		}
	}
	return 0;
}
