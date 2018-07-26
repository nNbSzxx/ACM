#include <iostream>
#include <stdio.h>
using namespace std;
long long F[1000100];
int phi[1000100];
int phi_table(int n){
    for(int i=2;i<=n;i++)phi[i]=0;
    phi[1]=1;
    for(int i=2;i<=n;i++){
        if(phi[i]) continue;
        for(int j=i;j<=n;j+=i){
            if(!phi[j])phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
    }
    return 0;
}
int main(){
    int n;
    F[1]=0;
    phi_table(1000000);
    for(int i=2;i<=1000000;i++)
		F[i] = F[i-1]+phi[i];
    while(scanf("%d",&n)&&n!=0){
        cout<<F[n]<<endl;
    }
    return 0;
}

