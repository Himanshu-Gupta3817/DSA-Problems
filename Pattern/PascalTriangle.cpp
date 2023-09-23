#include<iostream>
using namespace std;

int main(){
    int n;
    int pt,nt;
    if(0<=n<=30) cin>>n;

    for(int i=0;i<n;i++){
        pt=1;
        cout<<"1"<<" ";
        for(int j=1;j<=i;j++){
            nt = pt*(i-j+1) / j;
            cout<<nt<<" ";
            pt=nt;
        }
        cout<<endl;
    }

    return 0;
}
