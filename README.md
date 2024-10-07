# **Linked List in C++**
# Experiment 17 To study and implement Linked List

## Aim: - 
To run and execute a menu style code of linked list 


## Theory

A **Linked List** is a linear data structure where elements, called **nodes**, are stored in sequence, but unlike arrays, they are not stored in contiguous memory locations. Each node contains two parts:
1. **Data**: The value or data of the node.
2. **Pointer**: A reference (or pointer) to the next node in the sequence.

The last node in a linked list points to `NULL`, indicating the end of the list.

### **Types of Linked Lists**:
1. **Singly Linked List**:
   - Each node points to the next node in the sequence.
   - Traversal is unidirectional (from head to the last node).
   
2. **Doubly Linked List**:
   - Each node points to both the next node and the previous node.
   - Traversal can be bidirectional.

3. **Circular Linked List**:
   - The last node points back to the first node, forming a loop.

### **Basic Operations on Linked List**:
1. **Insertion**:
   - Adding a new node to the linked list at the beginning, end, or at a specific position.
   
2. **Deletion**:
   - Removing a node from the list by modifying pointers.
   
3. **Traversal**:
   - Visiting each node of the linked list to access or update its data.
   
4. **Search**:
   - Finding a node in the list by comparing node data.

### **Singly Linked List Implementation in C++**

Here’s how you can implement a basic **Singly Linked List** in C++:


### **Explanation of the Code**:
1. **Node Structure**: Each `Node` consists of two parts:
   - `data`: Stores the actual value.
   - `next`: A pointer to the next node in the list.

2. **LinkedList Class**:
   - Contains a pointer `head` to the first node in the list.
   - Functions include:
     - **Insert**: Adds a new node to the end of the list.
     - **Delete**: Deletes a node with a specific value.
     - **Display**: Prints the entire list.

3. **Main Function**: Provides a menu to perform various operations like insertion, deletion, and displaying the list.

### **Advantages of Linked List**:
1. **Dynamic Size**: Unlike arrays, linked lists are dynamic and can grow or shrink in size during runtime.
2. **Efficient Insertions/Deletions**: Insertions and deletions are easier and more efficient than in arrays, especially at the beginning or middle.

### **Disadvantages of Linked List**:
1. **No Random Access**: Elements must be accessed sequentially from the head node, making access time slower compared to arrays.
2. **Extra Memory Overhead**: Each node requires additional memory for the pointer (`next`), leading to increased memory consumption compared to arrays.

This C++ code provides a simple implementation of a **singly linked list** with basic operations.

## Code
~~~
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;        // Data of the node
    Node* next;      // Pointer to the next node
};

// LinkedList class
class LinkedList {
    Node* head;      // Pointer to the head (first node) of the list

public:
    // Constructor to initialize the head to NULL (empty list)
    LinkedList() {
        head = NULL;
    }

    // Function to insert a node at the end of the list
    void insert(int value) {
        Node* newNode = new Node();  // Create a new node
        newNode->data = value;       // Assign value to the new node
        newNode->next = NULL;        // New node will point to NULL as it's the last node

        if (head == NULL) {
            head = newNode;          // If list is empty, new node becomes the head
        } else {
            Node* temp = head;       // Temporary pointer to traverse the list
            while (temp->next != NULL) {
                temp = temp->next;   // Move to the last node
            }
            temp->next = newNode;    // Point the last node to the new node
        }
    }

    // Function to delete a node with a specific value
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        // If the node to be deleted is the head
        if (head->data == value) {
            Node* temp = head;       // Temporary pointer to store the current head
            head = head->next;       // Move the head pointer to the next node
            delete temp;             // Delete the old head
            cout << "Node with value " << value << " deleted." << endl;
            return;
        }

        // Deleting node in the middle or end
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;       // Traverse the list to find the node
        }

        if (temp->next == NULL) {
            cout << "Node with value " << value << " not found." << endl;
        } else {
            Node* deleteNode = temp->next;  // Store the node to be deleted
            temp->next = temp->next->next;  // Unlink the node from the list
            delete deleteNode;              // Delete the node
            cout << "Node with value " << value << " deleted." << endl;
        }
    }

    // Function to display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    int choice, value;

    while (1) {
        // Display menu options
        cout << "\nMenu Options:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                list.insert(value);
                break;

            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                list.deleteNode(value);
                break;

            case 3:
                list.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                return 0;

            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }

    return 0;
}
~~~
## Code Output

![](https://github.com/Sundar13905/Linked_list/blob/main/linked_list.png)

## Conclusion
We learnt how to implement single linked list in c++
