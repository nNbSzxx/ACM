#include<iostream>
#include<cmath>
using namespace std;
const double PI=3.1415926;
int main(){

	int n;
	double area,year;
	cin>>n;
	for(int i=1;i<=n;i++){
		double x,y;
		cin>>x>>y;
		area = PI*(pow(x,2)+pow(y,2))/2;
		year = area/50.0;
		year = ceil(year);
  		cout<<"Property "<<i<<": This property will begin eroding in year "<<year<<"."<<endl;
	}

		cout<<"END OF OUTPUT."<<endl;	
	return 0;
}
