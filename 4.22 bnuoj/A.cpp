#include <cstdio>
using namespace std;
int main() {
    //freopen("in.txt","r",stdin);
    int T,n,mmin,a,b;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        mmin=0x3F3F3F3F;
        for (int i=1; i<n; i++) {
            scanf("%d%d",&a,&b);
            if (a+b<mmin) mmin=a+b;
        }
        printf("%d\n",mmin);
    }
    return 0;
}
