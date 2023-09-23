#include<iostream>
using namespace std;
                            //odd in decreasing order and even in increasing order
void oddEven(int n)
{
	//base case
	if(n==0){
		return ;
	}

	//recursive case
	if(n%2!=0){
		cout<<n<<endl;
		oddEven(n-1);
	}
	else{
		oddEven(n-1);
		cout<<n<<endl;
	}
}

int main() {
	int number;
	cin>>number;

	oddEven(number);

	return 0;
}
