//Given an array, the task is to calculate the sum of lengths of contiguous subarrays having all elements distinct
/*Sub arrays of length 1 are=>{1},{2},{3},{2},{3}. =>ans = ans+ 5*1.

Sub arrays of length 2 are=>{1,2},{2,3},{3,2},{2,3}. =>ans = ans+ 4*2.

Sub arrays of length 3 are=>{1,2,3},{2,3,2},{3,2,3}. =>ans = ans+ 1*3. We add only 1 subarray of length 3 because, out of 3 subarrays of length 3, only 1 is unique

Sub arrays of length 4 are=>{1,2,3,2},{2,3,2,3}. =>ans = ans+ 0*4. We add 0 because, all subarrays of length 4, have duplicate elements.

Sub arrays of length 5 are=>{1,2,3,2,3}. =>ans = ans+ 0*4. We add 0 because, all subarrays of length 5, have duplicate elements.

Hence the answer is=>5+8+3=>16*/


#include <iostream>
using namespace std;

int main()
{
    int mod = 1e9 + 7;
    int n;
    cin >> n;
    int a[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0, j = 0;
    int x, ans = 0;
    int freq[100000] = {0};
    while (i < n && j < n)
    {
        int no = a[j];
        if (freq[no] > 0)
        {
            while (freq[no] > 0)
            {
                freq[a[i]]--;
                i++;
            }
        }
        else
        {
            freq[no]++;
            x = j - i + 1;
            ans += (x % mod * (x + 1) % mod) / 2;
            ans %= mod;
            j++;
        }
    }

    cout << ans << endl;

return 0;
}
