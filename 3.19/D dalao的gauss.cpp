#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int M=2;
int m,n,d,lena;
int a[630][630];
int gcd(int a,int b) {
    if (b==0) return a;
    else return gcd(b,a%b);
}
int lcm(int a,int b) {
    return a/gcd(a,b)*b;
}
int Gauss(int equ,int var) {
    int k,col;
    for (k=0,col=0; k<equ && col<var; k++,col++) {
        int max_r=k;
        for (int i=k+1; i<equ; i++)
            if (abs(a[i][col])>abs(a[max_r][col]))
                max_r=i;
        if (max_r!=k) {
            for (int i=k; i<=var; i++)
                swap(a[k][i],a[max_r][i]);
        }
        if (a[k][col]==0) {
            k--;
            continue;
        }
        for (int i=k+1; i<equ; i++)
        if (a[i][col]!=0) {
            int LCM=lcm(abs(a[i][col]),abs(a[k][col]));
            int ta=LCM/abs(a[i][col]);
            int tb=LCM/abs(a[k][col]);
            if (a[i][col]*a[k][col]<0) tb=-tb;
            for (int j=col; j<=var; j++)
                a[i][j]=((a[i][j]*ta-a[k][j]*tb)%M+M)%M;
        }
    }
    for (int i=k; i<equ; i++)
        if (a[i][col]!=0) return -1;
    return var-k;
}
bool judge(int x1,int y1,int x2,int y2) {
    if (x1==x2 && y1==y2) return true;
    if (abs(x1-x2)+abs(y1-y2)==d) return true;
    return false;
}
inline int solve() {
    memset(a,0,sizeof(a));
    lena=n*m;
    int id;
    for (int i=0; i<n; i++)
    for (int j=0; j<m; j++)
        scanf("%d",&a[i*m+j][lena]);
    for (int i=0; i<n; i++)
    for (int j=0; j<m; j++) {
        id=i*m+j;
        for (int ii=0; ii<n; ii++)
        for (int jj=0; jj<m; jj++)
            if (judge(i,j,ii,jj))
                a[id][ii*m+jj]=1;
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    while (~scanf("%d%d%d",&m,&n,&d)) {
        if (m==0 && n==0 && d==0) break;
        solve();
        for (int i = 0; i < lena; i ++) {
			for (int j = 0; j <= lena; j ++) {
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
        if (Gauss(lena,lena)==-1) printf("0\n");
            else printf("1\n");
        for (int i = 0; i < lena; i ++) {
			for (int j = 0; j <= lena; j ++) {
				printf("%d ",a[i][j]);
			}
			printf("\n");
		}
		printf("\n");
    }
    return 0;
}

