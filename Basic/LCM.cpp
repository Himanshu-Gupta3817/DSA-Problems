/*
Take the following as input.

A number (N1)
A number (N2)
Write a function which returns the LCM of N1 and N2. Print the value returned.

Input Format
Constraints
0 < N1 < 1000000000
0 < N2 < 1000000000

Output Format
Sample Input
4
6
Sample Output
12
Explanation
The smallest number that is divisible by both N1 and N2 is called the LCM of N1 and N2.
*/

#include <iostream>
using namespace std;
int main()
{
    // LCM ka way 1
    int no1, no2;
    cin >> no1 >> no2;
    int x = no2;
    while ((x % no1) != 0)
    {
        x = x + no2;
    }
    cout << x << endl;

    // int y = no1 * no2 / x;
    // cout << "GCD: " << y << endl;

    return 0;
}
