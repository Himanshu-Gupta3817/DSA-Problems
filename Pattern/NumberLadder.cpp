#include<iostream>
using namespace std;

int main() {
	int n;
	if(0<n<100) cin>>n;
	int no=1;

	for(int row=0;row<n;row++){
		for(int i=0;i<=row;i++){
			cout<<no<<"		";
			no++;
		}
		cout<<endl;
	}
	return 0;
}
