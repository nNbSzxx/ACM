#include<bits/stdc++.h> 
using namespace std;

int a[123][123]; 
int tmp[123]; 
int tmp2[123];
int ans;

int merger(int left,int right){
	if(left==right) return 0;
	int mid=(left+right)/2;
	merger(left,mid);
	merger(mid+1,right);
	int l=left,r=mid+1;
	for(int i=0;i<=(right-left);i++){
		//printf("%d %d %d %d\n",l,r,tmp2[l],tmp2[r]);
		if(l==mid+1||tmp2[r]<tmp2[l]&&r<=right) {
			tmp[i]=tmp2[r++];
			ans=ans+mid+1-l;
		}
		else if(r==right+1||tmp2[l]<tmp2[r]&&l<=mid){
			tmp[i]=tmp2[l++];
		}
		else {
			tmp[i]=tmp2[l++];
		}
		//printf("%d\n",tmp[i]);
	}
	//printf("left&RIGHT %d %d\n",left,right);
	for(int i=left;i<=right;i++){
		tmp2[i]=tmp[i-left];
		//printf("%d ",tmp[i-left]);
	}
	//puts("");
	return 0;
}

char s[123];

struct ct{
	int val,num;
}p[123];
 
bool cmp( ct A,ct B){
	return A.val<B.val;
}

int main(){
	int n,m;

	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>s;
		for(int j=0;j<n;j++){
			a[i][j+1]=s[j];
		}
	}
	//printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++) tmp2[j]=a[i][j];
		ans=0;
		merger(1,n);
		p[i].val=ans;p[i].num=i; 
	}
	sort(p+1,p+1+m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%c",a[p[i].num][j]);
		}
		puts("");
	}
	return 0;
}
