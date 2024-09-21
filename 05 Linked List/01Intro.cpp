// Linked List is Not have Contigious memory allocation
// Linked List is a data structure that contains a sequence of elements such that each element links to its next element in the sequence.
// Each element in a linked list is called a node. Each node contains two components: data and a reference (or link) to the next node in the sequence.
// The last node in the sequence contains a reference to null.
// The first node in the sequence is called the head node.
// The last node in the sequence is called the tail node.
// The time complexity of inserting or deleting an element in a linked list is O(1).
// The time complexity of searching for an element in a linked list is O(n).
// The space complexity of a linked list is O(n).
//
// Types of Linked List
// Singly Linked List
// Doubly Linked List
// Circular Linked List
//
// Singly Linked List
// A singly linked list is a data structure that contains a sequence of elements such that each element links to its next element in the sequence.
// Each element in a singly linked list is called a node. Each node contains two components: data and a reference (or link) to the next node in the sequence.
// The last node in the sequence contains a reference to null.
// The first node in the sequence is called the head node.
// The time complexity of inserting or deleting an element in a singly linked list is O(1).
// The time complexity of searching for an element in a singly linked list is O(n).
// The space complexity of a singly linked list is O(n).
//
// Doubly Linked List
// A doubly linked list is a data structure that contains a sequence of elements such that each element links to its next element and its previous element in the sequence.
// Each element in a doubly linked list is called a node. Each node contains three components: data, a reference (or link) to the next node in the sequence, and a reference (or link) to the previous node in the sequence.
// The first node in the sequence is called the head node.
// The last node in the sequence is called the tail node.
// The time complexity of inserting or deleting an element in a doubly linked list is O(1).
// The time complexity of searching for an element in a doubly linked list is O(n).
// The space complexity of a doubly linked list is O(n).
//
// Circular Linked List
// A circular linked list is a data structure that contains a sequence of elements such that each element links to its next element in the sequence.
// The last node in the sequence contains a reference to the first node in the sequence.
// The time complexity of inserting or deleting an element in a circular linked list is O(1).
// The time complexity of searching for an element in a circular linked list is O(n).
// The space complexity of a circular linked list is O(n).
//
// Implementing a Singly Linked List
// To implement a singly linked list, we need to define a structure for the nodes and a class for the linked list.
// The structure for the nodes contains two components: data and a pointer to the next node.
// The class for the linked list contains a pointer to the head node and methods to insert, delete, and search for elements in the linked list.
// The time complexity of inserting or deleting an element in a singly linked list is O(1).
// The time complexity of searching for an element in a singly linked list is O(n).
// The space complexity of a singly linked list is O(n).
//
// Implementing a Doubly Linked List
// To implement a doubly linked list, we need to define a structure for the nodes and a class for the linked list.
// The structure for the nodes contains three components: data, a pointer to the next node, and a pointer to the previous node.
// The class for the linked list contains pointers to the head node and the tail node, and methods to insert, delete, and search for elements in the linked list.
// The time complexity of inserting or deleting an element in a doubly linked list is O(1).
// The time complexity of searching for an element in a doubly linked list is O(n).
// The space complexity of a doubly linked list is O(n).
//
// Implementing a Circular Linked List
// To implement a circular linked list, we need to define a structure for the nodes and a class for the linked list.
// The structure for the nodes contains two components: data and a pointer to the next node.
// The class for the linked list contains a pointer to the head node and methods to insert, delete, and search for elements in the linked list.
// The time complexity of inserting or deleting an element in a circular linked list is O(1).
// The time complexity of searching for an element in a circular linked list is O(n).
// The space complexity of a circular linked list is O(n).
//
// Applications of Linked Lists
// Linked lists are used in many applications, including:
// Implementing stacks and queues
// Implementing hash tables
// Implementing graphs
// Implementing memory management systems
// Implementing file systems
// Implementing database systems
// Implementing operating systems
// Implementing web browsers
// Implementing text editors
// Implementing spreadsheets
// Implementing word processors
// Implementing image editors
// Implementing video editors
// Implementing audio editors
// Implementing games
// Implementing simulations
// Implementing artificial intelligence systems
// Implementing machine learning systems
// Implementing deep learning systems
// Implementing natural language processing systems
// Implementing computer vision systems



#include<bits/stdc++.h>
using namespace std;

struct Node
{
    public:
        int data;
        Node* next;

    public:
        Node(int data1, Node*next1){
            data = data1;
            next = next1;            
        }

    // Multiple Constructor
    public:
        Node(int data1){
            data = data1;
            next = nullptr;
        }        
};


// Conver Array To Linked List
Node * ConvertArrToLL(vector<int> &arr){
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

// Length of Linked List
int LengthOfLL(Node *head){
    int count = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// Check If Present
int CheckIfPresent(Node*head, int val){
    Node *temp = head;
    while (temp)
    {
        if (temp->data==val){
            return 1;    
        }
        temp = temp->next;
    }
    return 0;
}


int main(){
    vector<int> arr = {2, 5, 7, 8};


    // Node *y = new Node(arr[0], nullptr);      // That pointer (*) is used for pointer to memory location
    // cout << y << endl;


    // For Data we use
    // Node x =  Node(arr[0], nullptr);
    // cout << x.data << endl;

    // For Next we use
    // Node z = Node(arr[0], nullptr);
    // cout << z.next << endl;


    // For that Array to LL
    Node *head = ConvertArrToLL(arr);
    cout << head->data << endl;

    // For Print the elements of LL
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;


    // For print The Length
    cout <<"Length Of LL : " << LengthOfLL(head) << endl;


    // For Check If Present
    cout << CheckIfPresent(head, 7) << endl;
    cout << CheckIfPresent(head, 9) << endl;

    return 0;
}



// What about Memory Space 
// 32 Bit:
// 4 Bytes for Data
// 4 Bytes for Next
// 8 Bytes for Total
//     int == 4 bytes
//     pointer(*) == 4 bytes
//     Total  ==  8 Bytes        

// 64 Bit:
// 4 Bytes for Data
// 8 Bytes for Next
// 12 Bytes for Total
//     int == 4 bytes
//     pointer(*) == 8 bytes
//     Total  ==  12 Bytes
