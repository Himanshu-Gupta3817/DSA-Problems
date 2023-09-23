//Reverse a linked list by changing the data of its nodes in an iterative manner

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
void reverseLL(node *&head, node *&tail)
{
    node *c = head;
    node *p = NULL;

    while (c != NULL)
    {
        node *n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    swap(head, tail);
}
void printLL(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    //cout << "NULL\n";
}
int main() {
	node *head = NULL, *tail = NULL;
	int n,value;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>value;
		InsertAtEnd(head,tail,value);
	}
	reverseLL(head, tail);
	printLL(head);
	return 0;
}
