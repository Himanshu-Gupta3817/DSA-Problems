#include<iostream>
using namespace std;

int main() {
	int n;
	cin>>n;
	int k=0;
	for(int i=n;i>0;i--){
		int no=1;
		// for numbers
		for(int j=0;j<i;j++){
			cout<<no<<" ";
			no++;
		}
		// for stars
		for(int j=1;j<n-i+k;j++){
			cout<<"*"<<" ";
		}
		k++;
		cout<<endl;
	}
	return 0;
}
