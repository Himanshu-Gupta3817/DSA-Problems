#include<iostream>
using namespace std;

int main () {
	int n;
	cin>>n;

	for(int row=0;row<n;row++){
		for(int i=0;i<row;i++){
			cout<<" ";
		}
		for(int j=0;j<n-row;j++){
			cout<<"*"<<" ";
		}
		cout<<endl;
	}
	return 0;
}
