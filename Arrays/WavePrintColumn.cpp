#include<iostream>
using namespace std;

int main() {
	int M,N;
	int a[10][10];
	cin>>M>>N;
	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){		//array input
			cin>>a[i][j];
		}
	}

	for(int j=0;j<N;j++){
		if(j%2==0){
			for(int i=0;i<M;i++){		//even col
				cout<<a[i][j]<<", ";
			}
		}

		else{
			for(int i=M-1;i>=0;i--){		//odd col
				cout<<a[i][j]<<", ";
			}
		}
	}

	cout<<"END";
	return 0;
}
