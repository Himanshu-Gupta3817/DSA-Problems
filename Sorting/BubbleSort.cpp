#include<iostream>
using namespace std;

int main () {

	int a[100000],n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<=n-2-i;j++){
			if(a[j]>a[j+1]){
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
