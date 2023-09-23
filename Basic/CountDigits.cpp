#include<iostream>
using namespace std;

int count(int n,int digit)
{
	int cnt=0;
	while(n!=0){
		int dig=n%10;
		if(dig==digit){
			cnt++;
		}
		n/=10;
	}
	return cnt;
}

int main() {
	int number,digit;
	cin>>number;
	cin>>digit;

	int ans = count(number,digit);
	cout<<ans ;

	return 0;
}
