#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;        
    Node* next;      
};

// LinkedList class
class LinkedList {
    Node* head;      

public:

    LinkedList() {
        head = NULL;
    }

    void insert(int value) {
        Node* newNode = new Node();  
        newNode->data = value;      
        newNode->next = NULL;        

        if (head == NULL) {
            head = newNode;         
        } else {
            Node* temp = head;      
            while (temp->next != NULL) {
                temp = temp->next;   
            }
            temp->next = newNode;    
        }
    }

    
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        
        if (head->data == value) {
            Node* temp = head;       
            head = head->next;       
            delete temp;             
            cout << "Node with value " << value << " deleted." << endl;
            return;
        }

        
        Node* temp = head;
        while (temp->next != NULL && temp->next->data != value) {
            temp = temp->next;       
        }

        if (temp->next == NULL) {
            cout << "Node with value " << value << " not found." << endl;
        } else {
            Node* deleteNode = temp->next;  
            temp->next = temp->next->next;  
            delete deleteNode;              
            cout << "Node with value " << value << " deleted." << endl;
        }
    }

    
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
