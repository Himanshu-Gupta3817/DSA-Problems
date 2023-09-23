#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i>1){
            cout<<i-1;
            for(int j=2;j<=i-1;j++){
                cout<<"0";
            }
            cout<<i-1;
        }
        else{
            cout<<"1";
        }
        cout<<endl;
    }
    return 0;
}
