#include<iostream>
using namespace std;

int main() {
	int n;
	if(1<=n<10){
		cin>>n;
	}

	for(int i=0;i<n;i++){
		int no=1;
		//for numbers
		for(int j=0;j<=i;j++){
			cout<<no;
			no++;
		}
		//for stars
		for(int j=n-i-1;j>0;j--){
			cout<<"*";
		}
		cout<<endl;
	}
	return 0;
}
