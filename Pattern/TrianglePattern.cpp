#include<iostream>
using namespace std;

int main() {
	int n;
	if(0<n<10) cin>>n;
	int no=1;

	for(int row=0;row<n;row++){
		//for spaces
		for(int i=n-row-1;i>0;i--){
			cout<<"		";
		}

		//for numbers
		for(int j=0;j<=2*row;j++){
			if(j<=row){
				cout<<no<<"		";
			}
			else{
				no=no-2;
				cout<<no<<"		";
			}
			no++;
		}
		cout<<endl;
	}

	return 0;
}
