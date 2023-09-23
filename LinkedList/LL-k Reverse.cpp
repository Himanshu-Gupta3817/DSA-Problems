/*Given a head to Linked List L, write a function to reverse the list taking k elements at a time. Assume k is a factor of the size of List.

You need not have to create a new list. Just reverse the old one using head.

Input Format
The first line contains 2 space separated integers N and K

The next line contains N space separated integral elements of the list.

Constraints
0 <= N <= 10^6 0 <= K <= 10^6

Output Format
Display the linkedlist after reversing every k elements

Sample Input
9 3
9 4 1 7 8 3 2 6 5
Sample Output
1 4 9 3 8 7 5 6 2
Explanation
N = 9 & K = 3

Original LL is : 9 -> 4 -> 1 -> 7 -> 8 -> 3 -> 2 -> 6 -> 5

After k Reverse : 1 -> 4 -> 9 -> 3 -> 8 -> 7 -> 5 -> 6 -> 2
*/

#include<iostream>
using namespace std;

class node{
	public:
	int data;
	node* next;

	node(int d){
		data=d;
		next=NULL;
	}
};

void InsertAtEnd(node *&head, node *&tail, int data)
{
    if (head == NULL)
    {
        head = tail = new node(data);
    }
    else
    {
        node *n = new node(data);
        tail->next = n;
        tail = n;
    }
}

node* RevKLL(node* head,int k){
	//Base Case
	if(head==NULL){
		return NULL;
	}

	//1.Reverse First k node
	node* next=NULL;
	node* curr=head;
	node* prev=NULL;
	int count=0;

	while(curr!=NULL and count<k){
		next=curr->next;
		curr->next = prev;
		prev=curr;
		curr=next;
		count++;
	}

	//2.Recursion dekh lega
	if(next!=NULL){
	head->next=RevKLL(next,k);
	}

	//3.return prev
	return prev;
}


void display(node* head){
	node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	// cout<<"NULL"<<endl;
}

int main() {
	node* head=NULL,*tail=NULL;
	int n,k,value;
	cin>>n>>k;

	for(int i=1;i<=n;++i){
		cin>>value;
		InsertAtEnd(head,tail,value);
	}

	head=RevKLL(head,k);
	display(head);
	return 0;
}
