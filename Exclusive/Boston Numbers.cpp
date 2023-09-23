/*
A Boston number is a composite number,
the sum of whose digits is the sum of the digits of its prime factors
 obtained as a result of prime factorization (excluding 1 ).
 The first few such numbers are 4,22 ,27 ,58 ,85 ,94 and 121 .
 For example, 378 = 2 × 3 × 3 × 3 × 7 is a Boston number since 3 + 7 + 8 = 2 + 3 + 3 + 3 + 7.
 Write a program to check whether a given integer is a Boston number.

Input Format
There will be only one line of input:N , the number which needs to be checked.

Constraints
1 < N < 2,147,483,647 (max value of an integer of the size of 4 bytes)

Output Format
1 if the number is a Boston number. 0 if the number is a not Boston number.

Sample Input
378
Sample Output
1
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int n;
	cin >> n;

	int no = n;

	// Finding the sum of digits
	int sum_d = 0;
	while (n > 0) {

		int digit = n % 10;
		sum_d += digit;
		n /= 10;
	}


	// Finding the sum of prime factors
	n = no;
	int sum = 0;
	while (n % 2 == 0) {
		sum += 2;
		n /= 2;
	}
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		while (n % i == 0) {
			// Add the value of i to the sum, also break the i into single
			// digits if i contains digits more than 2 in itself
			int x = i;
			while (x > 0) {
				sum += x % 10;
				x /= 10;
			}

			n /= i;
		}
	}

	if (n > 0) {
		while (n > 0) {
			sum += n % 10;
			n /= 10;
		}
	}

	if (sum == sum_d) {
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}

	return 0;
}
