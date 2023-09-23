#include<iostream>
using namespace std;

int main() {
	int N;
	if( 0<=N<=10) cin>>N;
	if(N%2!=0){

		for(int row=1; row<=(N+1)/2; row++){
			if(row==1){
				for(int i=1; i<=N; i++){
					cout<<"*\t";
				}
			}
			else{
				//(1) (n+1)/2-row+1  *
				for(int i=1; i<=(N+1)/2-row+1; i++){
					cout<<"*\t";
				}

				//(2) 2*(row-1)-1 space
				for(int i=1; i<=2*(row-1)-1; i++){
					cout<<"\t";
				}

				//(3) (n+1)/2-row+1  *
				for(int i=1; i<=(N+1)/2-row+1; i++){
					cout<<"*\t";
				}
			}
			cout<<endl;
		}
		//Below
		for(int row=(N+1)/2-1; row>=1; row--){
			if(row==1){
				for(int i=1; i<=N; i++){
					cout<<"*\t";
				}
			}
			else{
				//(1) (n+1)/2-row+1  *
				for(int i=1; i<=(N+1)/2-row+1; i++){
					cout<<"*\t";
				}

				//(2) 2*(row-1)-1 space
				for(int i=1; i<=2*(row-1)-1; i++){
					cout<<"\t";
				}

				//(3) (n+1)/2-row+1  *
				for(int i=1; i<=(N+1)/2-row+1; i++){
					cout<<"*\t";
				}
			}
			cout<<endl;
		}
	}
	return 0;
}
