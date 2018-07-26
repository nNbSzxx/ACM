#include<bits/stdc++.h>
using namespace std;

int cg(char ch){
	if(ch>='0'&&ch<='9') return ch-'0';
    if(ch=='A' || ch=='B' || ch=='C')
        return 2;
    if(ch=='D' || ch=='E' || ch=='F')
        return 3;
    if(ch=='G' || ch=='H' || ch=='I')
        return 4;
    if(ch=='J' || ch=='K' || ch=='L')
        return 5;
    if(ch=='M' || ch=='N' || ch=='O')
        return 6;
    if(ch=='P' || ch=='R' || ch=='S')
        return 7;
    if(ch=='T' || ch=='U' || ch=='V')
        return 8;
    if(ch=='W' || ch=='X' || ch=='Y')
        return 9;
}
char C[220];
int a[12345678];
int b[10];
int prin(int num){
	for(register int i=1;i<=7;i++){
		b[i]=num%10;
		num=num/10;
	}
	for(register int i=7;i>=5;i--) printf("%d",b[i]);
	printf("-");
	for(register int i=4;i>=1;i--) printf("%d",b[i]);
	return 0;
}
int main(){
	int T;
	scanf("%d",&T); 
	while(T--){
		scanf("%s",C);
		int ans=0;
		for(register int i=1;i<=strlen(C);i++){
			if(C[i-1]!='-'&&C[i-1]!='Q'&&C[i-1]!='Z')ans=ans*10+cg(C[i-1]);		
		}
		a[ans]++;
	}
		int flag=0;
		for(register int i=0;i<=9999999;i++){
			if(a[i]>=2){
				flag=1;
				prin(i); printf(" %d\n",a[i]); 
			}
		}
		if(!flag)puts("No duplicates.");
	
	return 0;
}
