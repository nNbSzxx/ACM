#include<bits/stdc++.h> 
using namespace std;
long long  t;
long long extend_gcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	long long ans=extend_gcd(b,a%b,x,y);
	long long tmp=x;
	x=y;
	y=tmp-a/b*y;
	return ans;
}


int main(){
	long long b1, b2, c1, c2, m10, m20, c;
	int n;
	while (scanf("%d", &n) != EOF){
		bool flag = false;
		scanf("%lld %lld", &b1, &c1);
		for (int i = 1; i < n; i++){
			long long x,y;
			scanf("%lld %lld", &b2, &c2);
			if (flag) continue;
			int g=extend_gcd(b1, b2,x,y);//��Ϊ���������ǳ������ʣ����Գ��Թ�Լ��ʹ���以��
			c = c2 - c1;//k1*b1 == (c2 - c1) (mod b2)
			if (c % g){
				flag = true;
				continue;
			}
			m20 = b2 / g;//���Ϊ�µ�mod�������������µ�b1����
			c /= g;
			long long r0 = (c * x % m20 + m20) % m20;
			c1 = r0 * b1 + c1;
			b1 = b1 * m20;//�õ���ʽ�ӵ�ϵ���� b1 * x + c1 == c2 ����x = c1, c2...(mod b1, b2)
		}
		if (flag) puts("-1");
		else printf("%lld\n", c1);
	}
	return 0;
}
