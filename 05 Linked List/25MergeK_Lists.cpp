#include<bits/stdc++.h>
using namespace std;

class Node
{
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

Node *merge(vector<Node *> &listArray){
    priority_queue<pair<int, Node *>, vector<pair<int, Node *>>, greater<pair<int, Node *>>> pq;
    for (int i = 0; i < listArray.size(); i++)
    {
        if(listArray[i]){
            pq.push({listArray[i]->data, listArray[i]});
        }
    }
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        if (it.second->next)
        {
            pq.push({it.second->next->data, it.second->next});
        }
        temp->next = it.second;
        temp = temp->next;
    }
    return dummy->next;
}


int main()
{
    vector<Node *> listArray;
    listArray.push_back(new Node(1, new Node(4, new Node(5))));
    listArray.push_back(new Node(1, new Node(3, new Node(4))));
    listArray.push_back(new Node(2, new Node(6)));    
    Node *head = merge(listArray);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}