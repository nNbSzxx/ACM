#include<iostream>
using namespace std;

int n[7];  //价值为i的物品的个数
int SumValue;  //物品总价值
int HalfValue;  //物品平分价值
bool flag;    //标记是否能平分SumValue

void DFS(int value,int pre){
    if(flag)return;

    if(value==HalfValue){
        flag=true;
        return;
    }

    for(int i=pre;i>=1;i--){
        if(n[i]){
            if(value+i<=HalfValue){
                n[i]--;
                DFS(value+i,i);
                n[i]++;
                if(flag)
                    break;
            }
        }
    }
    return;
}
int b[7]={1,60,30,20,15,12,10};
int main(){
    int test=1;
    while(cin>>n[1]>>n[2]>>n[3]>>n[4]>>n[5]>>n[6]){
    	int i;
        SumValue=0;  

        for(i=1;i<=6;i++){
			n[i]=n[i]%b[i]; 
            SumValue+=i*n[i];
		}
        if(SumValue==0)
            break;

        if(SumValue%2){
            cout<<"Collection #"<<test++<<':'<<endl;
            cout<<"Can't be divided."<<endl<<endl;    
            continue;
        }

        HalfValue=SumValue/2;
        flag=false;

        DFS(0,6);

        if(flag){
            cout<<"Collection #"<<test++<<':'<<endl;
            cout<<"Can be divided."<<endl<<endl;
            continue;
        }
        else{
            cout<<"Collection #"<<test++<<':'<<endl;
            cout<<"Can't be divided."<<endl<<endl;
            continue;
        }
    }
    return 0;
}
