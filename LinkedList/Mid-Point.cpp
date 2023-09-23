/*
Find midpoint of a Linked List

Input Format
Enter the size N and N space separated elements

Constraints
None

Output Format
Mid node of the list

Sample Input
7
1 2 4 3 8 5 6
Sample Output
3
*/

#include<iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void InsertAtTail(node *&head, node *&tail, int d)
{
    if (head == NULL)
    {
        node *n = new node(d);
        head = tail = n;
    }
    else
    {
        node *n = new node(d);
        tail->next = n;
        tail = n;
    }
}
void midLL(node *head)
{
    if (head == NULL || head->next == NULL)
    {
    //    return head;
	cout<<head->data;
    }
    node *slow = head;
    node *fast = head->next;

    while (fast!=NULL && fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // return slow;
	cout<<slow->data;
}

int main() {
	 node*head=NULL,*tail=NULL;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
		int x;
        cin>>x;
        InsertAtTail(head,tail,x);
    }
//    head=midLL(head);
//    cout<<head;
   midLL(head);
	return 0;
}
