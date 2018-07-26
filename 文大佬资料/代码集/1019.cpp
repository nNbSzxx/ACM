#include<bits/stdc++.h> 
using  namespace std;
unsigned int ct,n;
int a[8],b[8]={1};
int get_count(int num){
	register int ct=0,tmp=num;	
	while(tmp){
		ct++;
		tmp=tmp/10;
	}
	ct--;
	return a[ct]+(num-b[ct]+1)*(ct+1);
}
 
int binary_search2(){
	 int l=0,r=40000;
	int ans=0;
	while(l<=r){
		 int mid=(l+r)>>1;
		if(get_count(mid)<n){
			ans=mid;
			l=mid+1;
		}
		else {
			r=mid-1;
		}
	}
	return ans;	
}
long long c[10101000],d[50500];

int binary_search1(){
	int l=0,r=40000;
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(c[mid]<n){
			ans=mid;
			l=mid+1;
		} 
		else r=mid-1;
	}
	return ans;	
}
 
int init(){
	register int i=0,j=0,k=1,lasti=1;
	while(c[i]/2<INT_MAX){
		i++;
		if(i==lasti*10){
			k++;lasti=i;
		}
		j+=k;
		c[i]=c[i-1]+j;
	}
	
	k=1,lasti=1;
	for(i=1;i<=40000;i++){
		if(i==lasti*10){
			k++;lasti=i;
		}
		d[i]=d[i-1]+k;
	}
	return 0;
}

int st[10];
int main(){
	init();
	long long tmp=9,tmp2=10;
	for(int i=1;i<=6;i++){
		a[i]=a[i-1]+tmp*i;
		b[i]=tmp2;
		tmp=tmp*10;tmp2=tmp2*10;
	}
	
	int T;
	cin>>T;
	
	while(T--){
		cin>>n;
		int tmp=binary_search1();//二分第几组12，123，1234，1235为不同组 
		n=n-c[tmp];
		tmp=binary_search2();//二分该组的第几个数1，2，3，4为不同数 
		n=n-d[tmp];
		tmp++;
		st[0]=0;
		while(tmp){
			st[++st[0]]=tmp%10;
			tmp=tmp/10;
		}//该数的第几位 
		
		printf("%d\n",st[st[0]-n+1]);
	}	
	return 0;
}
