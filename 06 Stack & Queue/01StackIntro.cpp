#include<bits/stdc++.h>
using namespace std;

// Using Double Queue


//Steps :-

//  For  push(x)
// 1.  Add to Queue2
// 2.  Add Queue1 to Queue2(element by element)
// 3.  Swap Queue1 and Queue2

// For pop
// 1.  Remove the front element of Queue1



class Stack{
    queue<int> q1;
    queue<int> q2;

    public:
    void push(int x){
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop(){
        int n = q1.front();
        q1.pop();
        return n;
    }

    int Top(){
        return q1.front();
    }

    int Size(){
        return q1.size();
    }
};

int main()
{
    Stack s;
    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack is before deleting any element" << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    s.pop();
    cout << "Top of stack is after deleting one element" << s.Top() << endl;
    cout << "Size of stack after deleting one element " << s.Size() << endl;
    return 0;
}



// Using Single Queue

// class Stack
// {
//     queue<int> q;

// public:
//     void push(int x)
//     {
//         int s = q.size();
//         q.push(x);
//         for (int i = 0; i < s; i++)
//         {
//             q.push(q.front());
//             q.pop();
//         }
//     }

//     int pop(){
//         int n = q.front();
//         q.pop();
//         return n;
//     }
//     int Top(){
//         return q.front();
//     }
//     int Size(){
//         return q.size();
//     }
// };


// int main()
// {
//     Stack s;
//     s.push(6);
//     s.push(3);
//     s.push(7);
//     cout << "Top of stack is before deleting any element" << s.Top() << endl;
//     cout << "Size of stack before deleting any element " << s.Size() << endl;
//     s.pop();
//     cout << "Top of stack is after deleting one element" << s.Top() << endl;
//     cout << "Size of stack after deleting one element " << s.Size() << endl;
//     return 0;
// }




// Using Array

// class Stack{
//     int size;
//     int *arr;
//     int top;
//     public:
//         Stack(){
//             top = -1;
//             size = 1000;
//             arr = new int[size];
//         }
//         void push(int x){
//             top++;
//             arr[top] = x;
//         }
//         int pop(){
//             int x = arr[top];
//             top--;
//             return x;
//         }
//         int Top(){
//             return arr[top];
//         }
//         int Size(){
//             return top + 1;
//         }
// };

// int main()
// {
//     Stack s;
//     s.push(6);
//     s.push(3);
//     s.push(7);
//     cout << "Top of stack is before deleting any element" << s.Top() << endl;
//     cout << "Size of stack before deleting any element " << s.Size() << endl;
//     s.pop();
//     cout << "Top of stack is after deleting one element" << s.Top() << endl;
//     cout << "Size of stack after deleting one element " << s.Size() << endl;
//     return 0;
// }

// Using Linked List

// struct Node{
//     int data;
//     Node *next;
//     int size;
//     Node(int d){
//         data = d;
//         next = NULL;
//     }
// };
// struct Stack
// {
//     Node *top;
//     int size;
//     Stack(){
//         top = NULL;
//         size = 0;
//     }
//     void push(int x){
//         Node *element = new Node(x);
//         element->next = top;
//         top = element;
//         size++;
//     }
//     int pop(){
//         if (top==NULL)
//         {
//             return -1;
//         }
//         int topData = top->data;
//         Node *temp = top;
//         top = top->next;
//         delete temp;
//         size--;
//         return topData;
//     }
//     int Size(){
//         return size;
//     }
//     bool isEmpty(){
//         return top == NULL;
//     }
//     int isFull(){
//         if (top == NULL)
//         {
//             return -1;
//         }
//         return top->data;
//     }
//     void printStack(){
//         Node *current = top;
//         while (current!=NULL)
//         {
//             cout << current->data << " ";
//             current = current->next;
//         }
//     }
// };

// int main()
// {
//     Stack ss;
//     ss.push(6);
//     cout << "Element popped: " << ss.pop() << "\n";
//     cout << "Stack size: " << ss.Size() << "\n";
//     cout << "Stack empty or not? " << ss.isEmpty() << "\n";
//     cout << "stack'ss top element: " << ss.isFull() << "\n";
//     return 0;
// }
