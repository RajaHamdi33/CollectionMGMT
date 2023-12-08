#ifndef TICKET
#define TICKET
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



// Ticket class definition
class Ticket {
public:

    //setter methods
    void setYear(int newYear) {
         year = newYear; 
    }

    void setGenre(const string& newGenre) {
         genre = newGenre; 
    }

    void setTitle(const string& newTitle) {
         title = newTitle; 
    }

    void setRating(double newRating) {
         rating = newRating; 
    }

    // getter methods
    int getYear() const {
         return year; 
    }
    

    const string& getGenre() const {
         return genre; 
    }
    

    const string& getTitle() const {
         return title; 
    }
    

    double getRating() const {
         return rating; 
    }

    

    // constructors
    Ticket(int year, const string& genre, const string& title, double rating)
        : year(year), genre(genre), title(title), rating(rating) {}

    Ticket(){
        year=0;
        genre="";
        title="";
        rating=0;
    }

    // Display ticket info
    void display() const {
        cout << "Year: " << year << ", Genre: " << genre << ", Title: " << title << ", Rating: " << rating << endl;
        
    }
    

    

private:
    int year;
    string genre;
    string title;
    double rating;
};



#endif