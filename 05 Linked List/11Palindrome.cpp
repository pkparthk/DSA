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

Node *ConvertArrToLL(vector<int> &arr)
{
    if (arr.empty())
    {
        return nullptr;
    }
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
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

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return true;
    }
    stack<int> st;
    Node *temp = head;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL)
    {
        if (temp->data != st.top())
        {
            return false;
        }
        st.pop();
        temp = temp->next;
    }
    return true;
}


// Optimised 

Node*reverse(Node*head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *prev = NULL;
    Node *temp = head;
    while (temp!=NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;        
    }
    return prev;
}

bool isPalindromeByTortoiseAndHareAlgo(Node*head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node *slow = head;
    Node *fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newHead = reverse(slow->next);
    Node *first = head;
    Node *second = newHead;
    while (second!=NULL)
    {
        if(first->data!=second->data){
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverse(newHead);
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *head = ConvertArrToLL(arr);
    // cout << isPalindrome(head) << endl;

    cout<<isPalindromeByTortoiseAndHareAlgo(head)<<endl;
    return 0;
}