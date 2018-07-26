#include <cstdio>
#include <cstring> 
using namespace std;

int sg[1000];
int main()
{
	sg[0] = 0;
	sg[1] = 1;
	int vis[4010];
	for (int i = 2; i < 1000; i ++) {
		memset(vis,0,sizeof(vis));
		for (int j = 0; j < i; j ++)
			vis[sg[j]] = 1;
		for (int j = 1; j < i; j ++) {
			int a = j;
			int b = i - j;
			vis[sg[a] ^ sg[b]] = 1;
		}
		for (int j = 1; ; j ++) {
			if (!vis[j]) {
				sg[i] = j;
				break;
			} 
		}
	}
	for (int i = 0; i < 1000; i ++) {
		printf("%d ",sg[i]);
	}
}
