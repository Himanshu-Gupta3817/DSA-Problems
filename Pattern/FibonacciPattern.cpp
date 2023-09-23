#include<iostream>
using namespace std;

int main() {
	int n;
	if(0<n<100) cin>>n;
	int no1=-1, no2=1;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int no3=no1+no2;
			no1=no2;
			no2=no3;
			cout<<no3<<"	";
		}
		cout<<endl;
	}
	return 0;
}
