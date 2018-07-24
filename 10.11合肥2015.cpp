#include<bits/stdc++.h>
using namespace std;
int f(int x,int  y){
	//printf("%d %d ", x, y)
    ; int c=0;
     while(y){
          c +=1;
          int t = x % y;
          x = y;
          y = t;
      }
      return c;
      //printf("cc %d\n", c);
      return c * x * x;
}

int main(){
	int k = 10;
	int ans = 0;
	for (int j = 1; j <= 666; j ++) {
		// int ans = 0;
		printf(j % k == 0 ? "%d\n":"%d ",f(j, k) );
		f(j, k); 
		for (int i = 1; i <= k; i ++) {
			// ans += i * j / f(j, k);
			// printf(i % (j * 2) == 0? "%-3d\n" : "%-3d ", i * j / f(i, j));
		}
		//printf(j % k == 0? "%d\n" : "%d ", ans);
}
	return 0;
}

