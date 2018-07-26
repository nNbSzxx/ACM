#include<bits/stdc++.h> 
using namespace std;
#define LL long long
int m,n;
const int mod=9973;
struct matrix{
    int f[11][11];
};
int euler_phi(int x){
    int p=(int)sqrt(x+0.5);
    int ans=x,i;
    for(i=2;i<=p;i++)
        if(x%i==0){
            ans=ans/i*(i-1);
            while(x%i==0)x/=i;
        }
    if(x>1)ans=ans/x*(x-1);
    return ans%mod;// ע��mod����Ȼ�ᱬint
}
matrix mul(matrix a,matrix b){
    int i,j,k;
    matrix c;
    memset(c.f,0,sizeof(c.f));
    for(k=1;k<=m;k++){
        for(i=1;i<=m;i++){
            if(!a.f[i][k])continue;
            for(j=1;j<=m;j++){
                if(!b.f[k][j])continue;
                c.f[i][j]=(c.f[i][j]+a.f[i][k]*b.f[j][k])%mod;
            }
        }
    }
    return c;
}
matrix pow_mod(matrix a,int b){
    matrix s;
    memset(s.f,0,sizeof(s.f));
    for(int i=1;i<=m;i++)
        s.f[i][i]=1;
    while(b){
        if(b&1)
            s=mul(s,a);
        a=mul(a,a);
        b=b>>1;
    }
    return s;
}
int solve(matrix e,int x){
    e=pow_mod(e,x);
    int i,ans=0;
    for(i=1;i<=m;i++)
        ans=(ans+e.f[i][i])%mod;
    return ans;
}
int pows(int a,int b){
    int s=1;
    while(b){
        if(b&1)
            s=(s*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return s;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int i,j,k,a,b,ans=0;
        cin>>n>>m>>k;
        matrix e;
        for(i=1;i<=m;i++)
            for(j=1;j<=m;j++)
            e.f[i][j]=1;
        for(i=0;i<k;i++){
            cin>>a>>b;
            e.f[a][b]=e.f[b][a]=0;
        }
        for(i=1;i*i<=n;i++){
            if(n%i==0){
                if(i*i==n)
                    ans=(ans+euler_phi(i)*solve(e,i))%mod;
                else
                    ans=(ans+euler_phi(i)*solve(e,n/i)+euler_phi(n/i)*solve(e,i))%mod;
            }
        }
        cout<<ans*pows(n%mod,mod-2)%mod<<endl;//pows��ע����n%mod
    }
    return 0;
}
/*
    ��������ŷ���������û���Burnside����;����������
    
    ŷ������euler_phi(x)������ǲ�����x����x���ʵ�����������
    Burnside��������һ���û�f����һ����ɫ����s�����û��󲻱䣬��sΪf�Ĳ����㡣��f�Ĳ���������ΪC(f)��
�����֤���ȼ�����ĿΪ����C(f)��ƽ��ֵ��
    ����
        f[i][j]=1��ʾ��ɫi�ĺ�����Խ���ɫj����f[i][j]=0��ʾ���С��õ�����A
        A^k�֡�f[i][i]��ʾ��Ϊk�ķ���Ҫ��ķ���������Ϊ�����ɻ�����һ���͵�k+1����ͬ
    sovle(k)��ʾ����Ϊk�������ķ�����
    
    ���������û��������ֻ�ÿ�����ת���ÿ��Ƿ�ת��������˳ʱ����ת1~n����n�֡�
    ������תi�����ӣ������p[i]=gcd(i,n)��ѭ����ÿ��ѭ������n/gcd(i,n);
    �Ҳ����㣬�����û������λ�õ���ɫ����ͬ�����Ե�j�����Ӻ͵�j+p[i]�����ӵ���ɫ��ͬ������ÿp��������ɫ�ظ�һ�Σ�
���ֻҪ���p[i]�����ӳ��������ж����ַ�����������תi�����ӵĲ�������

    ����������ans=��solve(p[i]),����n�ɴ�1e9�����Բ���ֱ����,����p[i]=gcd(i,n)������p[i]ֻ����n�����ӡ�
    ö�����ӣ�����ÿ������q���ܹ���euler_phi(n/q)��������n������n�����Լ����q��
��Ϊֻ�е�k<=n/q,��k��n/q���ʵ�����£�gcd(k*q,n)=q;
    ���ans=��euler_phi(n/q)*slove(q)(qΪn������)
    
    �𰸾���(ans/n)%mod<-->ans*n^(mod-2)%mod(modΪ����),���������ģ�˷�������֤��������ֱ�ӵ���������
*/
