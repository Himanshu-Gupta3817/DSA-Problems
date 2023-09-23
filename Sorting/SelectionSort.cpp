#include<iostream>
using namespace std;

int main() {

	//Read
	int n,min;
	if(n>=0) cin>>n;

	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	//Sorting
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min]){
				min=j;
			}
		}
		swap(a[min],a[i]);
	}

	//Print
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}

	return 0;
}
