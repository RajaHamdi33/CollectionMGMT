#include <string>
#include <vector>
#include <algorithm>
using namespace std;



// Function to read tickets from a file and store them in a vector
vector<Ticket> readTicketsFromFile(const string& filename) {
    vector<Ticket> tickets;  // Vector to store Ticket objects
    ifstream file(filename); // Open the file

    try {
        if (!file.is_open()) {
            throw runtime_error("Error opening file: " + filename);
        }

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string token;

            // Read values from the line using comma as delimiter
            int year;
            string genre, title;
            double rating;

            if (getline(iss, token, ','))
                year = stoi(token);

            if (getline(iss, token, ','))
                genre = token;

            if (getline(iss, token, ','))
                title = token;

            if (getline(iss, token, ','))
                rating = stod(token);

            // Create a Ticket object and add it to the vector
            tickets.emplace_back(year, genre, title, rating);
        }
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    file.close(); // Close the file
    return tickets;
}


// Function to add a new ticket to the vector and update the file
void addNewTicket(vector<Ticket>& tickets, const string& filename) {
    int year;
    string genre, title;
    double rating, newRating;

    try {
        // Get user input for the new ticket with error handling
        cout << "Enter year: ";
        cin >> year;
        if (cin.fail()) {
            throw invalid_argument("Invalid input. Please enter a valid year.");
        }

        cin.ignore(); // Ignore the newline character left in the buffer
        cout << "Enter genre: ";
        getline(cin, genre);
        if (genre.empty()) {
            throw invalid_argument("Invalid input. Please enter a non-empty genre.");
        }

        cout << "Enter title: ";
        getline(cin, title);
        if (title.empty()) {
            throw invalid_argument("Invalid input. Please enter a non-empty title.");
        }

        cout << "Enter rating: ";
        cin >> rating;
        if (cin.fail()) {
            throw invalid_argument("Invalid input. Please enter a valid rating.");
        }

        while (rating > 5 || rating < 0) {
        cout << "Invalid input. Please Enter rating between 0-5" << endl;
        cin >> newRating;
        rating = newRating;
        }
        // Create a new Ticket object
        Ticket newTicket(year, genre, title, rating);

        // Add the new ticket to the vector
        tickets.push_back(newTicket);

        // Update the file with the new ticket information
        ofstream file(filename, ios::app); // Open the file in append mode
        if (!file.is_open()) {
            throw runtime_error("Error opening file: " + filename);
        }

        file << newTicket.getYear() << ',' << newTicket.getGenre() << ',' << newTicket.getTitle()
             << ',' << newTicket.getRating() << endl;
        file.close();
        cout << "New ticket added successfully." << endl << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
        // Clear error flags and discard invalid input from the stream
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// display tickets
static void displayTickets(const vector<Ticket>& tickets) {
    for (const auto& ticket : tickets) {
        cout << "Year: " << ticket.getYear() << ", Genre: " << ticket.getGenre()
                  << ", Title: " << ticket.getTitle() << ", Rating: " << ticket.getRating() << endl;
    }
}

// Function to partition the vector for Quicksort
int partition(vector<Ticket>& tickets, int low, int high) {
    int pivot = tickets[high].getYear();
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (tickets[j].getYear() <= pivot) {
            i++;
            swap(tickets[i], tickets[j]);
        }
    }

    swap(tickets[i + 1], tickets[high]);
    return i + 1;
}

// Quicksort function
void quicksort(vector<Ticket>& tickets, int low, int high) {
    if (low < high) {
        int partitionIndex = partition(tickets, low, high);

        quicksort(tickets, low, partitionIndex - 1);
        quicksort(tickets, partitionIndex + 1, high);
    }
}

// Function to call Quicksort on the vector
void sortTicketsByYear(vector<Ticket>& tickets) {
    quicksort(tickets, 0, tickets.size() - 1);
}


// Merge function for merging two halves of the vector
void merge(vector<Ticket>& tickets, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary vectors


    vector<Ticket> leftHalf;
    vector<Ticket> rightHalf;
    leftHalf.resize(n1);
    rightHalf.resize(n2);


    // Copy data to temporary vectors leftHalf[] and rightHalf[]
    for (int i = 0; i < n1; i++) {
        leftHalf[i] = tickets[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightHalf[j] = tickets[mid + 1 + j];
    }

    // Merge the temporary vectors back into the original vector
    int i = 0; // Initial index of the first subvector
    int j = 0; // Initial index of the second subvector
    int k = left; // Initial index of the merged vector

    while (i < n1 && j < n2) {
        if (leftHalf[i].getRating() <= rightHalf[j].getRating()) {
            tickets[k] = leftHalf[i];
            i++;
        } else {
            tickets[k] = rightHalf[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftHalf
    while (i < n1) {
        tickets[k] = leftHalf[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightHalf
    while (j < n2) {
        tickets[k] = rightHalf[j];
        j++;
        k++;
    }
}


// Merge sort function
void mergeSort(vector<Ticket>& tickets, int left, int right) {
    if (left < right) {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(tickets, left, mid);
        mergeSort(tickets, mid + 1, right);

        // Merge the sorted halves
        merge(tickets, left, mid, right);
    }
}

// Function to call Merge sort on the vector by rating
void sortTicketsByRating(vector<Ticket>& tickets) {
    mergeSort(tickets, 0, tickets.size() - 1);
}




// Binary search function for a vector of Tickets based on rating
bool binarySearchByRating(const vector<Ticket>& tickets, double targetRating, vector<Ticket>& foundTickets) {
    foundTickets.clear(); // Clear the vector to store the results

    int left = 0;
    int right = tickets.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (tickets[mid].getRating() == targetRating) {
            // Found a match, so check for others
            foundTickets.push_back(tickets[mid]);

            // Check for matches on the left side
            int leftIndex = mid - 1;
            while (leftIndex >= 0 && tickets[leftIndex].getRating() == targetRating) {
                foundTickets.push_back(tickets[leftIndex]);
                leftIndex--;
            }

            // Check for matches on the right side
            int rightIndex = mid + 1;
            while (rightIndex < tickets.size() && tickets[rightIndex].getRating() == targetRating) {
                foundTickets.push_back(tickets[rightIndex]);
                rightIndex++;
            }

            return true; // Found the target ratings
        } else if (tickets[mid].getRating() < targetRating) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false; // rating not found
}




// Function to delete a ticket from the vector based on user input for the title
void deleteTicketByTitle(vector<Ticket>& tickets, const string& titleToDelete, const string& filename) {
    auto it = remove_if(tickets.begin(), tickets.end(),
        [titleToDelete](const Ticket& ticket) { return ticket.getTitle() == titleToDelete; });

    if (it != tickets.end()) {
        tickets.erase(it, tickets.end());

        // Update the file with the updated vector of tickets
        ofstream file(filename); // Open the file (truncating it)
        try {
            if (!file.is_open()) {
                throw runtime_error("Error opening file: " + filename);
            }

            for (const auto& ticket : tickets) {
                file << ticket.getYear() << ',' << ticket.getGenre() << ',' << ticket.getTitle()
                     << ',' << ticket.getRating() << endl;
            }

            cout << "Ticket with title \"" << titleToDelete << "\" deleted successfully.\n" << endl;
        } catch (const exception& e) {
            cerr << e.what() << endl;
        }

        file.close(); // Close the file
    } else {
        cout << "Ticket with title \"" << titleToDelete << "\" not found." << endl;
    }
}