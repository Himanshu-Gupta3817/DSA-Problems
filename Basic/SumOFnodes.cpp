/*Given a binary tree find sum of all the nodes.

Input Format
Enter the value of the node then the Boolean choice i.e
whether the node has a left child , then enter the left child's data .
The input acts in a recursive manner i.e when the left child's children are made only then we move onto the parent's right child

Constraints
None

Output Format
Display the sum of all the nodes

Sample Input
50 true 25 true 12 false false false true 75 true 62 false false false
Sample Output
224

Explanation
If we enter the following values

50 true 25 true 12 false false false true 75 true 62 false false false

the tree would look like :

25 => 50 <= 75
12 => 25 <= END
END => 12 <= END

62 => 75 <= END
END => 62 <= END
*/

#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

// node* buildtree(){
// 	int d;
// 	cin>>d;
// 	node* root=new node(d);

// 	string l;
// 	cin>>l;

// 	if(l=="true")
// 		root->left=buildtree();
// 	else
// 		root->left=NULL;

// 	cin>>l;
// 	if(l=="true")
// 		root->left=buildtree();
// 	else
// 		root->right=NULL;
// 		return root;
// }

void buildTree(node* &root){
	string left,right;
	int d;
	cin>>d;
	root = new node(d);
	cin>>left;
	if(left == "true"){
		buildTree(root->left);
	}
	cin>>right;
	if(right == "true"){
		buildTree(root->right);
	}
}

int sumNodes(node *root){
	if(root==NULL) {return 0;}
	return (sumNodes(root->left)+sumNodes(root->right)+root->data);
}

int main() {
	node* root=NULL;
	buildTree(root);
	cout<<sumNodes(root);
	return 0;
}
