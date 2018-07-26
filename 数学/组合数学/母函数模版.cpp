#include <iostream>  
using namespace std;  
// Author: Tanky Woo  
// www.wutianqi.com  
const int _max = 10001;   
// c1�Ǳ�������������������ϵ���Ŀ  
// c2���м���������ÿһ�ε����  
int c1[_max], c2[_max];     
int main()  
{   //int n,i,j,k;  
    int nNum;   //   
    int i, j, k;  
  
    while(cin >> nNum)  
    {  
        for(i=0; i<=nNum; ++i)   // ---- ��  
        {  
            c1[i] = 1;  
            c2[i] = 0;  
        }  
        for(i=2; i<=nNum; ++i)   // ----- ��  
        {  
  
            for(j=0; j<=nNum; ++j)   // ----- ��  
                for(k=0; k+j<=nNum; k+=i)  // ---- ��  
                {  
                    c2[j+k] += c1[j];  
                }  
            for(j=0; j<=nNum; ++j)     // ---- ��  
            {  
                c1[j] = c2[j];  
                c2[j] = 0;  
            }  
        }  
        cout << c1[nNum] << endl;  
    }  
    return 0;  
}  

//��  �����ȶ�c1��ʼ�����ɵ�һ�����ʽ(1+x+x^2+..x^n)��ʼ������������0��n���������붼��ʼ��Ϊ1.
//��  �� i��2��n����������i����ָ��i�����ʽ����������ĵڶ���ĸ������ϵʽ�ÿһ�������������ľ���һ�����ʽ��
//�ۡ�j ��0��n����������j����(ǰ��i�����ʽ�۳˵ı��ʽ)���j��������(�����лһ��seagg���Ѹ���ָ���Ĵ��󣬴�ҿ��Կ������Դ�������)����(1+x)(1+x^2)(1+x^3)��j��ָʾ����1��x��ϵ����i=2ִ����֮���Ϊ
//
//��1+x+x^2+x^3��(1+x^3)����ʱ��jӦ��ָʾ���Ǻϲ���ĵ�һ�����ŵ��ĸ�������ϵ����
//�� �� k��ʾ���ǵ�j��ָ��������kÿ����i����Ϊ��i�����ʽ��������i����
//��  ����c2��ֵ����c1,����c2��ʼ��Ϊ0����Ϊc2ÿ���Ǵ�һ�����ʽ�п�ʼ�ġ�



//aΪ��������bΪ�м�����  
//v�������������Ȩ����n1������ʹ�õ���������n2�����ʹ�õ������� 
int a[MAX],b[MAX];  
//��ʼ��a  
memset(a,0,sizeof(a));  
a[0]=1;  
for (int i=1;i<=17;i++)//ѭ��ÿ������  
{  
    memset(b,0,sizeof(b));  
    for (int j=n1[i];j<=n2[i]&&j*v[i]<=P;j++)//ѭ��ÿ�����ӵ�ÿһ��  
        for (int k=0;k+j*v[i]<=P;k++)//ѭ��a��ÿ����  
            b[k+j*v[i]]+=a[k];//�ѽ���ӵ���Ӧλ  
    memcpy(a,b,sizeof(b));//b��ֵ��a  
}  

//��ʼ��a����Ϊ��last���������������ʼ������λ  
a[0]=1;  
int last=0;  
for (int i=0;i<K;i++)  
{  
    int last2=min(last+n[i]*v[i],P);//������һ�ε�last  
    memset(b,0,sizeof(int)*(last2+1));//ֻ���b[0..last2]  
    for (int j=n1[i];j<=n2[i]&&j*v[i]<=last2;j++)//������last2  
        for (int k=0;k<=last&&k+j*v[i]<=last2;k++)//����һ����last��һ����last2  
            b[k+j*v[i]]+=a[k];  
    memcpy(a,b,sizeof(int)*(last2+1));//b��ֵ��a��ֻ��ֵ0..last2  
    last=last2;//����last  
}  

int a[MAX], b[MAX];
a[0] = 1;
for (int i = 1; i <= N; i ++) {
	memset(b, 0, sizeof(b));
	for (int j = n1[i]; j <= n2[i] && j <= P; j ++) {
		for (int k = 0; k + j * v[i] <= P; k ++) {
			b[k + j * v[i]] += a[k];
		}
	}
} 


