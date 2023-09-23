#include<iostream>
using namespace std;

int main () {
	int n;
	cin>>n;

	for(int row=n;row>0;row--){
		for(int i=0;i<row-1;i++){
			cout<<" "<<" ";
		}
		for(int j=0;j<=n-row;j++){
			cout<<"*"<<" ";
		}
		cout<<endl;
	}
	return 0;
}
