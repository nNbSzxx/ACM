#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long pre[255][255], pre1[255][255], dp[1010 * 250], dp1[1010 * 250];
int n, t;
int sum;

void init()
{
	// �������t���һ������Ϊi�Ŀ���j���ε������ 
	for (int i = 0; i < 255; i ++) {
		pre[i][0] = 1;
	}
	for (int i = 1; i < 255; i ++) {
		for (int j = 1; j <= i; j ++) {
			pre[i][j] = (pre[max(i - t - 1, 0)][j - 1] + pre[i - 1][j]) % MOD; 
		}
	}
	// pre1[i][j] ����Ϊi�Ŀ���j���Σ��ҷŵ�i��ʳ��һ������
	for (int i = 1; i < 255; i ++) {
		for (int j = 1; j <= i; j ++) {
			pre1[i][j] = pre[max(i - t - 1, 0)][j - 1];
		}
	}
	// ��ǰ׺�� 
	for (int i = 1; i < 255; i ++) {
		for (int j = 1; j < 255; j ++) {
			pre[i][j] = (pre[i][j] + pre[i][j - 1]) % MOD;
			pre1[i][j] = (pre1[i][j] + pre1[i][j - 1]) % MOD;
		}
	}
	 
}

int main()
{
	freopen("kebab.in", "r", stdin);
	freopen("kebab.out", "w", stdout);
	int q, x;
	scanf("%d%d", &n, &t);
	init();
	sum = 0;
	// dp��ʾ���кϷ�����
	// dp1��ʾĩβʳ������ʱ������ 
	dp[0] = 1;
	dp1[0] = 0;
	for (int block = 1; block <= n; ++ block) {
		scanf("%d%d", &q, &x);
		for (int i = 1; i <= q; i ++) {
			dp[sum + i] = dp[sum + i - 1];
			if (i <= t + 1) { // ĩβ���Σ�״̬һ���Ǵ�ǰһ����ת������ 
				for (int j = 1; j < i; j ++) {
					dp1[sum + i] = (dp1[sum + i] + pre1[j][q - x] * dp1[max(sum + i - t - j, 0)]) % MOD;
				}
				// j == i������ҪҪ��sum + i - t - iλ������1 
				dp1[sum + i] = (dp1[sum + i] + pre1[i][q - x] * dp[max(sum - t, 0)]) % MOD;
			} else { // ĩβ���ε�״̬�Ǵӵ�ǰ��ת�����ģ�����ĩβ��ʼ��Ҫ��ת�Ƶ���һ�����λ�ÿ�ʼ 
				for (int j = i - t; j < i; j ++) {
					dp1[sum + i] = (dp1[sum + i] + pre1[j][q - x] * dp1[max(sum + i - t - j, 0)]) % MOD;
				}
				dp1[sum + i] = (dp1[sum + i] + pre1[i][q - x] * dp[max(sum - t, 0)]) % MOD;
			}
			// ĩβ���κ�ĩβ��������� 
			dp[sum + i] = (dp[sum + i] + dp1[sum + i]) % MOD;
		}
		sum += q;
	}
	printf("%lld\n", dp[sum]);
	
	return 0;
}
