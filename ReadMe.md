# Ticket Collection Management Program

Welcome to the `Ticket Collection Managment` repository. The goal of this program is to create a collection managment system that will showcase the use of Data structures and a few Algorithms to manage a collection of objects. In this collection managment system I will implement features that will allow us to collect and manage Tickets of our favorite movies, concerts, and other events attended. The User Interface will be a simple command-line enabling the user to add, remove, sort, and search for Tickets in the collection. A .txt file will be included to persist data between sessions and I have included exception handling to deal with bad user input as well as issue reading/writing to file.

## Overview:
This program makes use of:

  - Two Data Structures (Linked List and Vector)
  - Two Sorting Algorithms (Quicksort and Mergesort)
  - Two Searching Algorithms (Binary Search and Linear Search)

These Data Structures and Algorithms will be implemeted with our class object `Ticket` to help manage this collection.

## Included Features:
The User Interface will be include 7 command-line user inputs from the main menu. See User Manual for more information.

Features of the User Interface included:

1. **View Collection**
2. **Add New Tickets**
3. **Delete Tickets**
4. **Search By Year**
5. **Search By Rating**
6. **Sort By Year**
7. **Sort By Rating**

## Files Included

**`DESIGNFINAL.md`** Updated Design document for Part 3 that explains implementation of user interface, exception handling, and persistent storage.

**`UserManual.md`** User Manual explains how to use command line UI.

**`collectionmain.cpp`** Updated main with command-line UI.

**`ticket.cpp`** Functions that incorporate Ticket class for use with Vector. Hold functions for searching and sorting vector * updated functions allow for persistent storage for reading/writing to file with exception handling.

**`ticketstubs.txt`** .txt document preloaded with ticket information to save data between sessions. You may add/delete from program.

**`ticket.h`** Header file for our ticket class definition. unchanged.

**`list.h`** Header file for Node and LinkedList definitions and Methods

  - Includes Linear Search by Rating implemented as method

**`list.cpp`** Functions that incorporate Linked List with Ticket Class

  - Includes Function to copy all tickets from vector for input into Linked List
