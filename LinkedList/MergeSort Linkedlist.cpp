/*Given a linked list, sort it using the merge sort algorithm.

Input Format
First line of input contains integer N,
denoting the size of the linked list.
Next line of input contains N space separated integers denoting the elements of the linked list.

Constraints
1<=N<=10^3

Output Format
Print the elements of the linked list after sorting.

Sample Input
5
5 4 3 2 1

Sample Output
1 2 3 4 5

Explanation
5 4 3 2 1 will become 1 2 3 4 5 after sorting.
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
node *mergeSortedLL(node *h1, node *h2)
{
    // Base Case
    if (h2 == NULL)
    {
        return h1;
    }
    if (h1 == NULL)
    {
        return h2;
    }

    // Recursive Case
    node *nH = NULL;
    if (h1->data < h2->data)
    {
        nH = h1;
        nH->next = mergeSortedLL(h1->next, h2);
    }
    else
    {
        nH = h2;
        nH->next = mergeSortedLL(h1, h2->next);
    }
    return nH;
}

node *midLL(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *slow = head;
    node *fast = head->next;

    while (fast and fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
node *mergeSort(node *head)
{
    // base case
    if (!head || !head->next)
    {
        return head;
    }

    // recursive case
    // 1.Divide LL
    node *m = midLL(head);
    node *a = head;
    node *b = m->next;
    m->next = NULL;

    // 2.Sort
    a = mergeSort(a);
    b = mergeSort(b);

    // 3.Merge
    node *nH = mergeSortedLL(a, b);
    return nH;
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
int main () {
	node*head=NULL,*tail=NULL;
    int n,value;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>value;
		InsertAtEnd(head,tail,value);
	}
	head=mergeSort(head);
	printLL(head);
	return 0;
}
