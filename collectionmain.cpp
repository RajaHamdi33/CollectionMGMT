#include <iostream>
#include "ticket.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <limits> // for numeric_limits
#include <algorithm>
#include "list.h"
#include "ticket.cpp"
#include "list.cpp"
using namespace std;



int main() {

    string filename = "ticketstub.txt";

    // Read tickets from the file
    vector<Ticket> tickets = readTicketsFromFile(filename);

    int input;
    cout << endl;
    cout << "Welcome to the Ticket Collection Catalog " << endl;
    cout << "Please Choose an option below: " << endl << endl;
    cout << "Press 1 to View entire collection" << endl;
    cout << "Press 2 to ADD to collection" << endl;
    cout << "Press 3 to DELETE from collection" << endl;
    cout << "Press 4 to SORT Collection by Year Accending(Vector-QuickSort)" << endl;
    cout << "Press 5 to Sort by Ratings accending (Vector-MergeSort)" << endl;
    cout << "Press 6 to SEARCH by Rating (Vector-BinarySearch)" << endl;
    cout << "Press 7 to SEARCH by Year (LinkedList-Linear Search)" << endl;
    cin >> input;

    while (input != 0) {
        if (input ==1) {
                // Display the tickets
                displayTickets(tickets);
                cout << endl;
        }
        else if (input == 2) {
            // Add a new ticket
            addNewTicket(tickets, filename);
        }
        else if (input == 3) {
             // Get user input for the title to delete
            string titleToDelete;
            cout << "Enter the title of the ticket to delete: ";
            cin.ignore();
            getline(cin, titleToDelete);

    
            // Delete the ticket from the vector and update the file
            deleteTicketByTitle(tickets, titleToDelete, filename);
        }

        else if (input == 4) {
            // Call the function to sort the vector by year
            sortTicketsByYear(tickets);

            // Display the sorted vector
            cout << "Sorted Vector: " << endl;
            for (const auto& ticket : tickets) {
            ticket.display();
        }
            cout << endl;
        }

        else if (input == 5) {
            // sort the vector by rating
            sortTicketsByRating(tickets);

            // Display the sorted vector
            cout << "Sorted Vector: " << endl;
            for (const auto& ticket : tickets) {
            ticket.display();
            
            }
            cout << endl;
        }
        else if (input == 6) {

            sortTicketsByRating(tickets);
            // Prompt user for a rating to search
            double targetRating, newRating;
            cout << "Enter the rating to search for between 1-5: " << endl;
            cin >> targetRating;
            while (targetRating > 5 || targetRating < 0) {
                
                cout << "Invalid selection please enter rating between 1-5" << endl;
                cin >> newRating;
                targetRating = newRating;

            }

            // Perform binary search and print all tickets with the specified rating
            vector<Ticket> foundTickets;
            if (binarySearchByRating(tickets, targetRating, foundTickets)) {
            cout << "Tickets found with rating " << targetRating << ":\n";
                for (const auto& ticket : foundTickets) {
                    ticket.display();
            
                }
                cout << endl;
            }
            else {
                cout << "No Tickets found with Rating: " << targetRating << endl << endl;
            }
        }
        
        else if (input == 7) {
            // Create a linked list
                LinkedList linkedList;

                // copy items from the vector into the linked list
                copyVectorToLinkedList(tickets, linkedList);

                // Search for tickets with a specific date
                int searchYear;
                cout << "Enter the year to search for tickets: ";
                cin >> searchYear;

                // linear search the linked list based on the user input date
                linkedList.searchByDate(searchYear);
                cout << endl;
        }
         
            else {
                cout << "Invalid Input please select from the options below: " << endl << endl;
            }
        
    cout << endl << "Menu Options: " << endl;
    cout << "Press 1 to View entire collection" << endl;
    cout << "Press 2 to ADD to collection" << endl;
    cout << "Press 3 to DELETE from collection" << endl;
    cout << "Press 4 to SORT Collection by Year Accending(Vector-QuickSort)" << endl;
    cout << "Press 5 to Sort by Ratings accending (Vector-MergeSort)" << endl;
    cout << "Press 6 to SEARCH by Rating (Vector-BinarySearch)" << endl;
    cout << "Press 7 to SEARCH by Year (LinkedList-Linear Search)" << endl;
    cin >> input;
        
    }
    
    cout << "Keep Collecting! Goodbye." << endl;

    return 0;
}
