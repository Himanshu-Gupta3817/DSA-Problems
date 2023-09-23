/*Given a binary tree. Print the level order traversal, make sure each level start at a new line.

Input Format
Enter the values of all the nodes in the binary tree in pre-order format where true suggest the node exists and false suggests it is NULL

Constraints
None

Output Format
Print the level order in which the different levels are in different lines, all the values should be in a space separated manner

Sample Input
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output
10
20 30
40 50 60 73
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

Node*buildtree()
{
        int d;
        cin>>d;
        Node*root=new Node(d);

        string l;
        cin>>l;

        if(l=="true")
            root->left=buildtree();
        else
            root->left=NULL;
        cin>>l;
        if(l=="true")
            root->right=buildtree();
        else
         root->right=NULL;
        return root;
    }

void printLevelOrderTraversal(Node *root){
	//base case
	if(root==NULL) return;
	//recursive case
	queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node *node=q.front();
		q.pop();
		if(node!=NULL){
			cout<<node->data<<" ";
			if( node->left) q.push(node->left);
			if(node->right) q.push(node->right);
		}
		else if(!q.empty()){
			q.push(NULL);
			cout<<endl;
		}
	}
}
int main(){
	Node*root=NULL;

    root=buildtree();

	printLevelOrderTraversal(root);
	return 0;
}
