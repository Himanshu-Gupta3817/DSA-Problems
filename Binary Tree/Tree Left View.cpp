/*Given a binary tree , print its nodes from root to bottom as visible from left side of tree

Input Format
Level order input for the binary tree will be given.

Constraints
No of nodes in the tree can be less than or equal to 10^7

Output Format
A single line containing space separated integers representing the left view of the tree

Sample Input
1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
Sample Output
1 2 4
Explanation
The tree looks like

             1
          /      \
       2           3
    /     \           \
   4       5           6
When viewed from the left , we would see the nodes 1,2 and 4.
*/

#include<iostream>
#include<queue>
using namespace std;

class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int d){
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};

Node* buildTree(){
	queue<Node*>q;
	int data;
	cin>>data;
	Node*  root=new Node(data);
	q.push(root);
	while(!q.empty()){
		Node* temp=q.front();
		q.pop();
		int l,r;
		cin>>l>>r;
		if(l!=-1){
			temp->left=new Node(l);
			q.push(temp->left);
		}
		if(r!=-1){
			temp->right=new Node(r);
			q.push(temp->right);
		}
	}
	return root;
}

void leftView(Node* root){
	if(root==NULL){
		return;
	}

	queue<Node*>q;
	q.push(root);

	while(!q.empty()){
		//no. of nodes in a current level
		int n=q.size();
		for(int i=1;i<=n;i++){
			Node* temp=q.front();
			q.pop();

			if(i==1){
				cout<<temp->data<<" ";
			}
			if(temp->left!=NULL){
				q.push(temp->left);
			}
			if(temp->right!=NULL){
				q.push(temp->right);
			}
		}
	}
}

int main() {
	Node* root=buildTree();
	leftView(root);
	return 0;
}
