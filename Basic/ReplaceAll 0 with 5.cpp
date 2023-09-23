#include<iostream>
using namespace std;

int reverse(int n)
{
	int digit,ans=0;
		while(n!=0){
		digit=n%10;
		if(digit==0){
			digit=5;
		}
		ans=ans*10+digit;
		n/=10;
	}
	return ans;
}

int main () {
	int n;
	cin>>n;
	int a=reverse(n);
	int b=reverse(a);
	cout<<b;

	return 0;
}
