//Implement Bubble Sort in a linked list using iterative methods

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

int LengthLL(node *head)
{
    int ans = 0;
    while (head != NULL)
    {
        head = head->next;
        ans++;
    }
    return ans;
}

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

void BubbleSortLL(node *&head)
{
    int len = LengthLL(head);
    for (int i = 0; i < len - 1; ++i)
    {
        node *c = head, *p = NULL;
        while (c != NULL and c->next != NULL)
        {
            node *n = c->next;
            if (c->data > n->data)
            {
                // swapping hogi
                if (p == NULL)
                {
                    c->next = n->next;
                    n->next = c;
                    p = head = n;
                }
                else
                {
                    c->next = n->next;
                    n->next = c;
                    p->next = n;
                    p = n;
                }
            }
            else
            {
                // swapping nhi hogi
                p = c;
                c = n;
            }
        }
    }
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
	node *head=NULL,*tail=NULL;
	int n,value;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>value;
		InsertAtEnd(head,tail,value);
	}
	BubbleSortLL(head);
    printLL(head);
	return 0;
}
