#include<bits/stdc++.h>
using namespace std;


// using Coupe of Queue

// Approach 1

// class Queue {
//     stack<int> s1, s2;
//     public:
//     void push(int x){
//         while (!s1.empty())
//         {
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s1.push(x);
//         while (!s2.empty())
//         {
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }

//     int pop(){
//         if (s1.empty())
//         {
//             return 0;
//         }
//         int n = s1.top();
//         s1.pop();
//         return n;
//     }

//     int Top(){
//         if (s1.empty())
//         {
//             return 0;
//         }
//         return s1.top();
//     }

//     int Size(){
//         return s1.size();
//     }
// };


// Approch 2
class Queue {
    stack<int> s1, s2;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s2.empty()){
            while (!s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }                        
        }
        int n = s2.top();
        s2.pop();
        return n;
    }

    int Top(){
        if (s2.empty())
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }                    
        }
        return s2.top();        
    }

    int Size(){
        return s1.size() + s2.size();
    }
};

int main()
{
    Queue q;
    q.push(6);
    q.push(3);
    q.push(7);
    cout << "Top of stack is before deleting any element" << q.Top() << endl;
    cout << "Size of stack before deleting any element " << q.Size() << endl;
    q.pop();
    cout << "Top of stack is after deleting one element" << q.Top() << endl;
    cout << "Size of stack after deleting one element " << q.Size() << endl;
    return 0;
}



// class Queue{
//     int *arr;
//     int start, end, currSize, maxSize;
//     public:
//     Queue(){
//         arr = new int[16];
//         start = -1;
//         end = -1;
//         currSize = 0;
//     }
//     Queue(int maxSize){
//         (*this).maxSize = maxSize;
//         arr = new int[maxSize];
//         start = -1;
//         end = -1;
//         currSize = 0;
//     }
//     void push( int newElement){
//         if (currSize == maxSize)
//         {
//             cout << "Queue is Full\n Exiting..." << endl;
//             exit(1);
//         }
//         if (end==-1)
//         {
//             start = 0;
//             end = 0;            
//         }
//         else
//         {
//             end = (end + 1) % maxSize;
//         }
//         arr[end] = newElement;
//         cout << "The Element pushed is" << newElement << endl;
//         currSize++;
//     }
//     int pop(){
//         if (start==-1)
//         {
//             cout << "Queue is Empty\n Exiting..." << endl;            
//         }
//         int x = arr[start];
//         if (currSize==1)
//         {
//             start = -1;
//             end = -1;
//         }
//         else
//         {
//             start = (start + 1) % maxSize;
//         }
//         currSize--;
//         return x;               
//     }
//     int Top(){
//         if (start==-1)
//         {
//             cout << "Queue is Empty" << endl;
//             exit(-1);
//         }
//         return arr[start];
//     }
//     int Size(){
//         return currSize;
//     }
// };

// int main()
// {
//     Queue q(6);
//     q.push(4);
//     q.push(14);
//     q.push(24);
//     q.push(34);
//     cout << "The peek of the queue before deleting any element " << q.Top() << endl;
//     cout << "The size of the queue before deletion " << q.Size() << endl;
//     cout << "The first element to be deleted " << q.pop() << endl;
//     cout << "The peek of the queue after deleting an element " << q.Top() << endl;
//     cout << "The size of the queue after deleting an element " << q.Size() << endl;
//     return 0;
// }



// Using Linked List

// class Node{
//     public:
//         int val;
//         Node *next;
//         Node(int data){
//             val = data;
//             next = nullptr;
//         }
// };

// Node *Front = nullptr;
// Node *Rear = nullptr;

// class Queue{
//     public:
//         int size = 0;
//         bool Empty();
//         void Enqueue(int value);
//         void Dequeue();
//         int peak();
// };
// bool Queue :: Empty(){
//     return Front = nullptr;    
// }

// int Queue :: peak(){
//     if(Front == nullptr){
//         cout << "Queue is Empty" << endl;
//         return -1;        
//     }
//     else
//     {
//         return Front->val;        
//     }        
// }

// void Queue :: Enqueue(int value){
//     Node *temp;
//     temp = new Node(value);
//     if (temp==NULL)
//     {
//         cout << "Queue is Full" << endl;
//         return;        
//     }
//     else
//     {
//         if (Front==nullptr)
//         {
//             Front = temp;
//             Rear = temp;
//         }
//         else
//         {
//             Rear->next = temp;
//             Rear = temp;
//         }                
//         size++;                
//     }        
// }

// void Queue :: Dequeue(){
//     Node *temp;
//     if (Front==nullptr)
//     {
//         cout << "Queue is Empty" << endl;
//         return;        
//     }
//     else
//     {
//         temp = Front;
//         Front = Front->next;
//         delete temp;
//         size--;        
//     }        
// }

// int main()
// {
//     Queue q;
//     q.Enqueue(4);
//     q.Enqueue(14);
//     q.Enqueue(24);
//     q.Enqueue(34);
//     cout << "The peek of the queue before deleting any element " << q.peak() << endl;
//     cout << "The size of the queue before deletion " << q.size << endl;
//     q.Dequeue();
//     cout << "The peek of the queue after deleting an element " << q.peak() << endl;
//     cout << "The size of the queue after deleting an element " << q.size << endl;
//     return 0;
// }