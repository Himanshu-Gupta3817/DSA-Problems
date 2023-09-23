//Given an array nums of length n. We define a running sum of an array as for every index runningSum[i] = sum(nums[0]…nums[i]).

//Return the running sum of array for each i (0 <= i < n).


#include <iostream>
using namespace std;
int main() {
   int n;
   cin>>n;

   int a[n];

   for(int i=0;i<n;i++){
       cin>>a[i];
   }

   int sum=0;

   for(int i=0;i<n;i++){
       sum+=a[i];
       cout<<sum<<" ";
   }

   return 0;
}
