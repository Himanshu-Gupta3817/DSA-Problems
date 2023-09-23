#include<iostream>
using namespace std;

int main()
{
	int n,num,i;
	bool isPrime;
	cin>>num;

	for(n=2;n<=num;n++){
		isPrime=true;
		for(i=2;i<n;i++){
			if(n%i==0){
				isPrime=false;
			}
		}

		if(isPrime==true){
			cout<<n<<endl;
		}
	}
	return 0;
}
