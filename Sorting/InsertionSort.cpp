#include<iostream>
using namespace std;

int main() {

	int n,i,j,HPC;
	if(1<=n<=1000) cin>>n;

	int a[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}

	//Sorting
	for(i=1;i<n;i++){
		HPC=a[i];
		for(j=i-1; j>=0 && a[j]>HPC; j--){
			a[j+1]=a[j];
		}
		a[j+1]=HPC;
	}

	//Print
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}

	return 0;
}
