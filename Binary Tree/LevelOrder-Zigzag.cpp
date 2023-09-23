/*Given a binary tree. Print the zig zag order i.e print level 1 from left to right,
level 2 from right to left and so on. This means odd levels should get printed from left to right and even levels should be printed from right to left.

Input Format
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints
None

Output Format
Display the values in zigzag level order in which each value is separated by a space

Sample Input
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output
10 30 20 40 50 60 73
*/

#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node{
	public:
	string data;
	Node* left;
	Node* right;

	Node(string d){
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};

Node*buildtree()
{
    string str;
    cin>>str;
    if(str=="false")
    {
           return NULL;
    }
    if(str=="true")
    {
         string d;
         cin>>d;
         Node*root=new Node(d);
        root->left=buildtree();
        root->right=buildtree();
        return root;
    }
    Node*root=new Node(str);
        root->left=buildtree();
        root->right=buildtree();
       return root;
}

void zigzagTraversal(Node* root){
	if(root==NULL){
		return;
	}

	stack<Node*> currLevel;
	stack<Node*> nextLevel;

	bool leftToRight=true;

	currLevel.push(root);

	while(!currLevel.empty()){
		Node* temp=currLevel.top();
		currLevel.pop();

		if(temp){
			cout<<temp->data<<" ";

			if(leftToRight){
				if(temp->left){
					nextLevel.push(temp->left);
				}
				if(temp->right){
					nextLevel.push(temp->right);
				}
			}
			else{
				if(temp->right){
					nextLevel.push(temp->right);
				}
				if(temp->left){
					nextLevel.push(temp->left);
				}
			}
		}
		if(currLevel.empty()){
			leftToRight=!leftToRight;
			swap(currLevel,nextLevel);
		}
	}
}

int main() {
	Node*root=buildtree();
	zigzagTraversal(root);
	cout<<endl;
	return 0;
}
