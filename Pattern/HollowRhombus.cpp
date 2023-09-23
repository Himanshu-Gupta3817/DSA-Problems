#include<iostream>
using namespace std;

int main() {
	int n;
	if(0<n<=20) cin>>n;

	for(int row=0;row<n;row++){
		//for spaces
		for(int i=n-row-1;i>0;i--){
			cout<<" ";
		}
		//for solid stars
		if(row==0 || row==n-1){
			for(int j=0;j<n;j++){
				cout<<"*";
			}
		}
		//for hollow stars
		else{
			for(int j=0;j<n;j++){
				if(j==0 || j==n-1){
					cout<<"*";
				}
				else{
					cout<<" ";
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
