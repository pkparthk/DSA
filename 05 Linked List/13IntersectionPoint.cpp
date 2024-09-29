#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data1, Node *next1)
        {
            data = data1;
            next = next1;
        }
        Node(int data1)
        {
            data = data1;
            next = nullptr;
        }
};

void insertNode(Node*&head, int val){
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Better Solution

// Node *IntersectionPoint(Node *head1, Node *head2){
//     while (head2!=NULL)
//     {
//         Node *temp = head1;
//         while (temp!=NULL)
//         {
//             if (temp == head2)
//             {
//                 return head2;
//             }
//             temp = temp->next;
//         }
//     }
//     return NULL;    
// }

// Time Complexity : O(n * m)
// Space Complexity: O(n)


// Optimized Solution

Node *IntersectionPoint(Node *head1, Node *head2){
    if (head1==NULL || head2==NULL)
    {
        return NULL;
    }
    Node *temp1 = head1;
    Node *temp2 = head2;
    while (temp1!=temp2)
    {
        temp1 = temp1==NULL ? head2 : temp1->next;
        temp2 = temp2==NULL ? head1 : temp2->next;
    }
    return temp1;
}

// Time Complexity : O(n + m)
// Space Complexity: O(1)

int main()
{
    // creation of both lists
    Node *head = NULL;
    int n, m;
    cout << "Enter the number of nodes in the first linked list: ";
    cin >> n;
    cout << "Enter the number of nodes in the second linked list: ";
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        insertNode(head, val);
    }
    Node *head1 = head;
    head = head->next->next->next;
    Node *headSec = NULL;
    for (int i = 0; i < m; i++)
    {
        int val;
        cin >> val;
        insertNode(headSec, val);
    }
    Node *head2 = headSec;
    headSec->next = head;

    // printing of the lists
    cout << "List1: ";
    print(head1);
    cout << "List2: ";
    print(head2);
    // checking if intersection is present
    Node *answerNode = IntersectionPoint (head1, head2);
    if (answerNode == NULL)
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->data << endl;
    return 0;
}