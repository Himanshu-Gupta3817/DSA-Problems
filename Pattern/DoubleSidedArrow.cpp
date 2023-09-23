#include<iostream>
using namespace std;

int main() {
	int N;
	cin>>N;
	if(N%2!=0){

		for(int row=1;row<=(N+1)/2;row++){
			//(1) (n+1)-2*row Spaces
			for(int i=1;i<=(N+1)-(2*row);i++){
				cout<<"  ";
			}

			//(2) row * no
			for(int j=row;j>=1;j--){
				cout<<j<<" ";
			}
			if(row==1){
				cout<<endl;
				continue;
			}

			//(3) 2*(row-1)-1 Spaces
			for(int i=1;i<=2*(row-1)-1;i++){
				cout<<"  ";
			}

			//(4)row * no
			for(int j=1;j<=row;j++){
				cout<<j<<" ";
			}

			cout<<endl;
		}

		//below

		for(int row=(N+1)/2-1; row>=1; row--){

			//(1) (n+1)-2*row spaces
			for(int i=1; i<=(N+1)-2*row; i++){
				cout<<"  ";
			}

			//(2) row * no
			for(int j=row; j>=1; j--){
				cout<<j<<" ";
			}
			if(row==1){
				cout<<endl;
				continue;
			}

			//(3) 2*(row-1)-1 spaces
			for(int i=1; i<=2*(row-1)-1; i++){
				cout<<"  ";
			}

			//(4) row * no
			for(int j=1; j<=row; j++){
				cout<<j<<" ";
			}

			cout<<endl;
		}
	}
	return 0;
}
