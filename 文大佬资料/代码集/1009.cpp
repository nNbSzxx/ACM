#include<bits/stdc++.h> 

using namespace std;
int n,m;
//1 2 3
//4 5 6
//7 8 9 
int a[1234],b[1234];
int c;
struct P{
	int val,nub;
}ANS[123456];
bool cmp(struct P X,struct P Y){
	return X.nub<Y.nub;
}

int find1(int num){
	if(num%m==1) return 0;
	if((num-1)/m==0) return 0;
	return num-m-1;
}
int find2(int num){
	if((num-1)/m==0) return 0;
	return num-m;
}
int find3(int num){
	if(num%m==0) return 0;
	if((num-1)/m==0) return 0;
	return num-m+1;
}
int find4(int num){
	if(num%m==1) return 0;
	return num-1;
}
int find6(int num){
	if(num%m==0) return 0;
	return num+1;
}
int find7(int num){
	if(num>b[n]-m) return 0;
	if(num%m==1) return 0;
	return num+m-1;
}

int find8(int num){
	if(num>b[n]-m) return 0;
	return num+m;
}

int find9(int num){
	if(num>b[n]-m) return 0;
	if(num%m==0) return 0;
	return num+m+1;
}

int div(int num,int left,int right){
	int mid=(left+right)>>1;
	if(b[mid-1]<num&&b[mid]>=num) return a[mid];
	if(b[mid]<num) return div(num,mid+1,right);
	else return div(num,left,mid-1);
}
int work(int num){
	if(num==0) return 0;
	int ans=0;
	if(find1(num)!=0) ans=max(ans,abs(div(find1(num),1,n)-div(num,1,n)));
	if(find2(num)!=0) ans=max(ans,abs(div(find2(num),1,n)-div(num,1,n)));
	if(find3(num)!=0) ans=max(ans,abs(div(find3(num),1,n)-div(num,1,n)));
	if(find4(num)!=0) ans=max(ans,abs(div(find4(num),1,n)-div(num,1,n)));
	if(find6(num)!=0) ans=max(ans,abs(div(find6(num),1,n)-div(num,1,n)));
	if(find7(num)!=0) ans=max(ans,abs(div(find7(num),1,n)-div(num,1,n)));
	if(find8(num)!=0) ans=max(ans,abs(div(find8(num),1,n)-div(num,1,n)));
	if(find9(num)!=0) ans=max(ans,abs(div(find9(num),1,n)-div(num,1,n)));

	c++;
	ANS[c].nub=num;
	ANS[c].val=ans;
	return 0;
}
int ouput[123456][2]; 
int get_first(int num){
	if(num%m==1) return num+m;
	else if(num%m==0) return num+m+1;
	else return num/m*m+1;
}
int main(){
	//freopen("A.txt","r",stdin);
	//freopen("A.out","w",stdout);
	while(cin>>m){
		if(m==0) break;
		n=0;c=0;
		int x,y;
		
		while(1){
			n++;
			cin>>x>>y;
			a[n]=x;
			b[n]=b[n-1]+y;
			if(x==0&&y==0){
				n--;
				break;
			}
			/*if(y>=2*m){
			printf("ABC%d\n",get_first(b[n-1]+1));
			work(get_first(b[n-1]+1));
			}*/
		}
		for(int i=1;i<=n;i++){
			if(b[i]-b[i-1]>2*m){
				//printf("AAA\n",get)
			work(get_first(b[i-1]+1));
			}
		}
		for(int i=1;i<=n;i++){
			int t=b[i-1]+1;
			work(t);
			if(find1(t)) work(find1(t));
			if(find2(t)) work(find2(t));
			if(find3(t)) work(find3(t));
			if(find4(t)) work(find4(t));
			if(find6(t)) work(find6(t));
			if(find7(t)) work(find7(t));
			if(find8(t)) work(find8(t));
			if(find9(t)) work(find9(t));
			
		}
		sort(1+ANS,1+ANS+c,cmp);
		int last=-1,cnt=0,pre=0;
		
		c++;
		ANS[c].nub=b[n]+1;
		ANS[c].val=-2;
		for(int i=1;i<=c;i++){
			 if(ANS[i].val==last) continue;
			 //printf("NUMNER%d %d\n",ANS[i].val,ANS[i].nub);
			 
			 cnt++;
			 last=ANS[i].val;
			 ouput[cnt][0]=last;
			 ouput[cnt][1]=ANS[i].nub-pre;
			 pre=ANS[i].nub;
		}
		printf("%d\n",m);
		for(int i=1;i<cnt;i++){
			printf("%d %d\n",ouput[i][0],ouput[i+1][1]);
		}
		printf("0 0\n");
	}
	printf("0\n");
	return 0;
}

