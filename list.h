#ifndef LIST
#define LIST
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


class Node {
public:
    Ticket data;
    Node* next;

    Node(const Ticket& data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to add a new node to the linked list
    void addNode(const Ticket& ticket) {
        Node* newNode = new Node(ticket);
        newNode->next = head;
        head = newNode;
    }

    // Function to display all nodes in the linked list
    void displayList() const {
        Node* current = head;
        while (current != nullptr) {
            current->data.display();
            
            current = current->next;
        }
    }

    // Function to clear all nodes in the linked list (free memory)
    void clearList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Getter function for the head of the linked list
    Node* getHead() const {
        return head;
    }

    // linear search the linked list based on the input date
    void searchByDate(int targetYear) const {
        Node* current = head;
        bool found = false;

        while (current != nullptr) {
            if (current->data.getYear() == targetYear) {
                current->data.display();
                
                found = true;
            }
            current = current->next;
        }

        if (!found) {
            cout << endl << "No tickets found for the year " << targetYear << endl;
        }
    }
};



#endif