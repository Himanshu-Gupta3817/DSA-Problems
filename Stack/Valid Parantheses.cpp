/*Given a string str containing just the character ‘(‘ , ’)’ , ’{‘ , ’}’ , ’[‘ , ’]’.
Determine if the input string is valid or not.
A string is valid if open brackets must be closed by the same type of brackets and open brackets must be closed in the correct order.

Input Format
First and only line of input contains a string.

Constraints
1<=str.length<=10^4

Output Format
Print true if string is balanced, otherwise print false.

Sample Input
()
)[]
Sample Output
True
False
Explanation
Testcase 1: "()" is a balanced string(String with equal number of opening and closing matched brackets.).
Testcase 2:")[]" is not a balanced string.
*/


#include<iostream>
#include<stack>
using namespace std;
bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '['){
                st.push(s[i]);
            }
            else{
                if(s[i] == ')' && !st.empty() && st.top() == '('){
                    st.pop();
                }
                else if(s[i] == '}'  && !st.empty()  && st.top() == '{'){
                    st.pop();
                }
                else if(s[i] == ']' && !st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
  return false;
                }
            }
        }

        if(st.empty()){
            return true;
        }
        return false;
}

void printIt(string s){
	if(isValid(s)){
		cout << "true"<<endl;
	}
	else{
		cout << "false" << endl;
	}
}
int main () {
	string str;
	// int i;
	// cin >> i;
	// bool check = true;
	// while(true){
		cin >> str;
		printIt(str);
	// Â }
}
