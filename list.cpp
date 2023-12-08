#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;


//copy items from a vector into a linked list
void copyVectorToLinkedList(const vector<Ticket>& ticketVector, LinkedList& linkedList) {
    for (const auto& ticket : ticketVector) {
        linkedList.addNode(ticket);
    }
}

