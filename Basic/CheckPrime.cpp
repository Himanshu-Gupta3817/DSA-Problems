#include<iostream>
using namespace std;

bool isPrimeNumber(int no){
	bool isPrime = true;
	for(int i=2; i<no; i++){
		if(no%i==0){
			isPrime=false;
			break;
		}
	}
	return isPrime;
}

int main() {

	int n;
	if(2<n) cin>>n;

	int ans=isPrimeNumber(n);

	if(ans==true){
		cout<<"Prime";
	}
	else{
		cout<<"Not Prime";
	}

	return 0;
}
