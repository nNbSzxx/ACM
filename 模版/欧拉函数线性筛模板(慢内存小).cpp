void init()
{
	memset(phi, 0, sizeof phi);
	phi[1] = 1;
	for (int i = 2; i < MAX; i ++) {
		if (!phi[i]) {
			phi[i] = i - 1;
			for (int j = 2 * i; j < MAX; j += i) {
				if (!phi[j])
					phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

