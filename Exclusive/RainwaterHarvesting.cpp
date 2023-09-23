#include<iostream>
using namespace std;

int main() {

	int n;
	cin>>n;
	int a[n];

	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	int left_max[n]={0};
	int right_max[n]={0};

	for(int i=1;i<n;i++){
		left_max[i]=max(a[i-1],left_max[i-1]);
	}

	//printing left max
	// for(int i=0;i<n;i++){
	// 	cout<<left_max[i]<<" ";
	// }
	// cout<<endl;

	for(int i=n-2;i>=0;i--){
		right_max[i]=max(a[i+1],right_max[i+1]);
	}

	//printing right max
	// for(int i=0;i<n;i++){
	// 	cout<<right_max[i]<<" ";
	// }
	// cout<<endl;

	int ans=0;
	for(int i=0;i<n;i++){
		int res=min(left_max[i],right_max[i])-a[i];
		if(res>0){
			ans+=res;
		}
	}
	cout<<ans<<endl;

	return 0;
}
