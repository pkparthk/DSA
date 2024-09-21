#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* ConvertArrToLL(vector<int> &arr){
    if (arr.empty())
    {
        return nullptr;
    }    
    Node *head= new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;        
    }
    return head;    
}

void print(Node* head){
    while (head !=NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;    
}

Node* removeHead(Node *head){
    if (head==NULL)
    {
        return head;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;    
}

Node* removeTail(Node *head){
    if (head== NULL || head->next==NULL)
    {
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next!=NULL)
    {
        temp = temp -> next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node* RemoveByK(Node* head, int k){
    if (head==NULL)
    {
        return head;
    }
    if (k==1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node *temp = head;
    Node *prev = NULL;
    while (temp!=NULL)
    {
        cnt++;
        if (cnt==k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *RemoveByElem(Node *head, int ele){
    if (head==NULL)
    {
        return head;
    }
    if (head->data==ele)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;        
    }
    Node *temp = head;
    Node *prev = NULL;
    while (temp!=NULL)
    {
        if (temp->data==ele)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *head = ConvertArrToLL(arr);
    
    
    // head = removeHead(head);       // Remove head

    // head = removeTail(head);     // Remove tail

    // Remove By Key
    // int k;
    // cin >> k;
    // head = RemoveByK(head, k);
    // print(head);


    // Remove By Element
    int ele;    
    cin >> ele;
    head = RemoveByElem(head, ele);
    print(head);
    return 0;
}