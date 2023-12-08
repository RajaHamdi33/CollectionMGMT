# Design Document Overview:

**Title:** Ticket Collection Managment System  
**Student:** Raja Hamdi
**Course:** COSC 2436 Fall 23  

## Introduction:
In this Initial Design Document We will go over all aspects of the program so that we have a good idea on how to build our program from the ground up. From the Data Structures and Algorithms we will use to how we will be able to react with our program through the User Interface. I will be using C++ code to build this program but will leave comments for simplicity. The goal of this program is to create a Collection Catalog System to help store and manage a collection. In this case I will be collecting Ticket Stubs. In Part 1 I will simply define object class with attributes and add to them in the coming parts. However this document will review the design of the entire system.


## Object Definition:

The Object in the collection is Tickets. Each ticket will have four attributes:

- **Genre:** The Genre of the ticket. For example Concert, Movie, Park addmisiion, Racing events, ect.
- **Title:** The Title of the ticket such as the title of the movie ticket or the title of the concert attended.
- **Year:** The year of the event of the Ticket.
- **Rating:** The Rating That the user inputs for that event.

## Data Structures:

For managing the collection, we plan to use two data structures:

**`Vector:`** A Vector will be used to store the entire collection. This data structure will allow for quick insertion and simple deletion of tickets from the collection. It will also allow implmentation of a MergeSort algorithm to sort the collection so that I am able to use Binary search with time complexity O(log n).

**`Linked List:`** A Linked List will be used for desmostration of Linear search. Because a simple linear search has time complexity of O(n) and the collection in the grand scheme will never be too large to matter.

## Search Algorithms:

**`Linear Search:`** Will be used with the Linked list for searching through the collection of tickets by a determined attribute. Despite its O(n) time complexity, this is a simple and effective method when the list is not sorted.

**`Binary Search:`** Binary Search will be implemented with use of the Vector due to the requirment that It must be sorted. I will implment a sorting algorithm on the vector then use Binary search to search by specific rating attribute. Time complexity of a binary search is very efficent O(log n)

## Sorting Algorithms:

**`QuickSort:`** QuickSort will be used to sort the vector by Year so that we may view entire collection In Year accending. Quicksort is easy to implement and has an average time complexity of O(n log n).

**`MergeSort:`** MergeSort Will be implemented to sort the vector by Rating accending for viewing pleasure and to allow the use of Binary Search algorithm when searching by Rating as described in Data Structures. 

## User Interface Design:

The User Interface will be include 7 command-line user inputs from the main menu. The main menu will give the user 7 options to choose from by entering in options 1-7 and depending on those options it may ask for more user input to search for a specific attribute.

Features of the User Interface will include:

1. **View Collection**
2. **Add New Tickets**
3. **Delete Tickets**
4. **Search By Year**
5. **Search By Rating**
6. **Sort By Year**
7. **Sort By Rating**

## Persistent Storage:

The goal of this program is to manage a collection so we will apply persistent storage allowing us to add/delete tickets and input/output to file to save our collection between sessions. I plan to add a .txt file that will save all ticket information with attributes sepperated by "commas" so that the program can read each attributes between the commas in case we have any blank space.

## Exception Handling:

The Program will handle exceptions from bad user input and problems opening file and well as read and write error handling. I plan to implement Try/Catch blocks to handle these exceptions.
