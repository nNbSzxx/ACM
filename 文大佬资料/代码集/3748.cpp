#include <bits/stdc++.h>//����ͷ�ļ� 
using namespace std;
int main(){
    int n,x,y;
    while(scanf("%x,%d,%d",&n,&x,&y)!=EOF){
      //%x Ϊ16���ƣ�%oΪ8���� 
	   bitset<32>q(n);//��ʼ�� 
   	   q.reset(x);
       q.set(y);
       q.set(y-1);
       q.reset(y-2);
       printf("%x\n",q.to_ulong());
    }
    return 0;
}
