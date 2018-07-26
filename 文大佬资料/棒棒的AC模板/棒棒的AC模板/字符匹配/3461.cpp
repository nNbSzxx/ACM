#include<bits/stdc++.h>
using namespace std;
int next[10010];
char  p[10010];
char s[1000010];
int slen,plen;
int get_next(){
  int i=0,j=-1;
  next[0]=-1;
  while(i<plen){
    if(j==-1||p[j]==p[i]){
      next[i+1]=j+1;
      i++;j++;
    }
    else
    j=next[j];
  }
  return 0;
}
int kmp(){  
  int ans=0;
  int i=0,j=0;
  while(i<slen&&j<plen){
    if(s[i]==p[j]||j==-1)
    {
      i++;j++;
    }
    else
    j=next[j];
    if(j>=plen){
        ans++;
        j=next[j];
    }
  }
  return ans;
}
int main(){
  	int N;
	scanf("%d",&N);
  	while(N--){
        scanf("%s",p);
        scanf("%s",s);
        plen=strlen(p);
        slen=strlen(s);
    	get_next();
    	printf("%d\n",kmp());
  	}
	return 0;
}
