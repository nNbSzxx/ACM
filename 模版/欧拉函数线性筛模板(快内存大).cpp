void init()
{
	memset(vis, 0, sizeof vis);
	phi[1] = 1;
	for (int i = 2; i < MAX; i ++) {
		if (!vis[i]) {
			prime[cnt ++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < cnt; j ++) {
			if (i * prime[j] >= MAX) break;
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = prime[j] * phi[i];
				break;
			} else {
				phi[i * prime[j]] = (prime[j] - 1) * phi[i];
			}
		}
	}
}

