#include <bits/stdc++.h>//万能头文件 
using namespace std;
int main(){
    int n,x,y;
    while(scanf("%x,%d,%d",&n,&x,&y)!=EOF){
      //%x 为16进制，%o为8进制 
	   bitset<32>q(n);//初始化 
   	   q.reset(x);
       q.set(y);
       q.set(y-1);
       q.reset(y-2);
       printf("%x\n",q.to_ulong());
    }
    return 0;
}
