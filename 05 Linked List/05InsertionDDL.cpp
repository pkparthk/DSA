#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *ConvertArrayToDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
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

Node *InsertBeforeHead(Node*head, int val){
    Node *newHead = new Node(val, head, nullptr);
    head->back = newHead;
    newHead->next = head;
    return newHead;
}

Node *InsertAfterHead(Node*head, int val){
    Node *newNode = new Node(val, head->next, head);
    head->next = newNode;
    newNode->back = head;
    return head;
}

Node*InsertBeforeTail(Node*head, int val){
    if (head->next==NULL)
    {
        Node *newNode = new Node(val, head, nullptr);
        head->back = newNode;
        newNode->next = head;
        return newNode;
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *prev = tail->back;
    Node *newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

Node *InsertAfterTail(Node*head, int val){
    if (head->next==NULL){
        Node *newNode = new Node(val, head->next, nullptr);
        head->next = newNode;
        newNode->back = head;
        return head;
    }
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *newNode = new Node(val, tail->next, tail);
    tail->next = newNode;
    newNode->back = tail;
    return head;
}

Node*InsertBeforeK(Node*head, int k, int val){
    if (k==1)
    {
        return InsertBeforeHead(head, val);
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt==k)
        {
            break;
        }
        temp = temp->next;        
    }
    Node *prev = temp->back;
    Node *newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

Node* InsertAfterK(Node*head, int k, int val){
    if (k==1)
    {
        return InsertAfterHead(head, val);
    }
    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt==k)
        {
            break;
        }
        temp = temp->next;        
    }
    Node *newNode = new Node(val, temp->next, temp);
    temp->next = newNode;
    newNode->back = temp;
    return head;
}

Node*InsertBeforeGivenNode(Node*node, int val){
    Node *prev = node->back;
    Node *newNode = new Node(val, node, prev);
    prev->next = newNode;
    node->back = newNode;
}

Node*InsertAfterGivenNode(Node*node, int val){
    Node *newNode = new Node(val, node->next, node);
    node->next = newNode;
    newNode->back = node;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *head = ConvertArrayToDLL(arr);

    int val;
    cin >> val;
    
    // Insert Before Head
    // head = InsertBeforeHead(head, val);

    // Insert After Head
    // head = InsertAfterHead(head, val);

    // Insert Before Tail
    // head = InsertBeforeTail(head, val);

    // Insert After Tail
    // head = InsertAfterTail(head, val);

    // Kth Element
    // int k;
    // cin >> k;
    
    // Insert Before K    
    // head = InsertBeforeK(head, k, val);

    // Insert After K
    // head = InsertAfterK(head, k, val);

    // Given Node
    // InsertBeforeGivenNode(head->next, val);
    // InsertBeforeGivenNode(head->next->next, val);

    InsertAfterGivenNode(head->next, val);

    print(head);
    return 0;
}