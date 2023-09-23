#include<iostream>
using namespace std;
                            //swap array with index
int main() {
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int b[100];
	for(int i=0;i<n;i++){
		int index=a[i];
		b[index]=i;
	}
	for(int i=0;i<n;i++){
		cout<<b[i]<< " ";
	}
	return 0;
}
