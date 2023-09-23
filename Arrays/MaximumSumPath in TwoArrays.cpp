/*You are provided two sorted arrays.
You need to find the maximum length of bitonic subsequence.
You need to find the sum of the maximum sum path to reach from beginning of any array to end of any of the two arrays.
You can switch from one array to another array only at common elements.
*/

#include<iostream>
using namespace std;

int main() {
	int tc;
	cin>>tc;

	while(tc--){
		int a[100000],b[100000];

	int n,m;
	cin>>n>>m;


	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int j=0;j<m;j++){
		cin>>b[j];
	}

	int i=0;
	int j=0;
	int sum1=0,sum2=0;
	int res=0;
	while(i<n && j<m)
	{
		if(a[i]==b[j])
		{
			res+=(sum1>sum2)?sum1:sum2;
			sum1=sum2=0;
			res=res+a[i];
			i++;
			j++;
		}
		else
		{
			if(a[i]>b[j])
			{
				sum2=sum2+b[j++];
			}
			else
			{
				sum1=sum1+a[i++];
			}
		}
	}


	while(i<n)
		sum1=sum1+a[i++];

	while(j<m)
		sum2=sum2+b[j++];

	if(sum1>sum2){
		res=res+sum1;
	}
	else{
		res=res+sum2;
	}
	cout<<res<<endl;
}
	return 0;
}
