#include <iostream>  
using namespace std;  
// Author: Tanky Woo  
// www.wutianqi.com  
const int _max = 10001;   
// c1是保存各项质量砝码可以组合的数目  
// c2是中间量，保存每一次的情况  
int c1[_max], c2[_max];     
int main()  
{   //int n,i,j,k;  
    int nNum;   //   
    int i, j, k;  
  
    while(cin >> nNum)  
    {  
        for(i=0; i<=nNum; ++i)   // ---- ①  
        {  
            c1[i] = 1;  
            c2[i] = 0;  
        }  
        for(i=2; i<=nNum; ++i)   // ----- ②  
        {  
  
            for(j=0; j<=nNum; ++j)   // ----- ③  
                for(k=0; k+j<=nNum; k+=i)  // ---- ④  
                {  
                    c2[j+k] += c1[j];  
                }  
            for(j=0; j<=nNum; ++j)     // ---- ⑤  
            {  
                c1[j] = c2[j];  
                c2[j] = 0;  
            }  
        }  
        cout << c1[nNum] << endl;  
    }  
    return 0;  
}  

//①  、首先对c1初始化，由第一个表达式(1+x+x^2+..x^n)初始化，把质量从0到n的所有砝码都初始化为1.
//②  、 i从2到n遍历，这里i就是指第i个表达式，上面给出的第二种母函数关系式里，每一个括号括起来的就是一个表达式。
//③、j 从0到n遍历，这里j就是(前面i個表达式累乘的表达式)里第j个变量，(这里感谢一下seagg朋友给我指出的错误，大家可以看下留言处的讨论)。如(1+x)(1+x^2)(1+x^3)，j先指示的是1和x的系数，i=2执行完之后变为
//
//（1+x+x^2+x^3）(1+x^3)，这时候j应该指示的是合并后的第一个括号的四个变量的系数。
//④ 、 k表示的是第j个指数，所以k每次增i（因为第i个表达式的增量是i）。
//⑤  、把c2的值赋给c1,而把c2初始化为0，因为c2每次是从一个表达式中开始的。



//a为计算结果，b为中间结果。  
//v是砝码的重量（权），n1是最少使用的砝码数，n2是最多使用的砝码数 
int a[MAX],b[MAX];  
//初始化a  
memset(a,0,sizeof(a));  
a[0]=1;  
for (int i=1;i<=17;i++)//循环每个因子  
{  
    memset(b,0,sizeof(b));  
    for (int j=n1[i];j<=n2[i]&&j*v[i]<=P;j++)//循环每个因子的每一项  
        for (int k=0;k+j*v[i]<=P;k++)//循环a的每个项  
            b[k+j*v[i]]+=a[k];//把结果加到对应位  
    memcpy(a,b,sizeof(b));//b赋值给a  
}  

//初始化a，因为有last，所以这里无需初始化其他位  
a[0]=1;  
int last=0;  
for (int i=0;i<K;i++)  
{  
    int last2=min(last+n[i]*v[i],P);//计算下一次的last  
    memset(b,0,sizeof(int)*(last2+1));//只清空b[0..last2]  
    for (int j=n1[i];j<=n2[i]&&j*v[i]<=last2;j++)//这里是last2  
        for (int k=0;k<=last&&k+j*v[i]<=last2;k++)//这里一个是last，一个是last2  
            b[k+j*v[i]]+=a[k];  
    memcpy(a,b,sizeof(int)*(last2+1));//b赋值给a，只赋值0..last2  
    last=last2;//更新last  
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


